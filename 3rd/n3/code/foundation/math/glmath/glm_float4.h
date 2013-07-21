#pragma once
//------------------------------------------------------------------------------
/**
    @class Math::float4

    Xbox360 implementation of float4. Note: float4 params are handed
    as values on the Xbox360, since 4 component vectors are a native datatype
    (and the compiler knows how to handle this stuff).

    (C) 2007 Radon Labs GmbH
*/
#include "core/types.h"
#include "math/scalar.h"

#define GLM_SWIZZLE 
#include <glm/glm.hpp>
#include <glm/gtx/norm.hpp>
#include <glm/gtx/vector_access.hpp>

//------------------------------------------------------------------------------
namespace Math
{
class matrix44;
class float4;

#if (defined(_XM_VMX128_INTRINSICS_) && !defined(_XM_NO_INTRINSICS_))
typedef const float4 __Float4Arg;
#else
// win32 VC++ does not support passing aligned objects as value so far
// here is a bug-report at microsoft saying so:
// http://connect.microsoft.com/VisualStudio/feedback/ViewFeedback.aspx?FeedbackID=334581
typedef const float4& __Float4Arg;
#endif


class float4
{
public:
    /// default constructor, NOTE: does NOT setup components!
    float4();
    /// construct from values
    float4(scalar x, scalar y, scalar z, scalar w);
    /// !!!! copy constructor forbidden, otherwise passing float4's to a function
    /// !!!! via Registers doesnt work
    //float4(const float4& rhs);
    /// construct from glm::vec4
    float4(glm::vec4 rhs);
    /// construct from glm::vec3
    float4(glm::vec3 rhs);

    /// assignment operator
    void operator=(const float4 &rhs);
    /// assign an glm::vec4
    void operator=(glm::vec4 rhs);
    /// flip sign
    float4 operator-() const;
    /// inplace add
    void operator+=(const float4 &rhs);
    /// inplace sub
    void operator-=(const float4 &rhs);
    /// inplace scalar multiply
    void operator*=(scalar s);
    /// muliply by a vector component-wise
    void operator*=(const float4& rhs);
    /// add 2 vectors
    float4 operator+(const float4 &rhs) const;
    /// subtract 2 vectors
    float4 operator-(const float4 &rhs) const;
    /// multiply with scalar
    float4 operator*(scalar s) const;
    /// equality operator
    bool operator==(const float4 &rhs) const;
    /// inequality operator
    bool operator!=(const float4 &rhs) const;

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

    /// return length of vector
    scalar length() const;
    /// return squared length of vector
    scalar lengthsq() const;
    /// return compononent-wise absolute
    float4 abs() const;

    /// component-wise multiplication
    static float4 multiply(const float4 &v0, const float4 &v1);
    /// return 3-dimensional cross product
    static float4 cross3(const float4 &v0, const float4 &v1);
    /// return 3d dot product of vectors
    static scalar dot3(const float4 &v0, const float4 &v1);
    /// perform Catmull-Rom interpolation
    /// perform linear interpolation between 2 4d vectors
    static float4 lerp(const float4 &v0, const float4 &v1, scalar s);
    /// return 4d vector made up of largest components of 2 vectors
    static float4 maximize(const float4 &v0, const float4 &v1);
    /// return 4d vector made up of smallest components of 2 vectors
    static float4 minimize(const float4 &v0, const float4 &v1);
    /// return normalized version of 4d vector
    static float4 normalize(const float4 &v);
    /// transform 4d vector by matrix44
    static __declspec(deprecated) float4 transform(__Float4Arg v, const matrix44 &m);
    /// reflect a vector v
    static float4 reflect(const float4 &normal, const float4 &incident);
    /// clamp to min/max vector
    static float4 clamp(__Float4Arg Clamp, __Float4Arg vMin, __Float4Arg vMax);
    /// angle between two vectors
    static scalar angle(__Float4Arg v0, __Float4Arg v1);
    
    /// return true if any XYZ component is less-then
    static bool less3_any(const float4 &v0, const float4 &v1);
    /// return true if all XYZ components are less-then
    static bool less3_all(const float4 &v0, const float4 &v1);
    /// return true if any XYZ component is less-or-equal
    static bool lessequal3_any(const float4 &v0, const float4 &v1);
    /// return true if all XYZ components are less-or-equal
    static bool lessequal3_all(const float4 &v0, const float4 &v1);
    /// return true if any XYZ component is greater
    static bool greater3_any(const float4 &v0, const float4 &v1);
    /// return true if all XYZ components are greater
    static bool greater3_all(const float4 &v0, const float4 &v1);
    /// return true if any XYZ component is greater-or-equal
    static bool greaterequal3_any(const float4 &v0, const float4 &v1);
    /// return true if all XYZ components are greater-or-equal
    static bool greaterequal3_all(const float4 &v0, const float4 &v1);
    /// return true if any XYZ component is equal
    static bool equal3_any(const float4 &v0, const float4 &v1);
    /// return true if all XYZ components are equal
    static bool equal3_all(const float4 &v0, const float4 &v1);
    /// perform near equal comparison with given epsilon (3 components)
    static bool nearequal3(const float4 &v0, const float4 &v1, const float4 &epsilon);

    /// return true if any XYZW component is less-then
    static bool less4_any(const float4 &v0, const float4 &v1);
    /// return true if all XYZW components are less-then
    static bool less4_all(const float4 &v0, const float4 &v1);
    /// return true if any XYZW component is less-or-equal
    static bool lessequal4_any(const float4 &v0, const float4 &v1);
    /// return true if all XYZW components are less-or-equal
    static bool lessequal4_all(const float4 &v0, const float4 &v1);
    /// return true if any XYZW component is greater
    static bool greater4_any(const float4 &v0, const float4 &v1);
    /// return true if all XYZW components are greater
    static bool greater4_all(const float4 &v0, const float4 &v1);
    /// return true if any XYZW component is greater-or-equal
    static bool greaterequal4_any(const float4 &v0, const float4 &v1);
    /// return true if all XYZW components are greater-or-equal
    static bool greaterequal4_all(const float4 &v0, const float4 &v1);
    /// return true if any XYZW component is equal
    static bool equal4_any(const float4 &v0, const float4 &v1);
    /// return true if all XYZW components are equal
    static bool equal4_all(const float4 &v0, const float4 &v1);
    /// perform near equal comparison with given epsilon (4 components)
    static bool nearequal4(const float4 &v0, const float4 &v1, const float4 &epsilon);
    
    glm::vec4 vec;
};

//------------------------------------------------------------------------------
/**
*/
__forceinline
float4::float4()
{
    //  empty
}

//------------------------------------------------------------------------------
/**
*/
__forceinline
float4::float4(scalar x, scalar y, scalar z, scalar w)
{
    this->vec = glm::vec4(x, y, z, w);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline
float4::float4(glm::vec4 rhs) :
    vec(rhs)
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
float4::operator=(const float4 &rhs)
{
    this->vec = rhs.vec;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
float4::operator=(glm::vec4 rhs)
{
    this->vec = rhs;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline float4
float4::operator-() const
{
    return this->vec * -1.f;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::operator==(const float4 &rhs) const
{
    return this->vec == rhs.vec;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::operator!=(const float4 &rhs) const
{
    return this->vec != rhs.vec;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline float4
float4::operator*(scalar t) const
{
    return float4(this->vec * t);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
float4::operator*=(const float4& rhs)
{
    this->vec = this->vec * rhs.vec;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
float4::operator+=(const float4 &rhs)
{
    this->vec = this->vec + rhs.vec;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
float4::operator-=(const float4 &rhs)
{
    this->vec = this->vec - rhs.vec;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
float4::operator*=(scalar s)
{
    this->vec = this->vec * s;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline float4
float4::operator+(const float4 &rhs) const
{
    return float4(this->vec + rhs.vec);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline float4
float4::operator-(const float4 &rhs) const
{
    return float4(this->vec - rhs.vec);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
float4::load(const scalar* ptr)
{
    this->set(ptr[0], ptr[1], ptr[2], ptr[3]);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
float4::loadu(const scalar* ptr)
{
    this->set(ptr[0], ptr[1], ptr[2], ptr[3]);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
float4::store(scalar* ptr) const
{
    ptr[0] = this->vec.x;
    ptr[1] = this->vec.y;
    ptr[2] = this->vec.z;
    ptr[3] = this->vec.w;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
float4::storeu(scalar* ptr) const
{
    ptr[0] = this->vec.x;
    ptr[1] = this->vec.y;
    ptr[2] = this->vec.z;
    ptr[3] = this->vec.w;
}


//------------------------------------------------------------------------------
/**
*/
__forceinline void
float4::stream(scalar* ptr) const
{
    ptr[0] = this->vec.x;
    ptr[1] = this->vec.y;
    ptr[2] = this->vec.z;
    ptr[3] = this->vec.w;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
float4::set(scalar x, scalar y, scalar z, scalar w)
{
    glm::set(this->vec, x, y, z, w);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar&
float4::x()
{
    return this->vec.x;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar
float4::x() const
{
    return this->vec.x;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar&
float4::y()
{
    return this->vec.y;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar
float4::y() const
{
    return this->vec.y;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar&
float4::z()
{
    return this->vec.z;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar
float4::z() const
{
    return this->vec.z;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar&
float4::w()
{
    return this->vec.w;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar
float4::w() const
{
    return this->vec.w;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
float4::set_x(scalar x)
{
    this->vec.x = x;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
float4::set_y(scalar y)
{
    this->vec.y = y;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
float4::set_z(scalar z)
{
    this->vec.z = z;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
float4::set_w(scalar w)
{
    this->vec.w = w;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar
float4::length() const
{
    return glm::length(this->vec);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar
float4::lengthsq() const
{
    return glm::length2(this->vec);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline float4
float4::multiply(const float4 &v0, const float4 &v1)
{
    return v0.vec * v1.vec;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline float4
float4::abs() const
{
    return glm::abs(this->vec);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline float4
float4::cross3(const float4 &v0, const float4 &v1)
{
    return float4(glm::vec4(glm::cross(glm::vec3(v0.vec.xyz), glm::vec3(v1.vec.xyz)), 0.0f));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar
float4::dot3(const float4 &v0, const float4 &v1)
{
    return glm::dot(v0.vec, v1.vec);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline float4
float4::lerp(const float4 &v0, const float4 &v1, scalar s)
{
    return glm::mix(v0.vec, v1.vec, s);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline float4
float4::maximize(const float4 &v0, const float4 &v1)
{
    return glm::max(v0.vec, v1.vec);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline float4
float4::minimize(const float4 &v0, const float4 &v1)
{
    return glm::min(v0.vec, v1.vec);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline float4
float4::normalize(const float4 &v)
{
    return glm::normalize(v.vec);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline float4
float4::reflect(const float4 &normal, const float4 &incident)
{
    return glm::reflect(incident.vec, normal.vec);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::less4_any(const float4 &v0, const float4 &v1)
{
    return glm::any(glm::lessThan(v0.vec, v1.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::less4_all(const float4 &v0, const float4 &v1)
{
    return glm::all(glm::lessThan(v0.vec, v1.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::lessequal4_any(const float4 &v0, const float4 &v1)
{
    return glm::any(glm::lessThanEqual(v0.vec, v1.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::lessequal4_all(const float4 &v0, const float4 &v1)
{
    return glm::all(glm::lessThanEqual(v0.vec, v1.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::greater4_any(const float4 &v0, const float4 &v1)
{
    return glm::any(glm::greaterThan(v0.vec, v1.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::greater4_all(const float4 &v0, const float4 &v1)
{
    return glm::all(glm::greaterThan(v0.vec, v1.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::greaterequal4_any(const float4 &v0, const float4 &v1)
{
    return glm::any(glm::greaterThanEqual(v0.vec, v1.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::greaterequal4_all(const float4 &v0, const float4 &v1)
{
    return glm::all(glm::greaterThanEqual(v0.vec, v1.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::equal4_any(const float4 &v0, const float4 &v1)
{
    return glm::any(glm::equal(v0.vec, v1.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::equal4_all(const float4 &v0, const float4 &v1)
{
    return glm::all(glm::equal(v0.vec, v1.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::nearequal4(const float4 &v0, const float4 &v1, const float4 &epsilon)
{
    n_error("float4::nearequal4: IMPLEMENT ME!");
    return glm::all(glm::equal(v0.vec, v1.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::less3_any(const float4 &v0, const float4 &v1)
{
    n_error("float4::less3_any: IMPLEMENT ME!");
    return glm::any(glm::lessThan(v0.vec, v1.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::less3_all(const float4 &v0, const float4 &v1)
{
    n_error("float4::less3_any: IMPLEMENT ME!");
    return glm::all(glm::lessThan(v0.vec, v1.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::lessequal3_any(const float4 &v0, const float4 &v1)
{
    n_error("float4::less3_any: IMPLEMENT ME!");
    return glm::any(glm::lessThanEqual(v0.vec, v1.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::lessequal3_all(const float4 &v0, const float4 &v1)
{
    n_error("float4::less3_any: IMPLEMENT ME!");
    return glm::all(glm::lessThanEqual(v0.vec, v1.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::greater3_any(const float4 &v0, const float4 &v1)
{
    n_error("float4::less3_any: IMPLEMENT ME!");
    return glm::any(glm::greaterThan(v0.vec, v1.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::greater3_all(const float4 &v0, const float4 &v1)
{
    n_error("float4::less3_any: IMPLEMENT ME!");
    return glm::all(glm::greaterThan(v0.vec, v1.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::greaterequal3_any(const float4 &v0, const float4 &v1)
{
    n_error("float4::less3_any: IMPLEMENT ME!");
    return glm::any(glm::greaterThanEqual(v0.vec, v1.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::greaterequal3_all(const float4 &v0, const float4 &v1)
{
    n_error("float4::less3_any: IMPLEMENT ME!");
    return glm::all(glm::greaterThanEqual(v0.vec, v1.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::equal3_any(const float4 &v0, const float4 &v1)
{
    n_error("float4::equal3_any: IMPLEMENT ME!");
    return glm::any(glm::equal(v0.vec, v1.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::equal3_all(const float4 &v0, const float4 &v1)
{
    n_error("float4::equal3_all: IMPLEMENT ME!");
    return glm::all(glm::equal(v0.vec, v1.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
float4::nearequal3(const float4 &v0, const float4 &v1, const float4 &epsilon)
{
    n_error("float4::nearequal3: IMPLEMENT ME!");
    return glm::all(glm::equal(v0.vec, v1.vec));
}

} // namespace Math
//------------------------------------------------------------------------------
