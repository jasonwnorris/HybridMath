// Rectangle.hpp

#ifndef __HM_RECTANGLE_HPP__
#define __HM_RECTANGLE_HPP__

namespace HM
{
  template<typename T> class Rectangle
  {
    public:
      static const Rectangle<T> Empty;

      Rectangle();
      Rectangle(T p_X, T p_Y, T p_Width, T p_Height);
      ~Rectangle();

      bool operator==(const Rectangle<T>& p_Other) const;
      bool operator!=(const Rectangle<T>& p_Other) const;

    public:
      T X;
      T Y;
      T Width;
      T Height;
  };

  using Rectanglei = Rectangle<int>;
  using Recntagleu = Rectangle<unsigned int>();
  using Rectanglef = Rectangle<float>;
  using Rectangled = Rectangle<double>;
}

// Template Definition Include
#include <HM/Rectangle.tpp>

#endif
