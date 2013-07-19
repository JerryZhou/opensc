#ifndef __JB_EFFECT_H_
#define __JB_EFFECT_H_
#include "stdinc.h"

namespace Component{
class Effect{
public:
	// effect states
	enum EffectState{
		Eff_Start,
		Eff_Stop,
		Eff_Finish,
		Eff_Error,
	};

	/// default constructor
	Effect();
	/// default destructor
	virtual ~Effect();

	/// start effect
	virtual bool start();
	/// stop effect
	virtual bool stop();

	/// when start
	virtual bool onStart();
	/// when get the execute chanece
	virtual bool onExecute(float ts);
	/// when stop
	virtual bool onStop();

	/// current effect state
	EffectState state() const;

protected:
	/// effect state is tag to control effect
	EffectState m_state;

};
}
#endif
