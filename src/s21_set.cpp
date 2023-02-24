#include <iostream>
#include <set>
using namespace std;
int main() {
  set<const char*> mySet;
  const char* c = "wfqefeqfeq";
  const char* c1 = "fe";
  mySet.insert(c);
  mySet.insert(c1);
  mySet.insert(c);
  for (auto i : mySet) cout << i << endl;
}