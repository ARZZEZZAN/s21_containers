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

  myMap1.insert(std::make_pair("orange", 1));
  myMap1.insert(std::make_pair("slivki", 1));
  myMap1.insert(std::make_pair("yabloko", 1));
  myMap["armen"] = 1;
  std::cout << myMap["armen"] << std::endl;
  // for (auto i : myMap) {
  //   std::cout << i.first << std::endl;
  // }
  // std::cout << "\n" << std::endl;
  for (auto i = myMap.begin(); i != myMap.end(); i++) {
    std::cout << i.operator->()->first << std::endl;
  }

  // for (const auto& kv : myMap) {
  //   std::cout << myMap.empty() << std::endl;
  // }
  // Set<int> mySet;
  // mySet.insert(5);
  // // Set<int> mySet1;
  // std::cout << *mySet.begin() << std::endl;

  // for (auto i : mySet) {
  //   std::cout << i << std::endl;
  // }
}
