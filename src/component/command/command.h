#ifndef __JB_COMMAND_H_
#define __JB_COMMAND_H_
#include "base/event/event.h"

namespace Component{

class Command : Base::Event{
public:
	/// default constructor
	Command();
	/// default destructor
	virtual ~Command();
};// end of Command

}// end of Component
#endif
