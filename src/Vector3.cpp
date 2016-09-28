// Vector3.cpp

// HM Includes
#include <HM/Math.hpp>
#include <HM/Vector3.hpp>

namespace HM
{
  const Vector3 Vector3::Up = Vector3(0.0f, 1.0f, 0.0f);
  const Vector3 Vector3::Down = Vector3(0.0f, -1.0f, 0.0f);
  const Vector3 Vector3::Left = Vector3(-1.0f, 0.0f, 0.0f);
  const Vector3 Vector3::Right = Vector3(1.0f, 0.0f, 0.0f);
  const Vector3 Vector3::Forward = Vector3(0.0f, 0.0f, -1.0f);
  const Vector3 Vector3::Backward = Vector3(0.0f, 0.0f, 1.0f);
  const Vector3 Vector3::Zero = Vector3(0.0f, 0.0f, 0.0f);
  const Vector3 Vector3::One = Vector3(1.0f, 1.0f, 1.0f);

  Vector3::Vector3()
  {
    X = 0.0f;
    Y = 0.0f;
    Z = 0.0f;
  }

  Vector3::Vector3(float p_X, float p_Y, float p_Z)
  {
    X = p_X;
    Y = p_Y;
    Z = p_Z;
  }

  Vector3::Vector3(int p_X, int p_Y, int p_Z)
  {
    X = static_cast<float>(p_X);
    Y = static_cast<float>(p_Y);
    Z = static_cast<float>(p_Z);
  }

  Vector3::Vector3(const Vector2& p_XY, float p_Z)
  {
    X = p_XY.X;
    Y = p_XY.Y;
    Z = p_Z;
  }

  Vector3::Vector3(const Vector2& p_XY, int p_Z)
  {
    X = static_cast<float>(p_XY.X);
    Y = static_cast<float>(p_XY.Y);
    Z = static_cast<float>(p_Z);
  }

  float Vector3::Length() const
  {
    return Math::Sqrt(LengthSquared());
  }

  float Vector3::LengthSquared() const
  {
    return X * X + Y * Y + Z * Z;
  }

  float Vector3::Dot(const Vector3& p_Other)
  {
    return X * p_Other.X + Y * p_Other.Y + Z * p_Other.Z;
  }

  const Vector3& Vector3::Normalize()
  {
    float n = Length();
    if (n != 0.0f)
    {
      X /= n;
      Y /= n;
      Z /= n;
    }

    return *this;
  }

  const Vector3 Vector3::Cross(const Vector3& p_Other)
  {
    return Vector3(Y * p_Other.Z - Z * p_Other.Y,
                   Z * p_Other.X - X * p_Other.Z,
                   X * p_Other.Y - Y * p_Other.X);
  }

  void Vector3::operator()(const float p_X, const float p_Y, const float p_Z)
  {
    X = p_X;
    Y = p_Y;
    Z = p_Z;
  }

  bool Vector3::operator==(const Vector3& p_Other) const
  {
    return X == p_Other.X && Y == p_Other.Y && Z == p_Other.Z;
  }

  bool Vector3::operator!=(const Vector3& p_Other) const
  {
    return X != p_Other.X || Y != p_Other.Y || Z != p_Other.Z;
  }

  Vector3& Vector3::operator=(const Vector3& p_Other)
  {
    X = p_Other.X;
    Y = p_Other.Y;
    Z = p_Other.Z;

    return *this;
  }

  Vector3 Vector3::operator-() const
  {
    return Vector3(-X, -Y, -Z);
  }

  Vector3 Vector3::operator-(const Vector3& p_Other) const
  {
    return Vector3(X - p_Other.X, Y - p_Other.Y, Z - p_Other.Z);
  }

  Vector3 Vector3::operator+(const Vector3& p_Other) const
  {
    return Vector3(X + p_Other.X, Y + p_Other.Y, Z + p_Other.Z);
  }

  Vector3 Vector3::operator*(float p_Scalar) const
  {
    return Vector3(X * p_Scalar, Y * p_Scalar, Z * p_Scalar);
  }

  Vector3 Vector3::operator/(float p_Scalar) const
  {
    return Vector3(X / p_Scalar, Y / p_Scalar, Z / p_Scalar);
  }

  Vector3& Vector3::operator+=(const Vector3& p_Other)
  {
    X += p_Other.X;
    Y += p_Other.Y;
    Z += p_Other.Z;

    return *this;
  }

  Vector3& Vector3::operator-=(const Vector3& p_Other)
  {
    X -= p_Other.X;
    Y -= p_Other.Y;
    Z -= p_Other.Z;

    return *this;
  }

  Vector3& Vector3::operator*=(float p_Scalar)
  {
    X *= p_Scalar;
    Y *= p_Scalar;
    Z *= p_Scalar;

    return *this;
  }

  Vector3& Vector3::operator/=(float p_Scalar)
  {
    X /= p_Scalar;
    Y /= p_Scalar;
    Z /= p_Scalar;

    return *this;
  }

  // static
  float Vector3::Dot(const Vector3& p_VectorA, const Vector3& p_VectorB)
  {
    return p_VectorA.X * p_VectorB.X + p_VectorA.Y * p_VectorB.Y + p_VectorA.Z * p_VectorB.Z;
  }

  // static
  const Vector3 Vector3::Cross(const Vector3& p_VectorA, const Vector3& p_VectorB)
  {
    return Vector3(p_VectorA.Y * p_VectorB.Z - p_VectorA.Z * p_VectorB.Y,
                   p_VectorA.Z * p_VectorB.X - p_VectorA.X * p_VectorB.Z,
                   p_VectorA.X * p_VectorB.Y - p_VectorA.Y * p_VectorB.X);
  }

  // static
  float Vector3::Distance(const Vector3& p_VectorA, const Vector3& p_VectorB)
  {
    return (p_VectorA - p_VectorB).Length();
  }
}
