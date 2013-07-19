#include "entitynode.h"

namespace Component{

/// default constructor
EntityNode::EntityNode()
: m_node(NULL){

}

/// default destructor
EntityNode::~EntityNode(){
	CC_SAFE_RELEASE_NULL(m_node);
}

/// get target
cocos2d::CCNode* EntityNode::node() const{
	return m_node;
}

/// attach target
void EntityNode::setNode(cocos2d::CCNode* target){
	IF_DO(target == m_node, return);

	CC_SAFE_RELEASE_NULL(m_node);
	m_node = target;
	CC_SAFE_RETAIN(m_node);
}
}
