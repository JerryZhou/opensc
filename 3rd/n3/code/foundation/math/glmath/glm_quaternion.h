#pragma once
//------------------------------------------------------------------------------
/**
    @class Math::quaternion
  
    A quaternion class on top of the Xbox360 math functions.
    
    (C) 2007 Radon Labs GmbH
*/    
#include "core/types.h"
#include "math/scalar.h"
#include "math/float4.h"

//------------------------------------------------------------------------------
namespace Math
{
class quaternion;

#if (defined(_XM_VMX128_INTRINSICS_) && !defined(_XM_NO_INTRINSICS_))
typedef const quaternion  __QuaternionArg;
#else
// win32 VC++ does not support passing aligned objects as value so far
// here is a bug-report at microsoft saying so:
// http://connect.microsoft.com/VisualStudio/feedback/ViewFeedback.aspx?FeedbackID=334581
typedef const quaternion& __QuaternionArg;
#endif


class quaternion
{
public:
    /// default constructor, NOTE: does NOT setup components!
    quaternion();
    /// construct from components
    quaternion(scalar x, scalar y, scalar z, scalar w);
    /// construct from float4
    quaternion(float4 const &rhs);
    /// copy constructor
    /// !!!! copy constructor forbidden, otherwise passing point's to a function
    /// !!!! via Registers doesnt work
    //quaternion(const quaternion& rhs);
    /// construct from glm::vec4
    quaternion(glm::vec4 rhs);

    /// assignment operator
    void operator=(const quaternion& rhs);
    /// assign XMVECTOR
    void operator=(glm::vec4 rhs);
    /// equality operator
    bool operator==(const quaternion& rhs) const;
    /// inequality operator
    bool operator!=(const quaternion& rhs) const;

    /// load content from 16-byte-aligned memory
    void load(const scalar* ptr);
    /// load content from unaligned memory
    void loadu(const scalar* ptr);
    /// write content to 16-byte-aligned memory through the write cache
    void store(scalar* ptr) const;
    /// write content to unaligned memory through the write cache
    void storeu(scalar* ptr) const;
    /// stream content to 16-byte-aligned memory circumventing the write-cache
    void stream(scalar* ptr) const;

    /// set content
    void set(scalar x, scalar y, scalar z, scalar w);
    /// set from float4
    void set(float4 const &f4);
    /// set the x component
    void set_x(scalar x);
    /// set the y component
    void set_y(scalar y);
    /// set the z component
    void set_z(scalar z);
    /// set the w component
    void set_w(scalar w);

    /// read/write access to x component
    scalar& x();
    /// read/write access to y component
    scalar& y();
    /// read/write access to z component
    scalar& z();
    /// read/write access to w component
    scalar& w();
    /// read-only access to x component
    scalar x() const;
    /// read-only access to y component
    scalar y() const;
    /// read-only access to z component
    scalar z() const;
    /// read-only access to w component
    scalar w() const;
    
    /// return true if quaternion is identity
    bool isidentity() const;
    /// returns length
    scalar length() const;
    /// returns length squared
    scalar lengthsq() const;
    /// un-denormalize quaternion (this is sort of a hack since Maya likes to return denormal quaternions)
    void undenormalize();

    /// return quaternion in barycentric coordinates
    static quaternion barycentric(const quaternion& q0, const quaternion& q1, const quaternion& q2, scalar f, scalar g);
    /// return conjugate of a normalized quaternion
    static quaternion conjugate(const quaternion& q);
    /// return dot product of two normalized quaternions
    static scalar dot(const quaternion& q0, const quaternion& q1);
    /// calculate the exponential
    static quaternion exp(const quaternion& q0);
    /// returns an identity quaternion
    static quaternion identity();
    /// conjugates and renormalizes quaternion
    static quaternion inverse(const quaternion& q);
    /// calculate the natural logarithm
    static quaternion ln(const quaternion& q);
    /// multiply 2 quaternions
    static quaternion multiply(const quaternion& q0, const quaternion& q1);
    /// compute unit length quaternion
    static quaternion normalize(const quaternion& q);
    /// build quaternion from axis and clockwise rotation angle in radians
    static quaternion rotationaxis(const float4& axis, scalar angle);
    /// build quaternion from rotation matrix
    static quaternion rotationmatrix(const matrix44& m);
    /// build quaternion from yaw, pitch and roll
    static quaternion rotationyawpitchroll(scalar yaw, scalar pitch, scalar roll);
    /// interpolate between 2 quaternion using spherical interpolation
    static quaternion slerp(const quaternion& q1, const quaternion& q2, scalar t);
    /// setup control points for spherical quadrangle interpolation
    static void squadsetup(const quaternion& q0, const quaternion& q1, const quaternion& q2, const quaternion& q3, quaternion& aOut, quaternion& bOut, quaternion& cOut);
    /// interpolate between quaternions using spherical quadrangle interpolation
    static quaternion squad(const quaternion& q1, const quaternion& a, const quaternion& b, const quaternion& c, scalar t);
    /// convert quaternion to axis and angle
    static void to_axisangle(const quaternion& q, float4& outAxis, scalar& outAngle);

private:
    friend class matrix44;

    glm::vec4 vec;
};

//------------------------------------------------------------------------------
/**
*/
__forceinline
quaternion::quaternion()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
__forceinline
quaternion::quaternion(scalar x, scalar y, scalar z, scalar w)
{
    this->vec = glm::vec4(x, y, z, w);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline
quaternion::quaternion(float4 const &rhs) :
    vec(rhs.vec)
{
    // empty
}
    
//------------------------------------------------------------------------------
/**
*/
__forceinline 
quaternion::quaternion(glm::vec4 rhs) :
    vec(rhs)
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
quaternion::operator=(const quaternion& rhs)
{
    this->vec = rhs.vec;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
quaternion::operator=(glm::vec4 rhs)
{
    this->vec = rhs;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
quaternion::operator==(const quaternion& rhs) const
{
    n_error("quaternion::operator==: IMPLEMENT ME!");
    return false;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
quaternion::operator!=(const quaternion& rhs) const
{
    n_error("quaternion::operator!=: IMPLEMENT ME!");
    return false;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
quaternion::load(const scalar* ptr)
{
    n_error("quaternion::load: IMPLEMENT ME!");
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
quaternion::loadu(const scalar* ptr)
{
    n_error("quaternion::loadu: IMPLEMENT ME!");
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
quaternion::store(scalar* ptr) const
{
    n_error("quaternion::store: IMPLEMENT ME!");
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
quaternion::storeu(scalar* ptr) const
{
    n_error("quaternion::storeu: IMPLEMENT ME!");
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
quaternion::stream(scalar* ptr) const
{
    n_error("quaternion::stream: IMPLEMENT ME!");
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
quaternion::set(scalar x, scalar y, scalar z, scalar w)
{
    this->vec = glm::vec4(x, y, z, w);
}

//------------------------------------------------------------------------------
/**
*/
inline void 
quaternion::set_x(scalar x)
{
    this->vec.x = x;
}

//------------------------------------------------------------------------------
/**
*/
inline void 
quaternion::set_y(scalar y)
{
    this->vec.y = y;
}

//------------------------------------------------------------------------------
/**
*/
inline void 
quaternion::set_z(scalar z)
{
    this->vec.z = z;
}

//------------------------------------------------------------------------------
/**
*/
inline void 
quaternion::set_w(scalar w)
{
    this->vec.w = w;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
quaternion::set(float4 const &f4)
{
    this->vec = f4.vec;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar&
quaternion::x()
{
    return this->vec.x;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar
quaternion::x() const
{
    return this->vec.x;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar&
quaternion::y()
{
    return this->vec.y;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar
quaternion::y() const
{
    return this->vec.y;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar&
quaternion::z()
{
    return this->vec.z;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar
quaternion::z() const
{
    return this->vec.z;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar&
quaternion::w()
{
    return this->vec.w;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar
quaternion::w() const
{
    return this->vec.w;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
quaternion::isidentity() const
{
    n_error("quaternion::isidentity(): IMPLEMENT ME!");
    return false;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar
quaternion::length() const
{
    n_error("quaternion::length(): IMPLEMENT ME!");
    return 0.0f;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar
quaternion::lengthsq() const
{
    n_error("quaternion::lengthsq(): IMPLEMENT ME!");
    return 0.0f;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
quaternion::undenormalize()
{
    // nothing to do on the xbox, since denormal numbers are not supported by the vmx unit, 
    // it is being set to zero anyway
#if __WIN32__
    this->set_x(n_undenormalize(this->x()));
    this->set_y(n_undenormalize(this->y()));
    this->set_z(n_undenormalize(this->z()));
    this->set_w(n_undenormalize(this->w()));
#endif
    n_error("quaternion::undenormalize(): IMPLEMENT ME!");
}

//------------------------------------------------------------------------------
/**
*/
__forceinline quaternion
quaternion::barycentric(const quaternion& q0, const quaternion& q1, const quaternion& q2, scalar f, scalar g)
{
    n_error("quaternion::barycentric(): IMPLEMENT ME!");
    return quaternion();
}

//------------------------------------------------------------------------------
/**
*/
__forceinline quaternion
quaternion::conjugate(const quaternion& q)
{
    n_error("quaternion::conjugate(): IMPLEMENT ME!");
    return quaternion();
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar
quaternion::dot(const quaternion& q0, const quaternion& q1)
{
    n_error("quaternion::dot(): IMPLEMENT ME!");
    return 0.0f;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline quaternion
quaternion::exp(const quaternion& q)
{
    n_error("quaternion::exp(): IMPLEMENT ME!");
    return quaternion();
}

//------------------------------------------------------------------------------
/**
*/
__forceinline quaternion
quaternion::identity()
{
    n_error("quaternion::identity(): IMPLEMENT ME!");
    return quaternion();
}

//------------------------------------------------------------------------------
/**
*/
__forceinline quaternion
quaternion::inverse(const quaternion& q)
{
    n_error("quaternion::inverse(): IMPLEMENT ME!");
    return quaternion();
}

//------------------------------------------------------------------------------
/**
*/
__forceinline quaternion
quaternion::ln(const quaternion& q)
{
    n_error("quaternion::inverse(): IMPLEMENT ME!");
    return quaternion();
}

//------------------------------------------------------------------------------
/**
*/
__forceinline quaternion
quaternion::multiply(const quaternion& q0, const quaternion& q1)
{
    n_error("quaternion::multiply(): IMPLEMENT ME!");
    return quaternion();
}

//------------------------------------------------------------------------------
/**
*/
__forceinline quaternion
quaternion::normalize(const quaternion& q)
{
    n_error("quaternion::normalize(): IMPLEMENT ME!");
    return quaternion();
}

//------------------------------------------------------------------------------
/**
*/
__forceinline quaternion
quaternion::rotationaxis(const float4& axis, scalar angle)
{
    n_error("quaternion::rotationaxis(): IMPLEMENT ME!");
    return quaternion();
}

//------------------------------------------------------------------------------
/**
*/
__forceinline quaternion
quaternion::rotationyawpitchroll(scalar yaw, scalar pitch, scalar roll)
{
    n_error("quaternion::rotationyawpitchroll(): IMPLEMENT ME!");
    return quaternion();
}

//------------------------------------------------------------------------------
/**
*/
__forceinline quaternion
quaternion::slerp(const quaternion& q1, const quaternion& q2, scalar t)
{
    n_error("quaternion::slerp(): IMPLEMENT ME!");
    return quaternion();
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
quaternion::squadsetup(const quaternion& q0, const quaternion& q1, const quaternion& q2, const quaternion& q3, quaternion& aOut, quaternion& bOut, quaternion& cOut)
{
    n_error("quaternion::squadsetup(): IMPLEMENT ME!");
}

//------------------------------------------------------------------------------
/**
*/
__forceinline quaternion
quaternion::squad(const quaternion& q1, const quaternion& a, const quaternion& b, const quaternion& c, scalar t)
{
    n_error("quaternion::squad(): IMPLEMENT ME!");
    return quaternion();
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
quaternion::to_axisangle(const quaternion& q, float4& outAxis, scalar& outAngle)
{
    n_error("quaternion::to_axisangle(): IMPLEMENT ME!");
}

} // namespace Math
//------------------------------------------------------------------------------
