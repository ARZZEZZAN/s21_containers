#ifndef S21_LIST_H
#define S21_LIST_H
#include <iostream>

namespace s21 {
template <class T>
class ListIterator;

template <class T>
class ListConstIterator;

template <typename T>
class list {
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;
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

  iterator insert(iterator pos, const_reference value);
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

  // List Iterators
  iterator begin(return iterator(head_));
  iterator end(return iterator(tail_));

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

template <class T>
class ListIterator {
  friend class list<T>;
  friend class ListConstIterator<T>;

  using value_type = T;
  using pointer = T*;
  using reference = T&;

 public:
  ListIterator() { ptr_ = nullptr; }
  ListIterator(Node<T>* ptr) { ptr_(ptr); }

  reference operator*() { return ptr_->value_; }

  ListIterator operator++(int) {
    ptr_ = ptr_->next;
    return *this;
  }

  ListIterator operator--(int) {
    ptr_ = ptr_->prev;
    return *this;
  }

  ListIterator& operator++() {
    ptr_ = ptr_->next;
    return *this;
  }

  ListIterator& operator--() {
    ptr_ = ptr_->prev;
    return *this;
  }

  ListIterator operator+(const size_t value) {
    ListIterator tmp(ptr_->value + value);
    return tmp;
  }

  ListIterator operator-(const size_t value) {
    ListIterator tmp(ptr_->value + value);
    return tmp;
  }

  bool operator==(ListIterator<T> other) { return ptr == other.ptr; }

  bool operator!=(ListIterator<T> other) { return ptr != other.ptr; }

 private:
  Node<T>* ptr_ = nullptr;
};

}  // namespace s21
#endif  // S21_LIST_H
