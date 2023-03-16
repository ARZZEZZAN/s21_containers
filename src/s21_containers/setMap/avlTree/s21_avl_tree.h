#ifndef SRC_AVL_H_
#define SRC_AVL_H_

#include <iostream>
using namespace std;

namespace s21 {
// AVL tree node
template <typename T, typename V>
class Node {
 public:
  mutable T key;
  int height;
  size_t size_;
  bool isSentinel;
  Node<T, V>* left;
  Node<T, V>* right;
  Node<T, V>* parent;

  Node(const T& k)
      : key(k),
        height(1),
        size_(1),
        isSentinel(false),
        left(nullptr),
        right(nullptr),
        parent(nullptr) {}

  Node(T& k)
      : key(k),
        height(1),
        size_(1),
        isSentinel(false),
        left(nullptr),
        right(nullptr),
        parent(nullptr) {}
};
template <typename T, typename V>
class AVLTree {
 public:
  AVLTree();
  AVLTree(const AVLTree& other);
  ~AVLTree();
  AVLTree<T, V>& operator=(AVLTree&& other) noexcept;
  Node<T, V>* Insert(T key);
  void Remove(T key);
  Node<T, V>* Search(T key);
  Node<T, V>* GetRoot() const;
  Node<T, V>* GetNil();
  void SetRoot(Node<T, V>* root);
  void Swap(AVLTree<T, V>& other);
  void Clear(Node<T, V>* node);
  bool GetInserted();
  Node<T, V>* MaximumKey(Node<T, V>* node);

 private:
  Node<T, V>* root;
  Node<T, V>* nil;
  bool inserted;
  int Size(Node<T, V>* node);
  int Height(Node<T, V>* node);
  void UpdateSize(Node<T, V>* node);
  int BalanceFactor(Node<T, V>* node);
  void UpdateHeight(Node<T, V>* node);
  Node<T, V>* Balance(Node<T, V>* node);
  Node<T, V>* FindMin(Node<T, V>* node);
  Node<T, V>* CopyTree(Node<T, V>* node);
  Node<T, V>* RotateLeft(Node<T, V>* node);
  Node<T, V>* RotateRight(Node<T, V>* node);
  Node<T, V>* RemoveMin(Node<T, V>* node);
  Node<T, V>* Remove(Node<T, V>* node, T key);
  Node<T, V>* Search(Node<T, V>* node, T key);
  Node<T, V>* Insert(Node<T, V>* node, T key, Node<T, V>* parent);
};
}  // namespace s21

#endif  // SRC_AVL_H_