#ifndef __JB_TEMPLATERECORD_H_
#define __JB_TEMPLATERECORD_H_

#include "stdinc.h"
#include "util/stringatom.h"

//------------------------------------------------------------------------------
namespace Component{
/// template record, used to config
/// data-driven framework
typedef struct _TemplateRecord{
    Util::StringAtom name;
    Util::StringAtom parent;
}TemplateRecord;
}
#endif
