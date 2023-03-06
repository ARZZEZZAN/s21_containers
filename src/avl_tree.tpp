#include "avl_tree.h"
namespace s21 {
template <typename T, typename V>
AVLTree<T, V>::AVLTree() {
  root = nullptr;
  inserted = false;
}

template <typename T, typename V>
int AVLTree<T, V>::height(Node<T, V>* node) {
  if (!node) return 0;
  return node->height;
}
template <typename T, typename V>
int AVLTree<T, V>::balanceFactor(Node<T, V>* node) {
  if (!node) return 0;
  return (height(node->left) - height(node->right));
}
template <typename T, typename V>
void AVLTree<T, V>::updateHeight(Node<T, V>* node) {
  int hl = height(node->left);
  int hr = height(node->right);
  node->height = (hl > hr ? hl : hr) + 1;
}
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::rotateRight(Node<T, V>* node) {
  Node<T, V>* newRoot = node->left;
  node->left = newRoot->right;
  if (newRoot->right) {
    newRoot->right->parent = node;
  }
  newRoot->right = node;
  newRoot->parent = node->parent;
  node->parent = newRoot;
  updateHeight(newRoot);
  updateHeight(node);
  return newRoot;
}
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::rotateLeft(Node<T, V>* node) {
  Node<T, V>* newRoot = node->right;
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
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::balance(Node<T, V>* node) {
  updateHeight(node);
  if (balanceFactor(node) == 2) {
    if (balanceFactor(node->right) < -1) {
      node->left = rotateLeft(node->left);
      updateSize(node->left);
    }
    node = rotateRight(node);
    updateSize(node);
  }
  if (balanceFactor(node) == -2) {
    if (balanceFactor(node->left) > 1) {
      node->right = rotateRight(node->right);
      updateSize(node->right);
    }
    node = rotateLeft(node);
    updateSize(node);
  }
  updateSize(node);
  return node;
}
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::insert(Node<T, V>* node, T key, Node<T, V>* parent) {
  inserted = false;
  if (!node) {
    node = new Node<T, V>(key);
    node->parent = parent;
    this->inserted = true;
    return balance(node);
  }
  if (key < node->key) {
    node->left = insert(node->left, key, node);
  } else if (key > node->key) {
    node->right = insert(node->right, key, node);
  } else {
    inserted = false;
  }
  return balance(node);
}

template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::findMin(Node<T, V>* node) {
  if (!node->left) return node;
  return findMin(node->left);
}
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::removeMin(Node<T, V>* node) {
  if (!node->left) return node->right;
  node->left = removeMin(node->left);
  return balance(node);
}
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::remove(Node<T, V>* node, T key) {
  if (!node) return nullptr;
  if (key < node->key) {
    node->left = remove(node->left, key);
  } else if (key > node->key) {
    node->right = remove(node->right, key);
  } else {
    Node<T, V>* left = node->left;
    Node<T, V>* right = node->right;
    delete node;
    if (!right) return left;
    if (!left) return right;
    Node<T, V>* min = findMin(right);
    min->right = removeMin(right);
    min->left = left;
    min->size_--;
    updateHeight(min);
    return balance(min);
  }
  node->size_--;
  updateHeight(node);
  return balance(node);
}
template <typename T, typename V>
AVLTree<T, V>::~AVLTree() {
  if (root) {
    clear(root);
  }
}
template <typename T, typename V>
void AVLTree<T, V>::clear(Node<T, V>* node) {
  if (node) {
    clear(node->left);
    clear(node->right);
    node->size_--;
    delete node;
  }
  node = nullptr;
}
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::search(Node<T, V>* node, T key) {
  if (!node || node->key == key) {
    return node;
  }
  if (key < node->key) {
    return search(node->left, key);
  } else {
    return search(node->right, key);
  }
}
template <typename T, typename V>
void AVLTree<T, V>::setRoot(Node<T, V>* root) {
  this->root = root;
  if (this->root != nullptr) {
    this->root->parent = nullptr;
  }
}
template <typename T, typename V>
void AVLTree<T, V>::updateSize(Node<T, V>* node) {
  if (node) {
    node->size_ = 1 + size(node->left) + size(node->right);
    updateSize(node->left);
    updateSize(node->right);
  }
}
template <typename T, typename V>
int AVLTree<T, V>::size(Node<T, V>* node) {
  if (node) {
    return node->size_;
  }
  return 0;
}
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::insert(T key) {
  root = insert(root, key, nullptr);
  return root;
}
template <typename T, typename V>
void AVLTree<T, V>::remove(T key) {
  root = remove(root, key);
}
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::search(T key) {
  return search(root, key);
}
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::getRoot() {
  return this->root;
}
template <typename T, typename V>
void AVLTree<T, V>::swap(AVLTree<T, V>& other) {
  std::swap(root, other.root);
}
template <typename T, typename V>
bool AVLTree<T, V>::getInserted() {
  return inserted;
}
}  // namespace s21