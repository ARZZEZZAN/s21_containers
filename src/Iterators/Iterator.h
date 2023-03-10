#ifndef AVL_ITERATOR_H_
#define AVL_ITERATOR_H_

#include "../AvlTree/avl_tree.tpp"

namespace s21 {

template <typename T, typename V>
class Iterator {
 public:
  using key_type = T;
  using reference = T&;
  using const_reference = const reference;
  using pointer = T*;

  Iterator(Node<T, V>* node = nullptr) : node_(node) {}
  Iterator operator+(const size_t value) {
    Iterator tmp = *this;
    for (size_t i = 0; i < value; i++) {
      ++tmp;
    }
    return tmp;
  }
  Iterator& operator++() {
    if (this->node_ == nullptr) {
      throw std::length_error("Node is nullptr");
    }
    if (this->node_->right != nullptr) {
      this->node_ = this->node_->right;
      while (this->node_->left != nullptr) {
        this->node_ = this->node_->left;
      }
    } else {
      Node<T, V>* parent = this->node_->parent;
      while (parent != nullptr && this->node_ == parent->right) {
        this->node_ = parent;
        parent = parent->parent;
      }
      this->node_ = parent;
    }
    return *this;
  }
  Iterator operator++(int) {
    Iterator tmp = *this;
    ++(*this);
    return tmp;
  }
  Iterator& operator--() {
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
      Node<T, V>* parent = node_->parent;
      while (parent != nullptr && node_ == parent->left) {
        node_ = parent;
        parent = parent->parent;
      }
      node_ = parent;
    }
    return *this;
  }

  Iterator operator--(int) {
    Iterator tmp = *this;
    --(*this);
    return tmp;
  }

  bool operator==(const Iterator& other) const { return node_ == other.node_; }
  bool operator!=(const Iterator& other) const { return node_ != other.node_; }

  reference operator*() const { return node_->key; }
  pointer operator->() const { return &(node_->key); }

 protected:
  Node<T, V>* node_;
};

template <typename T, typename V>
class ConstIterator : public Iterator<const T, const V> {
 public:
  using Iterator<const T, const V>::Iterator;

  using typename Iterator<const T, const V>::key_type;
  using typename Iterator<const T, const V>::reference;
  using typename Iterator<const T, const V>::const_reference;
  using typename Iterator<const T, const V>::pointer;
};

}  // namespace s21

#endif  // AVL_ITERATOR_H_