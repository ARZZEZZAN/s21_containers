#ifndef AVL_SET_H_
#define AVL_SET_H_

#include <iterator>
#include <limits>

#include "Iterator.h"
#include "avl_tree.tpp"

namespace s21 {

template <typename T>
class Set {
  using size_type = size_t;
  using Allocator = std::allocator<T>;

  Set() : tree_() {}
  ~Set() {}

  Iterator begin();
  Iterator end();

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  std::pair<Iterator, bool> insert(const T& value);
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