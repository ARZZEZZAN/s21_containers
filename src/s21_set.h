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
    Iterator(Node<T>* node = nullptr) : node_(node) {}
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
    bool operator==(const Iterator& other) const {
      return node_ == other.node_;
    }
    bool operator!=(const Iterator& other) const {
      return node_ != other.node_;
    }

   private:
    Node<T>* node_;
  };

  Set() : tree_() {}
  ~Set() {}

  Iterator begin();
  Iterator end();

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  std::pair<Iterator, bool> insert(const value_type& value);
  void erase(Iterator pos);
  void swap(Set<T>& other);
  void merge(Set<T>& other);

  bool contains(const T& key);
  Iterator find(const T& key);

 private:
  AVLTree<T> tree_;
  Allocator allocator;
};
}  // namespace s21

#endif  // AVL_SET_H_