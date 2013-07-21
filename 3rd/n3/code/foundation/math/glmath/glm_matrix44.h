#pragma once
//------------------------------------------------------------------------------
/**
    @class Math::matrix44
    
    A matrix44 class on top of Xbox360 math functions.
    
    (C) 2007 Radon Labs GmbH
*/
#include "core/types.h"
#include "math/scalar.h"
#include "math/float4.h"
#include "math/plane.h"
#include "math/quaternion.h"

#include <glm/gtx/matrix_query.hpp>
#include <glm/gtx/transform.hpp>

//------------------------------------------------------------------------------
namespace Math
{
class quaternion;
class plane;

// could not get the compiler to really pass it in registers for xbox, so
// this is a reference so far
typedef const matrix44& __Matrix44Arg;

class matrix44
{
public:
    /// default constructor, NOTE: does NOT setup components!
    matrix44();
    /// construct from components
    matrix44(float4 const &row0, float4 const &row1, float4 const &row2, float4 const &row3);
    /// copy constructor
    //matrix44(const matrix44& rhs);
    /// construct from XMMATRIX
    matrix44(const glm::mat4& rhs);
    
    /// assignment operator
    void operator=(const matrix44& rhs);
    /// assign XMMATRIX
    void operator=(const glm::mat4& rhs);
    /// equality operator
    bool operator==(const matrix44& rhs) const;
    /// inequality operator
    bool operator!=(const matrix44& rhs) const;

    /// set content
    void set(float4 const &row0, float4 const &row1, float4 const &row2, float4 const &row3);
    /// write access to x component
    void setrow0(float4 const &row0);
    /// write access to y component
    void setrow1(float4 const &row1);
    /// write access to z component
    void setrow2(float4 const &row2);
    /// write access to w component
    void setrow3(float4 const &row3);
    /// read-only access to x component
    const float4& getrow0() const;
    /// read-only access to y component
    const float4& getrow1() const;
    /// read-only access to z component
    const float4& getrow2() const;
    /// read-only access to w component
    const float4& getrow3() const;

    /// write access to x component
    void set_xaxis(float4 const &x);
    /// write access to y component
    void set_yaxis(float4 const &y);
    /// write access to z component
    void set_zaxis(float4 const &z);
    /// write access to w component / pos component
    void set_position(float4 const &pos);
    /// read access to x component
    const float4& get_xaxis() const;
    /// read access to y component
    const float4& get_yaxis() const;
    /// read access to z component
    const float4& get_zaxis() const;
    /// read access to w component / pos component
    const float4& get_position() const;
    /// add a translation to pos_component
    void translate(float4 const &t);
    /// scale matrix
    void scale(float4 const &v);

    /// return true if matrix is identity
    bool isidentity() const;
    /// return determinant of matrix
    scalar determinant() const;
    /// decompose into scale, rotation and translation
    /// !!! Note: 
    void decompose(float4& outScale, quaternion& outRotation, float4& outTranslation) const;

    /// build identity matrix
    static matrix44 identity();
    /// build matrix from affine transformation
    static matrix44 affinetransformation(scalar scaling, float4 const &rotationCenter, const quaternion& rotation, float4 const &translation);
    /// compute the inverse of a matrix
    static matrix44 inverse(const matrix44& m);
    /// build left handed lookat matrix
    static matrix44 lookatlh(float4 const &eye, float4 const &at, float4 const &up);
    /// build right handed lookat matrix
    static matrix44 lookatrh(float4 const &eye, float4 const &at, float4 const &up);
    /// multiply 2 matrices
    static matrix44 multiply(const matrix44& m0, const matrix44& m1);
    /// build left handed orthogonal projection matrix
    static matrix44 ortholh(scalar w, scalar h, scalar zn, scalar zf);
    /// build right handed orthogonal projection matrix
    static matrix44 orthorh(scalar w, scalar h, scalar zn, scalar zf);
    /// build left-handed off-center orthogonal projection matrix
    static matrix44 orthooffcenterlh(scalar l, scalar r, scalar b, scalar t, scalar zn, scalar zf);
    /// build right-handed off-center orthogonal projection matrix
    static matrix44 orthooffcenterrh(scalar l, scalar r, scalar b, scalar t, scalar zn, scalar zf);
    /// build left-handed perspective projection matrix based on field-of-view
    static matrix44 perspfovlh(scalar fovy, scalar aspect, scalar zn, scalar zf);
    /// build right-handed perspective projection matrix based on field-of-view
    static matrix44 perspfovrh(scalar fovy, scalar aspect, scalar zn, scalar zf);
    /// build left-handed perspective projection matrix
    static matrix44 persplh(scalar w, scalar h, scalar zn, scalar zf);
    /// build right-handed perspective projection matrix
    static matrix44 persprh(scalar w, scalar h, scalar zn, scalar zf);
    /// build left-handed off-center perspective projection matrix
    static matrix44 perspoffcenterlh(scalar l, scalar r, scalar b, scalar t, scalar zn, scalar zf);
    /// build right-handed off-center perspective projection matrix
    static matrix44 perspoffcenterrh(scalar l, scalar r, scalar b, scalar t, scalar zn, scalar zf);
    /// build matrix that reflects coordinates about a plance
    static matrix44 reflect(const plane& p);
    /// build rotation matrix around arbitrary axis
    static matrix44 rotationaxis(float4 const &axis, scalar angle);
    /// build rotation matrix from quaternion
    static matrix44 rotationquaternion(const quaternion& q);
    /// build x-axis-rotation matrix
    static matrix44 rotationx(scalar angle);
    /// build y-axis-rotation matrix
    static matrix44 rotationy(scalar angle);
    /// build z-axis-rotation matrix
    static matrix44 rotationz(scalar angle);
    /// build rotation matrix from yaw, pitch and roll
    //static matrix44 rotationyawpitchroll(scalar yaw, scalar pitch, scalar roll);
    /// build a scaling matrix from components
    static matrix44 scaling(scalar sx, scalar sy, scalar sz);
    /// build a scaling matrix from float4
    static matrix44 scaling(float4 const &s);
    /// build a transformation matrix
    static matrix44 transformation(float4 const &scalingCenter, const quaternion& scalingRotation, float4 const &scaling, float4 const &rotationCenter, const quaternion& rotation, float4 const &translation);
    /// build a translation matrix
    static matrix44 translation(scalar x, scalar y, scalar z);
    /// build a translation matrix from point
    static matrix44 translation(float4 const &t);
    /// return the transpose of a matrix
    static matrix44 transpose(const matrix44& m);
    /// transform 4d vector by matrix44, faster inline version than float4::transform
    static float4 transform(const float4 &v, const matrix44 &m);
    /// return a quaternion from rotational part of the 4x4 matrix
    static quaternion rotationmatrix(const matrix44& m);
    /// transform a plane with a matrix
    static plane transform(const plane& p, const matrix44& m);
    /// check if point lies inside matrix frustum
    static bool ispointinside(const float4& p, const matrix44& m);
    /// convert to any type
    template<typename T> T as() const;
    
    // TODO: does this need to be private
    glm::mat4x4 mx;

private:
    friend class float4;
    //friend class plane;
    //friend class quaternion;

};

//------------------------------------------------------------------------------
/**
*/
__forceinline
matrix44::matrix44():
    mx(glm::mat4(1.0f))
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
__forceinline
matrix44::matrix44(float4 const &row0, float4 const &row1, float4 const &row2, float4 const &row3)
{
    this->set(row0, row1, row2, row3);
}

//------------------------------------------------------------------------------
/**
*/
/*
__forceinline
matrix44::matrix44(const matrix44& rhs) :
    mx(rhs.mx)
{
    // empty
}
*/

//------------------------------------------------------------------------------
/**
*/
__forceinline
matrix44::matrix44(const glm::mat4& rhs) :
    mx(rhs)
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
matrix44::operator=(const matrix44& rhs)
{
    this->mx = rhs.mx;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
matrix44::operator=(const glm::mat4& rhs)
{
    this->mx = rhs;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
matrix44::operator==(const matrix44& rhs) const
{
    return this->mx == rhs.mx;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
matrix44::operator!=(const matrix44& rhs) const
{
    return this->mx != rhs.mx;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
matrix44::set(float4 const &row0, float4 const &row1, float4 const &row2, float4 const &row3)
{
    this->mx[0] = row0.vec;
    this->mx[1] = row1.vec;
    this->mx[2] = row2.vec;
    this->mx[3] = row3.vec;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
matrix44::setrow0(float4 const &r)
{
    this->mx[0] = r.vec;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline const float4&
matrix44::getrow0() const
{
    return *(float4*)&(this->mx[0]);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
matrix44::setrow1(float4 const &r)
{
    this->mx[1] = r.vec;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline const float4&
matrix44::getrow1() const
{
    return *(float4*)&(this->mx[1]);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
matrix44::setrow2(float4 const &r)
{
    this->mx[2] = r.vec;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline const float4&
matrix44::getrow2() const
{
    return *(float4*)&(this->mx[2]);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
matrix44::setrow3(float4 const &r)
{
    this->mx[3] = r.vec;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline const float4&
matrix44::getrow3() const
{
    return *(float4*)&(this->mx[3]);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
matrix44::set_xaxis(float4 const &x)
{
    this->mx[0] = x.vec;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
matrix44::set_yaxis(float4 const &y)
{
    this->mx[1] = y.vec;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
matrix44::set_zaxis(float4 const &z)
{
    this->mx[2] = z.vec;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
matrix44::set_position(float4 const &pos)
{
    this->mx[3] = pos.vec;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline const float4&
matrix44::get_xaxis() const
{
    return *(float4*)&(this->mx[0]);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline const float4&
matrix44::get_yaxis() const
{
    return *(float4*)&(this->mx[1]);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline const float4&
matrix44::get_zaxis() const
{
    return *(float4*)&(this->mx[2]);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline const float4&
matrix44::get_position() const
{
    return *(float4*)&(this->mx[3]);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline
void 
matrix44::translate(float4 const &t)
{
    #if _DEBUG
    n_assert2(t.w() == 0, "w component not 0, use vector for translation not a point!");
    #endif
    this->mx[3] += t.vec;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline void
matrix44::scale(float4 const &s) 
{    
    // need to make sure that last column isn't erased
    float4 scl = s;
    scl.set_w(1.0f);

    this->mx[0] = float4::multiply(this->mx[0], scl).vec;
    this->mx[1] = float4::multiply(this->mx[1], scl).vec;
    this->mx[2] = float4::multiply(this->mx[2], scl).vec;
    this->mx[3] = float4::multiply(this->mx[3], scl).vec;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline bool
matrix44::isidentity() const
{
    return glm::isIdentity(this->mx, 0.00001f);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline scalar
matrix44::determinant() const
{
    return glm::determinant(this->mx);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::identity()
{
    return matrix44(glm::mat4(1.0f));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::inverse(const matrix44& m)
{
    return matrix44(glm::inverse(m.mx));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::lookatlh(float4 const &eye, float4 const &at, float4 const &up)
{
#if NEBULA3_DEBUG
    n_assert(up.length() > 0);
#endif
    return matrix44(glm::lookAt(glm::vec3(eye.vec), glm::vec3(at.vec), glm::vec3(up.vec)));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::lookatrh(float4 const &eye, float4 const &at, float4 const &up)
{
#if NEBULA3_DEBUG
    n_assert(up.length() > 0);
#endif
    return matrix44(glm::lookAt(glm::vec3(eye.vec), glm::vec3(at.vec), glm::vec3(up.vec)));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::multiply(const matrix44& m0, const matrix44& m1)
{
    return m0.mx * m1.mx;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::ortholh(scalar w, scalar h, scalar zn, scalar zf)
{
    return glm::ortho(w, h, zn, zf);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::orthorh(scalar w, scalar h, scalar zn, scalar zf)
{
    return glm::ortho(w, h, zn, zf);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::orthooffcenterlh(scalar l, scalar r, scalar b, scalar t, scalar zn, scalar zf)
{
    return glm::ortho(l, r, b, t, zn, zf);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::orthooffcenterrh(scalar l, scalar r, scalar b, scalar t, scalar zn, scalar zf)
{
    return glm::ortho(l, r, b, t, zn, zf);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::perspfovlh(scalar fovy, scalar aspect, scalar zn, scalar zf)
{
    return glm::perspective(fovy, aspect, zn, zf);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::perspfovrh(scalar fovy, scalar aspect, scalar zn, scalar zf)
{
    return glm::perspective(fovy, aspect, zn, zf);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::persplh(scalar w, scalar h, scalar zn, scalar zf)
{
    // @todo: implement
    return glm::perspectiveFov(45.0f, w, h, zn, zf);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::persprh(scalar w, scalar h, scalar zn, scalar zf)
{
    // @todo: implement
    return glm::perspectiveFov(45.0f, w, h, zn, zf);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::perspoffcenterlh(scalar l, scalar r, scalar b, scalar t, scalar zn, scalar zf)
{
    return glm::frustum(l, r, b, t, zn, zf);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::perspoffcenterrh(scalar l, scalar r, scalar b, scalar t, scalar zn, scalar zf)
{
    return glm::frustum(l, r, b, t, zn, zf);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::rotationaxis(float4 const &axis, scalar angle)
{
    return glm::rotate(glm::mat4(1.0f), angle, glm::vec3(axis.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::rotationx(scalar angle)
{
    return matrix44::rotationaxis(float4(1.0f, 0.0f, 0.0f, 0.0f), angle);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::rotationy(scalar angle)
{
    return matrix44::rotationaxis(float4(0.0f, 1.0f, 0.0f, 0.0f), angle);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::rotationz(scalar angle)
{
    return matrix44::rotationaxis(float4(0.0f, 0.0f, 1.0f, 0.0f), angle);
}

//------------------------------------------------------------------------------
/**
*/
/*__forceinline matrix44
matrix44::rotationyawpitchroll(scalar yaw, scalar pitch, scalar roll)
{
    return matrix44::rotationaxis(float4(pitch, yaw, roll, 0.0f));
}
*/

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::scaling(scalar sx, scalar sy, scalar sz)
{
    return glm::scale(glm::mat4(1.0f), glm::vec3(sx, sy, sz));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::scaling(float4 const &s)
{
    return glm::mat4();//glm::scale(glm::vec3(s.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::translation(scalar x, scalar y, scalar z)
{
    return glm::translate(x, y, z);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::translation(float4 const &t)
{
    return glm::translate(glm::vec3(t.vec));
}

//------------------------------------------------------------------------------
/**
*/
__forceinline matrix44
matrix44::transpose(const matrix44& m)
{
    return transpose(m.mx);
}

//------------------------------------------------------------------------------
/**
*/
__forceinline
float4
matrix44::transform(const float4 &v, const matrix44 &m)
{
    return m.mx * v.vec;
}

//------------------------------------------------------------------------------
/**
*/
__forceinline
quaternion
matrix44::rotationmatrix(const matrix44& m)
{
    n_error("matrix44::rotationmatrix: IMPLEMENT ME!");
    return quaternion();
}


//------------------------------------------------------------------------------
/**
*/
__forceinline
plane
matrix44::transform(const plane &p, const matrix44& m)
{
    n_error("matrix44::transform: IMPLEMENT ME!");
    return plane();
}

} // namespace Math
//------------------------------------------------------------------------------

