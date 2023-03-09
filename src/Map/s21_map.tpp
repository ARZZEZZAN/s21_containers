#include "s21_map.h"
namespace s21 {
template <typename T, typename V>
Map<T, V>::Map() : tree_() {}
template <typename T, typename V>
Map<T, V>::Map(
    std::initializer_list<typename Map<T, V>::value_type> const& items) {
  for (auto i = items.begin(); i != items.end(); ++i) {
    this->insert(*i);
  }
}
template <typename T, typename V>
Map<T, V>::Map(const Map& m) : tree_(m.getTree()) {}
template <typename T, typename V>
Map<T, V> Map<T, V>::operator=(Map&& m) {
  if (this != &m) {
    clear();
    swap(m);
  }
  return *this;
}
template <typename T, typename V>
Map<T, V>::~Map() {}

template <typename T, typename V>
std::pair<typename Map<T, V>::iterator, bool> Map<T, V>::insert(
    const value_type& value) {
  std::pair<typename Map<T, V>::iterator, bool> result;
  this->tree_.insert(value);
  auto res = this->tree_.search(value);
  if (this->tree_.getInserted()) {
    result = std::make_pair(iterator(res), true);
  } else {
    result = std::make_pair(iterator(res), false);
  }
  return result;
}
template <typename T, typename V>
std::pair<typename Map<T, V>::iterator, bool> Map<T, V>::insert(
    const key_type& key, const mapped_type& obj) {
  return insert(std::pair<key_type, mapped_type>(key, obj));
}
template <typename T, typename V>
std::pair<typename Map<T, V>::iterator, bool> Map<T, V>::insert_or_assign(
    const key_type& key, const mapped_type& obj) {
  std::pair<typename Map<T, V>::iterator, bool> res;
  iterator i = this->begin();
  if (i != nullptr) {
    for (; i != this->end(); ++i) {
      if (i->first == key) {
        i->second = obj;
        return res;
      }
    }
  }
  return insert(std::pair<key_type, mapped_type>(key, obj));
}
template <typename T, typename V>
typename Map<T, V>::mapped_type& Map<T, V>::at(const T& key) {
  return operatorHelper(key, 0);
}
template <typename T, typename V>
typename Map<T, V>::mapped_type& Map<T, V>::operator[](const T& key) {
  return operatorHelper(key, 1);
}
template <typename T, typename V>
typename Map<T, V>::iterator Map<T, V>::begin() {
  Node<value_type, V>* node = tree_.getRoot();
  while (node != nullptr && node->left != nullptr) {
    node = node->left;
  }
  return iterator(node);
}
template <typename T, typename V>
typename Map<T, V>::iterator Map<T, V>::end() {
  return iterator(nullptr);
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
void Map<T, V>::erase(typename Map<T, V>::iterator pos) {
  if (pos != nullptr) {
    this->tree_.remove(*pos);
  }
}
template <typename T, typename V>
void Map<T, V>::swap(Map& other) {
  tree_.swap(other.tree_);
}
template <typename T, typename V>
void Map<T, V>::merge(Map& other) {
  iterator iter = other.begin();
  while (iter != other.end()) {
    this->insert(*iter);
    iter++;
  }
}
template <typename T, typename V>
bool Map<T, V>::contains(const T& key) {
  for (iterator i = this->begin(); i != this->end(); i++) {
    if (i->first == key) return true;
  }
  return false;
}
template <typename T, typename V>
typename Map<T, V>::mapped_type& Map<T, V>::operatorHelper(const T& key,
                                                           int flag) {
  iterator i = this->begin();
  if (i != nullptr) {
    for (; i != this->end(); ++i) {
      if (i->first == key) {
        return i->second;
      }
    }
    if (flag) {
      auto res = insert(value_type(key, mapped_type()));
      return res.first->second;
    } else {
      throw std::out_of_range("There is no such key");
    }
  }
  return i->second;
}
template <typename T, typename V>
const AVLTree<typename Map<T, V>::value_type, V>& Map<T, V>::getTree() const {
  return tree_;
}
}  // namespace s21