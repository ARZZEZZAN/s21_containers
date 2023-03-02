#include "s21_set.h"

#include <set>
using namespace std;
using namespace s21;
int main() {
  Set<int> mySet;
  Set<int> mySet1;
  mySet.insert(5);
  mySet.insert(3);
  mySet.insert(10);
  mySet.insert(-4);

  mySet1.insert(1);
  mySet1.insert(2);
  mySet1.insert(3);
  mySet1.insert(4);

  if (mySet.empty()) {
    std::cout << mySet.size() << std::endl;
  }
}