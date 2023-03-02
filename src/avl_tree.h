#ifndef SRC_AVL_H_
#define SRC_AVL_H_

#include <iostream>

#include "s21_set.h"

namespace s21 {
enum Duplicate { WITH_DUPLICATE, WITHOUT_DUPLICATE };
// AVL tree node
template <typename T>
class Node {
 public:
  T key;
  int height;
  size_t size_;
  Node<T>* left;
  Node<T>* right;
  Node<T>* parent;
  Node(T k) {
    key = k;
    height = 1;
    left = right = parent = nullptr;
  }
};
template <typename T>
class AVLTree {
 public:
  AVLTree();
  ~AVLTree();
  void insert(T key);
  void remove(T key) { root = remove(root, key); }
  Node<T>* search(T key) { return search(root, key); }
  Node<T>* getRoot() { return this->root; }
  void setRoot(Node<T>* root);
  void swap(AVLTree<T>& other) { std::swap(root, other.root); }
  void clear(Node<T>* node);

 private:
  Node<T>* root;
  int height(Node<T>* node);
  void updateSize(Node<T>* node);
  int balanceFactor(Node<T>* node);
  void updateHeight(Node<T>* node);
  Node<T>* rotateLeft(Node<T>* node);
  Node<T>* rotateRight(Node<T>* node);
  Node<T>* balance(Node<T>* node);
  Node<T>* insert(Node<T>* node, T key, Node<T>* parent);
  Node<T>* findMin(Node<T>* node);
  Node<T>* removeMin(Node<T>* node);
  Node<T>* remove(Node<T>* node, T key);
  Node<T>* search(Node<T>* node, T key);
};
}  // namespace s21

#endif  // SRC_AVL_H_