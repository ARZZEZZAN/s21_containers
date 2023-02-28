#ifndef S21_LIST_H
#define S21_LIST_H
#include <iostream>

namespace s21 {

template <typename T>
class list {
  using value_type = T;
  using size_type = std::size_t;
  using reference = T&;

 public:
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const& items);
  list(const list& l);
  list(list&& l);
  ~list();
  list& operator=(list&& l);

 private:
  struct Node {
    value_type value_;
    Node* prev_;
    Node* next_;

    Node(const value_type& value)
        : value_(value), prev(nullptr), next(nullptr) {}
  };

  Node* head_;
  Node* tail_;
  size_type size_;
};
}  // namespace s21
#endif  // S21_LIST_H
