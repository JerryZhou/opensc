#ifndef __JB_FSMTRANSITION_H_
#define __JB_FSMTRANSITION_H_
#include "stdinc.h"
#include "util/array.h"

namespace Base{

//---------------------------------------------------------------------------------
class FsmCondition;
class FsmAction;
class FsmContext;
class FsmEvent;

//---------------------------------------------------------------------------------
class FsmTransition{
public:
    /// constructor
    FsmTransition(int frm);
    /// destructor
    virtual ~FsmTransition();

    /// transition : from (state) ---(conditions) ----> to (state)
    int From() const;

    /// set transition : to (state)
    void SetTo(int to);
    /// get transition : to (state)
    int To() const;

    /// append action to actionlist, that will called when transition happened.
    void AddAction(FsmAction* action);
    /// append condition to conditionlist
    void AddCondition(FsmCondition* condition);

    /// if the condition is checked and returned true, will call apply actions
    bool ApplyAction(FsmContext* ct, FsmEvent* evt) const;

    /// when the transition is trigered, shall checking the conditions before do real actions
    bool CheckCondition(FsmContext* ct, FsmEvent* evt) const;
    
protected:
    /// transtion will change state from FromState to ToState
    int fromState;
    /// the next state
    int toState;
    /// all actions
    Util::Array<FsmAction*> actions;
    /// all conditions
    Util::Array<FsmCondition*> conditions;
};// end of FsmTransition
}// end of Base
#endif
