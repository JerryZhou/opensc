#include "entity.h"

namespace Component{

/// unique id generater
static int unique_id(){
	static volatile int s_id_pool = 0;
	return Base::Interlocked::increment(s_id_pool);
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
