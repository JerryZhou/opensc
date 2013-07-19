#ifndef __JB_ENTITYNODE_H_
#define __JB_ENTITYNODE_H_
#include "component/entity/entity.h"

namespace Component{
class EntityNode : public Component::Entity{
public:
	/// default constructor
	EntityNode();
	/// default destructor
	virtual ~EntityNode();

	/// get target
	cocos2d::CCNode* node() const;
	/// attach target
	void setNode(cocos2d::CCNode* target);

protected:
	/// target node
	cocos2d::CCNode* m_node;
};// end of EntityNode

}// end of Component
#endif
