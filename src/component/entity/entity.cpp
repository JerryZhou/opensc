#include "entity.h"
#include "threading/interlocked.h"

namespace Component{

__ImplementClass(Component::Entity, 'enty', Base::EventTarget);

/// unique id generater
static int unique_id(){
    static volatile int s_id_pool = 0;
    return Threading::Interlocked::Increment(s_id_pool);
}

/// unique id recycle
static void recycle_id(int id){
	;
}

/// default constructor
Entity::Entity()
:m_id(unique_id()){

}

/// default destructor
Entity::~Entity(){
    recycle_id(m_id);
}

/// unique id
int Entity::id() const{
    return m_id;
}
}// end of Component
