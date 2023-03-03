#ifndef AVL_SET_H_
#define AVL_SET_H_

#include <iterator>
#include <limits>

#include "./Iterators/Iterator.h"

namespace s21 {

template <typename T>
class Set {
 public:
  using value_type = T;
  using iterator = Iterator<T>;
  using constIterator = ConstIterator<T>;
  using size_type = size_t;
  using Allocator = std::allocator<T>;

  Set();
  Set(std::initializer_list<value_type> const& items);
  Set(const set& s);
  Set(set&& s);
  operator=(set&& s);
  ~Set() {}

  iterator begin();
  iterator end();

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  std::pair<iterator, bool> insert(const T& value);
  void erase(iterator pos);
  void swap(Set<T>& other);
  void merge(Set<T>& other);

  bool contains(const T& key);
  iterator find(const T& key);

 private:
  AVLTree<T> tree_;
  Allocator allocator;
};
}  // namespace s21

#endif  // AVL_SET_H_