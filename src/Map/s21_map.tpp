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
std::pair<typename Map<T, V>::iterator, bool> Map<T, V>::insert(
    const value_type& value) {}
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
  return tree_.empty();
}
template <typename T, typename V>
typename Map<T, V>::size_type Map<T, V>::size() {
  return 0;
}
template <typename T, typename V>
typename Map<T, V>::size_type Map<T, V>::max_size() {
  return 0;
}
template <typename T, typename V>
void Map<T, V>::clear() {}
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