#ifndef AVL_VIRTITERATOR_H_
#define AVL_VIRTITERATOR_H_

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

  virtual bool operator==(const IteratorBase& other) const = 0;
  virtual bool operator!=(const IteratorBase& other) const = 0;

  virtual reference operator*() const = 0;
  virtual pointer operator->() const = 0;

  virtual IteratorBase<T>& operator++() = 0;
  virtual IteratorBase<T>& operator++(int) = 0;
  virtual IteratorBase<T>& operator--() = 0;
  virtual IteratorBase<T>& operator--(int) = 0;
};
}  // namespace s21
#endif  // AVL_VIRTITERATOR_H_