#ifndef __JB_TEMPLATEMANAGER_H_
#define __JB_TEMPLATEMANAGER_H_
#include "base/manager.h"
#include "core/singleton.h"
#include "component/template/templatecontainer.h"

namespace Component{
class TemplateManager : public Base::Manager{
    __DeclareClass(TemplateManager);
    __DeclareSingleton(TemplateManager);
public:
    /// constructor
    TemplateManager();
    /// destructor
    virtual ~TemplateManager();
    
    /// do the init work in this
    virtual bool Open();
    /// do the uninit work in this
    virtual void Close();
    
    /// called every frame
    virtual void OnBeginFrame();
    /// called every frame
    virtual void OnFrame();
    /// called every frame
    virtual void OnEndFrame();
    
    /// find the record
    template<typename TYPE>
    const TYPE* FindRecord(const Util::StringAtom& name) const{
        const Record::TemplateRecord * record = this->container.FindRecord(name, TYPE::RECORDTYPE);
        if (record) {
            return (const TYPE*)(record);
        }
        return NULL;
    }
    
protected:
    /// container
    TemplateContainer container;
};
}
#endif