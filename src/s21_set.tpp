#include "s21_set.h"
namespace s21 {
template <typename T>
typename Set<T>::Iterator Set<T>::begin() {
  Node<T>* node = tree_.getRoot();
  while (node != nullptr && node->left != nullptr) {
    node = node->left;
  }
  return Iterator(node);
}
template <typename T>
typename Set<T>::Iterator Set<T>::end() {
  return Iterator(nullptr);
}
template <typename T>
bool Set<T>::empty() {
  if (this->tree_.getRoot() == nullptr) {
    return true;
  }
  if (this->tree_.getRoot()->size_ == 0) {
    return true;
  }
  return false;
}
template <typename T>
typename Set<T>::size_type Set<T>::size() {
  if (this->tree_.getRoot() == nullptr) {
    return 0;
  }
  return tree_.getRoot()->size_;
}
template <typename T>
typename Set<T>::size_type Set<T>::max_size() {
  return allocator.max_size() / 10;
}
template <typename T>
void Set<T>::clear() {
  if (this->tree_.getRoot()) {
    Node<T>* root = this->tree_.getRoot();
    this->tree_.clear(root);
    this->tree_.setRoot(nullptr);
  }
}
template <typename T>
std::pair<typename Set<T>::Iterator, bool> Set<T>::insert(const T& value) {
  std::pair<typename Set<T>::Iterator, bool> result;
  this->tree_.insert(value);
  if (this->tree_.getInserted()) {
    result = std::pair<typename Set<T>::Iterator, bool>(find(value), true);
  } else {
    result = std::pair<typename Set<T>::Iterator, bool>(find(value), false);
  }
  return result;
}

template <typename T>
void Set<T>::erase(Set<T>::Iterator pos) {
  tree_.remove(*pos);
}
template <typename T>
void Set<T>::swap(Set<T>& other) {
  tree_.swap(other.tree_);
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
  return tree_.search(key) != nullptr;
}
template <typename T>
typename Set<T>::Iterator Set<T>::find(const T& key) {
  return Iterator(tree_.search(key));
}
}  // namespace s21