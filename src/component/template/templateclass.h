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
/// dictionary
typedef Util::Dictionary<ETargetFilter, ETargetFilterState> TARGETFILTERDICTIONARY;
/// target filters
struct STargetFilters{
    TARGETFILTERDICTIONARY Filters;
};
/// actor term
struct SActorTerm{
    EActorTermType type;
    TID value;
    SActorTerm():type(EActorTermType_AbilKey){
    }
};
}

/// include in record base
#define JTemplateClass(DERIVED, BASE, KIND) namespace Record { \
    struct DERIVED : public BASE { \
    static ERecordType RECORDTYPE;\
    DERIVED(); \
    __DeclareRecordClassId; 

#define JTemplateStruct(DERIVED) namespace Record { struct DERIVED {  DERIVED();
#define JTemplateValue(TYPE, NAME) TYPE NAME;
#define JTemplateArray(TYPE, NAME, SIZE) Util::Array< TYPE > NAME;
#define JTemplateEnumA(TYPE, NAME, ENUM) Util::Array< TYPE > NAME;
#define JTemplateEnd() }; }
#include "component/template/record/recordstruct.h"
#include "component/template/record/recordclass.h"

#endif
