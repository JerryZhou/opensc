#include "templatemanager.h"
#include "templateloader.h"

namespace Component {
__ImplementClass(Component::TemplateManager, 'tmer', Base::Manager);
__ImplementSingleton(Component::TemplateManager);
    
/// constructor
TemplateManager::TemplateManager(){
    __ConstructSingleton;
}

/// destructor
TemplateManager::~TemplateManager(){
    __DestructSingleton;
}

/// do the init work in this
bool TemplateManager::Open(){
    Base::Manager::Open();
    TemplateLoader::LoadRecord("home/data/Abil.xml", this->container);
    return true;
}
    
/// do the uninit work in this
void TemplateManager::Close(){
    Base::Manager::Close();
}

/// called every frame
void TemplateManager::OnBeginFrame(){
    
}
/// called every frame
void TemplateManager::OnFrame(){
    
}
/// called every frame
void TemplateManager::OnEndFrame(){
    
}
}