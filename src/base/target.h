#ifndef __TARGET_H_
#define __TARGET_H_
#include "core/refcounted.h"
#include "core/ptr.h"

namespace Base{
class Target : public Core::RefCounted{
    __DeclareClass(Target);
public:
    /// default constructor
    Target();
    /// default destructor
    virtual ~Target();

};// end of Target
typedef int UnitId;
}// end of Base
#endif
