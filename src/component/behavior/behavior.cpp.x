#include "behavior.h"
#include "component/entity/entity.h"

namespace Component{

/// default constructor
Behavior::Behavior(){

}

/// default destructor: must detach first
Behavior::~Behavior(){
	J_ASSERT(m_owner.isNull());
}

/// behavior  will detach from the fomer target
void Behavior::attach(Component::Entity* target){
	// if target is the same , just return
	IF_DO(m_owner == target, return);
	// if former is not null, detach from owner
	IF_DO(m_owner, detach());

	// new owner
	m_owner = target;
	// call event
	IF_DO(target != NULL, onAttach(target));
}

/// detach from the owner
void Behavior::detach(){
	// call event
	IF_DO(m_owner, onDetach(m_owner));
	// clear target
	m_owner = NULL;
}

/// called when attach
void Behavior::onAttach(Component::Entity* target){

}

/// called when detach
void Behavior::onDetach(Component::Entity* target){

}

/// execute chance
void Behavior::onExecute(float ts){

}
}
