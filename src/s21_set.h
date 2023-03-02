#ifndef AVL_SET_H_
#define AVL_SET_H_

#include <iterator>
#include <limits>

#include "avl_tree.tpp"

namespace s21 {

template <typename T>
class Set {
 public:
  // iterator class
  using key_type = T;
  using value_type = T;
  using reference = T&;
  using const_reference = const reference;
  using size_type = size_t;
  using iterator_category = std::forward_iterator_tag;
  using difference_type = std::ptrdiff_t;
  using pointer = T*;
  using Allocator = std::allocator<T>;
  class Iterator {
   public:
    explicit Iterator(Node<T>* node = nullptr) : node_(node) {}
    reference operator*() const { return node_->key; }
    pointer operator->() const { return &(node_->key); }
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

  Iterator begin() {
    Node<T>* node = tree_.getRoot();
    while (node != nullptr && node->left != nullptr) {
      node = node->left;
    }
    return Iterator(node);
  }
  Iterator end() { return Iterator(nullptr); }
  bool contains(const T& key) { return tree_.search(key) != nullptr; }
  void merge(Set<T>& other) {
    if (this != &other) {
      for (auto& elem : other) {
        insert(elem);
      }
    }
    other.clear();
  }
  void clear() {
    if (this->tree_.getRoot()) {
      Node<T>* root = this->tree_.getRoot();
      this->tree_.clear(root);
      this->tree_.setRoot(nullptr);
    }
  }
  void swap(Set<T>& other) { tree_.swap(other.tree_); }
  Iterator find(const T& key) { return Iterator(tree_.search(key)); }
  size_type size() {
    if (this->tree_.getRoot() == nullptr) {
      return 0;
    }
    return tree_.getRoot()->size_;
  }
  size_type max_size() { return allocator.max_size() / 10; }
  bool empty() {
    if (this->tree_.getRoot() == nullptr) {
      return true;
    }
    if (this->tree_.getRoot()->size_ == 0) {
      return true;
    }
    return false;
  }
  void erase(Iterator pos) { tree_.remove(*pos); }
  void insert(T key) { tree_.insert(key); }
  // std::pair<Iterator, bool> insert(const value_type& value) {
  //   std::pair<Iterator, bool> result;
  //   if (this->tree_.insert(value) != nullptr) {
  //     result = std::pair<Iterator, bool>(find(value), true);
  //   } else {
  //     result = std::pair<Iterator, bool>(find(value), false);
  //   }
  //   return result;
  // }

 private:
  AVLTree<T> tree_;
  Allocator allocator;
};

}  // namespace s21

#endif  // AVL_SET_H_