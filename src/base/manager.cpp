#include "manager.h"

namespace Base {
__ImplementClass(Base::Manager, 'mger', Base::EventTarget);
/// constructor
Manager::Manager()
: opend(false)
, flags(0){
    
}

/// destructor
Manager::~Manager(){
    n_assert(this->opend == false);
}

/// do the init work in this
bool Manager::Open(){
    n_assert(this->opend == false);
    this->opend = true;
    return true;
}
/// do the uninit work in this
void Manager::Close(){
    n_assert(this->opend);
    this->opend = false;
}

/// called every frame
void Manager::OnBeginFrame(){
    
}

/// called every frame
void Manager::OnFrame(){
    
}

/// called every frame
void Manager::OnEndFrame(){
    
}
}