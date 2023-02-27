#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

namespace s21 {

template <class T>
class Vector {
  // Vector Member type
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  // using iterator = VectorIterator<T>;
  // using const_iterator = const_iterator_Vector<T>;
  using size_type = std::size_t;

 public:
  // Vector Member functions
  Vector();
  Vector(size_type n);
  Vector(std::initializer_list<value_type> const& items);
  Vector(const Vector& v);
  Vector(Vector&& v);
  ~Vector();
  Vector& operator=(const Vector&& v);

  // Vector Element access
  // reference at(size_type pos);
  reference operator[](size_type pos) { return container_[pos]; }
  const_reference operator[](size_type pos) const { return container_[pos]; }
  // const_reference front();
  // const_reference back();
  // T* data();

  // Vector Iterators
  //   value_type* begin() { return &container_[0]; }
  //   const value_type* begin() const { return &container_[0]; }
  //   value_type* end() { return &container_[size_]; }
  //   const value_type* end() const { return &container_[size_]; }

  // Vector Capacity
  [[nodiscard]] bool empty() const { return size_ == 0; }
  [[nodiscard]] size_type size() const { return size_; }
  [[nodiscard]] size_type max_size() const { return capacity_ * sizeof(T); }
  [[nodiscard]] size_type capacity() const { return capacity_; }
  void reserve(size_type size);
  void shrink_to_fit();

  // Vector Modifiers
  // void clear();
  // iterator insert(iterator pos, const_reference value);
  // void erase(iterator pos);
  void push_back(const_reference value);
  // void pop_back();
  // void swap(vector& other);

  // helper
  void bring_to_zero();
  void add_memory(size_type size, bool flag);
  size_type add_memory_size(size_type size, bool flag);
  void copy_vector(const Vector& v);
  void remove();

 private:
  size_type size_;
  size_type capacity_;
  value_type* container_;
};
}  // namespace s21
#endif  // VECTOR_H