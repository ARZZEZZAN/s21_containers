#include <set>

#include "s21_set.tpp"
using namespace std;
using namespace s21;
int main() {
  Set<int> mySet;
  Set<int> mySet1;
  mySet.insert(5);
  mySet.insert(3);
  mySet.insert(10);
  mySet.insert(-5);
  mySet.insert(11);
  mySet.insert(12);
  mySet.insert(13);
  mySet.insert(14);
  mySet.insert(15);

  mySet1.insert(1);
  mySet1.insert(2);
  mySet1.insert(3);
  mySet1.insert(4);

  std::cout << *mySet.begin()++ << std::endl;

  // for (auto i : mySet) {
  //   std::cout << i << std::endl;
  // }
}
