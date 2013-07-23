#ifndef __JB_TEMPLATECLASS_H_
#define __JB_TEMPLATECLASS_H_
#include "stdinc.h"
#include "util/stringatom.h"
#include "component/template/templaterecord.h"
#include "component/template/templateenum.h"

namespace Component {
template<typename CLASS>
class TemplateClass{
public:
private:
};// end of TemplateClass
}// end of Component

/// extend record type
namespace Record {
typedef Util::Dictionary<ETargetFilter, ETargetFilterState> TARGETFILTERDICTIONARY;
}

/// include in record base
#define JTemplateClass(DERIVED, BASE, KIND) namespace Record { struct DERIVED : public BASE { DERIVED();
#define JTemplateStruct(DERIVED) namespace Record { struct DERIVED {  DERIVED();
#define JTemplateValue(TYPE, NAME) TYPE NAME;
#define JTemplateArray(TYPE, NAME, SIZE) Util::Array< TYPE > NAME;
#define JTemplateEnumA(TYPE, NAME, ENUM) Util::Array< TYPE > NAME;
#define JTemplateEnd() }; }
#include "component/template/record/recordstruct.h"
#include "component/template/record/recordclass.h"

#undef JTemplateClass
#undef JTemplateStruct
#undef JTemplateValue
#undef JTemplateArray
#undef JTemplateEnumA
#undef JTemplateEnd
#define JTemplateClass(DERIVED, BASE, KIND) namespace Record { inline DERIVED::DERIVED(){ \
    RecordType = ERecordType_##KIND;
#define JTemplateStruct(DERIVED) namespace Record { inline DERIVED::DERIVED(){
#define JTemplateValue(TYPE, NAME)  Record::TemplateInit::Init(NAME);
#define JTemplateArray(TYPE, NAME, SIZE) NAME = Util::Array< TYPE >(SIZE != Record::UNKNOWN_SIZE ? SIZE : 0, 0);
#define JTemplateEnumA(TYPE, NAME, ENUM) NAME = Util::Array< TYPE >(Record::_##ENUM##_Size, 0);
#define JTemplateEnd() }; }
#include "component/template/record/recordstruct.h"
#include "component/template/record/recordclass.h"

#endif
