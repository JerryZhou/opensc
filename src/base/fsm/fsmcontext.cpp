#include "fsmcontext.h"

namespace Base {
/// constructor
FsmContext::FsmContext(){
    
}
    
/// destructor
FsmContext::~FsmContext(){
    
}

/// return current state
int FsmContext::CurState() const{
    return this->cur;
}

/// set current state to c
void FsmContext::SetCurState(int c){
    IF_DO(this->cur==c, return);
    int from = this->cur;
    
    OnLeave(this->cur);
    this->cur = c;
    OnEnter(c);
    
    OnTransition(from, c);
}

/// return next state
int FsmContext::NextState() const{
    return this->next;
}

/// set next state to n
void FsmContext::SetNextState(int n){
    this->next = n;
}
}