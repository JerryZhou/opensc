#ifndef __JB_TEMPLATELOADER_H_
#define __JB_TEMPLATELOADER_H_
#include "stdinc.h"
#include "io/uri.h"
#include "io/xmlreader.h"
#include "component/template/templaterecord.h"
#include "component/template/templateenum.h"
#include "component/template/templateclass.h"

namespace Component{
/// declare types
class TemplateContainer;
    
/// record loader
class TemplateLoader{
public:
    /// type define
    typedef Record::TemplateRecord* TemplateRecordPtr;
    typedef void (*LoadClassEntry)(Ptr<IO::XmlReader> &xmlReader, TemplateRecordPtr &ref, TemplateContainer& container);
    typedef Util::Dictionary<Util::StringAtom, LoadClassEntry> LoadClassEntryDictionary;
    
    /// load type: struct, enum, flag, basic types
    template<typename TYPE>
    static void LoadType(Ptr<IO::XmlReader> &xmlReader, TYPE &ref, const Util::StringAtom &attr, TemplateContainer& container){
        LOGE("Can not find loader for this type : sizeof(TYPE) == %d Name = %s Attr = %s",
             sizeof(TYPE),
             xmlReader->GetCurrentNodeName().AsCharPtr(),
             attr.IsValid() ? attr.Value() : "Value");
    }
    
    /// load data to ref
    static void Load(Ptr<IO::XmlReader> &xmlReader, const Util::StringAtom& n, TemplateRecordPtr &ref, TemplateContainer& container);
    
    /// setup the loader
    static void SetupLoader();
    
    /// load record
    static void LoadRecord(const IO::URI &uri, TemplateContainer& container);
    
    /// default attr
    static Util::StringAtom ValueAttr;
    static Util::StringAtom IdAttr;
    static Util::StringAtom DefaultAttr;
    static Util::StringAtom ParentAttr;
    static Util::StringAtom IndexAttr;
    
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
