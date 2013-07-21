#ifndef __JB_BEHAVIOR_H_
#define __JB_BEHAVIOR_H_
#include "base/target.h"

namespace Component{
//declare classes
//---------------------------------------------------------------------------------
class Entity;

//---------------------------------------------------------------------------------
class Entity;
class Behavior{
public:
	/// default constructor
	Behavior();
	/// default destructor
	virtual ~Behavior();

	/// behavior  will detach from the fomer target
	void attach(Component::Entity* target);
	/// detach from the owner
	void detach();

	/// called when attach
	virtual void onAttach(Component::Entity* target);
	/// called when detach
	virtual void onDetach(Component::Entity* target);

	/// execute chance
	virtual void onExecute(float ts);

protected:
	/// behavior target
	Base::TargetPtr<Component::Entity> m_owner;
};
}
#endif
