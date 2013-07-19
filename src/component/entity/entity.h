#ifndef __JB_ENTITY_H_
#define __JB_ENTITY_H_
#include "stdinc.h"
#include "base/refcountedtarget.h"

namespace Component{
class Entity : public Base::RefcountedTarget{
public:
	/// default constructor
	Entity();
	/// default destructor
	virtual ~Entity();

	/// unique id
	int id() const;

protected:
	int m_id;
};// end of Entity

}// end of Entity
#endif
