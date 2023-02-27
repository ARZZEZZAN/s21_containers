
#include <iostream>

#include "s21_vector.tpp"
using namespace s21;
using namespace std;

int main() {
  Vector<char> vec;
  vec.push_back(97);
  vec.push_back(98);
  vec.push_back(99);
  std::cout << vec[0] << std::endl;
  std::cout << vec[1] << std::endl;
  std::cout << vec[2] << std::endl;

  return 0;
}
