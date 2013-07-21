#ifndef __EVENTTARGET_H_
#define __EVENTTARGET_H_
#include "base/target.h"


namespace Base{
//---------------------------------------------------------------------------------
class Event;

/// class EventTarget
class EventTarget : public Base::Target{
public:
	EventTarget();
	virtual ~EventTarget();

	virtual void OnEvent(Base::Event* evt);
};
}// end of Base

#endif
