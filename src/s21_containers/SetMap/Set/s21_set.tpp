#include "./s21_set.h"

namespace s21 {
template <typename T>
set<T>::set() : tree_() {}
template <typename T>
set<T>::set(std::initializer_list<value_type> const& items) : tree_() {
  for (auto i = items.begin(); i != items.end(); ++i) {
    this->insert(*i);
  }
}
template <typename T>
set<T>::set(const set& s) : tree_(s.get_tree()) {}
template <typename T>
set<T>& set<T>::operator=(set<T>&& s) {
  if (this != &s) {
    tree_ = std::move(s.tree_);
  }
  return *this;
}

template <typename T>
typename set<T>::iterator set<T>::begin() {
  Node<T, T>* node = tree_.GetRoot();
  if (node == nullptr) {
    return iterator(nullptr);
  }
  while (node->left != nullptr && !node->left->isSentinel) {
    node = node->left;
  }
  if (node->isSentinel) {
    return iterator(nullptr);
  } else {
    return iterator(node);
  }
}
template <typename T>
typename set<T>::iterator set<T>::end() {
  return iterator(nullptr, tree_.GetRoot());
}
template <typename T>
bool set<T>::empty() {
  if (this->tree_.GetRoot() == nullptr) {
    return true;
  }
  if (this->tree_.GetRoot()->size_ == 0) {
    return true;
  }
  return false;
}
template <typename T>
typename set<T>::size_type set<T>::size() {
  if (this->tree_.GetRoot() == nullptr) {
    return 0;
  }
  return tree_.GetRoot()->size_;
}
template <typename T>
typename set<T>::size_type set<T>::max_size() {
  return allocator.max_size() / 10;
}
template <typename T>
void set<T>::clear() {
  if (this->tree_.GetRoot()) {
    Node<T, T>* root = this->tree_.GetRoot();
    this->tree_.Clear(root);
    this->tree_.SetRoot(nullptr);
  }
}
template <typename T>
std::pair<typename set<T>::iterator, bool> set<T>::insert(const T& value) {
  std::pair<typename set<T>::iterator, bool> result;
  this->tree_.Insert(value);
  if (this->tree_.GetInserted()) {
    result = std::pair<typename set<T>::iterator, bool>(find(value), true);
  } else {
    result = std::pair<typename set<T>::iterator, bool>(find(value), false);
  }
  return result;
}

template <typename T>
void set<T>::erase(set<T>::iterator pos) {
  if (pos != nullptr) {
    tree_.Remove(*pos);
  }
}
template <typename T>
void set<T>::swap(set<T>& other) {
  tree_.Swap(other.tree_);
}
template <typename T>
void set<T>::merge(set<T>& other) {
  if (this != &other) {
    for (auto i = other.begin(); i != other.end(); i++) {
      insert(*i);
    }
  }
  other.clear();
}
template <typename T>
bool set<T>::contains(const T& key) {
  return tree_.Search(key) != nullptr;
}
template <typename T>
typename set<T>::iterator set<T>::find(const T& key) {
  return iterator(tree_.Search(key));
}
template <typename T>
const AVLTree<T, T>& set<T>::get_tree() const {
  return tree_;
}
}  // namespace s21
