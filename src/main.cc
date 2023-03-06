#include <map>

#include "./Map/s21_map.tpp"
using namespace std;
using namespace s21;
int main() {
  Map<string, int> myMap;
  // auto res = myMap.insert(make_pair("Armen", 1));
  // std::cout << myMap.empty() << std::endl;
  Set<int> mySet;
  mySet.insert(5);
  // Set<int> mySet1;
  std::cout << *mySet.begin() << std::endl;

  // for (auto i : mySet) {
  //   std::cout << i << std::endl;
  // }
}
