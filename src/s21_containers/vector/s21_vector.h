#ifndef VECTOR_H
#define VECTOR_H
#include <initializer_list>
#include <iostream>
using namespace std;

namespace s21 {

template <class T>
class iterator_vector;

template <class T>
class const_iterator_vector;

template <class T>
class vector {
 public:
  // vector Member type
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = iterator_vector<T>;
  using const_iterator = const_iterator_vector<T>;
  using size_type = std::size_t;
  using pointer = T *;

 public:
  // vector Member functions
  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v);
  ~vector();
  vector &operator=(vector &&v);

  // vector Element access
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  pointer data() { return container_; }

  // vector Iterators
  iterator begin() { return iterator(container_); }
  iterator end() { return iterator(container_ + size_); }
  const_iterator begin() const { return const_iterator(container_); }
  const_iterator end() const { return const_iterator(container_ + size_); }

  // vector Capacity
  bool empty() const { return size_ == 0; }
  size_type size() const { return size_; }
  size_type max_size() const { return capacity_ * sizeof(value_type); }
  size_type capacity() const { return capacity_; }
  void reserve(size_type size);
  void shrink_to_fit();

  // vector Modifiers
  void clear() { this->size_ = 0; }
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back() { this->size_ > 0 ? this->size_-- : 0; };
  void swap(vector &other);

 private:
  size_type size_;
  size_type capacity_;
  value_type *container_;

  // helper
  void bring_to_zero();
  void add_memory(size_type size, bool flag);
  size_type add_memory_size(size_type size, bool flag);
  void copy_vector(const vector &v);
  void remove();
};

template <typename T>
class iterator_base {
 public:
  friend class vector<T>;

  using value_type = T;
  using pointer = T *;
  using reference = T &;

  iterator_base() { ptr_ = nullptr; }
  iterator_base(pointer ptr) { ptr_ = ptr; }

  value_type &operator*() { return (*ptr_); }
  pointer operator->() { return ptr_; }

  iterator_base &operator++() {
    ptr_++;
    return *this;
  }

  iterator_base &operator--() {
    ptr_--;
    return *this;
  }

  iterator_base operator++(int) {
    iterator_base tmp = *this;
    ++(*this);
    return tmp;
  }

  iterator_base operator--(int) {
    iterator_base tmp = *this;
    --(*this);
    return tmp;
  }

  iterator_base operator+(const size_t value) {
    iterator_base tmp(this->ptr_ + value);
    return tmp;
  }

  iterator_base operator-(const size_t value) {
    iterator_base tmp(this->ptr_ - value);
    return tmp;
  }

  bool operator==(const iterator_base &other) const {
    return ptr_ == other.ptr_;
  }
  bool operator!=(const iterator_base &other) const {
    return ptr_ != other.ptr_;
  }

 protected:
  pointer ptr_;
};

template <class T>
class iterator_vector : public iterator_base<T> {
 public:
  using iterator_base<T>::iterator_base;

  using typename iterator_base<T>::value_type;
  using typename iterator_base<T>::pointer;
  using typename iterator_base<T>::reference;
};

// template <class T>
// class const_iterator_vector : public iterator_base<T, const T *, const T &> {
//  public:
//   using iterator_base<T, const T &, const T *>::iterator_base;

//   using typename iterator_base<T, const T &, const T *>::value_type;
//   using typename iterator_base<T, const T &, const T *>::pointer;
//   using typename iterator_base<T, const T &, const T *>::reference;
// };

}  // namespace s21
#endif  // VECTOR_H