#ifndef __JB_UNITMANAGER_H_
#define __JB_UNITMANAGER_H_
#include "base/markflag.h"
#include "component/template/templateclass.h"
#include "component/template/templatecontainer.h"
#include "base/manager.h"

namespace Component {
/// declare class
class Unit;
/// unit manager
class UnitManager : public Base::Manager{
    __DeclareClass(UnitManager);
public:
    /// constructor
    UnitManager();
    /// destructor
    virtual ~UnitManager();
    
    /// create unit
    Ptr<Unit>& CreateUnit( Record::TID tid);
    /// destroy right now
    void DestroyUnit( const Ptr<Unit> &unit);
    /// destroy unit next frame begin
    void DestroyUnitLater( const Ptr<Unit> &unit);
    
    /// manager behavior
    const Ptr<Unit>& Find( int uid) const;
    
protected:
    /// frame behavior
    void OnBeginFrame();
    /// frame
    void OnFrame();
    /// after frame
    void OnEndFrame();
    
private:
    /// delay removed units
    Util::Array<Ptr<Unit> > delayDestroyUnits;
    /// delay added units
    Util::Array<Ptr<Unit> > delayAddUnits;
    /// unit continaer
    Util::Dictionary<int, Ptr<Unit> > units;
    /// null unit
    Ptr<Unit> nullPtr;
};
}
#endif