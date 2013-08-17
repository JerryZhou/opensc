#ifndef __JB_FSMACTION_H_
#define __JB_FSMACTION_H_
namespace Base{
// declares
//------------------------------------------------------------------------------
class FsmContext;
class FsmEvent;
    
//------------------------------------------------------------------------------
class FsmAction{
public:
    /// constructor
    FsmAction();
    /// destructor
    virtual ~FsmAction();

    /// apply to the context
    virtual bool Apply(FsmContext* ct, FsmEvent* et) const;
    
protected:
};// end of FsmAction
}// end of Base
#endif
