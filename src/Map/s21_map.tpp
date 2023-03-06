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
}  // namespace s21