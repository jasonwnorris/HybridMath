// Math.hpp

#ifndef __HM_MATH_HPP__
#define __HM_MATH_HPP__

namespace HM
{
  class Math
  {
    public:
      static float Pi;
      static float TwoPi;
      static float PiOver2;
      static float PiOver4;
      static float E;
      static float Epsilon;

      static int Min(int p_ValueA, int p_ValueB);
      static float Min(float p_ValueA, float p_ValueB);
      static double Min(double p_ValueA, double p_ValueB);

      static int Max(int p_ValueA, int p_ValueB);
      static float Max(float p_ValueA, float p_ValueB);
      static double Max(double p_ValueA, double p_ValueB);

      static int Abs(int p_Value);
      static float Abs(float p_Value);
      static double Abs(double p_Value);

      static int SignOf(int p_Value);
      static float SignOf(float p_Value);
      static double SignOf(double p_Value);

      static float Sqrt(float p_Value);
      static double Sqrt(double p_Value);

      static float Lerp(float p_ValueA, float p_ValueB, float p_Amount);
      static double Lerp(double p_ValueA, double p_ValueB, double p_Amount);

      static float Clamp(float p_Value, float p_Minimum, float p_Maximum);
      static double Clamp(double p_Value, double p_Minimum, double p_Maximum);

      static float ToRadians(float p_Degrees);
      static float ToDegrees(float p_Radians);

      static bool IsPowerOfTwo(int p_Number);
      static int NextPowerOfTwo(int p_Number);

      static float Cos(float p_Angle);
      static float Sin(float p_Angle);
      static float Tan(float p_Angle);
      static float Acos(float p_Angle);
      static float Asin(float p_Angle);
      static float Atan(float p_Angle);
      static float Atan2(float p_Y, float p_X);
  };
}

#endif
