#ifndef S21_LIST_H
#define S21_LIST_H

#include <initializer_list>
#include <iostream>
#include <limits>

namespace s21 {

template <typename T>
class list {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = std::size_t;

 private:
  struct Node {
    value_type value_;
    Node* prev_;
    Node* next_;

    Node(const value_type& value)
        : value_(value), prev_(nullptr), next_(nullptr) {}
  };

  Node* head_;
  Node* tail_;
  Node* end_;
  size_type size_;

 public:
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const& items);
  list(const list& l);
  list(list&& l);
  ~list();
  list& operator=(list&& l);

  const_reference front();
  const_reference back();

  void print_list();  // TODO review

  bool empty();
  size_type size();      // TODO review
  size_type max_size();  // TODO review

  void clear();  //
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list& other);
  void merge(list& other);  // TODO review
  void reverse();           // TODO review
  void unique();            // TODO review
  void sort();              // TODO review

  template <typename value_type>
  class ListConstIterator;

  template <typename value_type>
  class ListIterator {
    friend class ListConstIterator<T>;
    friend class list<T>;

   public:
    ListIterator() { ptr_ = nullptr; }
    ListIterator(Node* ptr) : ptr_(ptr){};

    reference operator*() { return this->ptr_->value_; }

    ListIterator operator++(int) {
      ptr_ = ptr_->next_;
      return *this;
    }

    ListIterator operator--(int) {
      ptr_ = ptr_->prev_;
      return *this;
    }

    ListIterator& operator++() {
      ptr_ = ptr_->next_;
      return *this;
    }

    ListIterator& operator--() {
      // if (!ptr_) {
      //   throw std::invalid_argument("hui");
      // }
      ptr_ = ptr_->prev_;
      return *this;
    }

    ListIterator operator+(const size_type value) {
      Node* tmp = ptr_;
      for (size_type i = 0; i < value; i++) {
        tmp = tmp->next_;
      }

      ListIterator res(tmp);
      return res;
    }

    ListIterator operator-(const size_type value) {
      Node* tmp = ptr_;
      for (size_type i = 0; i < value; i++) {
        tmp = tmp->prev_;
      }
      ListIterator res(tmp);
      return res;
    }

    // ListIterator& operator=(const ListIterator other) {
    //   this->ptr_ = other->ptr_;
    //   return *this;
    // }

    bool operator==(ListIterator other) { return this->ptr_ == other.ptr_; }

    bool operator!=(ListIterator other) { return this->ptr_ != other.ptr_; }

   private:
    Node* ptr_ = nullptr;
  };

  using iterator = ListIterator<T>;             // TODO
  using const_iterator = ListConstIterator<T>;  // TODO

  iterator begin() { return iterator(head_); }  // TODO
  iterator end() { return iterator(end_); }     // TODO

  iterator insert(iterator pos, const_reference value);  // TODO
  void erase(iterator pos);                              // TODO
  void splice(iterator pos,
              list& other);  // TODO поменять iterator на const_iterator

 private:
  // TODO все вспомогательные функции закинуть в private
  // ---------------support functions-----------------
  void add_end();  // TODO review и поменять название на change_end()
  // void sort_helper(iterator left, iterator right);
  // iterator partition(iterator left, iterator right);
};
}  // namespace s21
#endif  // S21_LIST_H

// --------------

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

// template <typename value_type>
// void list<value_type>::reverse() {
//   if (empty()) {
//     return;
//   }

//   Node* current_node = head_;
//   while (current_node) {
//     Node* next_node = current_node->next_;
//     current_node->next_ = current_node->prev_;
//     current_node->prev_ = next_node;
//     current_node = next_node;
//   }

//   std::swap(head_, tail_);
// }

// template <typename value_type>
// void list<value_type>::unique() {
//   if (empty()) {
//     return;
//   }

//   Node* current_node = head_;
//   while (current_node && current_node->next_) {
//     if (current_node->value_ == current_node->next_->value_) {
//       Node* duplicate_node = current_node->next_;
//       current_node->next_ = duplicate_node->next_;
//       if (duplicate_node->next_) {
//         duplicate_node->next_->prev_ = current_node;
//       } else {
//         tail_ = current_node;
//       }
//       delete duplicate_node;
//       size_--;
//     } else {
//       current_node = current_node->next_;
//     }
//   }
// }

// template <typename value_type>
// void list<value_type>::sort() {
//   if (size_ < 2) {
//     return;
//   }

//   list left_half;
//   list right_half;
//   split(left_half, right_half);

//   left_half.sort();
//   right_half.sort();

//   merge_sorted_lists(left_half, right_half);
// }

// template <typename value_type>
// void list<value_type>::split(list& left_half, list& right_half) {
//   Node* middle_node = head_;
//   Node* current_node = head_;
//   while (current_node) {
//     current_node = current_node->next_;
//     if (current_node) {
//       current_node = current_node->next_;
//       middle_node = middle_node->next_;
//     }
//   }

//   left_half.head_ = head_;
//   left_half.tail_ = middle_node;
//   right_half.head_ = middle_node->next_;
//   right_half.tail_ = tail_;

//   left_half.size_ = (size_ + 1) / 2;
//   right_half.size_ = size_ / 2;

//   middle_node->prev_->next_ = nullptr;
//   middle_node->prev_ = nullptr;

//   head_ = nullptr;
//   tail_ = nullptr;
//   size_ = 0;
// }

// template <typename value_type>
// void list<value_type>::merge_sorted_lists(list& left_half, list& right_half)
// {
//   if (left_half.empty()) {
//     *this = right_half;
//     right_half.head_ = nullptr;
//     right_half.tail_ = nullptr;
//     right_half.size_ = 0;
//     return;
//   }
//   if (right_half.empty()) {
//     *this = left_half;
//     left_half.head_ = nullptr;
//     left_half.tail_ = nullptr;
//     left_half.size_ = 0;
//     return;
//   }

//   Node* left_node = left_half.head_;
//   Node* right_node = right_half.head_;
//   Node* this_node = nullptr;
//   if (left_node->value_ < right_node->value_) {
//     this_node = left_node;
//     left_node = left_node->next_;
//   } else {
//     this_node = right_node;
//     right_node = right_node->next_;
//   }
//   head_ = this_node;

//   while (left_node && right_node) {
//     Node*& _node =
//         (left_node->value_ < right_node->value_) ? left_node : right_node;
//     this_node->next_ = _node;
//     _node->prev_ = this_node;
//     this_node = this_node->next_;
//     _node = _node->next_;
//   }

//   while (left_node) {
//     this_node->next_ = left_node;
//     left_node->prev_ = this_node;
//     this_node = this_node->next_;
//     left_node = left_node->next_;
//   }

//   while (right_node) {
//     this_node->next_ = right_node;
//     right_node->prev_ = this_node;
//     this_node = this_node->next_;
//     right_node = right_node->next_;
//   }

//   tail_ = this_node->prev_;
//   size_ = left_half.size_ + right_half.size_;
//   left_half.head_ = nullptr;
//   left_half.tail_ = nullptr;
//   left_half.size_ = 0;
//   right_half.head_ = nullptr;
//   right_half.tail_ = nullptr;
//   right_half.size_ = 0;
// }

// ---------------------------------------------