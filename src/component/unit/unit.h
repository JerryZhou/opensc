#ifndef __JB_UNIT_H_
#define __JB_UNIT_H_

#include "stdinc.h"
#include "base/event/eventtarget.h"
#include "component/template/templateclass.h"

namespace Component{
class UnitManager;
class Unit : public Base::EventTarget{
    __DeclareClass(Unit);
public:
    /// default constructor
    Unit();
    /// default destructor
    virtual ~Unit();

    /// unique id
    int uid() const;
    /// return the tid of unit
    const Record::TID& tid() const;
    /// return the record about the unit
    const Record::Unit* record() const;

protected:
    friend class Component::UnitManager;
    
    /// set the record*
    void SetRecord(const Record::Unit* record);
    
    /// data members
    int uuid;
    const Record::Unit *unitRecord;
};// end of Unit

}// end of Unit
#endif
