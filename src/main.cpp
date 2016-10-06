// main.cpp

// STL Includes
#include <iostream>
// HM Includes
#include <HM/HybridMath.hpp>

void printRectangle(const HM::Rectanglei p_Rectangle)
{
  std::cout << "Width: " << p_Rectangle.Width << ", Height: " << p_Rectangle.Height << std::endl;
}

void printVector2(const HM::Vector2f p_Vector2)
{
  std::cout << "X: " << p_Vector2.X << ", Y: " << p_Vector2.Y << ", Length: " << p_Vector2.Length() << std::endl;
}

void printVector3(const HM::Vector3f p_Vector3)
{
  std::cout << "X: " << p_Vector3.X << ", Y: " << p_Vector3.Y << ", Z: " << p_Vector3.Z << ", Length: " << p_Vector3.Length() << std::endl;
}

int main(int p_ArgCount, char** p_ArgVars)
{
  HM::Rectanglei rectangle(0, 0, 100, 100);
  printRectangle(rectangle);

  HM::Vector2f vector2(3.0f, 5.0f);
  printVector2(vector2);

  HM::Vector3f vector3(2.0f, 3.0f, 4.0f);
  printVector3(vector3);

  return 0;
}
