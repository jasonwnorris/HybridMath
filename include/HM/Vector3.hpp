// Vector3.hpp

#ifndef __HM_VECTOR3_HPP__
#define __HM_VECTOR3_HPP__

// HM Includes
#include <HM/Vector2.hpp>

namespace HM
{
  class Vector3
  {
    public:
      static const Vector3 Up;
      static const Vector3 Down;
      static const Vector3 Left;
      static const Vector3 Right;
      static const Vector3 Forward;
      static const Vector3 Backward;
      static const Vector3 Zero;
      static const Vector3 One;

      float X;
      float Y;
      float Z;

      Vector3();
      Vector3(float p_X, float p_Y, float p_Z);
      Vector3(int p_X, int p_Y, int p_Z);
      Vector3(const Vector2& p_XY, float p_Z);
      Vector3(const Vector2& p_XY, int p_Z);

      float Length() const;
      float LengthSquared() const;
      float Dot(const Vector3& p_Other);
      const Vector3& Normalize();
      const Vector3 Cross(const Vector3& p_Other);

      void operator()(const float p_X, const float p_Y, const float p_Z);
      bool operator==(const Vector3& p_Other) const;
      bool operator!=(const Vector3& p_Other) const;
      Vector3& operator=(const Vector3& p_Other);
      Vector3 operator-() const;
      Vector3 operator-(const Vector3& p_Other) const;
      Vector3 operator+(const Vector3& p_Other) const;
      Vector3 operator*(float p_Scalar) const;
      Vector3 operator/(float p_Scalar) const;
      Vector3& operator+=(const Vector3& p_Other);
      Vector3& operator-=(const Vector3& p_Other);
      Vector3& operator*=(float p_Scalar);
      Vector3& operator/=(float p_Scalar);

      static float Dot(const Vector3& p_VectorA, const Vector3& p_VectorB);
      static const Vector3 Cross(const Vector3& p_VectorA, const Vector3& p_VectorB);
      static float Distance(const Vector3& p_VectorA, const Vector3& p_VectorB);
  };
}

#endif
