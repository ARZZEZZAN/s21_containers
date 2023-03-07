#include "s21_map.h"
namespace s21 {
template <typename T, typename V>
Map<T, V>::Map() : tree_() {}
template <typename T, typename V>
Map<T, V>::Map(
    std::initializer_list<typename Map<T, V>::value_type> const& items) {}
template <typename T, typename V>
Map<T, V>::Map(const Map& m) {}
template <typename T, typename V>
Map<T, V>::Map(Map&& m) {}
template <typename T, typename V>
Map<T, V>::~Map() {}
template <typename T, typename V>
Map<T, V> Map<T, V>::operator=(Map&& m) {}

template <typename T, typename V>
void Map<T, V>::insert(const value_type& value) {
  auto pair_set = tree_.insert(value);
  //   return std::make_pair(iterator(pair_set.first), pair_set.second);
}
template <typename T, typename V>
typename Map<T, V>::iterator Map<T, V>::find(const T& key) {
  return iterator(tree_.search(key));
}
template <typename T, typename V>
std::pair<typename Map<T, V>::iterator, bool> Map<T, V>::insert(const T& key,
                                                                const T& obj) {}
template <typename T, typename V>
std::pair<typename Map<T, V>::iterator, bool> Map<T, V>::insert_or_assign(
    const T& key, const T& obj) {}

template <typename T, typename V>
T& Map<T, V>::at(const T& key) {}
template <typename T, typename V>
T& Map<T, V>::operator[](const T& key) {}

template <typename T, typename V>
typename Map<T, V>::iterator Map<T, V>::begin() {
  return nullptr;
}
template <typename T, typename V>
typename Map<T, V>::iterator Map<T, V>::end() {
  return nullptr;
}
template <typename T, typename V>
bool Map<T, V>::empty() {
  if (this->tree_.getRoot() == nullptr) {
    return true;
  }
  if (this->tree_.getRoot()->size_ == 0) {
    return true;
  }
  return false;
}
template <typename T, typename V>
typename Map<T, V>::size_type Map<T, V>::size() {
  if (this->tree_.getRoot() == nullptr) {
    return 0;
  }
  return tree_.getRoot()->size_;
}
template <typename T, typename V>
typename Map<T, V>::size_type Map<T, V>::max_size() {
  return allocator.max_size() / 10;
}
template <typename T, typename V>
void Map<T, V>::clear() {
  if (this->tree_.getRoot()) {
    Node<T, T>* root = this->tree_.getRoot();
    this->tree_.clear(root);
    this->tree_.setRoot(nullptr);
  }
}
template <typename T, typename V>
void Map<T, V>::erase(typename Map<T, V>::iterator pos) {}
template <typename T, typename V>
void Map<T, V>::swap(Map& other) {}
template <typename T, typename V>
void Map<T, V>::merge(Map& other) {}
template <typename T, typename V>
bool Map<T, V>::contains(const T& key) {
  return false;
}
}  // namespace s21