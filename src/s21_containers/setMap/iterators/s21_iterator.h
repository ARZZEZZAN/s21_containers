#ifndef AVL_ITERATOR_H_
#define AVL_ITERATOR_H_

#include "../avlTree/s21_avl_tree.tpp"

namespace s21 {

template <typename T, typename V>
class Iterator {
 public:
  using key_type = T;
  using reference = T&;
  using const_reference = const reference;
  using pointer = T*;

  Iterator(Node<T, V>* node = nullptr) : node_(node) {}
  Iterator(Node<T, V>* nil, Node<T, V>* root) : node_(nil), root_(root) {}
  Iterator(const Iterator&) = default;
  Iterator& operator=(const Iterator&) = default;
  ~Iterator() = default;
  Iterator operator+(const size_t value) {
    Iterator tmp = *this;
    for (size_t i = 0; i < value; i++) {
      ++tmp;
    }
    return tmp;
  }
  Iterator& operator++() {
    if (node_ != nullptr) {
      if (node_->right != nullptr) {
        node_ = node_->right;
        while (node_->left != nullptr) {
          node_ = node_->left;
        }
      } else {
        Node<T, V>* parent = node_->parent;
        while (parent != nullptr && node_ == parent->right) {
          node_ = parent;
          parent = parent->parent;
        }
        node_ = parent;
      }
      return *this;
    }
    return *this;
  }

  Iterator operator++(int) {
    Iterator tmp = *this;
    ++(*this);
    return tmp;
  }
  Iterator& operator--() {
    if (Size(root_) > 0) {
      if (node_ != nullptr) {
        return OperatorHelper();
      }
      node_ = MaximumKey(root_);
      return *this;
    }
    return OperatorHelper();
  }

  Iterator operator--(int) {
    Iterator tmp = *this;
    --(*this);
    return tmp;
  }

  bool operator==(const Iterator& other) const { return node_ == other.node_; }
  bool operator!=(const Iterator& other) const { return node_ != other.node_; }

  reference operator*() const {
    if (node_ == nullptr) {
      static T default_value = T{};
      return default_value;
    }
    return node_->key;
  }
  pointer operator->() const { return &(node_->key); }
  int Size(Node<T, V>* node) {
    if (node) {
      return node->size_;
    }
    return 0;
  }
  Node<T, V>* MaximumKey(Node<T, V>* node) {
    if (node != nullptr) {
      while (node->right != nullptr) {
        return this->MaximumKey(node->right);
      }
      return node;
    }
    return nullptr;
  }
  Iterator& OperatorHelper() {
    if (node_ != nullptr) {
      if (node_->left != nullptr) {
        node_ = node_->left;
        while (node_->right != nullptr) {
          node_ = node_->right;
        }
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
    return *this;
  }

 protected:
  Node<T, V>* node_;
  Node<T, V>* root_;
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