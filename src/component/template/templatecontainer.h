#ifndef __JB_TEMPLATECONTAINER_H_
#define __JB_TEMPLATECONTAINER_H_
#include "stdinc.h"
#include "util/stringatom.h"
#include "util/dictionary.h"
#include "base/event/eventtarget.h"
#include "component/template/templateenum.h"
#include "component/template/templaterecord.h"

namespace Component{
/// continer
class TemplateContainer : public Base::EventTarget{
    __DeclareClass(TemplateContainer);
public:
    /// declare types
    typedef Record::TemplateRecord* TemplateRecordPtr;
    
    /// constructor
    TemplateContainer();
    /// destructor
    virtual ~TemplateContainer();

    /// find the record
    const Record::TemplateRecord* FindRecord(const Util::StringAtom& name, Record::ERecordType record) const;
    
    /// add record
    void AddRecord(const Record::TemplateRecord* record);
    
    /// default manager
    void AddDefaultRecord(const TemplateRecordPtr &ref);
    
    /// get the default ref for class
    const Record::TemplateRecord* FindDefaultRecord(const TemplateRecordPtr &ref) const;

private:
    typedef Util::Dictionary<const Record::RecordClassId*, const Record::TemplateRecord*> DefaultRecordDictonary;
    typedef Util::Dictionary<Util::StringAtom, const Record::TemplateRecord*> RecordDictionary;
    typedef Util::Array<RecordDictionary> RecordDicArray;
    RecordDicArray records;
    DefaultRecordDictonary defaultRecords;
};
}
#endif
