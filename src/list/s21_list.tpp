#include "s21_list.h"
using namespace s21;

// Vector Member functions
template <typename value_type>
list<value_type>::list() {
  this->size_ = 0;
  this->capacity_ = 0;
  this->container_ = nullptr;
  this->head = this->tail = nullptr;
}

// #include <iostream>
// #include <utility>

// template<typename T>
// class List {
// public:
//     // Constructor
//     List() : head(nullptr), tail(nullptr), size(0) {}

//     // Destructor
//     ~List() {
//         clear();
//     }

//     // Copy constructor
//     List(const List& other) : List() {
//         for (const auto& item : other) {
//             push_back(item);
//         }
//     }

//     // Copy assignment operator
//     List& operator=(const List& other) {
//         if (this != &other) {
//             clear();
//             for (const auto& item : other) {
//                 push_back(item);
//             }
//         }
//         return *this;
//     }

//     // Move constructor
//     List(List&& other) noexcept : List() {
//         swap(*this, other);
//     }

//     // Move assignment operator
//     List& operator=(List&& other) noexcept {
//         swap(*this, other);
//         return *this;
//     }

//     // Push an element to the back of the list
//     void push_back(const T& value) {
//         Node* new_node = new Node(value);
//         if (tail == nullptr) {
//             head = tail = new_node;
//         } else {
//             tail->next = new_node;
//             new_node->prev = tail;
//             tail = new_node;
//         }
//         size++;
//     }

//     // Remove all elements from the list
//     void clear() {
//         while (head != nullptr) {
//             Node* next_node = head->next;
//             delete head;
//             head = next_node;
//         }
//         tail = nullptr;
//         size = 0;
//     }

//     // Swap the contents of two lists
//     friend void swap(List& a, List& b) noexcept {
//         using std::swap;
//         swap(a.head, b.head);
//         swap(a.tail, b.tail);
//         swap(a.size, b.size);
//     }

//     // Iterator
//     class Iterator {
//     public:
//         Iterator(Node* node) : node(node) {}

//         Iterator& operator++() {
//             node = node->next;
//             return *this;
//         }

//         bool operator!=(const Iterator& other) const {
//             return node != other.node;
//         }

//         T& operator*() const {
//             return node->value;
//         }

//     private:
//         Node* node;
//     };

//     // Begin iterator
//     Iterator begin() const {
//         return Iterator(head);
//     }

//     // End iterator
//     Iterator end() const {
//         return Iterator(nullptr);
//     }

// private:
//     // Node struct for the linked list
//     struct Node {
//         T value;
//         Node* prev;
//         Node* next;

//         Node(const T& value) : value(value), prev(nullptr), next(nullptr) {}
//     };

//     Node* head;
//     Node* tail;
//     size_t size;
// };