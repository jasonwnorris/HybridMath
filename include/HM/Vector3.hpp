// Vector3.hpp

#ifndef __HM_VECTOR3_HPP__
#define __HM_VECTOR3_HPP__

// HM Includes
#include <HM/Vector2.hpp>

namespace HM
{
  template<typename T> class Vector3
  {
    public:
      static const Vector3<T> Up;
      static const Vector3<T> Down;
      static const Vector3<T> Left;
      static const Vector3<T> Right;
      static const Vector3<T> Forward;
      static const Vector3<T> Backward;
      static const Vector3<T> Zero;
      static const Vector3<T> One;

      Vector3();
      Vector3(T p_X, T p_Y, T p_Z);
      Vector3(const Vector2<T>& p_Vector2, T p_Z);
      ~Vector3();

      T Length() const;
      T LengthSquared() const;
      T Dot(const Vector3<T>& p_Other);
      const Vector3<T>& Normalize();
      const Vector3<T> Cross(const Vector3<T>& p_Other);

      void operator()(const T p_X, const T p_Y, const T p_Z);
      void operator()(const Vector2<T>& p_Vector2, const T p_Z);
      bool operator==(const Vector3<T>& p_Other) const;
      bool operator!=(const Vector3<T>& p_Other) const;
      Vector3<T>& operator=(const Vector3<T>& p_Other);
      Vector3<T> operator-() const;
      Vector3<T> operator-(const Vector3<T>& p_Other) const;
      Vector3<T> operator+(const Vector3<T>& p_Other) const;
      Vector3<T> operator*(T p_Scalar) const;
      Vector3<T> operator/(T p_Scalar) const;
      Vector3<T>& operator+=(const Vector3<T>& p_Other);
      Vector3<T>& operator-=(const Vector3<T>& p_Other);
      Vector3<T>& operator*=(T p_Scalar);
      Vector3<T>& operator/=(T p_Scalar);

      static T Dot(const Vector3<T>& p_VectorA, const Vector3<T>& p_VectorB);
      static const Vector3<T> Cross(const Vector3<T>& p_VectorA, const Vector3<T>& p_VectorB);
      static T Distance(const Vector3<T>& p_VectorA, const Vector3<T>& p_VectorB);

    public:
      T X;
      T Y;
      T Z;
  };

  using Vector3i = Vector3<int>;
  using Vector3u = Vector3<unsigned int>();
  using Vector3f = Vector3<float>;
  using Vector3d = Vector3<double>;
}

// Template Definition Include
#include <HM/Vector3.tpp>

#endif
