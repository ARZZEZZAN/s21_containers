#ifndef AVL_ITERATOR_H_
#define AVL_ITERATOR_H_

#include "../avl_tree.tpp"

namespace s21 {

template <typename T, typename Ref, typename Ptr>
class IteratorBase {
 public:
  using key_type = T;
  using reference = Ref;
  using const_reference = const Ref;
  using pointer = Ptr;

  IteratorBase(Node<T>* node = nullptr) : node_(node) {}

  IteratorBase& operator++() {
    if (this->node_ == nullptr) {
      throw std::length_error("Node is nullptr");
    }
    if (node_->right != nullptr) {
      node_ = node_->right;
      while (node_->left != nullptr) node_ = node_->left;
    } else {
      Node<T>* parent = node_->parent;
      while (parent != nullptr && node_ == parent->right) {
        node_ = parent;
        parent = parent->parent;
      }
      node_ = parent;
    }
    return *this;
  }

  IteratorBase operator++(int) {
    IteratorBase tmp = *this;
    ++(*this);
    return tmp;
  }

  IteratorBase& operator--() {
    if (this->node_ == nullptr) {
      throw std::length_error("Node is nullptr");
    }
    if (this->node_ == nullptr) {
      throw std::length_error("Node is nullptr");
    }
    if (node_->left != nullptr) {
      node_ = node_->left;
      while (node_->right != nullptr) node_ = node_->right;
    } else {
      Node<T>* parent = node_->parent;
      while (parent != nullptr && node_ == parent->left) {
        node_ = parent;
        parent = parent->parent;
      }
      node_ = parent;
    }
    return *this;
  }

  IteratorBase operator--(int) {
    IteratorBase tmp = *this;
    --(*this);
    return tmp;
  }

  bool operator==(const IteratorBase& other) const {
    return node_ == other.node_;
  }
  bool operator!=(const IteratorBase& other) const {
    return node_ != other.node_;
  }

  reference operator*() const { return node_->key; }
  pointer operator->() const { return &(node_->key); }

 protected:
  Node<T>* node_;
};

template <typename T>
class Iterator : public IteratorBase<T, T&, T*> {
 public:
  using IteratorBase<T, T&, T*>::IteratorBase;

  using typename IteratorBase<T, T&, T*>::key_type;
  using typename IteratorBase<T, T&, T*>::reference;
  using typename IteratorBase<T, T&, T*>::const_reference;
  using typename IteratorBase<T, T&, T*>::pointer;
};

template <typename T>
class ConstIterator : public IteratorBase<T, const T&, const T*> {
 public:
  using IteratorBase<T, const T&, const T*>::IteratorBase;

  using typename IteratorBase<T, const T&, const T*>::key_type;
  using typename IteratorBase<T, const T&, const T*>::reference;
  using typename IteratorBase<T, const T&, const T*>::const_reference;
  using typename IteratorBase<T, const T&, const T*>::pointer;
};

}  // namespace s21

#endif