// #include "Set.h"
// #include "Stack.h"
#include "Vector.h"

int main() {
  Vector<int> v;
  v.pushBack(1);
  v.pushBack(2);
  v.pushBack(3);
  std::cout << v[2] << std::endl;
  std::cout << v << std::endl;

  return 0;
}