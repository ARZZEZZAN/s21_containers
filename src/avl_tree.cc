#include "avl_tree.h"
using namespace std;
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
  newRoot->right = node;
  updateHeight(newRoot);
  updateHeight(node);
  return newRoot;
}
template <typename T>
Node<T>* AVLTree<T>::rotateLeft(Node<T>* node) {
  Node<T>* newRoot = node->right;
  node->right = newRoot->left;
  newRoot->left = node;
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
Node<T>* AVLTree<T>::insert(Node<T>* node, T key) {
  if (!node) return new Node<T>(key);

  if (key < node->key) {
    node->left = insert(node->left, key);
  } else if (key > node->key) {
    node->right = insert(node->right, key);
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
    if (node->left != nullptr) {
      clear(node->left);
    }
    if (node->right != nullptr) {
      clear(node->right);
    }
    delete node;
  }
}
template <typename T>
void AVLTree<T>::output(Node<T>* node, int level) {
  if (node) {
    output(node->left, level + 1);
    for (int i = 0; i < level; i++) cout << "   ";
    cout << node->key << endl;
    output(node->right, level + 1);
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
// Node<T>* AVLTree<T>::rotateRight(Node<T>* node) {}
int main() {
  AVLTree<int> n;
  n.insert(20);
  n.insert(15);
  n.insert(25);
  n.insert(18);
  n.insert(30);
  n.insert(35);
  n.insert(24);
  n.insert(10);
  n.insert(5);
  n.insert(4);
  n.insert(12);
  n.insert(13);
  cout << n.search(15)->right->key << endl;
}