#include "s21_list.h"

using namespace s21;

// Constructors
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

template <typename value_type>
list<value_type>::list(std::initializer_list<value_type> const& items)
    : head_(nullptr), tail_(nullptr), size_(0) {
  end_ = new Node(size_);
  for (const auto& item : items) {
    push_back(item);
    add_end();
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
  // std::swap(this->head_, l.head_);
  // std::swap(this->tail_, l.tail_);
  // std::swap(this->size_, l.size_);
  swap(l);  // TODO проверить точно ли правильно работает
}

template <typename value_type>
list<value_type>::~list() {
  clear();
  delete end_;
}

template <typename value_type>
typename list<value_type>::list& list<value_type>::operator=(list&& l) {
  if (this != &l) {
    clear();
    // std::swap(head_, l.head_);
    // std::swap(tail_, l.tail_);
    // std::swap(size_, l.size_);
    swap(l);  // TODO review
  }
  return *this;
}

template <typename value_type>
typename list<value_type>::const_reference list<value_type>::front() {
  if (empty()) {
    throw std::out_of_range("list is empty");
  }
  return head_->value_;
}

template <typename value_type>
typename list<value_type>::const_reference list<value_type>::back() {
  if (empty()) {
    throw std::out_of_range("list is empty");
  }
  return tail_->value_;
}

template <typename value_type>
void list<value_type>::print_list() {  // TODO review
  std::cout << "[";
  for (iterator it = begin(); it != end(); ++it) {
    std::cout << *it;
    if ((it + 1) != end()) {
      std::cout << ", ";
    }
  }
  std::cout << "]\n";
  // old {
  // for (auto i = this->begin(); i != this->end(); ++i) {
  //   std::cout << *i << " ";
  // }
  // std::cout << std::endl;
  // }
}

template <typename value_type>
bool list<value_type>::empty() {
  return size_ == 0;
}

template <typename value_type>
typename list<value_type>::size_type list<value_type>::size() {
  return size_;
}

template <typename value_type>
typename list<value_type>::size_type list<value_type>::max_size() {
  return std::numeric_limits<size_type>::max();
}

template <typename value_type>
void list<value_type>::clear() {
  while (!empty()) {
    pop_back();
  }
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::insert(
    iterator pos, const_reference value) {  // TODO review
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
  size_++;
  add_end();
  return iterator(add);
}

// void erase(iterator pos);

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
    tail_->next_ = nullptr;
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

// template <typename value_type>
// void list<value_type>::merge(list& other) {
//   if (&other == this) {
//     return;
//   }

//   if (empty()) {
//     head_ = other.head_;
//     tail_ = other.tail_;
//     size_ = other.size_;
//     other.head_ = nullptr;
//     other.tail_ = nullptr;
//     other.size_ = 0;
//     return;
//   }

//   if (other.empty()) {
//     return;
//   }

//   Node* this_node = head_;
//   Node* other_node = other.head_;

//   while (this_node && other_node) {
//     if (other_node->value_ < this_node->value_) {
//       Node* next_node = other_node->next_;
//       insert_node_before(this_node, other_node);
//       other_node = next_node;
//     } else {
//       this_node = this_node->next_;
//     }
//   }

//   if (other_node) {
//     tail_->next_ = other_node;
//     other_node->prev_ = tail_;
//     tail_ = other.tail_;
//     size_ += other.size_;
//     other.head_ = nullptr;
//     other.tail_ = nullptr;
//     other.size_ = 0;
//   }
// }

// void splice(const_iterator pos, list& other); TODO жду итераторы
// void reverse();
// void unique();

// template <typename value_type>
// void list<value_type>::sort_helper(iterator left, iterator right) {
//   if (left == right || left == end_ || right == end_ || left == tail_) {
//     return;
//   }
//   iterator pivot = partition(left, right);
//   sort_helper(left, pivot);
//   sort_helper(++pivot, right);
// }

// template <typename value_type>
// typename list<value_type>::iterator list<value_type>::partition(
//     iterator left, iterator right) {
//   iterator pivot = left;
//   iterator i = left;
//   iterator j = ++left;
//   while (j != right) {
//     if (*j < *pivot) {
//       ++i;
//       std::swap(*i, *j);
//     }
//     ++j;
//   }
//   if (*i > *pivot) {
//     std::swap(*i, *pivot);
//     return i;
//   } else {
//     return pivot;
//   }
// }

// template <typename value_type>
// void list<value_type>::sort() {
//   if (size_ <= 1) {
//     return;
//   }
//   sort_helper(begin(), --end());
// }

template <typename value_type>
void list<value_type>::sort() {
  
}

// ---------------support functions-----------------
template <typename value_type>
void list<value_type>::add_end() {
  if (end_) {
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
}

// -------------------------------------------------
