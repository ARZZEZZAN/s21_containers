#include "s21_set.h"

#include <set>
using namespace std;
using namespace s21;
int main() {
  Set<int> mySet;
  mySet.insert(5);
  mySet.insert(10);
  mySet.insert(10);
  mySet.insert(-4);
  // cout << mySet.count(3) << endl;
}