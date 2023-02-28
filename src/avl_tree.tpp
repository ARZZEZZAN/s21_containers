#include "avl_tree.h"
using namespace s21;
template <typename T>
AVLTree<T>::AVLTree() {
  root = nullptr;
}
template <typename T>
int AVLTree<T>::height(Node<T>* node) {
  if (!node) return 0;
  return node->height;
}
template <typename T>
int AVLTree<T>::balanceFactor(Node<T>* node) {
  if (!node) return 0;
  return (height(node->left) - height(node->right));
}
template <typename T>
void AVLTree<T>::updateHeight(Node<T>* node) {
  int hl = height(node->left);
  int hr = height(node->right);
  node->height = (hl > hr ? hl : hr) + 1;
}
template <typename T>
Node<T>* AVLTree<T>::rotateRight(Node<T>* node) {
  Node<T>* newRoot = node->left;
  node->left = newRoot->right;
  if (newRoot->left) {
    newRoot->right->parent = node;
  }
  newRoot->right = node;
  newRoot->parent = node->parent;
  node->parent = newRoot;
  updateHeight(newRoot);
  updateHeight(node);
  return newRoot;
}
template <typename T>
Node<T>* AVLTree<T>::rotateLeft(Node<T>* node) {
  Node<T>* newRoot = node->right;
  node->right = newRoot->left;
  if (newRoot->left) {
    newRoot->left->parent = node;
  }
  newRoot->left = node;
  newRoot->parent = node->parent;
  node->parent = newRoot;
  updateHeight(newRoot);
  updateHeight(node);
  return newRoot;
}
template <typename T>
Node<T>* AVLTree<T>::balance(Node<T>* node) {
  updateHeight(node);
  if (balanceFactor(node) == 2) {
    if (balanceFactor(node->right) < -1) {
      node->left = rotateLeft(node->left);
    }
    return rotateRight(node);
  }
  if (balanceFactor(node) == -2) {
    if (balanceFactor(node->left) > 1) {
      node->right = rotateRight(node->right);
    }
    return rotateLeft(node);
  }
  return node;
}
template <typename T>
Node<T>* AVLTree<T>::insert(Node<T>* node, T key, Node<T>* parent) {
  if (!node) {
    node = new Node<T>(key);
    node->parent = parent;
    node->size_++;
    return node;
  }
  if (key < node->key) {
    node->left = insert(node->left, key, node);
  } else if (key > node->key) {
    node->right = insert(node->right, key, node);
  }
  return balance(node);
}

template <typename T>
Node<T>* AVLTree<T>::findMin(Node<T>* node) {
  if (!node->left) return node;
  return findMin(node->left);
}
template <typename T>
Node<T>* AVLTree<T>::removeMin(Node<T>* node) {
  if (!node->left) return node->right;
  node->left = removeMin(node->left);
  return balance(node);
}
template <typename T>
Node<T>* AVLTree<T>::remove(Node<T>* node, T key) {
  if (!node) return nullptr;
  if (key < node->key) {
    node->left = remove(node->left, key);
  } else if (key > node->key) {
    node->right = remove(node->right, key);
  } else {
    Node<T>* left = node->left;
    Node<T>* right = node->right;
    delete node;
    if (!right) return left;
    if (!left) return right;
    Node<T>* min = findMin(right);
    min->right = removeMin(right);
    min->left = left;
    updateHeight(min);
    node->size_--;
    return balance(min);
  }
  updateHeight(node);
  return balance(node);
}
template <typename T>
AVLTree<T>::~AVLTree() {
  clear(root);
}
template <typename T>
void AVLTree<T>::clear(Node<T>* node) {
  if (node != nullptr) {
    clear(node->left);
    clear(node->right);
    node->size_ = 0;
    node = nullptr;
  }
}
template <typename T>
Node<T>* AVLTree<T>::search(Node<T>* node, T key) {
  if (!node || node->key == key) {
    return node;
  }
  if (key < node->key) {
    return search(node->left, key);
  } else {
    return search(node->right, key);
  }
}
template <typename T>
void AVLTree<T>::swap(Node<T>* other) {
  std::swap(root, other);
  std::swap(root->size_, other->size_);
}
