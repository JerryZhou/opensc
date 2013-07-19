
#include "stdinc.h"
#include "base/event/event.h"

namespace Base{

///---------------------------------------------------------------------------------
/// declares
class EventTarget;

///---------------------------------------------------------------------------------
/// event delegate: strong reference
/// NB! STRONG REFERENCE
/// TODO: use weakference
class EventDelegate{
public:
	/// default constructor
	EventDelegate();
	/// construtor from target and handle
	EventDelegate(Base::EventTarget* target, JSEL_EventHandler handle);

	/// copy constructor
	EventDelegate(const EventDelegate& other);
	/// assignment constructor
	EventDelegate& operator = (const EventDelegate& other);
	/// override operator ==
	bool operator == (const EventDelegate& other);

	/// default destructor
	virtual ~EventDelegate();

	/// invoke the target event handle
	/// @param return true when the delegate is valid
	/// @param return false when the delegate is invalid
	bool invoke(Event* evt);

protected:
	/// data members
	Base::TargetPtr<Base::EventTarget> m_target;
	JSEL_EventHandler m_handle;
};// end of EventDelegate

}// end of Base
