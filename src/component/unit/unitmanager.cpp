#include "unitmanager.h"
#include "unit.h"
#include "component/template/templatemanager.h"

namespace Component {
__ImplementClass(Component::UnitManager, 'umgr', Base::Manager)
    
using namespace Base;
typedef Record::Unit RecordUnit;
    
/// constructor
UnitManager::UnitManager(){
    
}
/// destructor
UnitManager::~UnitManager(){
    
}

/// create unit
Ptr<Unit>& UnitManager::CreateUnit( Record::TID tid){
    const RecordUnit *record = TemplateManager::Singleton.get()->FindRecord<RecordUnit>(tid);
    if (record) {
        Ptr<Unit> unit = Unit::Create();
        unit->SetRecord(record);
        
        this->units.Add(unit->uid(), unit);
        
        return this->units.ValueAtIndex(this->units.FindIndex(unit->uid()));
    }
    return this->nullPtr;
}
/// destroy right now
void UnitManager::DestroyUnit( const Ptr<Unit> &unit){
    
}
/// destroy unit next frame begin
void UnitManager::DestroyUnitLater( const Ptr<Unit> &unit){
    
}

/// manager behavior
const Ptr<Unit>& UnitManager::Find( int uid) const{
    return this->nullPtr;
}
}