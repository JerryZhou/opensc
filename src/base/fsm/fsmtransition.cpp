#include "fsmtransition.h"
#include "fsmaction.h"
#include "fsmcondition.h"

namespace Base {
/// constructor
FsmTransition::FsmTransition(int frm){
    this->fromState = frm;
    this->toState = -1;
}

/// destructor
FsmTransition::~FsmTransition(){
        
}

/// transition : from (state) ---(conditions) ----> to (state)
int FsmTransition::from() const{
    return this->fromState;
}

/// set transition : to (state)
void FsmTransition::setTo(int to){
    this->toState = to;
}

/// get transition : to (state)
int FsmTransition::to() const{
    return this->toState;
}

/// append action to actionlist, that will called when transition happened.
void FsmTransition::addAction(FsmAction* action){
    this->actions.Append(action);
}

/// append condition to conditionlist
void FsmTransition::addCondition(FsmCondition* condition){
    this->conditions.Append(condition);
}

/// if the condition is checked and returned true, will call apply actions
bool FsmTransition::applyAction(FsmContext* ct, FsmEvent* evt) const{
    bool apply = true;
    for (IndexT idx=0; idx < this->actions.Size() && apply; ++idx) {
        const FsmAction *action = this->actions[idx];
        apply &= action->apply(ct, evt);
    }
    return apply;
}

/// when the transition is trigered, shall checking the conditions before do real actions
bool FsmTransition::checkCondition(FsmContext* ct, FsmEvent* evt) const{
    bool check = true;
    for (IndexT idx=0; idx<this->conditions.Size() && check; ++idx) {
        const FsmCondition *condition = this->conditions[idx];
        check &= condition->check(ct, evt);
    }
    return check;
}
}