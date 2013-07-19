#ifndef __EVENTTARGET_H_
#define __EVENTTARGET_H_
#include "target.h"


namespace Base{
//---------------------------------------------------------------------------------
class Event;

/// class EventTarget
class EventTarget : public Base::Target{
public:
	EventTarget();
	virtual ~EventTarget();

	virtual void onEvent(Base::Event* evt);
};
}// end of Base

#endif
