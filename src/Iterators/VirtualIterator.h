#ifndef AVL_ITERATOR_H_
#define AVL_ITERATOR_H_

namespace s21 {
template <typename T>
class IteratorBase {
 public:
  using key_type = T;
  using value_type = T;
  using reference = T&;
  using const_reference = const reference;
  using pointer = T*;

  virtual ~IteratorBase() {}

  bool operator==(const IteratorBase& other) const {
    return node_ == other.node_;
  }
  bool operator!=(const IteratorBase& other) const {
    return node_ != other.node_;
  }
  reference operator*() const override { return node_->key; }
  pointer operator->() const override { return &(node_->key); }
  virtual IteratorBase& operator++() = 0;
  virtual IteratorBase operator++(int) = 0;
  virtual IteratorBase& operator--() = 0;
  virtual IteratorBase operator--(int) = 0;
};
}  // namespace s21
#endif  // AVL_ITERATOR_H_