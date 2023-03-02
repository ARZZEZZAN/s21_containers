#ifndef S21_LIST_H
#define S21_LIST_H

#include <initializer_list>
#include <iostream>
#include <limits>

namespace s21 {
template <typename T>
class ListIterator;

template <typename T>
struct node {
  T value_;
  node* prev_;
  node* next_;

  node(const T& value) : value_(value), prev_(nullptr), next_(nullptr) {}
};

template <typename T>
class ListConstIterator;

template <typename T>
class list {
  // List Member type
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;
  using size_type = std::size_t;
  using Node = node<T>;

 public:
  // List Functions -- DONE
  list();
  list(size_type n);
  // list(std::initializer_list<value_type> const& items);
  list(const list& l);
  list(list&& l);
  ~list();
  list& operator=(list&& l);

  // List Element access -- DONE
  const_reference front() { return head_->value_; }
  const_reference back() { return tail_->value_; }

  // List Iterators -- DONE
  iterator begin() { return iterator(head_); }
  iterator end() { return iterator(end_); }

  // List Capacity -- DONE
  bool empty() { return size_ == 0; }
  size_type size() { return size_; }
  size_type max_size() { return std::numeric_limits<size_type>::max(); }

  // List Modifiers
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
  // void reverse();
  // void unique();
  // void sort();

  // Helpers
  // void list<T>::merge_sorted_lists(list& left_half, list& right_half);
  void print_list();

 private:
  Node* head_;
  Node* tail_;
  Node* end_;
  size_type size_;
  void add_end();
};

template <typename T>
class ListIterator {
  friend class ListConstIterator<T>;
  friend class list<T>;

  using value_type = T;
  using pointer = T*;
  using reference = T&;
  using Node = node<T>;
  using size_type = std::size_t;

 public:
  ListIterator() { ptr_ = nullptr; }
  ListIterator(Node* ptr) : ptr_(ptr){};

  reference operator*() { return this->ptr_->value_; }

  ListIterator operator++(int) {
    ptr_ = ptr_->next_;
    return *this;
  }

  ListIterator operator--(int) {
    ptr_ = ptr_->prev_;
    return *this;
  }

  ListIterator& operator++() {
    ptr_ = ptr_->next_;
    return *this;
  }

  ListIterator& operator--() {
    // if (!ptr_) {
    //   throw std::invalid_argument("hui");
    // }
    ptr_ = ptr_->prev_;
    return *this;
  }

  ListIterator operator+(const size_type value) {
    Node* tmp = ptr_;
    for (size_type i = 0; i < value; i++) {
      tmp = tmp->next_;
    }

    ListIterator res(tmp);
    return res;
  }

  ListIterator operator-(const size_type value) {
    Node* tmp = ptr_;
    for (size_type i = 0; i < value; i++) {
      tmp = tmp->prev_;
    }
    ListIterator res(tmp);
    return res;
  }

  // ListIterator& operator=(const ListIterator other) {
  //   this->ptr_ = other->ptr_;
  //   return *this;
  // }

  bool operator==(ListIterator other) { return this->ptr_ == other.ptr_; }

  bool operator!=(ListIterator other) { return this->ptr_ != other.ptr_; }

 private:
  Node* ptr_ = nullptr;
};

}  // namespace s21
#endif  // S21_LIST_H
