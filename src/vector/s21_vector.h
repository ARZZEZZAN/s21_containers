#ifndef S21_VECTOR_H
#define S21_VECTOR_H

// #include <cstring>
#include <iostream>

namespace s21 {

template <class T>
class iterator_Vector;

template <class T, class Allocator = std::allocator<T> >
class Vector {
 public:
  // Member types
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = iterator_Vector<T>;
  // using const_iterator = const_iterator_Vector<T>;
  using size_type = std::size_t;
  using pointer = T *;
  // using const_pointer = const T *;
  using allocator_type = Allocator;

  // Vector Member functions
  Vector();
  Vector(size_type n);
  Vector(std::initializer_list<value_type> const &items);
  Vector(const Vector &v);
  Vector(Vector &&v);
  ~Vector();
  // operator=(Vector &&v);

  // Vector Element access
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  iterator data();

  // Vector Iterators
  iterator begin() {
    iterator tmp(container_);
    return tmp;
  }
  iterator end() {
    iterator tmp(container_ + size_);
    return tmp;
  }

  // Vector Capacity
  size_type size() const { return size_; }
  size_type max_size() const { return capacity_ * sizeof(value_type); }
  size_type capacity() const { return capacity_; }
  bool empty() const { return size_ > 0 ? false : true; }
  void reserve(size_type size);
  void shrink_to_fit();

  // Vector Modifiers
  iterator insert(iterator pos, const_reference value);
  void clear();
  void erase(iterator pos);
  void push_back(const_reference value) { this->insert(this->end(), value); }
  void pop_back();
  void swap(Vector &other);

  // Helpers
  void bring_to_zero();
  pointer memory_allocate(size_type size);

 private:
  size_type size_;
  size_type capacity_;
  value_type *container_;
};

template <class T>
class iterator_Vector {
  friend class Vector<T>;

  using iterator_category = std::bidirectional_iterator_tag;
  using difference_type = std::ptrdiff_t;
  using value_type = T;
  using pointer = T *;
  using reference = T &;
  pointer ptr_;

 public:
  // Конструкторы
  iterator_Vector() : ptr_(nullptr){};
  iterator_Vector(pointer ptr) : ptr_(ptr){};

  // Oператоры
  value_type &operator*() const { return (*ptr_); }
  pointer operator->() { return ptr_; }
  iterator_Vector &operator++() {
    ptr_++;
    return *this;
  }
  iterator_Vector &operator--() {
    ptr_--;
    return *this;
  }
  iterator_Vector operator++(int) {
    iterator_Vector tmp = *this;
    ++(*this);
    return tmp;
  }
  iterator_Vector operator--(int) {
    iterator_Vector tmp = *this;
    --(*this);
    return tmp;
  }
  bool operator==(iterator_Vector &tmp) { return ptr_ == tmp.ptr_; }
  bool operator!=(iterator_Vector &tmp) { return ptr_ != tmp.ptr_; }
};

}  // namespace s21
#endif  // S21_VECTOR_H
