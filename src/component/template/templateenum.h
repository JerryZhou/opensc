#ifndef __JB_TEMPLATEENUM_H_
#define __JB_TEMPLATEENUM_H_
#include "stdinc.h"
#include "base/log.h"
#include "util/stringatom.h"
#include "util/dictionary.h"
#include "util/array.h"
#include "component/template/templateinit.h"

namespace Component {
/// template enum
template<typename ENUMTYPE>
class TemplateEnum {
public:
    /// typedef enum
    typedef TemplateEnum<ENUMTYPE> TemplateEnumThis;
    
    /// get the name of enum
    static const Util::StringAtom& Name(const ENUMTYPE& e){
        // first from the array
        if (TemplateEnumThis::enum2Name.IsEmpty()) {
            return NameAt((IndexT)(e));
        }
        // from the dictionary
        IndexT idx = TemplateEnumThis::enum2Name.FindIndex(e);
        if (idx != InvalidIndex) {
            return TemplateEnumThis::enum2Name.ValueAtIndex(idx);
        }
        // do not get it
        static Util::StringAtom dummys;
        LOGE("wrong enum value to find name %d in %s", (int)(e), TemplateEnumThis::name.Value());
        return dummys;
    }
    
    /// get name from the array
    static const Util::StringAtom& NameAt(IndexT idx){
        if (idx >= 0 && idx < TemplateEnumThis::enumNames.Size()) {
            return TemplateEnumThis::enumNames[idx];
        }
        static Util::StringAtom dummys;
        LOGE("wrong enum value to find name %d in %s", idx, TemplateEnumThis::name.Value());
        return dummys;
    }
    
    /// get the idx of whatever is the normal enum or the flag
    static IndexT IndexOf(const ENUMTYPE& e){
        // first we can juadge if this enum is a flag
        if (TemplateEnumThis::enum2Name.IsEmpty()) {
            return (IndexT)(e);
        }
        return IndexOf(Name(e));
    }
    
    /// get the idx from name 
    static IndexT IndexOf(const Util::StringAtom &n){
        for (IndexT i = 0; i < TemplateEnumThis::enumNames.Size(); ++i) {
            if (TemplateEnumThis::enumNames[i] == n) {
                return i;
            }
        }
        return InvalidIndex;
    }
    
    /// get the num of name
    static const ENUMTYPE& Value(const Util::StringAtom& n){
        IndexT idx = TemplateEnumThis::name2Enum.FindIndex(n);
        if (idx != InvalidIndex) {
            return TemplateEnumThis::name2Enum.ValueAtIndex(idx);
        }
        LOGE("wrong name value to find enum %s in %s", n.Value(), TemplateEnumThis::name.Value());
        return (ENUMTYPE)(Size());
    }
    
    /// get the size of enum
    static SizeT Size() {
        return TemplateEnumThis::enumNames.Size();
    }
    
    /// setup the enum
    static void Setup(){
        ;
    };
    
    /// type name
    static const Util::StringAtom Name(){
        return TemplateEnumThis::name;
    }
    
private:
    /// begin bulk add entry for enum
    static void BeginAdd(){
        TemplateEnumThis::enum2Name.BeginBulkAdd();
    }
    /// add entry for enum
    static void Add(const Util::StringAtom &n, const ENUMTYPE& e, bool map = true){
        if (map) {
            TemplateEnumThis::enum2Name.Add(e, n);
        }
        TemplateEnumThis::name2Enum.Add(n, e);
        TemplateEnumThis::enumNames.Append(n);
    }
    /// end bulk add entry for enum
    static void EndAdd(){
        TemplateEnumThis::enum2Name.EndBulkAdd();
    }
    
    /// data members
    static Util::Dictionary<ENUMTYPE, Util::StringAtom> enum2Name;
    static Util::Dictionary<Util::StringAtom, ENUMTYPE> name2Enum;
    static Util::Array<Util::StringAtom> enumNames;
    static Util::StringAtom name;
};// end of TemplateEnum

/// delcare template variable enum2Name
template<typename ENUMTYPE>
Util::Dictionary<ENUMTYPE, Util::StringAtom> TemplateEnum<ENUMTYPE>::enum2Name;
/// declare template variable name2Enum
template<typename ENUMTYPE>
Util::Dictionary<Util::StringAtom, ENUMTYPE > TemplateEnum<ENUMTYPE>::name2Enum;
/// declare template variable enumNames
template<typename ENUMTYPE>
Util::Array<Util::StringAtom> TemplateEnum<ENUMTYPE>::enumNames;

/// declare template name
template<typename ENUMTYPE>
Util::StringAtom TemplateEnum<ENUMTYPE>::name;
    
/// setup from definitions
void SetupEnums();
}// end of Component

/// define nums
#define JEnumBegin(NS, Enum) namespace NS { \
    extern const char* _##Enum [];\
    extern const SizeT _##Enum##_Size;\
    enum Enum{
#define JEnumBeginWith(NS, Enum, TYPE) namespace NS { \
    extern const char* _##Enum [];\
    extern const SizeT _##Enum##_Size;\
    enum Enum : TYPE {
#define JEnumValueWith(Enum, n, i) Enum##_##n = i,
#define JEnumValue(Enum, n) Enum##_##n,
#define JEnumEnd(NS, Enum) Enum##_Count, }; typedef Component::TemplateEnum< NS::Enum > E##Enum;}\
    template<>\
    NS::Enum & Record::TemplateInit::Init< NS::Enum > ( NS::Enum &ref);\
    template<>\
    void Component::TemplateEnum< NS::Enum >::Setup();
#include "component/template/record/recordenum.h"
#include "component/template/record/recordflag.h"

#endif
