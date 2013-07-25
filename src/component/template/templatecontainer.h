#ifndef __JB_TEMPLATECONTAINER_H_
#define __JB_TEMPLATECONTAINER_H_
#include "stdinc.h"
#include "util/stringatom.h"
#include "util/dictionary.h"
#include "base/event/eventtarget.h"
#include "component/template/templateenum.h"

/// declare record
namespace Record {
struct TemplateRecord;
}
namespace Component{
/// continer
class TemplateContainer : public Base::EventTarget{
    __DeclareClass(TemplateContainer);
public:
    /// constructor
    TemplateContainer();
    /// destructor
    virtual ~TemplateContainer();

    /// find the record
    const Record::TemplateRecord* FindRecord(const Util::StringAtom& name, Record::ERecordType record) const;
    
    /// add record
    void AddRecord(const Record::TemplateRecord* record);

private:
    typedef Util::Dictionary<Util::StringAtom, const Record::TemplateRecord*> RecordDictionary;
    typedef Util::Array<RecordDictionary> RecordDicArray;
    RecordDicArray records;
};
}
#endif
