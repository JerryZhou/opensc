//------------------------------------------------------------------------------
//  float4.cc
//  (C) 2007 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "math/float4.h"
#include "math/matrix44.h"
#include "system/byteorder.h"

#include <glm/gtx/vector_angle.hpp>

namespace Math
{

//------------------------------------------------------------------------------
/**
*/
float4
float4::transform(__Float4Arg v, const matrix44 &m)
{
    return m.mx * v.vec;
}

//------------------------------------------------------------------------------
/**
*/
float4
float4::clamp(__Float4Arg vClamp, __Float4Arg vMin, __Float4Arg vMax)
{
    return glm::clamp(vClamp.vec, vMin.vec, vMax.vec);
}

//------------------------------------------------------------------------------
/**
*/
scalar
float4::angle(__Float4Arg v0, __Float4Arg v1)
{
    return glm::angle(v0.vec, v1.vec);
}

} // namespace Math
