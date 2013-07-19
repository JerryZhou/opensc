#ifndef __JB_ABILITY_H_
#define __JB_ABILITY_H_
#include "target.h"

namespace Component{
//declare classes
//---------------------------------------------------------------------------------
class Entity;

//---------------------------------------------------------------------------------
class Ability{
public:
	/// default constructor
	Ability(Component::Entity* owner);
	/// default destructor
	virtual ~Ability();

	/// get the ability owner
	Component::Entity* owner() const;

protected:
	/// ability target
	Base::TargetPtr<Component::Entity> m_owner;
};// end of Ability

}// end of Component
#endif
