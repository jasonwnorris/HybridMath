// Quaternion.cpp

// HM Includes
#include <HM/Quaternion.hpp>
#include <HM/Math.hpp>
// STL Includes
#include <math.h>

namespace HM
{
  Quaternion::Quaternion()
  {
    m_Real = 0.0f;
    m_Imaginary = Vector3f::Zero;
  }

  Quaternion::Quaternion(float p_Real, float p_I, float p_J, float p_K)
  {
    m_Real = p_Real;
    m_Imaginary = Vector3f(p_I, p_J, p_K);
  }

  Quaternion::Quaternion(float p_Real, const Vector3f& p_Imaginary)
  {
    m_Real = p_Real;
    m_Imaginary = p_Imaginary;
  }

  Quaternion::Quaternion(float p_X, float p_Y, float p_Z)
  {
    float cosHalfX = Math::Cos(p_X * 0.5f);
    float cosHalfY = Math::Cos(p_Y * 0.5f);
    float cosHalfZ = Math::Cos(p_Z * 0.5f);

    float sinHalfX = Math::Sin(p_X * 0.5f);
    float sinHalfY = Math::Sin(p_Y * 0.5f);
    float sinHalfZ = Math::Sin(p_Z * 0.5f);

    m_Real = cosHalfZ * cosHalfY * cosHalfX + sinHalfZ * sinHalfY * sinHalfX;
    m_Imaginary.X = cosHalfZ * cosHalfY * sinHalfX - sinHalfZ * sinHalfY * cosHalfX;
    m_Imaginary.Y = cosHalfZ * sinHalfY * cosHalfX + sinHalfZ * cosHalfY * sinHalfX;
    m_Imaginary.Z = sinHalfZ * cosHalfY * cosHalfX - cosHalfZ * sinHalfY * sinHalfX;
  }

  Quaternion::Quaternion(const Vector3f& p_Angles)
  {
    float cosHalfX = Math::Cos(p_Angles.X * 0.5f);
    float cosHalfY = Math::Cos(p_Angles.Y * 0.5f);
    float cosHalfZ = Math::Cos(p_Angles.Z * 0.5f);

    float sinHalfX = Math::Sin(p_Angles.X * 0.5f);
    float sinHalfY = Math::Sin(p_Angles.Y * 0.5f);
    float sinHalfZ = Math::Sin(p_Angles.Z * 0.5f);

    m_Real = cosHalfZ * cosHalfY * cosHalfX + sinHalfZ * sinHalfY * sinHalfX;
    m_Imaginary.X = cosHalfZ * cosHalfY * sinHalfX - sinHalfZ * sinHalfY * cosHalfX;
    m_Imaginary.Y = cosHalfZ * sinHalfY * cosHalfX + sinHalfZ * cosHalfY * sinHalfX;
    m_Imaginary.Z = sinHalfZ * cosHalfY * cosHalfX - cosHalfZ * sinHalfY * sinHalfX;
  }

  float Quaternion::GetReal() const
  {
    return m_Real;
  }

  Vector3f Quaternion::GetImaginary() const
  {
    return m_Imaginary;
  }

  Quaternion& Quaternion::operator=(const Quaternion& p_Other)
  {
    m_Real = p_Other.GetReal();
    m_Imaginary = p_Other.GetImaginary();

    return *this;
  }

  const Quaternion Quaternion::operator+(const Quaternion& p_Other) const
  {
    return Quaternion(m_Real + p_Other.GetReal(), m_Imaginary + p_Other.GetImaginary());
  }

  const Quaternion Quaternion::operator-(const Quaternion& p_Other) const
  {
    return Quaternion(m_Real - p_Other.GetReal(), m_Imaginary - p_Other.GetImaginary());
  }

  const Quaternion Quaternion::operator*(const Quaternion& p_Other) const
  {
    return Quaternion(m_Real * p_Other.GetReal() - Vector3f::Dot(m_Imaginary, p_Other.GetImaginary()),
                      m_Imaginary.Y * p_Other.GetImaginary().Z - m_Imaginary.Z * p_Other.GetImaginary().Y + m_Real * p_Other.GetImaginary().X + m_Imaginary.X * p_Other.GetReal(),
                      m_Imaginary.Z * p_Other.GetImaginary().X - m_Imaginary.X * p_Other.GetImaginary().Z + m_Real * p_Other.GetImaginary().Y + m_Imaginary.Y * p_Other.GetReal(),
                      m_Imaginary.X * p_Other.GetImaginary().Y - m_Imaginary.Y * p_Other.GetImaginary().X + m_Real * p_Other.GetImaginary().Z + m_Imaginary.Z * p_Other.GetReal());
  }

  const Quaternion Quaternion::operator/(const Quaternion& p_Other) const
  {
    Quaternion temp(p_Other);
    temp.Invert();

    return *this * temp;
  }

  const Quaternion Quaternion::operator*(float p_Scale) const
  {
    return Quaternion(m_Real * p_Scale, m_Imaginary * p_Scale);
  }

  const Quaternion Quaternion::operator/(float p_Scale) const
  {
    return Quaternion(m_Real / p_Scale, m_Imaginary / p_Scale);
  }

  const Quaternion Quaternion::operator-() const
  {
    return Quaternion(-m_Real, -m_Imaginary);
  }

  const Quaternion& Quaternion::operator+=(const Quaternion& p_Other)
  {
    m_Real += p_Other.GetReal();
    m_Imaginary += p_Other.GetImaginary();

    return *this;
  }

  const Quaternion& Quaternion::operator-=(const Quaternion& p_Other)
  {
    m_Real -= p_Other.GetReal();
    m_Imaginary -= p_Other.GetImaginary();

    return *this;
  }

  const Quaternion& Quaternion::operator*=(float p_Scale)
  {
    m_Real *= p_Scale;
    m_Imaginary *= p_Scale;

    return *this;
  }

  const Quaternion& Quaternion::operator/=(float p_Scale)
  {
    m_Real /= p_Scale;
    m_Imaginary /= p_Scale;

    return *this;
  }

  float Quaternion::Length() const
  {
    return Math::Sqrt(LengthSquared());
  }

  float Quaternion::LengthSquared() const
  {
    return m_Real * m_Real + Vector3f::Dot(m_Imaginary, m_Imaginary);
  }

  void Quaternion::Normalize()
  {
    *this /= Length();
  }

  Quaternion Quaternion::Normalized() const
  {
    return *this / Length();
  }

  void Quaternion::Conjugate()
  {
    m_Imaginary = -m_Imaginary;
  }

  void Quaternion::Invert()
  {
    Conjugate();
    *this /= LengthSquared();
  }

  Quaternion Quaternion::Log() const
  {
    float acosR = Math::Acos(m_Real);
    float sinA = Math::Sin(acosR);

    Vector3f ret;

    if (sinA > 0.0f)
    {
      ret.X = acosR * m_Imaginary.X / sinA;
      ret.Y = acosR * m_Imaginary.Y / sinA;
      ret.Z = acosR * m_Imaginary.Z / sinA;
    }

    return Quaternion(0, ret);
  }

  Quaternion Quaternion::Exp() const
  {
    float iLen = m_Imaginary.Length();
    float cosL = Math::Cos(iLen);
    float sinL = Math::Sin(iLen);

    Vector3f ret;

    if (iLen > 0.0f)
    {
      ret.X = sinL * m_Imaginary.X / iLen;
      ret.Y = sinL * m_Imaginary.Y / iLen;
      ret.Z = sinL * m_Imaginary.Z / iLen;
    }

    return Quaternion(cosL, ret);
  }

  Matrix3f Quaternion::ToMatrix3() const
  {
    float m[9] = {
      1.0f - 2.0f * (m_Imaginary.Y * m_Imaginary.Y + m_Imaginary.Z * m_Imaginary.Z),
             2.0f * (m_Imaginary.X * m_Imaginary.Y - m_Real * m_Imaginary.Z),
             2.0f * (m_Imaginary.X * m_Imaginary.Z + m_Real * m_Imaginary.Y),
             2.0f * (m_Imaginary.X * m_Imaginary.Y + m_Real * m_Imaginary.Z),
      1.0f - 2.0f * (m_Imaginary.X * m_Imaginary.X + m_Imaginary.Z * m_Imaginary.Z),
             2.0f * (m_Imaginary.Y * m_Imaginary.Z - m_Real * m_Imaginary.X),
             2.0f * (m_Imaginary.X * m_Imaginary.Z - m_Real * m_Imaginary.Y),
             2.0f * (m_Imaginary.Y * m_Imaginary.Z + m_Real * m_Imaginary.X),
      1.0f - 2.0f * (m_Imaginary.X * m_Imaginary.X + m_Imaginary.Y * m_Imaginary.Y)
    };

    return Matrix3f(m);
  }

  Matrix4 Quaternion::ToMatrix4() const
  {
    float m[16] = {
      m_Real,        -m_Imaginary.X, -m_Imaginary.Y, -m_Imaginary.Z,
      m_Imaginary.X,  m_Real,        -m_Imaginary.Z,  m_Imaginary.Y,
      m_Imaginary.Y,  m_Imaginary.Z,  m_Real,        -m_Imaginary.X,
      m_Imaginary.Z, -m_Imaginary.Y,  m_Imaginary.X,  m_Real
    };

    return Matrix4(m);
  }

  void Quaternion::ToAxisAngle(Vector3f& p_Axis, float& p_Angle) const
  {
    float acosReal = Math::Acos(m_Real);
    float sinInv = 1.0f / Math::Sin(acosReal);

    p_Angle = acosReal * 2.0f;
    p_Axis.X = m_Imaginary.X * sinInv;
    p_Axis.Y = m_Imaginary.Y * sinInv;
    p_Axis.Z = m_Imaginary.Z * sinInv;
  }

  Vector3f Quaternion::Rotate(const Vector3f& p_Rotation)
  {
    Quaternion temp(0.0f, p_Rotation);
    Quaternion conj(*this);
    conj.Conjugate();

    return (*this * temp * conj).m_Imaginary;
  }

  Vector3f Quaternion::EulerAngles(bool p_Homogenous) const
  {
    float sqReal = m_Real * m_Real;
    float sqI = m_Imaginary.X * m_Imaginary.X;
    float sqJ = m_Imaginary.Y * m_Imaginary.Y;
    float sqK = m_Imaginary.Z * m_Imaginary.Z;

    Vector3f euler;

    if (p_Homogenous)
    {
      euler.X = Math::Atan2(2.0f * (m_Imaginary.X * m_Imaginary.Y + m_Imaginary.Z * m_Real), sqI - sqJ - sqK + sqReal);
      euler.Y = Math::Asin(-2.0f * (m_Imaginary.X * m_Imaginary.Z - m_Imaginary.Y * m_Real));
      euler.Z = Math::Atan2(2.0f * (m_Imaginary.Y * m_Imaginary.Z + m_Imaginary.X * m_Real), -sqI - sqJ + sqK + sqReal);
    }
    else
    {
      euler.X = Math::Atan2(2.0f * (m_Imaginary.Z * m_Imaginary.Y + m_Imaginary.X * m_Real), 1.0f - 2.0f * (sqI + sqJ));
      euler.Y = Math::Asin(-2.0f * (m_Imaginary.X * m_Imaginary.Z - m_Imaginary.Y * m_Real));
      euler.Z = Math::Atan2(2.0f * (m_Imaginary.X * m_Imaginary.Y + m_Imaginary.Z * m_Real), 1.0f - 2.0f * (sqJ + sqK));
    }

    return euler;
  }

  // static
  float Quaternion::Dot(const Quaternion& p_QuaternionA, const Quaternion& p_QuaternionB)
  {
    return p_QuaternionA.GetReal() * p_QuaternionB.GetReal() + Vector3f::Dot(p_QuaternionA.GetImaginary(), p_QuaternionB.GetImaginary());
  }

  // static
  Quaternion Quaternion::FromAxisAngle(const Vector3f& p_Axis, float p_Angle)
  {
    return Quaternion(Math::Cos(p_Angle / 2.0f), p_Axis * Math::Sin(p_Angle / 2.0f));
  }

  // static
  Quaternion Quaternion::Lerp(const Quaternion& p_QuaternionA, const Quaternion& p_QuaternionB, float p_Amount)
  {
    Quaternion ret = p_QuaternionA * (1.0f - p_Amount) + p_QuaternionB * p_Amount;
    ret.Normalize();

    return ret;
  }

  // static
  Quaternion Quaternion::Slerp(const Quaternion& p_QuaternionA, const Quaternion& p_QuaternionB, float p_Amount)
  {
    float dot = Quaternion::Dot(p_QuaternionA, p_QuaternionB);

    Quaternion ret;

    if (dot < 0.0f)
    {
      dot = -dot;
      ret = -p_QuaternionB;
    }
    else
    {
      ret = p_QuaternionB;
    }

    if (dot < 0.95f)
    {
      float angle = Math::Acos(dot);

      return (p_QuaternionA * Math::Sin(angle * (1.0f - p_Amount)) + ret * Math::Sin(angle * p_Amount)) / Math::Sin(angle);
    }

    return Quaternion::Lerp(p_QuaternionA, ret, p_Amount);
  }

  // static
  Quaternion Quaternion::SlerpNoInvert(const Quaternion& p_QuaternionA, const Quaternion& p_QuaternionB, float p_Amount)
  {
    float dot = Quaternion::Dot(p_QuaternionA, p_QuaternionB);

    if (dot > -0.95f && dot < 0.95f)
    {
      float angle = Math::Acos(dot);

      return (p_QuaternionA * Math::Sin(angle * (1.0f - p_Amount)) + p_QuaternionB * Math::Sin(angle * p_Amount)) / Math::Sin(angle);
    }

    return Quaternion::Lerp(p_QuaternionA, p_QuaternionB, p_Amount);
  }

  // static
  Quaternion Quaternion::Squad(const Quaternion& p_Quaternion1, const Quaternion& p_Quaternion2, const Quaternion& p_QuaternionA, const Quaternion& p_QuaternionB, float p_Amount)
  {
    Quaternion c = Quaternion::SlerpNoInvert(p_Quaternion1, p_Quaternion2, p_Amount);
    Quaternion d = Quaternion::SlerpNoInvert(p_QuaternionA, p_QuaternionB, p_Amount);

    return Quaternion::SlerpNoInvert(c, d, 2.0f * p_Amount * (1.0f - p_Amount));
  }

  // static
  Quaternion Quaternion::Bezier(const Quaternion& p_Quaternion1, const Quaternion& p_Quaternion2, const Quaternion& p_QuaternionA, const Quaternion& p_QuaternionB, float p_Amount)
  {
    Quaternion q1 = Quaternion::SlerpNoInvert(p_Quaternion1, p_QuaternionA, p_Amount);
    Quaternion q2 = Quaternion::SlerpNoInvert(p_QuaternionA, p_QuaternionB, p_Amount);
    Quaternion q3 = Quaternion::SlerpNoInvert(p_QuaternionB, p_Quaternion2, p_Amount);

    return Quaternion::SlerpNoInvert(Quaternion::SlerpNoInvert(q1, q2, p_Amount), Quaternion::SlerpNoInvert(q2, q3, p_Amount), p_Amount);
  }

  // static
  Quaternion Quaternion::Spline(const Quaternion& p_QuaternionM, const Quaternion& p_QuaternionN, const Quaternion& p_QuaternionP)
  {
    Quaternion q(p_QuaternionN.GetReal(), -p_QuaternionN.GetImaginary());

    return p_QuaternionN * (((q * p_QuaternionM).Log() + (q * p_QuaternionP).Log()) / -4.0f).Exp();
  }
}
