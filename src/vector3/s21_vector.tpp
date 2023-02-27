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
  this->copy_vector(v);
}

template <class value_type>
Vector<value_type>::Vector(Vector&& v) {
  this->size_ = v.size_;
  this->capacity_ = v.capacity_;
  this->container_ = v.container_;
  v.bring_to_zero();
}

template <class value_type>
Vector<value_type>::~Vector() {
  this->remove();
}

template <class value_type>
Vector<value_type>& Vector<value_type>::operator=(const Vector&& v) {
  this->copy_vector(v);
  return *this;
}

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
void Vector<value_type>::add_memory(size_type size, bool flag) {
  this->capacity_ = this->add_memory_size(size, flag);
  value_type* tmp = this->container_;
  this->container_ = new value_type[this->capacity_];
  for (size_t i = 0; i < this->size_; ++i) {
    this->container_[i] = tmp[i];
  }
  delete[] tmp;
}

template <typename value_type>
[[nodiscard]] typename Vector<value_type>::size_type
Vector<value_type>::add_memory_size(size_type size, bool flag) {
  size_type n = 2;
  if (this->size_ > 1e+5) {
    n = 1.0;
  } else if (this->size_ > 1e+4) {
    n = 1.3;
  } else if (this->size_ > 1e+3) {
    n = 1.5;
  }
  return flag ? size : n * this->capacity_;
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

template <class value_type>
void Vector<value_type>::push_back(const_reference value) {
  if (this->size_ >= this->capacity_) {
    add_memory(0, false);
  }
  this->container_[this->size_++] = value;
}

// Vector Capacity
template <class value_type>
void Vector<value_type>::reserve(size_type size) {
  if (size > this->size_) {
    this->add_memory(size, true);
  }
}

/*---current---*/
template <class value_type>
void Vector<value_type>::shrink_to_fit() {
  if (this->size_ < this->capacity_) {
    this->add_memory(this->size_, true);
  }
}
/*---current---*/