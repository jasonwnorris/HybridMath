// Rectangle.hpp

#ifndef __HM_RECTANGLE_HPP__
#define __HM_RECTANGLE_HPP__

namespace HM
{
  class Rectangle
  {
    public:
      static const Rectangle Empty;

      Rectangle();
      Rectangle(int p_X, int p_Y, int p_Width, int p_Height);
      ~Rectangle();

      bool operator==(const Rectangle& p_Other) const;
      bool operator!=(const Rectangle& p_Other) const;

      int X;
      int Y;
      int Width;
      int Height;
  };
}

#endif
