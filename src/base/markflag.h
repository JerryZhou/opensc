#ifndef __JB_MARKFLAG_H_
#define __JB_MARKFLAG_H
namespace Base{
/// mark flag for most behavior
enum Flags{
    InCreate = 0x000001,
    InDestroy = 0x000002,
    InDestroyLater = 0x000004,
    InBeginFrame = 0x000008,
    InFrame = 0x000010,
    InEndFrame = 0x000020,
    InFind = 0x000040,
    InDestructor = 0x000080,
    InConstructor = 0x0000100,
    
    InDelay = 0x000200,
};

#define J_Mark(flags, mark) ( (flags) |= (mark) )
#define J_UnMark(flags, mark) ( flags) &= (~(mark))
#define J_IsMark(flags, mark) (((flags) & (mark)) == (mark))

/// flag mark helper
class AutoMarkFlag{
public:
    AutoMarkFlag(int &_flag, int _mark)
    : flags(_flag)
    , mark(_mark){
        J_Mark(this->flags, this->mark);
    }
    ~AutoMarkFlag(){
        J_UnMark(this->flags, this->mark);
    }
protected:
    int &flags;
    int mark;
};
}
#endif