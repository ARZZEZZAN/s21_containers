#include "s21_list.h"

namespace s21 {

//  List Functions
template <typename value_type>
list<value_type>::list() : head_(nullptr), tail_(nullptr), size_(0) {
  end_ = new Node(size_);
  add_end();
}

template <typename value_type>
list<value_type>::list(size_type n) {
  for (size_type i = 0; i < n; ++i) {
    push_back(value_type());
  }
  end_ = new Node(size_);
  add_end();
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

template <typename value_type>
typename list<value_type>::iterator list<value_type>::insert(
    iterator pos, const_reference value) {
  Node* current = pos.ptr_;
  Node* add = new Node(value);
  if (empty()) {
    add->next_ = end_;
    add->prev_ = end_;
    head_ = add;
    tail_ = add;
  } else {
    if (current == head_) {
      head_ = add;
    } else if (current == end_) {
      tail_ = add;
    }
    add->next_ = current;
    add->prev_ = current->prev_;
    current->prev_->next_ = add;
    current->prev_ = add;
  }

  size_++;
  add_end();
  return iterator(add);
}

template <typename value_type>
void list<value_type>::erase(iterator pos) {
  Node* current = pos.ptr_;
  if (!empty() && current != end_) {
    if (current == head_) {
      if (current->next_ && current->next_ != end_) {
        head_ = current->next_;
      }
    }
    current->prev_->next_ = current->next_;
    current->next_->prev_ = current->prev_;
    delete current;
    this->size_--;
  } else {
    throw std::invalid_argument("Invalid argument");
  }
}

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
  add_end();
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
    tail_->next_ = end_;
  }
  delete last_node;
  size_--;
  add_end();
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
  add_end();
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
  add_end();
}

template <typename value_type>
void list<value_type>::swap(list& other) {
  using std::swap;
  swap(this->head_, other.head_);
  swap(this->tail_, other.tail_);
  swap(this->size_, other.size_);
  swap(this->end_, other.end_);
}

template <typename value_type>
void list<value_type>::merge(list& other) {
  iterator iter_this = this->begin();
  iterator iter_other = other.begin();

  while (iter_this != this->end()) {
    if (iter_other != other.end()) {
      if (iter_this.ptr_->value_ >= iter_other.ptr_->value_) {
        this->insert(iter_this, iter_other.ptr_->value_);
        iter_other++;
      }
    } else {
      iter_this++;
    }
  }
  while (iter_other != other.end()) {
    this->insert(iter_this, iter_other.ptr_->value_);
  }
}

template <typename value_type>
void list<value_type>::splice(iterator pos, list& other) {
  for (iterator iter = other.begin(); iter != other.end(); ++iter) {
    this->insert(pos, *iter);
    other.erase(iter);
  }
}

template <typename value_type>
void list<value_type>::reverse() {
  size_type step = 0;
  for (iterator iter = this->begin(); step <= this->size(); ++iter) {
    step++;
    std::swap(iter.ptr_->prev_, iter.ptr_->next_);
  }
  std::swap(head_, tail_);
}

template <typename value_type>
void list<value_type>::unique() {
  for (iterator iter = this->begin(); iter != this->end(); ++iter) {
    if (iter.ptr_->next_ && iter.ptr_->next_ != end_) {
      if (iter.ptr_->value_ == iter.ptr_->next_->value_) {
        this->erase(iter);
      }
    }
  }
}

// helpers
template <typename value_type>
void print_list(list<value_type>& l) {
  for (auto i = l.begin(); i != l.end(); ++i) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
}

template <typename value_type>
void list<value_type>::add_end() {
  end_->next_ = head_;
  end_->prev_ = tail_;
  end_->value_ = size();
  if (head_) {
    head_->prev_ = end_;
  }
  if (tail_) {
    tail_->next_ = end_;
  }
}
}  // namespace s21
