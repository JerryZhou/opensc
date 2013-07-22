#include "templateenum.h"

namespace Component {

/// redefine the enum macros
#undef JEnumBegin
#undef JEnumBeginWith
#undef JEnumValueWith
#undef JEnumValue
#undef JEnumEnd

/// define the enum setup
#define JEnumBegin(NameSpace, Enum)  \
    template<>\
    void TemplateEnum<NameSpace::Enum>::Setup(){\
    using namespace NameSpace;\
    name = #Enum;
#define JEnumBeginWith(NameSpace, Enum, TYPE) JEnumBegin(NameSpace, Enum)
#define JEnumValueWith(Enum, n, i) Add(#n, Enum##_##n);
#define JEnumValue(Enum, n) Add(#n, Enum##_##n);
#define JEnumEnd(NameSpace, Enum) }
#include "component/template/record/recordenum.h"

/// add
#undef JEnumBegin
#undef JEnumBeginWith
#undef JEnumValueWith
#undef JEnumValue
#undef JEnumEnd
#define JEnumBegin(NameSpace, Enum) TemplateEnum< NameSpace::Enum >::Setup();
#define JEnumBeginWith(NameSpace, Enum, TYPE) JEnumBegin(NameSpace, Enum)
#define JEnumValueWith(Enum, n, i)
#define JEnumValue(Enum, n)
#define JEnumEnd(NameSpace, Enum)

void SetupEnums(){
#include "component/template/record/recordenum.h"
}
}
