#include <algorithm>
#include <map>
#include <vector>

#include "./Map/s21_map.tpp"
using namespace std;
using namespace s21;
int main() {
  Map<string, int> myMap;
  myMap.insert(std::make_pair("apple", 1));
  myMap.insert(std::make_pair("or", 1));
  myMap.insert(std::make_pair("adf", 1));
  myMap.insert(std::make_pair("appsafsle", 1));
  myMap.insert(std::make_pair("appfafale", 1));
  for (auto i : myMap) {
    std::cout << i.first << std::endl;
  }
  myMap.erase(myMap.find("apple"));
  // Output the keys of the map
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
