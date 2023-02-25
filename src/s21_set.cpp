#include "s21_set.hpp"

#include <iostream>
#include <set>
using namespace std;
using namespace s21;
int main() {
  set<int> mySet = {1, 2, 3, 10, 4};
  for (auto i : mySet) {
    cout << i << endl;
  }
}