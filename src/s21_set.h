#ifndef AVL_SET_H_
#define AVL_SET_H_

#include <iterator>

#include "avl_tree.tpp"

namespace s21 {

template <typename T>
class Set {
 public:
  // iterator class
  class Iterator {
   public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    explicit Iterator(Node<T>* node = nullptr) : node_(node) {}

    reference operator*() const { return node_->key; }
    pointer operator->() const { return &(node_->key); }

    Iterator& operator++() {
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

    friend bool operator==(const Iterator& a, const Iterator& b) {
      return a.node_ == b.node_;
    }

    friend bool operator!=(const Iterator& a, const Iterator& b) {
      return a.node_ != b.node_;
    }

   private:
    Node<T>* node_;
  };

  Set() : tree_() {}
  ~Set() {}

  void insert(T key) { tree_.insert(key); }

  void remove(T key) { tree_.remove(key); }

  bool contains(T key) const { return tree_.search(key) != nullptr; }

  Iterator begin() {
    Node<T>* node = tree_.getRoot();
    if (node == nullptr) return Iterator(nullptr);
    while (node->left != nullptr) node = node->left;
    return Iterator(node);
  }

  Iterator end() { return Iterator(nullptr); }

 private:
  AVLTree<T> tree_;
};

}  // namespace s21

#endif  // AVL_SET_H_