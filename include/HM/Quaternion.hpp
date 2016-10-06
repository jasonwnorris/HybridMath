// Quaternion.hpp

#ifndef __HM_QUATERNION_HPP__
#define __HM_QUATERNION_HPP__

// HM Includes
#include <HM/Matrix3.hpp>
#include <HM/Matrix4.hpp>

namespace HM
{
  class Quaternion
  {
    public:
      Quaternion();
      Quaternion(float p_Real, float p_I, float p_J, float p_K);
      Quaternion(float p_Real, const Vector3f& p_Imaginary);
      Quaternion(float p_X, float p_Y, float p_Z);
      Quaternion(const Vector3f& p_Angles);

      float GetReal() const;
      Vector3f GetImaginary() const;

      Quaternion& operator=(const Quaternion& p_Other);
      const Quaternion operator+(const Quaternion& p_Other) const;
      const Quaternion operator-(const Quaternion& p_Other) const;
      const Quaternion operator*(const Quaternion& p_Other) const;
      const Quaternion operator/(const Quaternion& p_Other) const;
      const Quaternion operator*(float p_Scale) const;
      const Quaternion operator/(float p_Scale) const;
      const Quaternion operator-() const;
      const Quaternion& operator+=(const Quaternion& p_Other);
      const Quaternion& operator-=(const Quaternion& p_Other);
      const Quaternion& operator*=(float p_Scale);
      const Quaternion& operator/=(float p_Scale);

      float Length() const;
      float LengthSquared() const;

      void Normalize();
      Quaternion Normalized() const;
      void Conjugate();
      void Invert();

      Quaternion Log() const;
      Quaternion Exp() const;

      Matrix3 ToMatrix3() const;
      Matrix4 ToMatrix4() const;
      void ToAxisAngle(Vector3f& p_Axis, float& p_Angle) const;
      Vector3f Rotate(const Vector3f& p_Rotation);
      Vector3f EulerAngles(bool p_Homogenous = true) const;

      static inline float Dot(const Quaternion& p_QuaternionA, const Quaternion& p_QuaternionB);
      static inline Quaternion FromAxisAngle(const Vector3f& p_Axis, float p_Angle);
      static Quaternion Lerp(const Quaternion& p_QuaternionA, const Quaternion& p_QuaternionB, float p_Amount);
      static Quaternion Slerp(const Quaternion& p_QuaternionA, const Quaternion& p_QuaternionB, float p_Amount);
      static Quaternion SlerpNoInvert(const Quaternion& p_QuaternionA, const Quaternion& p_QuaternionB, float p_Amount);
      static Quaternion Squad(const Quaternion& p_Quaternion1, const Quaternion& p_Quaternion2, const Quaternion& p_QuaternionA, const Quaternion& p_QuaternionB, float p_Amount);
      static Quaternion Bezier(const Quaternion& p_Quaternion1, const Quaternion& p_Quaternion2, const Quaternion& p_QuaternionA, const Quaternion& p_QuaternionB, float p_Amount);
      static Quaternion Spline(const Quaternion& p_QuaternionM, const Quaternion& p_QuaternionN, const Quaternion& p_QuaternionP);

    private:
      float m_Real;
      Vector3f m_Imaginary;
  };
}

#endif
