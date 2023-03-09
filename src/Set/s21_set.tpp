#include "./s21_set.h"

namespace s21 {
template <typename T>
Set<T>::Set() : tree_() {}
template <typename T>
Set<T>::Set(std::initializer_list<value_type> const& items) : tree_() {
  for (auto i = items.begin(); i != items.end(); ++i) {
    this->insert(*i);
  }
}
template <typename T>
Set<T>::Set(const Set& s) : tree_(s.getTree()) {}
template <typename T>
Set<T> Set<T>::operator=(Set<T>&& s) {
  if (this != &s) {
    tree_ = std::move(s.tree_);
  }
  return *this;
}

template <typename T>
typename Set<T>::iterator Set<T>::begin() {
  Node<T, T>* node = tree_.GetRoot();
  while (node != nullptr && node->left != nullptr) {
    node = node->left;
  }
  return iterator(node);
}
template <typename T>
typename Set<T>::iterator Set<T>::end() {
  return iterator(nullptr);
}
template <typename T>
bool Set<T>::empty() {
  if (this->tree_.GetRoot() == nullptr) {
    return true;
  }
  if (this->tree_.GetRoot()->size_ == 0) {
    return true;
  }
  return false;
}
template <typename T>
typename Set<T>::size_type Set<T>::size() {
  if (this->tree_.GetRoot() == nullptr) {
    return 0;
  }
  return tree_.GetRoot()->size_;
}
template <typename T>
typename Set<T>::size_type Set<T>::max_size() {
  return allocator.max_size() / 10;
}
template <typename T>
void Set<T>::clear() {
  if (this->tree_.GetRoot()) {
    Node<T, T>* root = this->tree_.GetRoot();
    this->tree_.Clear(root);
    this->tree_.SetRoot(nullptr);
  }
}
template <typename T>
std::pair<typename Set<T>::iterator, bool> Set<T>::insert(const T& value) {
  std::pair<typename Set<T>::iterator, bool> result;
  this->tree_.Insert(value);
  if (this->tree_.GetInserted()) {
    result = std::pair<typename Set<T>::iterator, bool>(find(value), true);
  } else {
    result = std::pair<typename Set<T>::iterator, bool>(find(value), false);
  }
  return result;
}

template <typename T>
void Set<T>::erase(Set<T>::iterator pos) {
  if (pos != nullptr) {
    tree_.Remove(*pos);
  }
}
template <typename T>
void Set<T>::swap(Set<T>& other) {
  tree_.Swap(other.tree_);
}
template <typename T>
void Set<T>::merge(Set<T>& other) {
  if (this != &other) {
    for (auto& elem : other) {
      insert(elem);
    }
  }
  other.clear();
}
template <typename T>
bool Set<T>::contains(const T& key) {
  return tree_.Search(key) != nullptr;
}
template <typename T>
typename Set<T>::iterator Set<T>::find(const T& key) {
  return iterator(tree_.Search(key));
}
template <typename T>
const AVLTree<T, T>& Set<T>::getTree() const {
  return tree_;
}
}  // namespace s21
