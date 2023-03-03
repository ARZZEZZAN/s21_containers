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
void print_std_list(std::list<int>& l) {
  for (auto i = l.begin(); i != l.end(); ++i) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
}

int main() {
  // s21::list<int>* gt = new s21::list<int>(1468588943);
  // std::cout << gt->getValue();
  // delete gt;
  // s21::list<int> l;
  // l.hui = 2;
  // std::cout << l.hui;
  s21::list<int> l = {99, 9, 1, 2, 3};
  std::list<int> l2 = {99, 9, 1, 2, 3};

  l.print_list();
  print_std_list(l2);

  l.sort();
  l2.sort();

  l.print_list();
  print_std_list(l2);
  // l.push_back(3);
  // l.push_front(3);
  // s21::print_list(l);
  // s21::print_list(l);
  // for (auto item : l) {
  //   std::cout << item << " ";
  // }
  // std::cout << l.size() << endl;
  // std::cout << "my " << sizeof(l, l2) << std::endl;
  // std::cout << "std " << sizeof(l2) << std::endl;

  // std::list<int> l3;
  // l3.push_back(1);
  // l3.push_back(2);
  // l3.push_back(3);
  // for (auto i = l3.begin(); i != l3.end(); ++i) {
  //   std::cout << *i << " ";
  // }
  // std::cout << std::endl;
  return 0;
}
// 1468588943
// 1826378361