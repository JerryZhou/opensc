#ifndef __JB_SIM_H_
#include "stdinc.h"

namespace Simulation{
/// simulation entity id
typedef uint32_t SimEntityId;
    
/// invalid simulation entity id
const SimEntityId InvalidEntityId = 0;
    
/**
 * Entity ID for singleton 'system' components.
 * Use with QueryInterface to get the component instance.
 * (This allows those systems to make convenient use of the common infrastructure
 * for message-passing, scripting, serialisation, etc.)
 */
const SimEntityId SystemEntityId = 1;
    
/// entity is normal
// Entities are split into two kinds:
// "Normal" (for most entities)
// "Local" (for entities that only exist on the local machine, aren't synchronised across the network,
// aren't retained in saved games, etc)
// The distinction is encoded in the entity ID, so that they're easily distinguished.
//
// We want all entity_id_ts to fit in ints, i.e. 1-2^30 .. 2^30-1 (inclusive)
// We want them to be unsigned ints (actually it shouldn't matter but unsigned seems simpler)
// We want 1 tag bit
// So we have 1 Script-reserved bit, 1 unused sign bit, 1 local tag bit, 29 counter bits
// (0.5B entities should be plenty)

#define ENTITY_TAGMASK (1 << 29)
#define ENTITY_IS_NORMAL(id) (((id) & ENTITY_TAGMASK) == 0)
#define ENTITY_IS_LOCAL(id) (((id) & ENTITY_TAGMASK) == ENTITY_TAGMASK)
const SimEntityId FIRST_LOCAL_ENTITY = ENTITY_TAGMASK;
    
#define SIM_INTERFACE(name)
#define SIM_EVENT(name)
#define SIM_COMPONENT(name)

#undef SIM_INTERFACE
#define SIM_INTERFACE(name) iid_##name,
enum InterfaceId{
    iid_Invalid,
#include "simulation/sim.inl"
    iid_Count,
};
#undef SIM_INTERFACE
#define SIM_INTERFACE(name)
    
#undef SIM_EVENT
#define SIM_EVENT(name) eid_##name,
enum EventId{
    eid_Invalid,
#include "simulation/sim.inl"
    eid_Count,
};
#undef SIM_EVENT
#define SIM_EVENT(name)
    
#undef SIM_COMPONENT
#define SIM_COMPONENT(name) cid_##name,
enum ComponentId{
cid_Invalid,
#include "simulation/sim.inl"
cid_Count,
};
#undef SIM_COMPONENT
#define SIM_COMPONENT(name)
    
}// end of Simulation
