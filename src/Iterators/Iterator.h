#ifndef AVL_ITERATOR_H_
#define AVL_ITERATOR_H_

#include "../avl_tree.tpp"

namespace s21 {
template <typename T>
class Iterator {
 public:
  using key_type = T;
  using value_type = T;
  using reference = T&;
  using const_reference = const reference;
  using pointer = T*;

  Iterator(Node<T>* node = nullptr) : node_(node) {}

  Iterator& operator++() {
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
      Node<T>* parent = node_->parent;
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

 private:
  Node<T>* node_;
};
template <typename T>
class ConstIterator {
 public:
  using key_type = T;
  using value_type = T;
  using reference = const T&;  // use const reference
  using const_reference = reference;
  using pointer = const T*;  // use const pointer
  ConstIterator(const Node<T>* node = nullptr) : node_(node) {}

  ConstIterator& operator++() {
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

  ConstIterator operator++(int) {
    ConstIterator tmp = *this;
    ++(*this);
    return tmp;
  }

  ConstIterator& operator--() {
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

  ConstIterator operator--(int) {
    ConstIterator tmp = *this;
    --(*this);
    return tmp;
  }
  bool operator==(const ConstIterator& other) const {
    return node_ == other.node_;
  }
  bool operator!=(const ConstIterator& other) const {
    return node_ != other.node_;
  }

  reference operator*() const { return node_->key; }
  pointer operator->() const { return &(node_->key); }

 private:
  const Node<T>* node_;
};
}  // namespace s21
#endif  // AVL_ITERATOR_H_
