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
    int CurState() const;
    /// set current state to c 
    void SetCurState(int c);

    /// return next state
    int NextState() const;
    /// set next state to n
    void SetNextState(int n);

protected:
    /// when change the current state 
    virtual void OnTransition(int from, int to);
    /// enter current state
    virtual void OnEnter(int to);
    /// leave current state
    virtual void OnLeave(int from);

    /// current state
    int cur;
    /// next state
    int next;
};// end of FsmContext
}// end of Base
#endif
