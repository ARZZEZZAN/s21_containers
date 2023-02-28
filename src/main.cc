// #include "list/s21_list.tpp"
#include <iostream>
namespace s21 {
template <typename T>
class list {
  using value_type = T;

 public:
  list() { this->value = 0; }
  list(value_type var) { this->value = var; }
  // ~list() {
  //   delete
  // }
  value_type getValue() { return this->value; }

 private:
  value_type value;
};
}  // namespace s21

int main() {
  s21::list<int>* gt = new s21::list<int>(1468588943);
  std::cout << gt->getValue();
  delete gt;
  return 0;
}
// 1468588943
// 1826378361