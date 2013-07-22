#ifndef __JB_TEMPLATEENUM_H_
#define __JB_TEMPLATEENUM_H_
#include "stdinc.h"
#include "base/log.h"
#include "util/stringatom.h"
#include "util/dictionary.h"

namespace Component {
/// template enum
template<typename ENUMTYPE>
class TemplateEnum {
public:
    /// typedef enum
    typedef TemplateEnum<ENUMTYPE> TemplateEnumThis;
    
    /// get the name of enum
    static const Util::StringAtom& Name(const ENUMTYPE& e){
        IndexT idx = TemplateEnumThis::enum2Name.FindIndex(e);
        if (idx != InvalidIndex) {
            return TemplateEnumThis::enum2Name.ValueAtIndex(idx);
        }
        static Util::StringAtom dummys;
        LOGE("wrong enum value to find name %d in %s", (int)(e), TemplateEnumThis::name.Value());
        return dummys;
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
        return TemplateEnumThis::enum2Name.Size();
    }
    
    /// setup the enum
    static void Setup(){
        ;
    };
    
private:
    /// add entry for enum
    static void Add(const Util::StringAtom &n, const ENUMTYPE& e){
        TemplateEnumThis::enum2Name.Add(e, n);
        TemplateEnumThis::name2Enum.Add(n, e);
    }
    
    /// data members
    static Util::Dictionary<ENUMTYPE, Util::StringAtom> enum2Name;
    static Util::Dictionary<Util::StringAtom, ENUMTYPE> name2Enum;
    static Util::StringAtom name;
};// end of TemplateEnum

/// delcare template variable enum2Name
template<typename ENUMTYPE>
Util::Dictionary<ENUMTYPE, Util::StringAtom> TemplateEnum<ENUMTYPE>::enum2Name;
/// declare template variable name2Enum
template<typename ENUMTYPE>
Util::Dictionary<Util::StringAtom, ENUMTYPE > TemplateEnum<ENUMTYPE>::name2Enum;
/// declare template name
template<typename ENUMTYPE>
Util::StringAtom TemplateEnum<ENUMTYPE>::name;
    
/// setup from definitions
void SetupEnums();
}// end of Component

/// define nums
#define JEnumBegin(NS, Enum) namespace NS { enum Enum{
#define JEnumBeginWith(NS, Enum, TYPE) namespace NS { enum Enum : TYPE {
#define JEnumValueWith(Enum, n, i) Enum##_##n = i,
#define JEnumValue(Enum, n) Enum##_##n,
#define JEnumEnd(NS, Enum) Enum##_Count, }; }\
    template<>\
    void Component::TemplateEnum< NS::Enum >::Setup();
#include "component/template/record/recordenum.h"
#include "component/template/record/recordflag.h"
#endif
