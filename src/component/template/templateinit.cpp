#include "templateinit.h"

namespace Record {
template<>
uint8_t& TemplateInit::Init<uint8_t>(uint8_t &ref){
    ref = 0;
    return ref;
}
template<>
uint16_t& TemplateInit::Init<uint16_t>(uint16_t &ref){
    ref = 0;
    return ref;
}
template<>
uint32_t& TemplateInit::Init<uint32_t>(uint32_t &ref){
        ref = 0;
    return ref;
}
template<>
uint64_t& TemplateInit::Init<uint64_t>(uint64_t &ref){
        ref = 0;
    return ref;
}
template<>
int8_t& TemplateInit::Init<int8_t>(int8_t &ref){
        ref = 0;
    return ref;
}
template<>
int16_t& TemplateInit::Init<int16_t>(int16_t &ref){
        ref = 0;
    return ref;
}
template<>
int32_t& TemplateInit::Init<int32_t>(int32_t &ref){
        ref = 0;
    return ref;
}
template<>
int64_t& TemplateInit::Init<int64_t>(int64_t &ref){
        ref = 0;
    return ref;
}
template<>
float& TemplateInit::Init<float>(float &ref){
        ref = 0;
    return ref;
}
template<>
double& TemplateInit::Init<double>(double &ref){
        ref = 0;
    return ref;
}
}