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
  // std::swap(this->head_, l.head_);
  // std::swap(this->tail_, l.tail_);
  // std::swap(this->size_, l.size_);
  swap(l);  // TODO проверить точно ли правильно работает
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

// iterator insert(iterator pos, const_reference value);
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

template <typename value_type>
void list<value_type>::sort() {
  if (size_ > 1) {
    Node* pivot = head_;
    Node* current = head_->next_;
    Node* last = tail_;
    while (current != nullptr) {
      if (current->value_ < pivot->value_) {
        Node* tmp = current;
        current = current->next_;
        tmp->prev_->next_ = tmp->next_;
        if (tmp->next_ != nullptr) {
          tmp->next_->prev_ = tmp->prev_;
        } else {
          last = tmp->prev_;
        }
        tmp->prev_ = nullptr;
        tmp->next_ = head_;
        head_->prev_ = tmp;
        head_ = tmp;
      } else {
        current = current->next_;
      }
    }
    list<value_type> left_half;
    list<value_type> right_half;
    pivot->prev_->next_ = nullptr;
    pivot->prev_ = nullptr;
    left_half.head_ = head_;
    left_half.tail_ = pivot;
    right_half.head_ = pivot->next_;
    right_half.tail_ = last;
    left_half.size_ = 1;
    right_half.size_ = size_ - 1;
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
    left_half.sort();
    right_half.sort();
    if (left_half.size_ > 0) {
      head_ = left_half.head_;
      left_half.tail_->next_ = pivot;
      pivot->prev_ = left_half.tail_;
      size_ += left_half.size_;
    } else {
      head_ = pivot;
    }
    if (right_half.size_ > 0) {
      if (left_half.size_ == 0) {
        pivot->prev_ = nullptr;
      }
      pivot->next_ = right_half.head_;
      right_half.head_->prev_ = pivot;
      tail_ = right_half.tail_;
      size_ += right_half.size_;
    } else {
      tail_ = pivot;
    }
  }
}

// TODO сделать Iterator
// template <typename value_type>
// void print_list(list<value_type>& l) {
//   for (auto i = l.begin(); i != l.end(); ++i) {
//     std::cout << *i << " ";
//   }
//   std::cout << std::endl;
// }

// ---------------support functions-----------------
template <typename value_type>
void list<value_type>::print_list() {  // TODO review
  std::cout << "[";
  for (Node* node = head_; node; node = node->next_) {
    std::cout << node->value_;
    if (node->next_) {
      std::cout << ", ";
    }
  }
  std::cout << "]\n";
}
// -------------------------------------------------
