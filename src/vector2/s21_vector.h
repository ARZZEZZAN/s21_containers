#ifndef S21_VECTOR_HPP
#define S21_VECTOR_HPP
// #include <cstddef>
#define size_tt

namespace s21 {

template <class T>
class Vector {
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_tt;

 public:
  Vector();
  Vector(size_type n);
  reference operator[](size_type pos);

  void push_back1(reference value);

 private:
  size_type size_;
  size_type capacity_;
  value_type *container_;
};

}  // namespace s21

#endif  // S21_VECTOR_HPP
