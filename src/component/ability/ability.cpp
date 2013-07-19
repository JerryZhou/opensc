#include "ability.h"
#include "component/entity/entity.h"

namespace Component{

/// default constructor
Ability::Ability(Component::Entity* owner)
: m_owner(owner){

}
/// default destructor
Ability::~Ability(){
	m_owner = NULL;
}

/// get the ability owner
Component::Entity* Ability::owner() const{
	return m_owner;
}

}// end of Component
