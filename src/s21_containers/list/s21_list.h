#ifndef S21_LIST_H
#define S21_LIST_H
#include <iostream>

namespace s21 {

template <typename T>
class list {
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = std::size_t;

 public:
  value_type hui;
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const& items);
  list(const list& l);
  list(list&& l);
  ~list();

  list& operator=(list&& l);

  bool empty() const;
  void clear();

  // iterator insert(iterator pos, const_reference value);
  // void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list& other);
  void merge(list& other);
  // void splice(const_iterator pos, list& other);
  void reverse();
  void unique();
  void sort();

  void print_list();

 private:
  struct Node {
    value_type value_;
    Node* prev_;
    Node* next_;

    Node(const value_type& value)
        : value_(value), prev_(nullptr), next_(nullptr) {}
  };

  Node* head_;
  Node* tail_;
  size_type size_;
};
}  // namespace s21
#endif  // S21_LIST_H

// template <typename T>
// void list<T>::push_back(const value_type& value) {
//   auto new_node = new Node(value);
//   if (empty()) {
//     head_ = new_node;
//   } else {
//     new_node->prev_ = tail_;
//     tail_->next_ = new_node;
//   }
//   tail_ = new_node;
//   ++size_;
// }

// template <typename T>
// void list<T>::pop_back() {
//   if (!empty()) {
//     auto last_node = tail_;
//     tail_ = last_node->prev_;
//     if (tail_) {
//       tail_->next_ = nullptr;
//     } else {
//       head_ = nullptr;
//     }
//     delete last_node;
//     --size_;
//   }
// }

// template <typename T>
// void list<T>::push_front(const value_type& value) {
//   auto new_node = new Node(value);
//   if (empty()) {
//     tail_ = new_node;
//   } else {
//     new_node->next_ = head_;
//     head_->prev_ = new_node;
//   }
//   head_ = new_node;
//   ++size_;
// }

// template <typename T>
// void list<T>::pop_front() {
//   if (!empty()) {
//     auto first_node = head_;
//     head_ = first_node->next_;
//     if (head_) {
//       head_->prev_ = nullptr;
//     } else {
//       tail_ = nullptr;
//     }
//     delete first_node;
//     --size_;
//   }
// }

// template <typename T>
// typename list<T>::reference list<T>::front() {
//   return head_->value_;
// }

// template <typename T>
// typename list<T>::reference list<T>::back() {
//   return tail_->value_;
// }

// template <typename T>
// typename list<T>::size_type list<T>::size() const {
//   return size_;
// }

// template <typename T>
// bool list<T>::empty() const {
//   return size_ == 0;
// }

// template <typename T>
// void list<T>::clear() {
//   while (!empty()) {
//     pop_back();
//   }
// }

// }  // namespace s21