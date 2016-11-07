// Math.cpp

// HM Includes
#include <HM/Math.hpp>
// STD Includes
#include <math.h>
#include <cstdlib>

namespace HM
{
  float Math::Pi = 3.14159265f;
  float Math::TwoPi = Pi * 2.0f;
  float Math::PiOver2 = Pi / 2.0f;
  float Math::PiOver4 = Pi / 4.0f;
  float Math::E = 2.71828183f;
  float Math::Epsilon = 0.001f;

  int Math::Min(int p_ValueA, int p_ValueB)
  {
    return (p_ValueA < p_ValueB) ? p_ValueA : p_ValueB;
  }

  float Math::Min(float p_ValueA, float p_ValueB)
  {
    return (p_ValueA < p_ValueB) ? p_ValueA : p_ValueB;
  }

  double Math::Min(double p_ValueA, double p_ValueB)
  {
    return (p_ValueA < p_ValueB) ? p_ValueA : p_ValueB;
  }

  int Math::Max(int p_ValueA, int p_ValueB)
  {
    return (p_ValueA > p_ValueB) ? p_ValueA : p_ValueB;
  }

  float Math::Max(float p_ValueA, float p_ValueB)
  {
    return (p_ValueA > p_ValueB) ? p_ValueA : p_ValueB;
  }

  double Math::Max(double p_ValueA, double p_ValueB)
  {
    return (p_ValueA > p_ValueB) ? p_ValueA : p_ValueB;
  }

  int Math::Abs(int p_Value)
  {
    return (p_Value < 0) ? -p_Value : p_Value;
  }

  float Math::Abs(float p_Value)
  {
    return (p_Value < 0.0f) ? -p_Value : p_Value;
  }

  double Math::Abs(double p_Value)
  {
    return (p_Value < 0.0) ? -p_Value : p_Value;
  }

  int Math::SignOf(int p_Value)
  {
    return p_Value / Abs(p_Value);
  }

  float Math::SignOf(float p_Value)
  {
    return p_Value / Abs(p_Value);
  }

  double Math::SignOf(double p_Value)
  {
    return p_Value / Abs(p_Value);
  }

  float Math::Sqrt(float p_Value)
  {
    return sqrtf(p_Value);
  }

  double Math::Sqrt(double p_Value)
  {
    return sqrt(p_Value);
  }

  float Math::Lerp(float p_ValueA, float p_ValueB, float p_Amount)
  {
    if (p_Amount < 0.0f)
    {
      return p_ValueA;
    }
    if (p_Amount > 1.0f)
    {
      return p_ValueB;
    }

    return p_ValueA + ((p_ValueB - p_ValueA) * p_Amount);
  }

  double Math::Lerp(double p_ValueA, double p_ValueB, double p_Amount)
  {
    if (p_Amount < 0.0)
    {
      return p_ValueA;
    }
    if (p_Amount > 1.0)
    {
      return p_ValueB;
    }

    return p_ValueA + ((p_ValueB - p_ValueA) * p_Amount);
  }

  float Math::Clamp(float p_Value, float p_Minimum, float p_Maximum)
  {
    return (p_Value < p_Minimum) ? p_Minimum : (p_Value > p_Maximum) ? p_Maximum : p_Value;
  }

  double Math::Clamp(double p_Value, double p_Minimum, double p_Maximum)
  {
    return (p_Value < p_Minimum) ? p_Minimum : (p_Value > p_Maximum) ? p_Maximum : p_Value;
  }

  float Math::ToRadians(float p_Degrees)
  {
    return p_Degrees / 180.0f * Pi;
  }

  float Math::ToDegrees(float p_Radians)
  {
    return p_Radians / Pi * 180.0f;
  }

  bool Math::IsPowerOfTwo(int p_Number)
  {
    return (p_Number & (p_Number - 1)) != 0;
  }

  int Math::NextPowerOfTwo(int p_Number)
  {
    if (p_Number <= 0)
    {
      return 1;
    }

    int next = 1;

    while (next < p_Number)
    {
      next *= 2;
    }

    return next;
  }

  float Math::Cos(float p_Angle)
  {
    return cosf(p_Angle);
  }

  float Math::Sin(float p_Angle)
  {
    return sinf(p_Angle);
  }

  float Math::Tan(float p_Angle)
  {
    return tanf(p_Angle);
  }

  float Math::Acos(float p_Angle)
  {
    return acosf(p_Angle);
  }

  float Math::Asin(float p_Angle)
  {
    return asinf(p_Angle);
  }

  float Math::Atan(float p_Angle)
  {
    return atanf(p_Angle);
  }

  float Math::Atan2(float p_Y, float p_X)
  {
    return atan2f(p_Y, p_X);
  }
}
