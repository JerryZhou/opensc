#ifndef __JB_TEMPLATECONTAINER_H_
#define __JB_TEMPLATECONTAINER_H_
#include "stdinc.h"
#include "eventtarget.h"

namespace Component{
class TemplateContainer : public Base::EventTarget{
    __DeclareClass(TemplateContainer);
public:
    /// constructor
    TemplateContainer();
    /// destructor
    virtual ~TemplateContainer();

    /// find the record
    const TemplateRecord* FindRecord(const Util::StringAtom& name) const;
    /// add record
    void AddRecord(const Util::StringAtom& n, const TemplateRecord* record);

private:
    Util::Dictionary<const Util::StringAtom, const TemplateRecord*> records;
}
#endif
