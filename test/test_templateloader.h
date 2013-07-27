#include "component/template/templateloader.h"

TEST(TemplateLoader, setup){
}

TEST(TemplateLoader, LoadRecord){
    Ptr<TemplateContainer> container = TemplateContainer::Create();
    TemplateLoader::LoadRecord("home:data/AbilData.xml", *container);
    
    Record::AbilBuild* abilBuild = (Record::AbilBuild*) container->FindRecord(Util::StringAtom("TerranAddOns"), ERecordType_Abil);
    // load NAME TID ...
    EXPECT_EQ( abilBuild->Alert , Util::StringAtom("AddOnComplete"));
    
    // load enum
    EXPECT_EQ( EAbilBuildType_AddOn, abilBuild->Type);
   
    // load flag
    EXPECT_TRUE( abilBuild->FlagArray & EAbilBuildFlag_InstantPlacement);
    EXPECT_TRUE( abilBuild->FlagArray & EAbilBuildFlag_PeonDisableAbils);
    EXPECT_TRUE( abilBuild->FlagArray & EAbilBuildFlag_ShowProgress);
    
    // load enum array and struct
    SAbilBuildInfo& abilInfo_build1 = abilBuild->InfoArray[EAbilBuildCmd_Build1];
    EXPECT_EQ( Util::StringAtom("TechLab"), abilInfo_build1.Unit);
    EXPECT_EQ( 30, abilInfo_build1.Time);
    EXPECT_EQ( -1, abilInfo_build1.AddOnParentCmdPriority);
    EXPECT_EQ( Util::StringAtom("TechLabBarracks"), abilInfo_build1.Button.DefaultButtonFace);
    EXPECT_EQ( EAbilCmdState_Suppressed, abilInfo_build1.Button.State);
    
    SAbilBuildInfo& abilInfo_build2 = abilBuild->InfoArray[EAbilBuildCmd_Build2];
    EXPECT_EQ( Util::StringAtom("Reactor"), abilInfo_build2.Unit);
    EXPECT_EQ( 40, abilInfo_build2.Time);
    EXPECT_EQ( 1, abilInfo_build2.AddOnParentCmdPriority);
    EXPECT_EQ( Util::StringAtom("Reactor"), abilInfo_build2.Button.DefaultButtonFace);
    EXPECT_EQ( EAbilCmdState_Restricted, abilInfo_build2.Button.State);
    
}
