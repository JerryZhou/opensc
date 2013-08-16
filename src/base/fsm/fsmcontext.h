#ifndef __JB_FSMCONTEXT_H_
#define __JB_FSMCONTEXT_H_
#include "stdinc.h"

namespace Base{
class FsmContext{
public:
    /// constructor
    FsmContext();
    /// destructor
    virtual ~FsmContext();

    /// return current state
    int curState() const;
    /// set current state to c 
    void setCurState(int c);

    /// return next state
    int nextState() const;
    /// set next state to n
    void setNextState(int n);

protected:
    /// when change the current state 
    virtual void onTransition(int from, int to);
    /// enter current state
    virtual void onEnter(int to);
    /// leave current state
    virtual void onLeave(int from);

    /// current state
    int cur;
    /// next state
    int next;
};// end of FsmContext
}// end of Base
#endif
