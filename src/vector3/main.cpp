
#include <iostream>

#include "s21_vector.tpp"
using namespace s21;

#include "vector"
using namespace std;

int main() {
  Vector<char> my;
  my.push_back(97);
  my.push_back(98);
  my.push_back(99);
  my.push_back(100);
  my.push_back(101);
  my.push_back(102);
  // my.printVector();

  // my.insert(my.begin() + 2, 110);
  my.erase(my.begin() + 2);
  cout << "size = " << my.size() << endl;
  cout << "capacity = " << my.capacity() << endl;
  cout << my.at(0) << endl;
  cout << my.at(1) << endl;
  cout << my.at(2) << endl;
  cout << my.at(3) << endl;
  cout << my.at(4) << endl;
  // cout << my.at() << endl;
  return 0;
}
