#ifndef SRC_AVL_H_
#define SRC_AVL_H_

#include <iostream>

#include "./Set/s21_set.h"

namespace s21 {
// AVL tree node
template <typename T, typename V>
class Node {
 public:
  T key;
  int height;
  size_t size_;
  Node<T, V>* left;
  Node<T, V>* right;
  Node<T, V>* parent;
  Node(T k) {
    key = k;
    height = 1;
    size_ = 1;
    left = right = parent = nullptr;
  }
};
template <typename T, typename V>
class AVLTree {
 public:
  AVLTree();
  ~AVLTree();
  Node<T, V>* insert(T key);
  void remove(T key);
  Node<T, V>* search(T key);
  Node<T, V>* getRoot();
  void setRoot(Node<T, V>* root);
  void swap(AVLTree<T, V>& other);
  void clear(Node<T, V>* node);
  bool getInserted();

 private:
  Node<T, V>* root;
  bool inserted;
  int size(Node<T, V>* node);
  int height(Node<T, V>* node);
  void updateSize(Node<T, V>* node);
  int balanceFactor(Node<T, V>* node);
  void updateHeight(Node<T, V>* node);
  Node<T, V>* balance(Node<T, V>* node);
  Node<T, V>* findMin(Node<T, V>* node);
  Node<T, V>* rotateLeft(Node<T, V>* node);
  Node<T, V>* rotateRight(Node<T, V>* node);
  Node<T, V>* removeMin(Node<T, V>* node);
  Node<T, V>* remove(Node<T, V>* node, T key);
  Node<T, V>* search(Node<T, V>* node, T key);
  Node<T, V>* insert(Node<T, V>* node, T key, Node<T, V>* parent);
};
}  // namespace s21

#endif  // SRC_AVL_H_