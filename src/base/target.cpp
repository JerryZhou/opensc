#include "target.h"

namespace Base{
/// default constructor
Target::Target(){
}

/// default destructor
Target::~Target(){
    THolderCenter<Target>::Instance()->destroyHolder(this);
}

}// end of Base
