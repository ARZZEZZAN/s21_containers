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

  const_reference front() { return !head_ ? end_->value_ : head_->value_; }
  const_reference back() { return !tail_ ? end_->value_ : tail_->value_; }

  void print_list();  // TODO review

  bool empty() { return size_ == 0; }
  size_type size() { return size_; }
  size_type max_size();

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
  class ListIterator {
   public:
    ListIterator() { ptr_ = nullptr; }
    ListIterator(Node* ptr) : ptr_(ptr){};

    reference operator*() {
      if (!this->ptr_) {
        throw std::invalid_argument("Value is nullptr");
      }
      return this->ptr_->value_;
    }

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

    bool operator==(ListIterator other) { return this->ptr_ == other.ptr_; }

    bool operator!=(ListIterator other) { return this->ptr_ != other.ptr_; }

   private:
    Node* ptr_ = nullptr;
    friend class list<T>;
  };

  template <typename value_type>
  class ListConstIterator : public ListIterator<T> {
   public:
    ListConstIterator(ListIterator<T> other) : ListIterator<T>(other) {}
    const T& operator*() { return ListIterator<T>::operator*(); }
  };

  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;

  iterator begin() { return !head_ ? iterator(end_) : iterator(head_); }
  iterator end() { return iterator(end_); }
  const_iterator begin() const {
    return !head_ ? const_iterator(end_) : const_iterator(head_);
  }
  const_iterator end() const { return const_iterator(end_); }

  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void splice(const_iterator pos, list& other);

 private:
  // ---------------support functions-----------------
  void
  change_end();  // TODO review и поменять название на change_end() и убрать
                 // излишний вызов например в push и поп он вызывается, после
                 // push мы вызываем change_end который уже был вызван в push
  void quick_sort(iterator left, iterator right);
  iterator partition(iterator first, iterator last);
  void copy(const list& l);
};
}  // namespace s21
#endif  // S21_LIST_H
