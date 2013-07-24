#ifndef __JB_TEMPLATELOADER_H_
#define __JB_TEMPLATELOADER_H_
#include "component/template/templaterecord.h"
#include "component/template/templateenum.h"
#include "component/template/templateclass.h"

namespace Component{
/// record loader
class TemplateLoader{
public:
    /// type define
    typedef Record::TemplateRecord* TemplateRecordPtr;
    typedef void (*LoadClassEntry)(TemplateRecordPtr &ref);
    typedef Util::Dictionary<Util::StringAtom, LoadClassEntry> LoadClassEntryDictionary;
    
    /// load type: struct, enum, flag, basic types
    template<typename TYPE>
    static void LoadType(TYPE &ref);

    /// load class
    template<typename CLASS>
    static void LoadClass(TemplateRecordPtr &ref);
    
    /// load data to ref
    static void Load(const Util::StringAtom& n, TemplateRecordPtr &ref);
    
    /// setup the loader
    static void SetupLoader();
    
private:
    /// begin add the entrys
    static void BeginBulkAdd();
    /// add entrys
    static void Add(const Util::StringAtom& n, LoadClassEntry entry);
    /// end add entrys
    static void EndBulkAdd();
    
    /// save the load entry
    static LoadClassEntryDictionary loadEntrys;
};
}
#endif
