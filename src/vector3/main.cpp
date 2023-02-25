
#include <iostream>

// #include "Vector.h"
#include "s21_vector.tpp"
using namespace s21;

int main() {
  Vector<int> vector;
  vector.pushBack(1);
  vector.pushBack(2);
  vector.pushBack(3);
  std::cout << vector[0] << std::endl;
  std::cout << vector[1] << std::endl;
  std::cout << vector[2] << std::endl;

  return 0;
}