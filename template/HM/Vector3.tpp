// Vector3.cpp

// HM Includes
#include <HM/Math.hpp>
#include <HM/Vector3.hpp>

#ifdef __HM_VECTOR3_HPP__

namespace HM
{
  template<typename T> const Vector3<T> Vector3<T>::Up = Vector3<T>(0, 1, 0);
  template<typename T> const Vector3<T> Vector3<T>::Down = Vector3<T>(0, -1, 0);
  template<typename T> const Vector3<T> Vector3<T>::Left = Vector3<T>(-1, 0, 0);
  template<typename T> const Vector3<T> Vector3<T>::Right = Vector3<T>(1, 0, 0);
  template<typename T> const Vector3<T> Vector3<T>::Forward = Vector3<T>(0, 0, -1);
  template<typename T> const Vector3<T> Vector3<T>::Backward = Vector3<T>(0, 0, 1);
  template<typename T> const Vector3<T> Vector3<T>::Zero = Vector3<T>(0, 0, 0);
  template<typename T> const Vector3<T> Vector3<T>::One = Vector3<T>(1, 1, 1);

  template<typename T> Vector3<T>::Vector3()
  {
    X = static_cast<T>(0);
    Y = static_cast<T>(0);
    Z = static_cast<T>(0);
  }

  template<typename T> Vector3<T>::Vector3(T p_X, T p_Y, T p_Z)
  {
    X = p_X;
    Y = p_Y;
    Z = p_Z;
  }

  template<typename T> Vector3<T>::Vector3(const Vector2<T>& p_Vector2, T p_Z)
  {
    X = p_Vector2.X;
    Y = p_Vector2.Y;
    Z = p_Z;
  }

  template<typename T> Vector3<T>::~Vector3() { }

  template<typename T> T Vector3<T>::Length() const
  {
    return Math::Sqrt(LengthSquared());
  }

  template<typename T> T Vector3<T>::LengthSquared() const
  {
    return X * X + Y * Y + Z * Z;
  }

  template<typename T> T Vector3<T>::Dot(const Vector3<T>& p_Other)
  {
    return X * p_Other.X + Y * p_Other.Y + Z * p_Other.Z;
  }

  template<typename T> const Vector3<T>& Vector3<T>::Normalize()
  {
    T n = Length();
    if (n != static_cast<T>(0))
    {
      X /= n;
      Y /= n;
      Z /= n;
    }

    return *this;
  }

  template<typename T> const Vector3<T> Vector3<T>::Cross(const Vector3<T>& p_Other)
  {
    return Vector3(Y * p_Other.Z - Z * p_Other.Y,
                   Z * p_Other.X - X * p_Other.Z,
                   X * p_Other.Y - Y * p_Other.X);
  }

  template<typename T> void Vector3<T>::operator()(const T p_X, const T p_Y, const T p_Z)
  {
    X = p_X;
    Y = p_Y;
    Z = p_Z;
  }

  template<typename T> void Vector3<T>::operator()(const Vector2<T>& p_Vector2, const T p_Z)
  {
    X = p_Vector2.X;
    Y = p_Vector2.Y;
    Z = p_Z;
  }

  template<typename T> bool Vector3<T>::operator==(const Vector3<T>& p_Other) const
  {
    return X == p_Other.X && Y == p_Other.Y && Z == p_Other.Z;
  }

  template<typename T> bool Vector3<T>::operator!=(const Vector3<T>& p_Other) const
  {
    return X != p_Other.X || Y != p_Other.Y || Z != p_Other.Z;
  }

  template<typename T> Vector3<T>& Vector3<T>::operator=(const Vector3<T>& p_Other)
  {
    X = p_Other.X;
    Y = p_Other.Y;
    Z = p_Other.Z;

    return *this;
  }

  template<typename T> Vector3<T> Vector3<T>::operator-() const
  {
    return Vector3(-X, -Y, -Z);
  }

  template<typename T> Vector3<T> Vector3<T>::operator-(const Vector3<T>& p_Other) const
  {
    return Vector3(X - p_Other.X, Y - p_Other.Y, Z - p_Other.Z);
  }

  template<typename T> Vector3<T> Vector3<T>::operator+(const Vector3<T>& p_Other) const
  {
    return Vector3(X + p_Other.X, Y + p_Other.Y, Z + p_Other.Z);
  }

  template<typename T> Vector3<T> Vector3<T>::operator*(T p_Scalar) const
  {
    return Vector3(X * p_Scalar, Y * p_Scalar, Z * p_Scalar);
  }

  template<typename T> Vector3<T> Vector3<T>::operator/(T p_Scalar) const
  {
    return Vector3(X / p_Scalar, Y / p_Scalar, Z / p_Scalar);
  }

  template<typename T> Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& p_Other)
  {
    X += p_Other.X;
    Y += p_Other.Y;
    Z += p_Other.Z;

    return *this;
  }

  template<typename T> Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& p_Other)
  {
    X -= p_Other.X;
    Y -= p_Other.Y;
    Z -= p_Other.Z;

    return *this;
  }

  template<typename T> Vector3<T>& Vector3<T>::operator*=(T p_Scalar)
  {
    X *= p_Scalar;
    Y *= p_Scalar;
    Z *= p_Scalar;

    return *this;
  }

  template<typename T> Vector3<T>& Vector3<T>::operator/=(T p_Scalar)
  {
    X /= p_Scalar;
    Y /= p_Scalar;
    Z /= p_Scalar;

    return *this;
  }

  // static
  template<typename T> T Vector3<T>::Dot(const Vector3<T>& p_VectorA, const Vector3<T>& p_VectorB)
  {
    return p_VectorA.X * p_VectorB.X + p_VectorA.Y * p_VectorB.Y + p_VectorA.Z * p_VectorB.Z;
  }

  // static
  template<typename T> const Vector3<T> Vector3<T>::Cross(const Vector3<T>& p_VectorA, const Vector3<T>& p_VectorB)
  {
    return Vector3(p_VectorA.Y * p_VectorB.Z - p_VectorA.Z * p_VectorB.Y,
                   p_VectorA.Z * p_VectorB.X - p_VectorA.X * p_VectorB.Z,
                   p_VectorA.X * p_VectorB.Y - p_VectorA.Y * p_VectorB.X);
  }

  // static
  template<typename T> T Vector3<T>::Distance(const Vector3<T>& p_VectorA, const Vector3<T>& p_VectorB)
  {
    return (p_VectorA - p_VectorB).Length();
  }
}

#endif
