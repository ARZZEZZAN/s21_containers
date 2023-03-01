// #include <iostream>
#include <list>

#include "s21_containers/list/s21_list.tpp"
// namespace s21 {
// template <typename T>
// class list {
//   using value_type = T;

//  public:
//   list() { this->value = 0; }
//   list(value_type var) { this->value = var; }
//   // ~list() {
//   //   delete
//   // }
//   value_type getValue() { return this->value; }

//  private:
//   value_type value;
// };
// using namespace s21;
int main() {
  // s21::list<int>* gt = new s21::list<int>(1468588943);
  // std::cout << gt->getValue();
  // delete gt;
  // s21::list<int> l;
  // l.hui = 2;
  // std::cout << l.hui;
  s21::list<int> l = {2, 3, 4, 2, 5, 3, 4, 2, 5, 3, 4, 2, 5};
  s21::list<int> l2 = {2, 3, 4, 2, 5, 3, 4, 2, 5, 3, 4, 2, 5};
  std::list<int> l3;
  l.push_back(3);
  l.push_front(3);
  l.pop_front();
  l.swap(l2);

  l3.push_back(3);
  // s21::print_list(l);
  // s21::print_list(l);
  // for (auto item : l) {
  //   std::cout << item << " ";
  // }
  // std::cout << l.size() << endl;

  std::cout << "my " << sizeof(l, l2) << std::endl;
  std::cout << "std " << sizeof(l2) << std::endl;
  return 0;
}
// 1468588943
// 1826378361