#include "s21_list.h"

namespace s21 {

//  List Functions
template <typename value_type>
list<value_type>::list() : head_(nullptr), tail_(nullptr), size_(0) {}

template <typename value_type>
list<value_type>::list(size_type n) {
  for (size_type i = 0; i < n; ++i) {
    push_back(value_type());
  }
}

// template <typename value_type>
// list<value_type>::list(std::initializer_list<value_type> const& items)
//     : head_(nullptr), tail_(nullptr), size_(0) {
//   for (const auto& item : items) {
//     push_back(item);
//   }
// }

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

// List Modifiers
template <typename value_type>
void list<value_type>::clear() {
  while (!empty()) {
    pop_back();
  }
}

/* current */
template <typename value_type>
typename list<value_type>::iterator list<value_type>::insert(
    iterator pos, const_reference value) {
  Node* current = pos.ptr_;
  Node* add = new Node(value);
  if (!current) {
    // add to tail
    tail_->next_ = add;
    add->prev_ = tail_;
    tail_ = add;
  } else if (!current->prev_) {
    // add to head
    head_->prev_ = add;
    add->next_ = head_;
    head_ = add;
  } else {
    // add between
    add->next_ = current;
    add->prev_ = current->prev_;
    current->prev_->next_ = add;
    current->prev_ = add;
  }
  return iterator(add);
}

/* current */

template <typename value_type>
void list<value_type>::push_back(const_reference value) {
  Node* new_node = new Node(value);
  if (empty()) {
    head_ = new_node;
    tail_ = new_node;
  } else {
    new_node->prev_ = tail_;
    tail_->next_ = new_node;
    tail_ = new_node;
  }
  size_++;
}

template <typename value_type>
void list<value_type>::pop_back() {
  if (empty()) {
    throw std::out_of_range("list is empty");
  }
  Node* last_node = tail_;
  if (size_ == 1) {
    head_ = nullptr;
    tail_ = nullptr;
  } else {
    tail_ = last_node->prev_;
    tail_->next_ = nullptr;
  }
  delete last_node;
  size_--;
}

template <typename value_type>
void list<value_type>::push_front(const_reference value) {
  Node* new_node = new Node(value);
  if (empty()) {
    head_ = new_node;
    tail_ = new_node;
  } else {
    new_node->next_ = head_;
    head_->prev_ = new_node;
    head_ = new_node;
  }
  size_++;
}

template <typename value_type>
void list<value_type>::pop_front() {
  if (empty()) {
    throw std::out_of_range("list is empty");
  }
  Node* first_node = head_;
  if (size_ == 1) {
    head_ = nullptr;
    tail_ = nullptr;
  } else {
    head_ = first_node->next_;
    head_->prev_ = nullptr;
  }
  delete first_node;
  size_--;
}

template <typename value_type>
void list<value_type>::swap(list& other) {
  using std::swap;
  swap(this->head_, other.head_);
  swap(this->tail_, other.tail_);
  swap(this->size_, other.size_);
}

template <typename value_type>
void list<value_type>::merge(list& other) {}

// helpers
template <typename value_type>
void print_list(list<value_type>& l) {
  for (auto i = l.begin(); i != l.end(); ++i) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
}
}  // namespace s21