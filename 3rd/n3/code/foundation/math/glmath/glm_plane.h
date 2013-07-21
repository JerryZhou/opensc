#pragma once
//------------------------------------------------------------------------------
/**
    @class Math::plane
    
    A plane class on top of glm math functions.
    
    (C) 2013 Larry Weya
*/
#include "core/types.h"
#include "math/scalar.h"
#include "math/float4.h"
#include "math/line.h"
#include "math/clipstatus.h"

//------------------------------------------------------------------------------
namespace Math
{
class matrix44;
class plane;

#if (defined(_XM_VMX128_INTRINSICS_) && !defined(_XM_NO_INTRINSICS_))
typedef const plane __PlaneArg;
#else
// win32 VC++ does not support passing aligned objects as value so far
// here is a bug-report at microsoft saying so:
// http://connect.microsoft.com/VisualStudio/feedback/ViewFeedback.aspx?FeedbackID=334581
typedef const plane& __PlaneArg;
#endif


class plane
{
public:
    /// default constructor, NOTE: does NOT setup componenets!
    plane();
    /// !!!! copy constructor forbidden, otherwise passing plane's to a function
    /// !!!! via Registers doesnt work
    //plane(const plane& rhs);
    /// construct from components
    plane(scalar a, scalar b, scalar c, scalar d);
    /// construct from points
    plane(const float4& p0, const float4& p1, const float4& p2);
    /// construct from point and normal
    plane(const float4& p, const float4& n);
    /// construct from XMVECTOR
    plane(glm::vec4 rhs);

    /// setup from points
    void setup_from_points(const float4& p0, const float4& p1, const float4& p2);
    /// setup from point and normal
    void setup_from_point_and_normal(const float4& p, const float4& n);
    /// set componenets
    void set(scalar a, scalar b, scalar c, scalar d);
    /// set the x component
    void set_a(scalar a);
    /// set the y component
    void set_b(scalar b);
    /// set the z component
    void set_c(scalar c);
    /// set the w component
    void set_d(scalar d);

    /// read/write access to A component
    scalar& a();
    /// read/write access to B component
    scalar& b();
    /// read/write access to C component
    scalar& c();
    /// read/write access to D component
    scalar& d();
    /// read-only access to A component
    scalar a() const;
    /// read-only access to B component
    scalar b() const;
    /// read-only access to C component
    scalar c() const;
    /// read-only access to D component
    scalar d() const;

    /// compute dot product of plane and vector
    scalar dot(const float4& v) const;
    /// find intersection with line
    bool intersectline(const float4& startPoint, const float4& endPoint, float4& outIntersectPoint) const;
    /// clip line against this plane
    ClipStatus::Type clip(const line& l, line& outClippedLine) const;
    /// normalize plane components a,b,c
    static plane normalize(const plane& p);

    /// transform plane by inverse transpose of transform
    //static __declspec(deprecated) plane transform(__PlaneArg p, const matrix44& m);

private:
    friend class matrix44;

    glm::vec4 vec;
};

//------------------------------------------------------------------------------
/**
*/
inline
plane::plane()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
inline
plane::plane(scalar a, scalar b, scalar c, scalar d)
{
    this->vec = glm::vec4(a, b, c, d);
}

//------------------------------------------------------------------------------
/**
*/
inline
plane::plane(const float4& p0, const float4& p1, const float4& p2)
{
    this->setup_from_points(p0, p1, p2);
}

//------------------------------------------------------------------------------
/**
*/
inline
plane::plane(const float4& p0, const float4& n)
{
    this->setup_from_point_and_normal(p0, n);
}

//------------------------------------------------------------------------------
/**
*/
inline
plane::plane(glm::vec4 rhs) :
    vec(rhs)
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
inline void
plane::setup_from_points(const float4& p0, const float4& p1, const float4& p2)
{
    n_error("plane::setup_from_points(): IMPLEMENT ME!");
}

//------------------------------------------------------------------------------
/**
*/
inline void
plane::setup_from_point_and_normal(const float4& p, const float4& n)
{
    n_error("plane::setup_from_point_and_normal(): IMPLEMENT ME!");
}

//------------------------------------------------------------------------------
/**
*/
inline void
plane::set(scalar a, scalar b, scalar c, scalar d)
{
    this->vec = glm::vec4(a, b, c, d);
}

//------------------------------------------------------------------------------
/**
*/
inline scalar&
plane::a()
{
    return this->vec.x;
}

//------------------------------------------------------------------------------
/**
*/
inline scalar
plane::a() const
{
    return this->vec.x;
}

//------------------------------------------------------------------------------
/**
*/
inline scalar&
plane::b()
{
    return this->vec.y;
}

//------------------------------------------------------------------------------
/**
*/ 
inline scalar
plane::b() const
{
    return this->vec.y;
}

//------------------------------------------------------------------------------
/**
*/
inline scalar&
plane::c()
{
    return this->vec.z;
}

//------------------------------------------------------------------------------
/**
*/
inline scalar
plane::c() const
{
    return this->vec.z;
}

//------------------------------------------------------------------------------
/**
*/
inline scalar&
plane::d()
{
    return this->vec.w;
}

//------------------------------------------------------------------------------
/**
*/
inline scalar
plane::d() const
{
    return this->vec.w;
}

//------------------------------------------------------------------------------
/**
*/
inline scalar
plane::dot(const float4& v) const
{
    n_error("plane::setup_from_point_and_normal(): IMPLEMENT ME!");
    return 1.0f;
}

//------------------------------------------------------------------------------
/**
*/
inline bool
plane::intersectline(const float4& startPoint, const float4& endPoint, float4& outIntersectPoint) const
{
  n_error("plane::setup_from_point_and_normal(): IMPLEMENT ME!");
  return false;
}

//------------------------------------------------------------------------------
/**
*/
inline plane
plane::normalize(const plane& p)
{
    n_error("plane::setup_from_point_and_normal(): IMPLEMENT ME!");
    return glm::normalize(p.vec);
}

//------------------------------------------------------------------------------
/**
*/
inline void 
plane::set_a(scalar a)
{
    this->vec.x = a;
}

//------------------------------------------------------------------------------
/**
*/
inline void 
plane::set_b(scalar b)
{
    this->vec.y = b;
}

//------------------------------------------------------------------------------
/**
*/
inline void 
plane::set_c(scalar c)
{
    this->vec.z = c;
}

//------------------------------------------------------------------------------
/**
*/
inline void 
plane::set_d(scalar d)
{
    this->vec.w = d;
}

//------------------------------------------------------------------------------
/**
*/
inline ClipStatus::Type
plane::clip(const line& l, line& clippedLine) const
{
    n_assert(&l != &clippedLine);
    float d0 = this->dot(l.start());
    float d1 = this->dot(l.end());
    if ((d0 >= N_TINY) && (d1 >= N_TINY))
    {
        // start and end point above plane
        clippedLine = l;
        return ClipStatus::Inside;
    }
    else if ((d0 < N_TINY) && (d1 < N_TINY))
    {
        // start and end point below plane
        return ClipStatus::Outside;
    }
    else
    {
        // line is clipped
        point clipPoint;
        this->intersectline(l.start(), l.end(), clipPoint);
        if (d0 >= N_TINY)
        {
            clippedLine.set(l.start(), clipPoint);
        }
        else
        {
            clippedLine.set(clipPoint, l.end());
        }
        return ClipStatus::Clipped;
    }
}

} // namespace Math
//------------------------------------------------------------------------------
