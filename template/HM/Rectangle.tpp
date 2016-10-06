// Rectangle.cpp

// HM Includes
#include <HM/Rectangle.hpp>

#ifdef __HM_RECTANGLE_HPP__

namespace HM
{
  template<typename T> const Rectangle<T> Rectangle<T>::Empty = Rectangle<T>();

  template<typename T> Rectangle<T>::Rectangle()
  {
    X = static_cast<T>(0);
    Y = static_cast<T>(0);
    Width = static_cast<T>(0);
    Height = static_cast<T>(0);
  }

  template<typename T> Rectangle<T>::Rectangle(T p_X, T p_Y, T p_Width, T p_Height)
  {
    X = p_X;
    Y = p_Y;
    Width = p_Width;
    Height = p_Height;
  }

  template<typename T> Rectangle<T>::~Rectangle() { }

  template<typename T> bool Rectangle<T>::operator==(const Rectangle<T>& p_Other) const
  {
    return X == p_Other.X &&
           Y == p_Other.Y &&
           Width == p_Other.Width &&
           Height == p_Other.Height;
  }

  template<typename T> bool Rectangle<T>::operator!=(const Rectangle<T>& p_Other) const
  {
    return X != p_Other.X ||
           Y != p_Other.Y ||
           Width != p_Other.Width ||
           Height != p_Other.Height;
  }
}

#endif
