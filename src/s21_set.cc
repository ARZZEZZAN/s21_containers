#include "s21_set.h"

#include <set>
using namespace std;
using namespace s21;
int main() {
  Set<int> mySet;
  mySet.insert(5);
  mySet.insert(3);
  mySet.insert(10);
  mySet.insert(-4);
  if (mySet.contains(4)) {
    std::cout << "hi" << std::endl;
  }
}