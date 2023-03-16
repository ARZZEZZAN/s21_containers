#ifndef AVL_MAP_H_
#define AVL_MAP_H_

#include <limits>

#include "../iterators/s21_iterator.h"

namespace s21 {
template <typename T, typename V>
class map {
 public:
  using key_type = T;
  using mapped_type = V;
  using default_value = mapped_type&;
  using value_type = std::pair<const key_type, mapped_type>;
  using iterator = Iterator<value_type, V>;
  using const_iterator = ConstIterator<value_type, V>;
  using size_type = size_t;
  using Allocator = std::allocator<T>;

  map();
  map(std::initializer_list<value_type> const& items);
  map(const map& m);
  map(map&& m) = default;
  map<T, V> operator=(map&& m);
  ~map();

  mapped_type& at(const T& key);
  mapped_type& operator[](const T& key);

  iterator begin();
  iterator end();

  bool empty();
  size_type size();
  size_type max_size();

  void clear();

  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert(const key_type& key, const mapped_type& obj);
  std::pair<iterator, bool> insert_or_assign(const key_type& key,
                                             const mapped_type& obj);
  void erase(iterator pos);
  void swap(map& other);
  void merge(map& other);
  bool contains(const T& key);
  const AVLTree<value_type, V>& get_tree() const;

 private:
  AVLTree<value_type, V> tree_;
  Allocator allocator;

  mapped_type& operatorHelper(const T& key, int flag);
  bool check_duplicates(const value_type& value);
};

}  // namespace s21

#endif  // AVL_MAP_H_