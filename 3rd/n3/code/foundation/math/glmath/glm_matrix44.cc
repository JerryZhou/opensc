//------------------------------------------------------------------------------
//  matrix44.cc
//  (C) 2007 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "math/matrix44.h"
#include "math/plane.h"
#include "math/quaternion.h"

namespace Math
{

//------------------------------------------------------------------------------
/**
*/
matrix44
matrix44::reflect(const plane& p)
{
    n_error("matrix44::reflect: IMPLEMENT ME!");
    return matrix44();
}

//------------------------------------------------------------------------------
/**
*/
void
matrix44::decompose(float4& outScale, quaternion& outRotation, float4& outTranslation) const
{
    n_error("matrix44::reflect: IMPLEMENT ME!");
}

//------------------------------------------------------------------------------
/**
*/
matrix44
matrix44::affinetransformation(scalar scaling, float4 const &rotationCenter, const quaternion& rotation, float4 const &translation)
{
    n_error("matrix44::affinetransformation: IMPLEMENT ME!");
    return matrix44();
}

//------------------------------------------------------------------------------
/**
*/
matrix44
matrix44::rotationquaternion(const quaternion& q)
{
    n_error("matrix44::rotationquaternion: IMPLEMENT ME!");
    return matrix44();
}

//------------------------------------------------------------------------------
/**
*/
matrix44
matrix44::transformation(float4 const &scalingCenter, const quaternion& scalingRotation, float4 const &scaling, float4 const &rotationCenter, const quaternion& rotation, float4 const &translation)
{
    n_error("matrix44::transformation: IMPLEMENT ME!");
    return matrix44();
}

//------------------------------------------------------------------------------
/**
*/
bool 
matrix44::ispointinside(const float4& p, const matrix44& m)
{
    n_error("matrix44::ispointinside: IMPLEMENT ME!");
    return false;
}
} // namespace Math
