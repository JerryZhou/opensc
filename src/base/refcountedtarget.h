#ifndef __JB_REFCOUNTEDTARGET_H_
#define __JB_REFCOUNTEDTARGET_H_
#include "base/event/eventtarget.h"

namespace Base{
class RefcountedTarget : public EventTarget{
private:
	/// disable copy and assign constructor
	RefcountedTarget(const RefcountedTarget& other);
	RefcountedTarget& operator= (const RefcountedTarget& other);

public:
	/// default constructor
	RefcountedTarget();
	/// default destructor
	virtual ~RefcountedTarget();

	/// reference counting, increment
    void release(void);
    /// reference counting, decrement
    void retain(void);

    /// current reference count
    int retainCount(void);

protected:
	volatile int m_refcounted;
};
}
#endif
