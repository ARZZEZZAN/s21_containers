#include <map>

#include "./Map/s21_map.tpp"
using namespace std;
using namespace s21;
int main() {
  map<string, int> myMap;
  auto res = myMap.insert(make_pair("Armen", 1));
  std::cout << res.second << std::endl;
  // Set<int> mySet;
  // Set<int> mySet1;
  // std::cout << mySet.size() << std::endl;

  // for (auto i : mySet) {
  //   std::cout << i << std::endl;
  // }
}
