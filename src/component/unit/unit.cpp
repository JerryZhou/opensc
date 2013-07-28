#include "unit.h"
#include "threading/interlocked.h"

namespace Component{

__ImplementClass(Component::Unit, 'unit', Base::EventTarget);

/// unique id generater
static int unique_id(){
    static volatile int s_id_pool = 10000000;
    return Threading::Interlocked::Increment(s_id_pool);
}

/// unique id recycle
static void recycle_id(int id){
	;
}

/// default constructor
Unit::Unit()
:uuid(unique_id()){

}

/// default destructor
Unit::~Unit(){
    recycle_id(uuid);
}

/// unique id
int Unit::uid() const{
    return this->uuid;
}
    
/// return the tid of unit
const Record::TID& Unit::tid() const{
    return this->unitRecord->Id;
}

/// return the record about the unit
const Record::Unit* Unit::record() const{
    return this->unitRecord;
}
    
/// set the record*
void Unit::SetRecord(const Record::Unit* record){
    this->unitRecord = record;
}
    
}// end of Component
