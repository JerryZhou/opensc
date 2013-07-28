#ifndef __JB_MANAGER_D_H_
#define __JB_MANAGER_D_H_
#include "stdinc.h"
#include "base/event/eventtarget.h"

namespace Base{
class Manager : public Base::EventTarget{
    __DeclareClass(Manager);
public:
    /// constructor
    Manager();
    /// destructor
    virtual ~Manager();
    
    /// do the init work in this
    virtual bool Open();
    /// do the uninit work in this
    virtual void Close();
    
    /// called every frame
    virtual void OnBeginFrame();
    /// called every frame
    virtual void OnFrame();
    /// called every frame
    virtual void OnEndFrame();
    
protected:
    /// state
    bool opend;
    /// state
    int flags;
};// end of manager
} // end of namespace
#endif