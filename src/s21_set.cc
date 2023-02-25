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
  for (auto i = mySet.begin(); i != mySet.end(); i++) {
    cout << *i << endl;
  }
}