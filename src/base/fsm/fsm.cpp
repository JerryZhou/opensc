#include "fsm.h"
#include "fsmtransition.h"
#include "fsmcontext.h"
#include "fsmevent.h"

namespace Base{
/// invalid state
static int InvalidState = -1;
    
/// constructor
Fsm::Fsm(){
}

/// destructor
Fsm::~Fsm(){
}

/// init the fsmContext
bool Fsm::setupContext(FsmContext* ct){
    ct->setCurState(this->firstState);
    ct->setNextState(InvalidState);
    return true;
}

/// add transition to fsm
void Fsm::addTransition(int evt, FsmTransition* tn){

    State from = tn->from();

    IndexT idx = this->fsmMachine.FindIndex(from);
    if(idx != InvalidIndex){
	EventTransMap& evtTransMap = this->fsmMachine.ValueAtIndex(idx);
	IndexT transIdx = evtTransMap.FindIndex(evt);
	if(transIdx != InvalidIndex){
	    // add transitions
	    FsmTransitionArray& transitions = evtTransMap.ValueAtIndex(transIdx);
	    transitions.Append(tn);
	}else{
	    // add event map and transitions
	    FsmTransitionArray transitions;
	    transitions.Append(tn);
	    evtTransMap.Add(evt, transitions); 
	}
    }else{
	// add state map and event map and transtions
	EventTransMap evtTransMap;
	FsmTransitionArray transitions;
	transitions.Append(tn);
	evtTransMap.Add(evt, transitions);
	this->fsmMachine.Add(evt, evtTransMap); 
    }
}

/// drived the fsmContext to next state
void Fsm::update(FsmContext* ct, int evt, void *evtParam){
    // get current transitions
    const FsmTransitionArray& transitions = transitionsWhen(ct->curState(), evt);
    IF_DO(transitions.Size() == 0, return);

    // construct a fsm evt
    FsmEvent fsmEvt(evt, evtParam);

    // foreach the valid transitions
    for(IndexT idx=0; idx<transitions.Size(); ++idx){
        // get transition from idx
        FsmTransition * transition = transitions[idx];
        // check conditions
        if( transition->checkCondition(ct, &fsmEvt) ){
            // change to next state
            ct->setNextState(transition->to()); 
            // run actions
            if( transition->applyAction(ct, &fsmEvt) ){
                // change cur state to next state
                ct->setCurState(transition->to());
                // reset next state
                ct->setNextState(InvalidState);
                // break the loop
                break;
            }
        }
    }
}

/// get the transtions at currentstate(state) will change do when the event (evt) happend
const Util::Array<FsmTransition*>& Fsm::transitionsWhen(int state, int evt) const{
    // state map
    IndexT idx = this->fsmMachine.FindIndex(state);
    if(idx != InvalidIndex){
        // event map
        const EventTransMap& evtTransMap = this->fsmMachine.ValueAtIndex(idx);
        // transition map
        IndexT transIdx = evtTransMap.FindIndex(evt);
        if(transIdx != InvalidIndex){
            return evtTransMap.ValueAtIndex(transIdx);
        }
    }
    // return the invalid holder
    return this->fsmInvalidTransitions;
}

}
