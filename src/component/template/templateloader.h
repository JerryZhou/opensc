#ifndef __JB_TEMPLATELOADER_H_
#define __JB_TEMPLATELOADER_H_
#include "component/template/templaterecord.h"

namespace Component{
/// record loader
class TemplateLoader{
public:
    template<typename TYPE>
    static void loadType(TYPE &ref);

    int mArg;
    template<typename CLASS>
    static void loadClass(CLASS &ref);
    
    static void load(TemplateRecord* &ref)
private:
    
};
}
#endif
