// Matrix3<T>.cpp

// HM Includes
#include <HM/Matrix3.hpp>
// STL Includes
#include <utility>

#ifdef __HM_MATRIX3_HPP__

namespace HM
{
  template<typename T> const Matrix3<T> Matrix3<T>::Identity = Matrix3<T>({ 1, 0, 0,
                                                                            0, 1, 0,
                                                                            0, 0, 1 });

  template<typename T> const Matrix3<T> Matrix3<T>::Zero = Matrix3<T>({ 0, 0, 0,
                                                                        0, 0, 0,
                                                                        0, 0, 0 });

  template<typename T> Matrix3<T>::Matrix3()
  {
    Elements[0] = static_cast<T>(1);
    Elements[1] = static_cast<T>(0);
    Elements[2] = static_cast<T>(0);
    Elements[3] = static_cast<T>(0);
    Elements[4] = static_cast<T>(1);
    Elements[5] = static_cast<T>(0);
    Elements[6] = static_cast<T>(0);
    Elements[7] = static_cast<T>(0);
    Elements[8] = static_cast<T>(1);
  }

  template<typename T> Matrix3<T>::Matrix3(T p_Element0, T p_Element1, T p_Element2,
                                           T p_Element3, T p_Element4, T p_Element5,
                                           T p_Element6, T p_Element7, T p_Element8)
  {
    Elements[0] = p_Element0;
    Elements[1] = p_Element1;
    Elements[2] = p_Element2;
    Elements[3] = p_Element3;
    Elements[4] = p_Element4;
    Elements[5] = p_Element5;
    Elements[6] = p_Element6;
    Elements[7] = p_Element7;
    Elements[8] = p_Element8;
  }

  template<typename T> Matrix3<T>::Matrix3(const T(&M)[9])
  {
    for (int i = 0; i < 9; ++i)
    {
      Elements[i] = M[i];
    }
  }

  template<typename T> Matrix3<T>& Matrix3<T>::operator=(const Matrix3<T>& p_Other)
  {
    for (int i = 0; i < 9; ++i)
    {
      Elements[i] = p_Other.Elements[i];
    }

    return *this;
  }

  template<typename T> Matrix3<T>& Matrix3<T>::operator+=(const Matrix3<T>& p_Other)
  {
    for (int i = 0; i < 9; ++i)
    {
      Elements[i] += p_Other.Elements[i];
    }

    return *this;
  }

  template<typename T> Matrix3<T> Matrix3<T>::operator+(const Matrix3<T>& p_Other) const
  {
    Matrix3<T> ret;

    for (int i = 0; i < 9; ++i)
    {
      ret.Elements[i] = Elements[i] + p_Other.Elements[i];
    }

    return ret;
  }

  template<typename T> Matrix3<T>& Matrix3<T>::operator-=(const Matrix3<T>& p_Other)
  {
    for (int i = 0; i < 9; ++i)
    {
      Elements[i] -= p_Other.Elements[i];
    }

    return *this;
  }

  template<typename T> Matrix3<T> Matrix3<T>::operator-(const Matrix3<T>& p_Other) const
  {
    Matrix3<T> ret;

    for (int i = 0; i < 9; ++i)
    {
      ret.Elements[i] = Elements[i] - p_Other.Elements[i];
    }

    return ret;
  }

  template<typename T> Matrix3<T>& Matrix3<T>::operator*=(const Matrix3<T>& p_Other)
  {
    T m11 = Elements[0] * p_Other.Elements[0] + Elements[1] * p_Other.Elements[3] + Elements[2] * p_Other.Elements[6];
    T m12 = Elements[0] * p_Other.Elements[1] + Elements[1] * p_Other.Elements[4] + Elements[2] * p_Other.Elements[7];
    T m13 = Elements[0] * p_Other.Elements[2] + Elements[1] * p_Other.Elements[5] + Elements[2] * p_Other.Elements[8];
    T m21 = Elements[3] * p_Other.Elements[0] + Elements[4] * p_Other.Elements[3] + Elements[5] * p_Other.Elements[6];
    T m22 = Elements[3] * p_Other.Elements[1] + Elements[4] * p_Other.Elements[4] + Elements[5] * p_Other.Elements[7];
    T m23 = Elements[3] * p_Other.Elements[2] + Elements[4] * p_Other.Elements[5] + Elements[5] * p_Other.Elements[8];
    T m31 = Elements[6] * p_Other.Elements[0] + Elements[7] * p_Other.Elements[3] + Elements[8] * p_Other.Elements[6];
    T m32 = Elements[6] * p_Other.Elements[1] + Elements[7] * p_Other.Elements[4] + Elements[8] * p_Other.Elements[7];
    T m33 = Elements[6] * p_Other.Elements[2] + Elements[7] * p_Other.Elements[5] + Elements[8] * p_Other.Elements[8];

    Elements[0] = m11;
    Elements[1] = m12;
    Elements[2] = m13;
    Elements[3] = m21;
    Elements[4] = m22;
    Elements[5] = m23;
    Elements[6] = m31;
    Elements[7] = m32;
    Elements[8] = m33;

    return *this;
  }

  template<typename T> Matrix3<T> Matrix3<T>::operator*(const Matrix3<T>& p_Other) const
  {
    T m11 = Elements[0] * p_Other.Elements[0] + Elements[1] * p_Other.Elements[3] + Elements[2] * p_Other.Elements[6];
    T m12 = Elements[0] * p_Other.Elements[1] + Elements[1] * p_Other.Elements[4] + Elements[2] * p_Other.Elements[7];
    T m13 = Elements[0] * p_Other.Elements[2] + Elements[1] * p_Other.Elements[5] + Elements[2] * p_Other.Elements[8];
    T m21 = Elements[3] * p_Other.Elements[0] + Elements[4] * p_Other.Elements[3] + Elements[5] * p_Other.Elements[6];
    T m22 = Elements[3] * p_Other.Elements[1] + Elements[4] * p_Other.Elements[4] + Elements[5] * p_Other.Elements[7];
    T m23 = Elements[3] * p_Other.Elements[2] + Elements[4] * p_Other.Elements[5] + Elements[5] * p_Other.Elements[8];
    T m31 = Elements[6] * p_Other.Elements[0] + Elements[7] * p_Other.Elements[3] + Elements[8] * p_Other.Elements[6];
    T m32 = Elements[6] * p_Other.Elements[1] + Elements[7] * p_Other.Elements[4] + Elements[8] * p_Other.Elements[7];
    T m33 = Elements[6] * p_Other.Elements[2] + Elements[7] * p_Other.Elements[5] + Elements[8] * p_Other.Elements[8];

    return Matrix3<T>(m11, m12, m13, m21, m22, m23, m31, m32, m33);
  }

  template<typename T> Matrix3<T>& Matrix3<T>::operator*=(T p_Scalar)
  {
    for (int i = 0; i < 9; ++i)
    {
      Elements[i] *= p_Scalar;
    }

    return *this;
  }

  template<typename T> Matrix3<T> Matrix3<T>::operator*(T p_Scalar) const
  {
    Matrix3<T> ret;

    for (int i = 0; i < 9; ++i)
    {
      ret.Elements[i] = Elements[i] * p_Scalar;
    }

    return ret;
  }

  template<typename T> Matrix3<T>& Matrix3<T>::operator/=(T p_Scalar)
  {
    for (int i = 0; i < 9; ++i)
    {
      Elements[i] /= p_Scalar;
    }

    return *this;
  }

  template<typename T> Matrix3<T> Matrix3<T>::operator/(T p_Scalar) const
  {
    Matrix3<T> ret;

    for (int i = 0; i < 9; ++i)
    {
      ret.Elements[i] = Elements[i] / p_Scalar;
    }

    return ret;
  }

  template<typename T> bool Matrix3<T>::operator==(const Matrix3<T>& p_Other) const
  {
    for (int i = 0; i < 9; ++i)
    {
      if (Elements[i] != p_Other.Elements[i])
      {
        return false;
      }
    }

    return true;
  }

  template<typename T> bool Matrix3<T>::operator!=(const Matrix3<T>& p_Other) const
  {
    return !(*this == p_Other);
  }

  template<typename T> T Matrix3<T>::Determinant() const
  {
    return Elements[0] * Elements[4] * Elements[8] +
           Elements[1] * Elements[5] * Elements[6] +
           Elements[2] * Elements[3] * Elements[7] -
           Elements[2] * Elements[4] * Elements[6] -
           Elements[0] * Elements[5] * Elements[7] -
           Elements[1] * Elements[3] * Elements[8];
  }

  template<typename T> bool Matrix3<T>::IsInvertable() const
  {
    return Determinant() != 0;
  }

  template<typename T> void Matrix3<T>::Invert()
  {
    T det = Determinant();
    if (det != static_cast<T>(0))
    {
      T b11 = Elements[4] * Elements[8] - Elements[5] * Elements[7];
      T b12 = Elements[3] * Elements[8] - Elements[5] * Elements[6];
      T b13 = Elements[3] * Elements[7] - Elements[4] * Elements[6];
      T b21 = Elements[1] * Elements[8] - Elements[2] * Elements[7];
      T b22 = Elements[0] * Elements[8] - Elements[2] * Elements[6];
      T b23 = Elements[0] * Elements[7] - Elements[1] * Elements[6];
      T b31 = Elements[1] * Elements[5] - Elements[2] * Elements[4];
      T b32 = Elements[0] * Elements[5] - Elements[2] * Elements[3];
      T b33 = Elements[0] * Elements[4] - Elements[1] * Elements[3];

      Elements[0] = b11 / det;
      Elements[1] = -b21 / det;
      Elements[2] = b31 / det;
      Elements[3] = -b12 / det;
      Elements[4] = b22 / det;
      Elements[5] = -b32 / det;
      Elements[6] = b13 / det;
      Elements[7] = -b23 / det;
      Elements[8] = b33 / det;
    }
  }

  template<typename T> Matrix3<T> Matrix3<T>::Inverse() const
  {
    T det = Determinant();
    if (det != static_cast<T>(0))
    {
      T b11 = Elements[4] * Elements[8] - Elements[5] * Elements[7];
      T b12 = Elements[3] * Elements[8] - Elements[5] * Elements[6];
      T b13 = Elements[3] * Elements[7] - Elements[4] * Elements[6];
      T b21 = Elements[1] * Elements[8] - Elements[2] * Elements[7];
      T b22 = Elements[0] * Elements[8] - Elements[2] * Elements[6];
      T b23 = Elements[0] * Elements[7] - Elements[1] * Elements[6];
      T b31 = Elements[1] * Elements[5] - Elements[2] * Elements[4];
      T b32 = Elements[0] * Elements[5] - Elements[2] * Elements[3];
      T b33 = Elements[0] * Elements[4] - Elements[1] * Elements[3];

      Matrix3<T> ret(b11, -b21, b31, -b12, b22, -b32, b13, -b23, b33);
      ret /= det;

      return ret;
    }

    return Matrix3<T>::Zero;
  }

  template<typename T> Matrix3<T>& Matrix3<T>::Transpose()
  {
    std::swap(Elements[1], Elements[3]);
    std::swap(Elements[2], Elements[6]);
    std::swap(Elements[5], Elements[7]);

    return *this;
  }

  template<typename T> Matrix3<T> operator*(T p_Scalar, const Matrix3<T>& p_Matrix)
  {
    Matrix3<T> ret;

    for (int i = 0; i < 9; ++i)
    {
      ret.Elements[i] = p_Scalar * p_Matrix.Elements[i];
    }

    return ret;
  }
}

#endif
