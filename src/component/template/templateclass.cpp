#include "templateclass.h"

namespace Component {
}

#undef JTemplateClass
#undef JTemplateStruct
#undef JTemplateValue
#undef JTemplateArray
#undef JTemplateEnumA
#undef JTemplateEnd
#define JTemplateClass(DERIVED, BASE, KIND) namespace Record { \
    __ImplementRecordClassId( DERIVED );\
    DERIVED::DERIVED(){ \
    RecordType = ERecordType_##KIND;
#define JTemplateStruct(DERIVED) namespace Record { DERIVED::DERIVED(){
#define JTemplateValue(TYPE, NAME)  Record::TemplateInit::Init(NAME);
#define JTemplateArray(TYPE, NAME, SIZE) if(SIZE != Record::UNKNOWN_SIZE ) \
    { TYPE initValue; Record::TemplateInit::Init(initValue); NAME = Util::Array< TYPE >(SIZE != Record::UNKNOWN_SIZE ? SIZE : 0, 0, initValue); }
#define JTemplateEnumA(TYPE, NAME, ENUM) {TYPE initValue; Record::TemplateInit::Init(initValue);  \
    NAME = Util::Array< TYPE >(Record::_##ENUM##_Size, 0, initValue); }
#define JTemplateEnd() }; }
#include "component/template/record/recordstruct.h"
#include "component/template/record/recordclass.h"

