#include <iostream>

#include "s21_vector.tpp"
#include "vector"
using namespace s21;
using namespace std;

int main() {
  std::vector<int> s21_vector{1, 9999, 20000};
  cout << *(s21_vector.begin()++) << endl;

  std::vector<int> std_vector{1, 9999, 20000};
  cout << *(std_vector.begin()++) << endl;

  return 0;
}
