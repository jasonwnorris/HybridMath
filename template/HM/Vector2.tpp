// Vector2.cpp

// HM Includes
#include <HM/Math.hpp>
#include <HM/Vector2.hpp>

#ifdef __HM_VECTOR2_HPP__

namespace HM
{
  template<typename T> const Vector2<T> Vector2<T>::Up = Vector2<T>(0, 1);
  template<typename T> const Vector2<T> Vector2<T>::Down = Vector2<T>(0, -1);
  template<typename T> const Vector2<T> Vector2<T>::Left = Vector2<T>(-1, 0);
  template<typename T> const Vector2<T> Vector2<T>::Right = Vector2<T>(1, 0);
  template<typename T> const Vector2<T> Vector2<T>::Zero = Vector2<T>(0, 0);
  template<typename T> const Vector2<T> Vector2<T>::One = Vector2<T>(1, 1);

  template<typename T> Vector2<T>::Vector2()
  {
    X = static_cast<T>(0);
    Y = static_cast<T>(0);
  }

  template<typename T> Vector2<T>::Vector2(T p_X, T p_Y)
  {
    X = p_X;
    Y = p_Y;
  }

  template<typename T> Vector2<T>::~Vector2() { }

  template<typename T> T Vector2<T>::Length() const
  {
    return Math::Sqrt(LengthSquared());
  }

  template<typename T> T Vector2<T>::LengthSquared() const
  {
    return X * X + Y * Y;
  }

  template<typename T> T Vector2<T>::Dot(const Vector2& p_Other)
  {
    return X * p_Other.X + Y * p_Other.Y;
  }

  template<typename T> const Vector2<T>& Vector2<T>::Normalize()
  {
    T n = Length();
    if (n != static_cast<T>(0))
    {
      X /= n;
      Y /= n;
    }

    return *this;
  }

  template<typename T> void Vector2<T>::operator()(const T p_X, const T p_Y)
  {
    X = p_X;
    Y = p_Y;
  }

  template<typename T> bool Vector2<T>::operator==(const Vector2<T>& p_Other) const
  {
    return X == p_Other.X && Y == p_Other.Y;
  }

  template<typename T> bool Vector2<T>::operator!=(const Vector2<T>& p_Other) const
  {
    return X != p_Other.X || Y != p_Other.Y;
  }

  template<typename T> Vector2<T>& Vector2<T>::operator=(const Vector2<T>& p_Other)
  {
    X = p_Other.X;
    Y = p_Other.Y;

    return *this;
  }

  template<typename T> Vector2<T> Vector2<T>::operator-() const
  {
    return Vector2(-X, -Y);
  }

  template<typename T> Vector2<T> Vector2<T>::operator-(const Vector2<T>& p_Other) const
  {
    return Vector2(X - p_Other.X, Y - p_Other.Y);
  }

  template<typename T> Vector2<T> Vector2<T>::operator+(const Vector2<T>& p_Other) const
  {
    return Vector2(X + p_Other.X, Y + p_Other.Y);
  }

  template<typename T> Vector2<T> Vector2<T>::operator*(T p_Scalar) const
  {
    return Vector2(X * p_Scalar, Y * p_Scalar);
  }

  template<typename T> Vector2<T> Vector2<T>::operator/(T p_Scalar) const
  {
    return Vector2(X / p_Scalar, Y / p_Scalar);
  }

  template<typename T> Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& p_Other)
  {
    X += p_Other.X;
    Y += p_Other.Y;

    return *this;
  }

  template<typename T> Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& p_Other)
  {
    X -= p_Other.X;
    Y -= p_Other.Y;

    return *this;
  }

  template<typename T> Vector2<T>& Vector2<T>::operator*=(T p_Scalar)
  {
    X *= p_Scalar;
    Y *= p_Scalar;

    return *this;
  }

  template<typename T> Vector2<T>& Vector2<T>::operator/=(T p_Scalar)
  {
    X /= p_Scalar;
    Y /= p_Scalar;

    return *this;
  }

  // static
  template<typename T> T Vector2<T>::Dot(const Vector2<T>& p_VectorA, const Vector2<T>& p_VectorB)
  {
    return p_VectorA.X * p_VectorB.X + p_VectorA.Y * p_VectorB.Y;
  }

  // static
  template<typename T> T Vector2<T>::Distance(const Vector2<T>& p_VectorA, const Vector2<T>& p_VectorB)
  {
    return (p_VectorA - p_VectorB).Length();
  }
}

#endif
