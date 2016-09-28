// main.cpp

// STL Includes
#include <iostream>
// HM Includes
#include <HM/HybridMath.hpp>

int main(int p_ArgCount, char** p_ArgVars)
{
  HM::Vector2 vector(3.0f, 4.0f);

  std::cout << "X: " << vector.X << ", Y: " << vector.Y << ", Length: " << vector.Length() << std::endl;

  return 0;
}
