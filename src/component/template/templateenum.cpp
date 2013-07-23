#include "templateenum.h"


/// define const datas about nums
#undef JEnumBegin
#undef JEnumBeginWith
#undef JEnumValueWith
#undef JEnumValue
#undef JEnumEnd
#define JEnumBegin(NS, Enum) namespace NS { const char* _##Enum [] = {
#define JEnumBeginWith(NS, Enum, TYPE) namespace NS { const char* _##Enum [] = {
#define JEnumValueWith(Enum, n, i) #n ,
#define JEnumValue(Enum, n) #n ,
#define JEnumEnd(NS, Enum) }; \
const SizeT _##Enum##_Size = __countof(_##Enum); }
#include "component/template/record/recordenum.h"
#include "component/template/record/recordflag.h"

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
    name = #Enum;\
    BeginAdd();
    
#define JEnumBeginWith(NameSpace, Enum, TYPE) JEnumBegin(NameSpace, Enum)
#define JEnumValueWith(Enum, n, i) Add(#n, Enum##_##n, false);
#define JEnumValue(Enum, n) Add(#n, Enum##_##n, false);
#define JEnumEnd(NameSpace, Enum) EndAdd(); }
#include "component/template/record/recordenum.h"
    
/// define the flag setup
#undef JEnumValueWith
#undef JEnumValue
#define JEnumValueWith(Enum, n, i) Add(#n, Enum##_##n, true);
#define JEnumValue(Enum, n) Add(#n, Enum##_##n, true);
#include "component/template/record/recordflag.h"
    
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
#include "component/template/record/recordflag.h"
}
}
