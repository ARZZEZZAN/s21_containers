#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

namespace s21 {

template <class T>
class iterator_Vector;

template <class T>
class const_iterator_Vector;

template <class T>
class Vector {
  // Vector Member type -- DONE
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = iterator_Vector<T>;
  using const_iterator = const_iterator_Vector<T>;
  using size_type = std::size_t;

 public:
  // Vector Member functions
  Vector();
  Vector(size_type n);
  Vector(std::initializer_list<value_type> const &items);
  Vector(const Vector &v);
  Vector(Vector &&v);
  ~Vector();
  Vector &operator=(const Vector &&v);

  // Vector Element access -- DONE
  reference at(size_type pos);
  reference operator[](size_type pos) { return container_[pos]; }
  const_reference front();
  const_reference back();
  T *data() { return container_; }

  // Vector Iterators -- DONE
  iterator begin() { return iterator(container_); }
  iterator end() { return iterator(container_ + size_); }
  const_iterator begin() const { return const_iterator(container_); }
  const_iterator end() const { return const_iterator(container_ + size_); }

  // Vector Capacity -- DONE
  bool empty() const { return size_ == 0; }
  size_type size() const { return size_; }
  size_type max_size() const { return capacity_ * sizeof(T); }
  size_type capacity() const { return capacity_; }
  void reserve(size_type size);
  void shrink_to_fit();

  // Vector Modifiers -- DONE
  void clear() { this->size_ = 0; }
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back() { this->size_ > 0 ? this->size_-- : 0; };
  void swap(Vector &other);

  // helper -- DONE
  void bring_to_zero();
  void add_memory(size_type size, bool flag);
  size_type add_memory_size(size_type size, bool flag);
  void copy_vector(const Vector &v);
  void remove();
  void printVector();

 private:
  size_type size_;
  size_type capacity_;
  value_type *container_;
};

template <class T>
class iterator_Vector {
  friend class Vector<T>;
  friend class const_iterator_Vector<T>;

  using value_type = T;
  using pointer = T *;
  using reference = T &;

 public:
  iterator_Vector() { ptr_ = nullptr; }
  iterator_Vector(pointer ptr) { ptr_ = ptr; }

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

  iterator_Vector operator+(const size_t value) {
    iterator_Vector tmp(this->ptr_ + value);
    return tmp;
  }

  iterator_Vector operator-(const size_t value) {
    iterator_Vector tmp(this->ptr_ - value);
    return tmp;
  }

  friend bool operator==(const iterator_Vector &a, const iterator_Vector &b) {
    return a.ptr_ == b.ptr_;
  }

  friend bool operator!=(const iterator_Vector &a, const iterator_Vector &b) {
    return a.ptr_ != b.ptr_;
  }

  operator const_iterator_Vector<T>() const {
    return const_iterator_Vector<T>(ptr_);
  }

 private:
  pointer ptr_;
};

template <class T>
class const_iterator_Vector {
  friend class Vector<T>;
  friend class iterator_Vector<T>;

  using value_type = T;
  using pointer = T *;
  using reference = T &;

 public:
  const_iterator_Vector() { ptr_ = nullptr; };
  const_iterator_Vector(pointer ptr) { ptr_ = ptr; };
  value_type operator*() const { return (*ptr_); }
  pointer operator->() { return ptr_; }

  const_iterator_Vector &operator++() {
    ptr_++;
    return *this;
  }

  const_iterator_Vector &operator--() {
    ptr_--;
    return *this;
  }

  const_iterator_Vector operator++(int) {
    const_iterator_Vector tmp = *this;
    ++(*this);
    return tmp;
  }

  const_iterator_Vector operator--(int) {
    const_iterator_Vector tmp = *this;
    --(*this);
    return tmp;
  }

  friend bool operator==(const const_iterator_Vector &a,
                         const const_iterator_Vector &b) {
    return a.ptr_ == b.ptr_;
  }

  friend bool operator!=(const const_iterator_Vector &a,
                         const const_iterator_Vector &b) {
    return a.ptr_ != b.ptr_;
  }

  operator iterator_Vector<T>() const { return iterator_Vector<T>(ptr_); }

 private:
  pointer ptr_;
};

}  // namespace s21
#endif  // VECTOR_H