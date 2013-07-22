#include "effect.h"

namespace Component{

/// default constructor
Effect::Effect()
: m_state(Eff_Stop){

}

/// default destructor
Effect::~Effect(){

}

/// start
 bool Effect::start(){
	 J_ASSERT(m_state == Eff_Stop);
	 if(!onStart()){
		 return false;
	 }

	 m_state = Eff_Start;
	 return true;
 }

 /// stop
 bool Effect::stop(){
	 J_ASSERT(m_state != Eff_Stop);

	 if(!onStop()){
		 return false;
	 }

	 m_state = Eff_Stop;
	 return true;
 }

/// when start
bool Effect::onStart(){
	return true;
}

/// when get the execute chanece
bool Effect::onExecute(float ts){
	return true;
}

/// when stop
bool Effect::onStop(){
	return true;
}

/// current effect state
Effect::EffectState Effect::state() const{
	return m_state;
}

}// end of Component

