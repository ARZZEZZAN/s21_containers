#include "s21_list.h"
using namespace s21;

// Constructor
template <typename value_type>
list<value_type>::list() : head_(nullptr), tail_(nullptr), size_(0) {}

// Destructor
template <typename value_type>
list<value_type>::~list() {
  // clear();
}

// Copy constructor
template <typename value_type>
list<value_type>::list(const value_type& other) : list() {
  // for (const auto& item : other) {
  //   push_back(item);
  // }
}

// Copy assignment operator
template <typename value_type>
list<value_type>::list<value_type>& operator=(const list& other) {
  if (this != &other) {
    clear();
    for (const auto& item : other) {
      push_back(item);
    }
  }
  return *this;
}

// Move constructor
list(list&& other) noexcept : list() { swap(*this, other); }

// Move assignment operator
list& operator=(list&& other) noexcept {
  swap(*this, other);
  return *this;
}

// Push an element to the back of the list
void push_back(const T& value) {
  Node* new_node = new Node(value);
  if (tail == nullptr) {
    head = tail = new_node;
  } else {
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
  }
  size++;
}

// Remove all elements from the list
void clear() {
  while (head != nullptr) {
    Node* next_node = head->next;
    delete head;
    head = next_node;
  }
  tail = nullptr;
  size = 0;
}

// Swap the contents of two lists
friend void swap(list& a, list& b) noexcept {
  using std::swap;
  swap(a.head, b.head);
  swap(a.tail, b.tail);
  swap(a.size, b.size);
}

// Iterator
class Iterator {
 public:
  Iterator(Node* node) : node(node) {}

  Iterator& operator++() {
    node = node->next;
    return *this;
  }

  bool operator!=(const Iterator& other) const { return node != other.node; }

  T& operator*() const { return node->value; }

 private:
  Node* node;
};

// Begin iterator
Iterator begin() const { return Iterator(head); }

// End iterator
Iterator end() const { return Iterator(nullptr); }

private:
// Node struct for the linked list
struct Node {
  T value;
  Node* prev;
  Node* next;

  Node(const T& value) : value(value), prev(nullptr), next(nullptr) {}
};

Node* head;
Node* tail;
size_t size;
}
;