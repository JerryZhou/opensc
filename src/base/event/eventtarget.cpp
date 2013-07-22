#include "eventtarget.h"
#include "event.h"

using namespace Core;

namespace Base{

__ImplementClass(Base::EventTarget, 'etet', Base::Target);

//------------------------------------------------------------------------------
/**
*/
EventTarget::EventTarget(){

}

//------------------------------------------------------------------------------
/**
*/
EventTarget::~EventTarget(){

}

//------------------------------------------------------------------------------
/**
*/
void 
EventTarget::OnEvent(Ptr<Event> &evt){

}

}// end of Base
