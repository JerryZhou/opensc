#ifndef __JB_TEMPLATEINIT_H_
#define __JB_TEMPLATEINIT_H_
#include "component/template/templaterecord.h"

namespace Record{
/// helper class to init the value
class TemplateInit{
public:
    template<typename TYPE>
    static void Init(TYPE& ref){
        ;
    }
};
template<>
void TemplateInit::Init<uint8_t>(uint8_t &ref);
template<>
void TemplateInit::Init<uint16_t>(uint16_t &ref);
template<>
void TemplateInit::Init<uint32_t>(uint32_t &ref);
template<>
void TemplateInit::Init<uint64_t>(uint64_t &ref);
template<>
void TemplateInit::Init<int8_t>(int8_t &ref);
template<>
void TemplateInit::Init<int16_t>(int16_t &ref);
template<>
void TemplateInit::Init<int32_t>(int32_t &ref);
template<>
void TemplateInit::Init<int64_t>(int64_t &ref);
template<>
void TemplateInit::Init<float>(float &ref);
template<>
void TemplateInit::Init<double>(double &ref);

}
#endif
