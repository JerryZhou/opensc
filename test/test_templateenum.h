#include "component/template/templateenum.h"

using namespace Component;
using namespace Record;
using namespace Util;

TEST(TemplateEnum, Name){
    StringAtom atom = EEAbilAlignment::Name(Record::EAbilAlignment_Negative);
    EXPECT_EQ(atom, StringAtom("Negative"));
    
    const char* expectName = _EAbilAlignment[EAbilAlignment_Negative];
    
    EXPECT_EQ(atom, StringAtom(expectName));
    
    StringAtom name = EEAbilAlignment::Name();
    EXPECT_EQ(StringAtom("EAbilAlignment"), name);
}

TEST(TemplateEnum, NameAt){
    StringAtom atom = EEAbilAlignment::NameAt(0);
    EXPECT_EQ(atom, StringAtom("Negative"));
}

TEST(TemplateEnum, IndexOf){
    IndexT idx = EEAbilAlignment::IndexOf(Record::EAbilAlignment_Negative);
    EXPECT_EQ(0, idx);
    
    IndexT idxName = EEAbilAlignment::IndexOf(StringAtom("Negative"));
    EXPECT_EQ(0, idxName);
}

TEST(TemplateEnum, Value){
    EAbilAlignment v = EEAbilAlignment::Value(StringAtom("Negative"));
    EXPECT_EQ(Record::EAbilAlignment_Negative, v);
}

TEST(TemplateEnum, Size){
    SizeT size = EEAbilAlignment::Size();
    EXPECT_EQ(_EAbilAlignment_Size, size);
}