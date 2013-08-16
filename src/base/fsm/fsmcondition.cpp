#include "fsmcondition.h"

namespace Base {
    
/// constructor
FsmCondition::FsmCondition(){
    
}

/// destructor
FsmCondition::~FsmCondition(){
    
}

/// check if the context is statify the condition
bool FsmCondition::check(FsmContext* ct, FsmEvent* et) const{
    return false;
}

}