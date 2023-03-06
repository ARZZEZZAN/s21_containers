#include "s21_list.h"
namespace s21 {

template <typename value_type>
list<value_type>::list()
    : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
  end_ = new Node(size_);
  add_end();
}

template <typename value_type>
list<value_type>::list(size_type n)
    : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
  if (n >= max_size()) {
    throw std::out_of_range("Limit of the container is exceeded");
  }
  end_ = new Node(size_);
  for (size_type i = 0; i < n; ++i) {
    push_back(value_type());
  }
  add_end();
}

template <typename value_type>
list<value_type>::list(std::initializer_list<value_type> const& items)
    : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
  end_ = new Node(size_);
  for (const auto& item : items) {
    push_back(item);
    add_end();
  }
}

template <typename value_type>
list<value_type>::list(const list& l)  // TODO need review
    : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
  end_ = new Node(size_);
  Node* current = l.head_;
  for (size_type i = 0; i != l.size_; i++) {
    push_back(current->value_);
    current = current->next_;
  }
}

template <typename value_type>
list<value_type>::list(list&& l)
    : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
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
void list<value_type>::splice(const_iterator pos, list& other) {
  for (iterator it = other.begin(); it != other.end(); ++it) {
    this->insert(pos, *it);
    other.erase(it);
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

template <typename value_type>
void list<value_type>::merge(list& other) {
  iterator iter_this = this->begin();
  iterator iter_other = other.begin();

  while (iter_this != this->end()) {
    if (iter_other != other.end()) {
      if (iter_this.ptr_->value_ >= iter_other.ptr_->value_) {
        this->insert(iter_this, iter_other.ptr_->value_);
        iter_other++;
      } else {
        iter_this++;
      }
    } else {
      iter_this++;
    }
  }
  while (iter_other != other.end()) {
    this->insert(iter_this, iter_other.ptr_->value_);
    iter_other++;
  }
}

template <typename value_type>
void list<value_type>::reverse() {
  size_type step = 0;
  for (iterator it = this->begin(); step <= this->size(); ++it) {
    step++;
    std::swap(it.ptr_->prev_, it.ptr_->next_);
  }
  std::swap(head_, tail_);
}

template <typename value_type>
void list<value_type>::unique() {
  for (iterator it = this->begin(); it != this->end(); it++) {
    if (it.ptr_->value_ == it.ptr_->prev_->value_) {
      iterator del_it = (it - 1);
      this->erase(del_it);
    }
  }
}

template <typename value_type>
void list<value_type>::sort() {
  if (size_ > 1) {
    quick_sort(begin(), --end());
  }
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

template <typename value_type>
void list<value_type>::quick_sort(iterator first, iterator last) {
  if (first == last || first == end_ || last == end_ || first == tail_) {
    return;
  }
  iterator pivot = partition(first, last);
  quick_sort(first, --pivot);
  quick_sort(++pivot, last);
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::partition(iterator first,
                                                                iterator last) {
  value_type pivot_value = last.ptr_->value_;
  iterator i = first;

  for (iterator j = first; j != last; ++j) {
    if (j.ptr_->value_ <= pivot_value) {
      std::swap(i.ptr_->value_, j.ptr_->value_);
      i++;
    }
  }

  std::swap(i.ptr_->value_, last.ptr_->value_);

  return i;
}
}  // namespace s21