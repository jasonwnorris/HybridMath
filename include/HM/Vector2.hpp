// Vector2.hpp

#ifndef __HM_VECTOR2_HPP__
#define __HM_VECTOR2_HPP__

namespace HM
{
  template<typename T> class Vector2
  {
    public:
      static const Vector2<T> Up;
      static const Vector2<T> Down;
      static const Vector2<T> Left;
      static const Vector2<T> Right;
      static const Vector2<T> Zero;
      static const Vector2<T> One;

      Vector2();
      Vector2(T p_X, T p_Y);
      ~Vector2();

      T Length() const;
      T LengthSquared() const;
      T Dot(const Vector2<T>& p_Other);
      const Vector2<T>& Normalize();

      void operator()(const T p_X, const T p_Y);
      bool operator==(const Vector2<T>& p_Other) const;
      bool operator!=(const Vector2<T>& p_Other) const;
      Vector2<T>& operator=(const Vector2<T>& p_Other);
      Vector2<T> operator-() const;
      Vector2<T> operator-(const Vector2<T>& p_Other) const;
      Vector2<T> operator+(const Vector2<T>& p_Other) const;
      Vector2<T> operator*(T p_Scalar) const;
      Vector2<T> operator/(T p_Scalar) const;
      Vector2<T>& operator+=(const Vector2<T>& p_Other);
      Vector2<T>& operator-=(const Vector2<T>& p_Other);
      Vector2<T>& operator*=(T p_Scalar);
      Vector2<T>& operator/=(T p_Scalar);

      static T Dot(const Vector2<T>& p_VectorA, const Vector2<T>& p_VectorB);
      static T Distance(const Vector2<T>& p_VectorA, const Vector2<T>& p_VectorB);

    public:
      T X;
      T Y;
  };

  using Vector2i = Vector2<int>;
  using Vector2u = Vector2<unsigned int>();
  using Vector2f = Vector2<float>;
  using Vector2d = Vector2<double>;
}

// Template Definition Include
#include <HM/Vector2.tpp>

#endif
