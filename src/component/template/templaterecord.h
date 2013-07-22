#ifndef __JB_TEMPLATERECORD_H_
#define __JB_TEMPLATERECORD_H_

#include "stdinc.h"
#include "util/stringatom.h"

//------------------------------------------------------------------------------
namespace Record{
/// const numbers
static const SizeT UNKNOWN_SIZE = 4;
    
/// basic types used in record namespace
typedef Util::StringAtom NAME;
typedef Util::StringAtom TID;
typedef int32_t INT32;
typedef float FIXF32;

/// template record, used to config
/// data-driven framework
typedef struct _TemplateRecord{
}TemplateRecord;

struct AbilEx : public TemplateRecord{
    
};
    
    enum EnEx : long long {
        
    };
}
#endif
