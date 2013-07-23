#include "templateinit.h"

namespace Record {
template<>
void TemplateInit::Init<uint8_t>(uint8_t &ref){
    ref = 0;
}
template<>
void TemplateInit::Init<uint16_t>(uint16_t &ref){
        ref = 0;
}
template<>
void TemplateInit::Init<uint32_t>(uint32_t &ref){
        ref = 0;
}
template<>
void TemplateInit::Init<uint64_t>(uint64_t &ref){
        ref = 0;
}
template<>
void TemplateInit::Init<int8_t>(int8_t &ref){
        ref = 0;
}
template<>
void TemplateInit::Init<int16_t>(int16_t &ref){
        ref = 0;
}
template<>
void TemplateInit::Init<int32_t>(int32_t &ref){
        ref = 0;
}
template<>
void TemplateInit::Init<int64_t>(int64_t &ref){
        ref = 0;
}
template<>
void TemplateInit::Init<float>(float &ref){
        ref = 0;
}
template<>
void TemplateInit::Init<double>(double &ref){
        ref = 0;
}
}