#ifndef AVL_MAP_H_
#define AVL_MAP_H_

#include <limits>

#include "../Iterators/Iterator.h"
#include "../Set/s21_set.tpp"

namespace s21 {
template <typename T, typename V>
class Map {
 public:
  using key_type = T;
  using mapped_type = V;
  using value_type = std::pair<const key_type, mapped_type>;
  using iterator = Iterator<value_type, V>;
  using constIterator = ConstIterator<value_type, V>;
  using size_type = size_t;
  using Allocator = std::allocator<T>;

  Map();
  Map(std::initializer_list<value_type> const& items);
  Map(const Map& m);
  Map(Map&& m);
  ~Map();
  Map<T, V> operator=(Map&& m);

  T& at(const T& key);
  T& operator[](const T& key);

  iterator begin();
  iterator end();

  bool empty();
  size_type size();
  size_type max_size();

  void clear();

  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert(const T& key, const T& obj);
  std::pair<iterator, bool> insert_or_assign(const T& key, const T& obj);
  void erase(iterator pos);
  void swap(Map& other);
  void merge(Map& other);
  bool contains(const T& key);
  iterator find(const T& key);

 private:
  AVLTree<value_type, V> tree_;
  Allocator allocator;
};

}  // namespace s21

#endif  // AVL_MAP_H_