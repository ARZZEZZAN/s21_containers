// using namespace s21;
#include "iostream"
#include "s21_vector.h"
#include "vector"

int main() {
  std::vector<int> orig(5);
  s21::Vector<int> my;
  int v1 = 5;
  // my.push_back1(v1);
  orig.push_back(v1);
  std::cout << "orig: " << orig[0] << " " << orig[1] << std::endl;
  // std::cout << "my: " << my[0] << " " << my[1] << std::endl;
}