// Matrix3.hpp

#ifndef __HM_MATRIX3_HPP__
#define __HM_MATRIX3_HPP__

namespace HM
{
  template<typename T> class Matrix3
  {
    public:
      static const Matrix3<T> Identity;
      static const Matrix3<T> Zero;

      Matrix3<T>();
      Matrix3<T>(T p_Element0, T p_Element1, T p_Element2,
                 T p_Element3, T p_Element4, T p_Element5,
                 T p_Element6, T p_Element7, T p_Element8);
      Matrix3<T>(const T(&M)[9]);

      Matrix3<T>& operator=(const Matrix3<T>& p_Other);
      Matrix3<T>& operator+=(const Matrix3<T>& p_Other);
      Matrix3<T> operator+(const Matrix3<T>& p_Other) const;
      Matrix3<T>& operator-=(const Matrix3<T>& p_Other);
      Matrix3<T> operator-(const Matrix3<T>& p_Other) const;
      Matrix3<T>& operator*=(const Matrix3<T>& p_Other);
      Matrix3<T> operator*(const Matrix3<T>& p_Other) const;
      Matrix3<T>& operator*=(T p_Scalar);
      Matrix3<T> operator*(T p_Scalar) const;
      Matrix3<T>& operator/=(T p_Scalar);
      Matrix3<T> operator/(T p_Scalar) const;
      bool operator==(const Matrix3<T>& p_Other) const;
      bool operator!=(const Matrix3<T>& p_Other) const;

      T Determinant() const;
      bool IsInvertable() const;
      void Invert();
      Matrix3<T> Inverse() const;
      Matrix3<T>& Transpose();

    public:
      T Elements[9];
  };

  template<typename T> Matrix3<T> operator*(T p_Scalar, const Matrix3<T>& p_Matrix);

  using Matrix3i = Matrix3<int>;
  using Matrix3u = Matrix3<unsigned int>();
  using Matrix3f = Matrix3<float>;
  using Matrix3d = Matrix3<double>;
}

// Template Definition Include
#include <HM/Matrix3.tpp>

#endif
