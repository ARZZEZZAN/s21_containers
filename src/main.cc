#include <algorithm>
#include <map>
#include <vector>

#include "./Map/s21_map.tpp"
using namespace std;
using namespace s21;
int main() {
  Map<string, int> myMap;
  Map<string, int> myMap1;
  myMap.insert(std::make_pair("apple", 99));
  myMap.insert(std::make_pair("or", 1));
  myMap.insert(std::make_pair("adf", 1));
  myMap.insert(std::make_pair("appsafsle", 1));
  myMap.insert(std::make_pair("appfafale", 1));
  myMap["string"] = 999;
  std::cout << myMap["string"] << std::endl;
  // for (auto i : myMap) {
  //   std::cout << i.first << std::endl;
  // }
  // std::cout << "\n" << std::endl;
  for (auto i = myMap.begin(); i != myMap.end(); i++) {
    std::cout << i.operator->()->first << std::endl;
    std::cout << i.operator->()->second << std::endl;
  }

  // for (const auto& kv : myMap) {
  //   std::cout << myMap.empty() << std::endl;
  // }
  Set<int> mySet;
  mySet.insert(5);
  // Set<int> mySet1;
  std::cout << *mySet.begin() << std::endl;

  // for (auto i : mySet) {
  //   std::cout << i << std::endl;
  // }
}
