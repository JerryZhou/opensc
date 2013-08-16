#ifndef __JB_FSEVENT_H_
#define __JB_FSEVENT_H_
#include "stdinc.h"

namespace Base{
class FsmEvent{
public:
    /// default constructor
    FsmEvent();
    /// construct from e and p
    FsmEvent(int e, void* p);
    /// default destructor
    virtual ~FsmEvent();

    /// event idx
    int evt;
    /// event param
    void *param;
};// end of FsmEvent
}// end of Base
#endif
