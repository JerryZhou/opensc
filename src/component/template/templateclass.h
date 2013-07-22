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

/// include in record base
#define JTemplateClass(DERIVED, BASE, NameSpace) namespace NameSpace { typedef struct _##DERIVED : public BASE {
#define JTemplateValue(TYPE, NAME) TYPE NAME;
#define JTemplateArray(TYPE, NAME, SIZE) Util::Array<TYPE> NAME;
#define JTemplateEnd(DERIVED) }DERIVED; }
#include "component/template/record/recordclass.h"

#endif
