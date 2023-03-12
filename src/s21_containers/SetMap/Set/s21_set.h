#ifndef AVL_SET_H_
#define AVL_SET_H_

#include <algorithm>

#include "../Iterators/s21_iterator.h"

namespace s21 {

template <typename T>
class Set {
 public:
  using value_type = T;
  using iterator = Iterator<T, T>;
  using constIterator = ConstIterator<T, T>;
  using size_type = size_t;
  using Allocator = std::allocator<T>;

  Set();
  Set(std::initializer_list<value_type> const& items);
  Set(const Set& s);
  Set(Set<T>&& s) = default;
  Set<T>& operator=(Set&& s);
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
  const AVLTree<T, T>& getTree() const;

 private:
  AVLTree<T, T> tree_;
  Allocator allocator;
};
}  // namespace s21

#endif  // AVL_SET_H_