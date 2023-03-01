#include "s21_list.h"

using namespace s21;

// Constructor
template <typename value_type>
list<value_type>::list() : head_(nullptr), tail_(nullptr), size_(0) {}

template <typename value_type>
list<value_type>::list(size_type n) {
  for (size_type i = 0; i < n; ++i) {
    // TODO раскоментить после реализации push_back();
    // push_back(item);
  }
}
template <typename value_type>
list<value_type>::list(std::initializer_list<value_type> const& items)
    : head_(nullptr), tail_(nullptr), size_(0) {
  // for (const auto& item : items) {
  //   // push_back(item); TODO
  // }
}

template <typename value_type>
list<value_type>::list(const list& l)
    : head_(nullptr), tail_(nullptr), size_(0) {
  for (const auto& item : l) {
    // TODO раскоментить после реализации push_back();
    // push_back(item);
  }
}

template <typename value_type>
list<value_type>::list(list&& l) : head_(nullptr), tail_(nullptr), size_(0) {
  std::swap(this->head_, l.head_);
  std::swap(this->tail_, l.tail_);
  std::swap(this->size_, l.size_);
}

template <typename value_type>
list<value_type>::~list() {
  clear();
}

template <typename value_type>
typename list<value_type>::list& list<value_type>::operator=(list&& l) {
  if (this != &l) {
    clear();
    std::swap(head_, l.head_);
    std::swap(tail_, l.tail_);
    std::swap(size_, l.size_);
  }
  return *this;
}

template <typename value_type>
bool list<value_type>::empty() const {
  return size_ == 0;
}

template <typename value_type>
void list<value_type>::clear() {
  while (!empty()) {
    pop_back();
  }
}

// iterator insert(iterator pos, const_reference value);
// void erase(iterator pos);
// void push_back(const_reference value);

template <typename value_type>
void list<value_type>::pop_back() {
  if (!empty()) {
    auto last_node = tail_;
    tail_ = last_node->prev_;
    if (tail_) {
      tail_->next_ = nullptr;
    } else {
      head_ = nullptr;
    }
    delete last_node;
    --size_;
  }
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::insert(
    iterator pos, const_reference value) {
  size_type position = &(*pos) - this->container_;
  size_type zero = 0;
  if (zero > position || position > this->size_) {
    throw std::out_of_range("Index out ot range");
  }
  if (position = this->size_) {
    this->push_back(value);
  } else {
    Node<int> current;
    for (size_type i = 0; i <= position; ++i) {
      push_back(value_type());
    }

    value_type replace = this->container_[position];
    this->size_++;
    this->container_[position] = value;
    for (size_type i = position + 1; i < this->size_; ++i) {
      value_type next = this->container_[i];
      this->container_[i] = replace;
      replace = next;
    }
  }
  return this->container_ + position;
}

node* addNode(node* base, const T* value, bool route) {
  node* add = new node;
  if (value != nullptr) add->value = *value;
  route ? base->addPrev(add) : base->addNext(add);
  rootHead();
  size_++;
  return add;
}