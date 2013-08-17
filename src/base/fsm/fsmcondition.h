#ifndef __JB_FSMCONDITION_H_
#define __JB_FSMCONDITION_H_
namespace Base{
//--------------------------------------------------------------------------------------------
class FsmContext;
class FsmEvent;

//--------------------------------------------------------------------------------------------
class FsmCondition{
public:
    /// constructor
    FsmCondition();
    /// destructor
    virtual ~FsmCondition();

    /// check if the context is statify the condition
    bool Check(FsmContext* ct, FsmEvent* et) const;

protected:
    /// data members
    int id;
};// end of FsmCondition
}// end of Base
#endif
