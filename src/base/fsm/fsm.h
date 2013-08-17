#ifndef __JB_FSM_H_
#define __JB_FSM_H_
#include "stdinc.h"
#include "util/array.h"
#include "util/dictionary.h"

namespace Base{

// class delcares
//---------------------------------------------------------------------------------
class FsmContext;
class FsmEvent;
class FsmAction;
class FsmCondition;
class FsmTransition;

// details : see http://en.wikipedia.org/wiki/Finite-state_machine 
// @author jerryzhou@outlook.com
// @CurState-(Event)---: Transtion :---@NextState
// Event -- GetTranstion With-CurState,With-Event 
//		-- Transtion ApplyConditions-Context
//		    -- if false break
//		-- Transtion DoActions
//		-- Transtion Change To NextState
//		    -- Leave CurState -- Enter NextState
//---------------------------------------------------------------------------------
class Fsm{
public:
    /// default constructor
    Fsm();
    /// default destructor
    virtual ~Fsm();

    /// init the fsmContext
    bool SetupContext(FsmContext* ct);

    /// add a transition to fsm
    void AddTransition(int evt, FsmTransition* transition);

    /// drive the fsm to the next state
    void Update(FsmContext* ct, int evt, void *evtParam);

protected:
    /// get current transitions
    const Util::Array<FsmTransition*>& TransitionsWhen(int state, int evt) const;

    /// type nonations
    typedef int State;
    typedef int Event;
    typedef Util::Array<FsmTransition*> FsmTransitionArray;
    typedef Util::Dictionary<Event, FsmTransitionArray > EventTransMap;
    typedef Util::Dictionary<State, EventTransMap > StateTransMap;

    /// first State
    State firstState;
    /// fsm map
    StateTransMap fsmMachine; 
    FsmTransitionArray fsmInvalidTransitions;
};// end of Fsm

}// end of namespace Base
#endif
