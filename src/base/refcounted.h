#ifndef __JB_REFCOUNTEDTARGET_H_
#define __JB_REFCOUNTEDTARGET_H_
#include "base/event/eventtarget.h"

namespace Base{
class Refcounted : public EventTarget{
private:
    /// disable copy and assign constructor
    Refcounted(const Refcounted& other);
    Refcounted& operator= (const Refcounted& other);

public:
    /// default constructor
    Refcounted();
    /// default destructor
    virtual ~Refcounted();

    /// reference counting, increment
    void Release(void);
    /// reference counting, decrement
    void Retain(void);

    /// current reference count
    int RetainCount(void);

protected:
    volatile int refcounted;
};
}
#endif
