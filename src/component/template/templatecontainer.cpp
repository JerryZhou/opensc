#include "templatecontainer.h"
#include "component/template/templaterecord.h"

namespace Component{
using namespace Record;
    
__ImplementClass(Component::TemplateContainer, 'tcer', Base::EventTarget);
    
/// constructor
TemplateContainer::TemplateContainer()
: records(Record::_ERecordType_Size, 0, RecordDictionary()){
    
}
/// destructor
TemplateContainer::~TemplateContainer(){
    for (int i = 0; i < Record::_ERecordType_Size; ++i) {
        for (int j=0; j<this->records[i].Size(); ++j) {
            Record::TemplateRecord* record = (Record::TemplateRecord*)(this->records[i].ValueAtIndex(j));
            delete  record;
        }
    }
}

/// find the record
const Record::TemplateRecord* TemplateContainer::FindRecord(const Util::StringAtom& name, Record::ERecordType recordType) const{
    IndexT idx = this->records[recordType].FindIndex(name);
    if (idx != InvalidIndex) {
        return this->records[recordType].ValueAtIndex(idx);
    }
    LOGE("can not find templaterecord [%s]", name.Value());
    return NULL;
}

/// add record
void TemplateContainer::AddRecord(const Record::TemplateRecord* record){
    if (record) {
        this->records[record->RecordType].Add(record->Id, record);
    }
}
    
/// add ref as the defalt record
void TemplateContainer::AddDefaultRecord(const TemplateRecordPtr &ref){
    this->defaultRecords.Add(&(ref->GetRecordId()), ref);
}

/// find if there is a default structor
const Record::TemplateRecord* TemplateContainer::FindDefaultRecord(const TemplateRecordPtr &ref) const{
    IndexT idx = this->defaultRecords.FindIndex(&(ref->GetRecordId()));
    if (idx != InvalidIndex) {
        return this->defaultRecords.ValueAtIndex(idx);
    }
    return NULL;
}
    
}
