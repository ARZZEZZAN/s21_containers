#ifndef S21_LIST_H
#define S21_LIST_H
#include <iostream>

namespace s21 {

template <class T>
class list {
  using value_type = T;
  using size_type = std::size_t;

 public:
  // list();
  // ~list();
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const& items);
  list(const list& l);
  list(list&& l);
  ~list();
  operator=(list&& l);

 private:
  struct Node {
    T value;
    Node* prev;
    Node* next;

    Node(const T& value) : value(value), prev(nullptr), next(nullptr) {}
  };

  Node* head;
  Node* tail;
  size_type size_;
  size_type capacity_;
  value_type* container_;
};
}  // namespace s21
#endif  // S21_LIST_H
