#ifndef __JB_TEMPLATERECORD_H_
#define __JB_TEMPLATERECORD_H_

#include "stdinc.h"
#include "util/stringatom.h"
#include "util/array.h"
#include "util/dictionary.h"
#include "base/log.h"
#include "messaging/message.h"

//------------------------------------------------------------------------------
namespace Record{
/// typedef class id
typedef Messaging::Id RecordClassId;
/// const numbers
static const SizeT UNKNOWN_SIZE = InvalidIndex;
    
/// basic types used in record namespace
typedef Util::StringAtom NAME;
typedef Util::StringAtom TID;
typedef Util::StringAtom SError;
typedef Util::StringAtom LINK;
typedef int32_t INT32;
typedef Util::StringAtom UNKNOWN_TYPE;
typedef float FIXF32;
typedef Util::Dictionary<NAME,NAME> NAMEDICTIONARY;

/// colcor
struct SColor{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};
/// vector2
struct SVector2{
    FIXF32 x;
    FIXF32 y;
};
/// vector3
struct SVector3{
    FIXF32 x;
    FIXF32 y;
    FIXF32 z;
};
/// vector4
struct SVector4{
    FIXF32 x;
    FIXF32 y;
    FIXF32 z;
    FIXF32 w;
};
/// range
struct SIntRange{
    int min;
    int max;
};
/// range
struct SFloatRange{
    float min;
    float max;
};
/// rotator
struct SRotator{
    float pitch;
    float roll;
    float yaw;
};
/// actor key
struct SActorKey{
    TID actor;
    TID alias;
    TID custom;
    TID reference;
    TID system;
};
/// time of day
struct STimeOfDay{
    int hour;
    int minute;
    int second;
    STimeOfDay(){
        memset(this, 0, sizeof(STimeOfDay));
    }
};
/// base range
struct SBaseRange{
    int base;
    int range;
    SBaseRange(){
        memset(this, 0, sizeof(SBaseRange));
    }
};
/// float range in mirror
struct SFloatRangeMirror{
    float negtiveMax;
    float negtiveMin;
    float positiveMax;
    float positiveMin;
    SFloatRangeMirror(){
        memset(this, 0, sizeof(SFloatRangeMirror));
    }
};

//------------------------------------------------------------------------------
/**
 Message Id macros.
 */
#define __DeclareRecordClassId \
    static Record::RecordClassId RecordId; \
    virtual const Messaging::Id& GetRecordId() const;

#define __ImplementRecordClassId(type) \
    Record::RecordClassId type::RecordId; \
    const Record::RecordClassId& type::GetRecordId() const { return type::RecordId; }

    /// template record, used to config
/// data-driven framework
struct TemplateRecord{
    __DeclareRecordClassId;
    int RecordType;
    Util::StringAtom Id;
    TemplateRecord()
    : RecordType(0){
    }
    virtual ~TemplateRecord(){
    }
};

}
#endif
