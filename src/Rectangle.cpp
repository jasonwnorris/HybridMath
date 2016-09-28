// Rectangle.cpp

// HM Includes
#include <HM/Rectangle.hpp>

namespace HM
{
  const Rectangle Rectangle::Empty = Rectangle(0, 0, 0, 0);

  Rectangle::Rectangle()
  {
    X = 0;
    Y = 0;
    Width = 0;
    Height = 0;
  }

  Rectangle::Rectangle(int p_X, int p_Y, int p_Width, int p_Height)
  {
    X = p_X;
    Y = p_Y;
    Width = p_Width;
    Height = p_Height;
  }

  Rectangle::~Rectangle()
  {
  }

  bool Rectangle::operator==(const Rectangle& p_Other) const
  {
    return X == p_Other.X && Y == p_Other.Y && Width == p_Other.Width && Height == p_Other.Height;
  }

  bool Rectangle::operator!=(const Rectangle& p_Other) const
  {
    return !(*this == p_Other);
  }
}
