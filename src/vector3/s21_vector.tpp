#include "Vector.h"
using namespace s21;

// Vector Member functions
template <typename value_type>
Vector<value_type>::Vector() {
  this->bring_to_zero();
}

template <class value_type>
Vector<value_type>::Vector(size_type n) {
  this->size_ = n;
  this->capacity_ = n;
  this->container_ = new value_type[n];
}

template <class value_type>
Vector<value_type>::Vector(std::initializer_list<value_type> const& items) {
  this->capacity_ = this->size_ = items.size();
  if (this->size_) {
    this->container_ = new value_type[this->size_];
    std::copy(items.begin(), items.end(), this->container_);
  } else {
    this->bring_to_zero();
  }
}

template <class value_type>
Vector<value_type>::Vector(const Vector& v) {
  this->bring_to_zero();
  *this = v;
}

template <class value_type>
Vector<value_type>::Vector(Vector&& v) {
  this->bring_to_zero();
  if (this->container_ != v.container_) {
    *this = std::move(v);
    v.bring_to_zero();
  }
}

template <class value_type>
Vector<value_type>::~Vector() {
  this->remove();
}

template <class value_type>
Vector<value_type>& Vector<value_type>::operator=(const Vector&& v) {
  if (this->container_ != v.container_) {
    this->remove();
    this->copy_vector(v);
  }
  return *this;
}

// template <class value_type>
// Vector<value_type>& Vector<value_type>::operator=(const Vector&& v) {
//   if (this->arr_ != v.arr_) {
//     if (this->arr_ != nullptr) {
//       delete[] this->arr_;
//     }
//     if (this->m_capacity_ < v.m_size_) {
//       this->m_capacity_ = v.m_capacity_;
//     }

//     this->m_size_ = v.m_size_;
//     this->arr_ = this->get_memory(this->m_capacity_);
//     for (size_type i = 0; i < this->m_size_; ++i) this->arr_[i] = v.arr_[i];
//   }
//   return *this;
// }

// Helpers
template <class value_type>
void Vector<value_type>::copy_vector(const Vector& v) {
  this->remove();
  this->size_ = v.size_;
  this->capacity_ = v.capacity_;
  this->container_ = new value_type[this->size_];
  for (int i = 0; i < this->size_; i++) {
    this->container_[i] = v.container_[i];
  }
}

template <typename value_type>
void Vector<value_type>::add_memory() {
  capacity_ *= 2;
  value_type* tmp = container_;
  container_ = new value_type[capacity_];
  for (size_t i = 0; i < size_; ++i) {
    container_[i] = tmp[i];
  }
  delete[] tmp;
}

template <class value_type>
void Vector<value_type>::bring_to_zero() {
  this->size_ = 0;
  this->capacity_ = 0;
  this->container_ = nullptr;
}

template <class value_type>
void Vector<value_type>::remove() {
  if (this->container_ != nullptr) {
    delete[] this->container_;
  }
  this->container_ = nullptr;
  this->size_ = this->capacity_ = 0;
}