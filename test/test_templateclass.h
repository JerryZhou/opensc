#include "component/template/templateclass.h"

using namespace Record;
using namespace Util;

TEST(TemplateClass, RecordType){
    Abil abil;
    EXPECT_EQ(abil.RecordType, (int)(ERecordType_Abil));
}

TEST(TemplateClass, Init_basic_type){
    Abil abil;
    EXPECT_EQ(0, abil.InfoTooltipPriority);
    EXPECT_EQ(EAbilAlignment_Negative, abil.Alignment);
    EXPECT_EQ(StringAtom(), abil.AbilSetId);
}

TEST(TemplateClass, Init_array_type){
    AbilQueue abilQueue;
    EXPECT_EQ(0, (int)(abilQueue.Flags));
    EXPECT_EQ(_EAbilQueueCmd_Size, abilQueue.CmdButtonArray.Size());
    
    AbilArmMagazine abilArmMagazine;
    EXPECT_EQ(0, abilArmMagazine.ExternalAngle.Size());
}

TEST(TemplateClass, Init_Struct){
    AbilQueue abilQueue;
    SAbilCmdButton initButton;
    TemplateInit::Init<SAbilCmdButton>(initButton);
    EXPECT_EQ(initButton.DefaultButtonFace, abilQueue.CmdButtonArray[0].DefaultButtonFace);
    EXPECT_EQ(initButton.Flags, abilQueue.CmdButtonArray[0].Flags);
    EXPECT_EQ(initButton.Requirements, abilQueue.CmdButtonArray[0].Requirements);
    EXPECT_EQ(initButton.State, abilQueue.CmdButtonArray[0].State);
}
