// Vector2.cpp

// HM Includes
#include <HM/Math.hpp>
#include <HM/Vector2.hpp>

namespace HM
{
  const Vector2 Vector2::Up = Vector2(0.0f, 1.0f);
  const Vector2 Vector2::Down = Vector2(0.0f, -1.0f);
  const Vector2 Vector2::Left = Vector2(-1.0f, 0.0f);
  const Vector2 Vector2::Right = Vector2(1.0f, 0.0f);
  const Vector2 Vector2::Zero = Vector2(0.0f, 0.0f);
  const Vector2 Vector2::One = Vector2(1.0f, 1.0f);

  Vector2::Vector2()
  {
    X = 0.0f;
    Y = 0.0f;
  }

  Vector2::Vector2(float p_X, float p_Y)
  {
    X = p_X;
    Y = p_Y;
  }

  Vector2::Vector2(int p_X, int p_Y)
  {
    X = static_cast<float>(p_X);
    Y = static_cast<float>(p_Y);
  }

  float Vector2::Length() const
  {
    return Math::Sqrt(LengthSquared());
  }

  float Vector2::LengthSquared() const
  {
    return X * X + Y * Y;
  }

  float Vector2::Dot(const Vector2& p_Other)
  {
    return X * p_Other.X + Y * p_Other.Y;
  }

  const Vector2& Vector2::Normalize()
  {
    float n = Length();
    if (n != 0.0f)
    {
      X /= n;
      Y /= n;
    }

    return *this;
  }

  void Vector2::operator()(const float p_X, const float p_Y)
  {
    X = p_X;
    Y = p_Y;
  }

  bool Vector2::operator==(const Vector2& p_Other) const
  {
    return X == p_Other.X && Y == p_Other.Y;
  }

  bool Vector2::operator!=(const Vector2& p_Other) const
  {
    return X != p_Other.X || Y != p_Other.Y;
  }

  Vector2& Vector2::operator=(const Vector2& p_Other)
  {
    X = p_Other.X;
    Y = p_Other.Y;

    return *this;
  }

  Vector2 Vector2::operator-() const
  {
    return Vector2(-X, -Y);
  }

  Vector2 Vector2::operator-(const Vector2& p_Other) const
  {
    return Vector2(X - p_Other.X, Y - p_Other.Y);
  }

  Vector2 Vector2::operator+(const Vector2& p_Other) const
  {
    return Vector2(X + p_Other.X, Y + p_Other.Y);
  }

  Vector2 Vector2::operator*(float p_Scalar) const
  {
    return Vector2(X * p_Scalar, Y * p_Scalar);
  }

  Vector2 Vector2::operator/(float p_Scalar) const
  {
    return Vector2(X / p_Scalar, Y / p_Scalar);
  }

  Vector2& Vector2::operator+=(const Vector2& p_Other)
  {
    X += p_Other.X;
    Y += p_Other.Y;

    return *this;
  }

  Vector2& Vector2::operator-=(const Vector2& p_Other)
  {
    X -= p_Other.X;
    Y -= p_Other.Y;

    return *this;
  }

  Vector2& Vector2::operator*=(float p_Scalar)
  {
    X *= p_Scalar;
    Y *= p_Scalar;

    return *this;
  }

  Vector2& Vector2::operator/=(float p_Scalar)
  {
    X /= p_Scalar;
    Y /= p_Scalar;

    return *this;
  }

  // static
  float Vector2::Length(const Vector2& p_Vector)
  {
    return p_Vector.Length();
  }

  // static
  float Vector2::LengthSquared(const Vector2& p_Vector)
  {
    return p_Vector.LengthSquared();
  }

  // static
  float Vector2::Dot(const Vector2& p_VectorA, const Vector2& p_VectorB)
  {
    return p_VectorA.X * p_VectorB.X + p_VectorA.Y * p_VectorB.Y;
  }

  // static
  float Vector2::Distance(const Vector2& p_VectorA, const Vector2& p_VectorB)
  {
    return (p_VectorA - p_VectorB).Length();
  }
}
