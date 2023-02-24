#include "s21_vector.h"
namespace s21 {

template <class value_type>
Vector<value_type>::Vector() {
  this->size_ = this->capacity_ = 0;
  this->container_ = nullptr;
}

template <class value_type>
Vector<value_type>::Vector(size_type n) {
  this->size_ = n;
  this->capacity_ = n;
  this->container_ = new value_type[n];
}

template <class value_type>
void Vector<value_type>::push_back1(reference value) {
  this->container_[0] = value;
}

}  // namespace s21