#ifndef AVL_SET_H_
#define AVL_SET_H_

#include <algorithm>

#include "../iterators/s21_iterator.h"

namespace s21 {

template <typename T>
class set {
 public:
  using value_type = T;
  using iterator = Iterator<T, T>;
  using const_iterator = ConstIterator<T, T>;
  using size_type = size_t;
  using Allocator = std::allocator<T>;

  set();
  set(std::initializer_list<value_type> const& items);
  set(const set& s);
  set(set<T>&& s) = default;
  set<T>& operator=(set&& s);
  ~set() {}

  iterator begin();
  iterator end();

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  std::pair<iterator, bool> insert(const T& value);
  void erase(iterator pos);
  void swap(set<T>& other);
  void merge(set<T>& other);

  bool contains(const T& key);
  iterator find(const T& key);
  const AVLTree<T, T>& get_tree() const;

 private:
  AVLTree<T, T> tree_;
  Allocator allocator;
};
}  // namespace s21

#endif  // AVL_SET_H_