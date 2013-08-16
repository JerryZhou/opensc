#include "fsmevent.h"

namespace Base {
    /// default constructor
    FsmEvent::FsmEvent()
    : evt(-1)
    , param(NULL){
        
    }
    
    /// construct from e and p
    FsmEvent::FsmEvent(int e, void* p)
    : evt(e)
    , param(p){
        
    }
    
    /// default destructor
    FsmEvent::~FsmEvent(){
        
    }
}