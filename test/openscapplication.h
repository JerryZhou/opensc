#ifndef __JB_OPENSCAPPLICATION_H_
#define __JB_OPENSCAPPLICATION_H_

#include "io/iointerface.h"
#include "app/consoleapplication.h"

namespace App{
class OpenSCApplication : public ConsoleApplication{
public:
   /// open the application
    virtual bool Open();
    /// run the application
    virtual void Run();
    /// close the application
    virtual void Close();

    /// check if quit was requested
    bool IsQuitRequested() const;
    /// request quit
    void SetQuitRequested();

protected:
    Ptr<IO::IoInterface> ioInterface;
    bool quitRequested;
};

//------------------------------------------------------------------------------
/**
 */
inline bool
OpenSCApplication::IsQuitRequested() const {
    return this->quitRequested;
}

//------------------------------------------------------------------------------
/**
 */
inline void
OpenSCApplication::SetQuitRequested() {
    this->quitRequested = true;
}
} // namespace App
//------------------------------------------------------------------------------
#endif
