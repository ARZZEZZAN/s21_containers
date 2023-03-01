#include "s21_list.h"

using namespace s21;

// Constructor
template <typename value_type>
list<value_type>::list() : head_(nullptr), tail_(nullptr), size_(0) {}

template <typename value_type>
list<value_type>::list(size_type n) {
  for (size_type i = 0; i < n; ++i) {
    push_back(value_type());
  }
}

template <typename value_type>
list<value_type>::list(std::initializer_list<value_type> const& items)
    : head_(nullptr), tail_(nullptr), size_(0) {
  for (const auto& item : items) {
    push_back(item);
  }
}

template <typename value_type>
list<value_type>::list(const list& l)
    : head_(nullptr), tail_(nullptr), size_(0) {
  for (const auto& item : l) {
    push_back(item);
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

template <typename value_type>
void list<value_type>::push_back(const value_type& value) {
  auto new_node = new Node(value);
  if (empty()) {
    head_ = new_node;
  } else {
    new_node->prev_ = tail_;
    tail_->next_ = new_node;
  }
  tail_ = new_node;
  ++size_;
}

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
void list<value_type>::push_front(const value_type& value) {
  auto new_node = new Node(value);
  if (empty()) {
    tail_ = new_node;
  } else {
    new_node->next_ = head_;
    head_->prev_ = new_node;
  }
  head_ = new_node;
  ++size_;
}

// void pop_front();
// void swap(list& other);
// void merge(list& other);
// void splice(const_iterator pos, list& other);
// void reverse();
// void unique();
// void sort();

// TODO сделать Iterator
// template <typename value_type>
// void print_list(list<value_type>& l) {
//   for (auto i = l.begin(); i != l.end(); ++i) {
//     std::cout << *i << " ";
//   }
//   std::cout << std::endl;
// }
