#include "s21_vector.h"
#include "vector"

int main() {
  s21::Vector<int> a;  // my vector
  std::vector<int> b;  // original vector
  a.push_back(5);
  b.push_back(4);
  std::cout << a[0] << std::endl;
  std::cout << b[0] << std::endl;
}
