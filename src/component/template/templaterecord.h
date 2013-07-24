#ifndef __JB_TEMPLATERECORD_H_
#define __JB_TEMPLATERECORD_H_

#include "stdinc.h"
#include "util/stringatom.h"
#include "util/array.h"
#include "util/dictionary.h"
#include "base/log.h"

//------------------------------------------------------------------------------
namespace Record{
/// const numbers
static const SizeT UNKNOWN_SIZE = -1;
    
/// basic types used in record namespace
typedef Util::StringAtom NAME;
typedef Util::StringAtom TID;
typedef Util::StringAtom SError;
typedef Util::StringAtom LINK;
typedef int32_t INT32;
typedef int UNKNOWN_TYPE;
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
    float x;
    float y;
    float z;
    float angle;
};
/// error
struct EError{

};
/// target filters
struct STargetFilters{
    
};
/// actor key
struct SActorKey{
    
};
/// time of day
struct STimeOfDay{
    
};
/// base range
struct SBaseRange{
    
};
/// blend stop
struct SBlendStop{
    
};
/// float range in mirror
struct SFloatRangeMirror{
    
};
/// actor term
struct SActorTerm{
    
};
    
/// template record, used to config
/// data-driven framework
struct TemplateRecord{
    int RecordType;
    TemplateRecord()
    : RecordType(0){
    }
};

}
#endif
