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
template<>
Record::SColor& TemplateInit::Init<Record::SColor>(Record::SColor &ref){
    ref.r = ref.g = ref.b = 0;
    ref.a = 255;
    return ref;
}
template<>
Record::SVector2& TemplateInit::Init<Record::SVector2>(Record::SVector2 &ref){
    ref.x = 0;
    ref.y = 0;
    return ref;
}
template<>
Record::SVector3& TemplateInit::Init<Record::SVector3>(Record::SVector3 &ref){
    ref.x = 0;
    ref.y = 0;
    ref.z = 0;
    return ref;
}
template<>
Record::SVector4& TemplateInit::Init<Record::SVector4>(Record::SVector4 &ref){
    ref.x = 0;
    ref.y = 0;
    ref.z = 0;
    ref.w = 0;
    return ref;
}
    
template<>
Record::SIntRange& TemplateInit::Init<Record::SIntRange>(Record::SIntRange &ref){
    ref.min = 0;
    ref.max = 0;
    return ref;
}
        
template<>
Record::SFloatRange& TemplateInit::Init<Record::SFloatRange>(Record::SFloatRange &ref){
    ref.min = 0;
    ref.max = 0;
    return ref;
}
            
template<>
Record::SRotator& TemplateInit::Init<Record::SRotator>(Record::SRotator &ref){
    ref.pitch = 0;
    ref.roll = 0;
    ref.yaw = 0;
    return ref;
}
}