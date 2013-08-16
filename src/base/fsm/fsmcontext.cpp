#include "fsmcontext.h"

namespace Base {
/// constructor
FsmContext::FsmContext(){
    
}
    
/// destructor
FsmContext::~FsmContext(){
    
}

/// return current state
int FsmContext::curState() const{
    return this->cur;
}

/// set current state to c
void FsmContext::setCurState(int c){
    IF_DO(this->cur==c, return);
    int from = this->cur;
    
    onLeave(this->cur);
    this->cur = c;
    onEnter(c);
    
    onTransition(from, c);
}

/// return next state
int FsmContext::nextState() const{
    return this->next;
}

/// set next state to n
void FsmContext::setNextState(int n){
    this->next = n;
}
}