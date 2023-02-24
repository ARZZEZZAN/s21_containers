// gcc -Wall -Wextra -Werror -lstdc++ s21_vector.cc
#include "s21_vector.h"

using namespace s21;

// Vector Member functions
/// @brief Конструктор по умолчанию
/// @tparam value_type
/// @tparam allocator_type
template <class value_type, class allocator_type>
Vector<value_type, allocator_type>::Vector() {
  this->bring_to_zero();
}

/// @brief Параметризованный конструктор
/// @tparam value_type
/// @tparam allocator_type
/// @param n
template <class value_type, class allocator_type>
Vector<value_type, allocator_type>::Vector(size_type n) {
  this->size_ = n;
  this->capacity_ = n;
  this->container_ = new value_type[n];
}

/// @brief Конструктор списка инициализаторов
/// @tparam value_type
/// @tparam allocator_type
/// @param items
template <class value_type, class allocator_type>
Vector<value_type, allocator_type>::Vector(
    std::initializer_list<value_type> const &items) {
  this->capacity_ = this->size_ = items.size();
  if (this->size_) {
    this->container_ = new value_type[this->size_];
    std::copy(items.begin(), items.end(), this->container_);
  } else {
    this->bring_to_zero();
  }
}

/// @brief Конструктор копирования
/// @tparam value_type
/// @tparam allocator_type
/// @param v
template <class value_type, class allocator_type>
Vector<value_type, allocator_type>::Vector(const Vector &v) {
  this->bring_to_zero();
  *this = v;
}

// /// @brief Конструктор перемещения
// /// @tparam value_type
// /// @tparam allocator_type
// /// @param v
// template <class value_type, class allocator_type>
// Vector<value_type, allocator_type>::Vector(Vector &&v) {}

// Vector Modifiers
template <class value_type, class allocator_type>
typename Vector<value_type, allocator_type>::iterator
Vector<value_type, allocator_type>::insert(iterator pos,
                                           const_reference value) {
  this->size_++;
  if (this->container_ == nullptr) {
    this->capacity_ = 1;
    this->container_ = new value_type[this->capacity_];
    *this->container_ = value;
    return iterator(this->container_);
  }

  if (this->size_ <= this->capacity_) {
    std::memmove(pos.ptr_ + 1, pos.ptr_,
                 (size_ - 1) * sizeof(value_type) -
                     (pos.ptr_ - this->container_) * sizeof(value_type));
    *(pos.ptr_) = value;
    return iterator(pos);
  } else {
    this->capacity_ *= 2;
    pointer reallocated = new value_type[this->capacity_];

    std::memmove(reallocated, this->container_,
                 (size_ - 1) * sizeof(value_type));
    size_type p = pos.ptr_ - this->container_;
    delete[] this->container_;

    this->container_ = reallocated;

    if (p != this->size_ - 1) {
      std::memmove(this->container_ + p + 1, this->container_ + p,
                   (this->size_ - 1 - p) * sizeof(value_type));
    }

    *(this->container_ + p) = value;
    return iterator(this->container_ + p);
  }
}

// template <class value_type, class allocator_type>
// void Vector<value_type, allocator_type>::push_back(const_reference value) {
//   this->capacity_ = this->size_ = this - size_ + 1;
// }

// Helpers
template <class value_type, class allocator_type>
void Vector<value_type, allocator_type>::bring_to_zero() {
  this->size_ = 0;
  this->capacity_ = 0;
  this->container_ = nullptr;
}