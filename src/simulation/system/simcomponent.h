#ifndef __JB_SIMCOMPONENT_H_
#define __JB_SIMCOMPONENT_H_
#include "stdinc.h"
#include "simulation/sim.h"

namespace Simulation{
//@author jerryzhou@outlook.com
//@description simulation is running across network, frame-setup-async system is build
//  in the whole system. all the componnet communicating by simeent, and we support the
//  serialize and deserialize the component to network
//----------------------------------------------------------------------------------
class SimContext;
class SimEvent;
class SimParamNode;
class SimSituation;
class SimSerialize;
class SimDeserialize;

//----------------------------------------------------------------------------------
class SimComponent{
public:
    /// constructor
    SimComponent();
    /// destructor
    virtual ~SimComponent();

    /// get simulation context
    SimContext* GetSimContext() const;
    /// set simulation context
    void SetSimContext(const SimContext* ct);

    /// get the target entity id
    const SimEntityId& GetEntityId() const; 
    /// set the target entity id
    void SetEntityId(const SimEntityId& id);

    /// handle the simulation event
    virtual void HandleEvent(const SimEvent* evt, const SimSituation* situation);
    /// serialize the component out
    virtual void Serialize(SimSerialize& serialize);
    /// deserialize information from out
    virtual void Deserialize(const SimParamNode& node, SimDeserialize& deserialize);

protected:
    /// context
    SimContext* context;
    /// target entity id
    SimEntityId entity;
};
}
#endif
