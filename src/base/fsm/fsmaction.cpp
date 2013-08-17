#include "fsmaction.h"

namespace Base {
    
/// constructor
FsmAction::FsmAction(){
    
}

/// destructor
FsmAction::~FsmAction(){
    
}

/// apply to the context
bool FsmAction::Apply(FsmContext* ct, FsmEvent* et) const{
    return false;
}
    
}