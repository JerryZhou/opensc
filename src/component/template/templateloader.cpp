#include "templateloader.h"

namespace Component {
/// declare the loadEntrys
TemplateLoader::LoadClassEntryDictionary TemplateLoader::loadEntrys;

/// load class
void TemplateLoader::Load(const Util::StringAtom& n, TemplateRecordPtr &ref){
    IndexT idx = loadEntrys.FindIndex(n);
    if (idx != InvalidIndex) {
        LoadClassEntry entry = loadEntrys.ValueAtIndex(idx);
        (*entry)(ref);
    }else{
        LOGE("wrong class name %s, we can not find load entry!", n.Value());
    }
}
}