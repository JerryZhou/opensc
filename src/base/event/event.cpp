#include "event.h"

namespace Base{
__ImplementClass(Base::Event, 'bevt', Messaging::Message);
__ImplementMsgId(Base::Event);

//------------------------------------------------------------------------------
/*
 * */
Event::Event(){
    // empty
}

//------------------------------------------------------------------------------
/*
 * */
Event::~Event(){
}

}// end of Base

