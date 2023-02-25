#ifndef VECTOR_H
#define VECTOR_H

namespace s21 {

template <class T>
class Vector {
  // Vector Member type
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  // using iterator = VectorIterator<T>;
  // using const_iterator = const_iterator_Vector<T>;
  using size_type = std::size_t;

 public:
  // Vector Member functions
  Vector();
  Vector(size_type n);
  Vector(std::initializer_list<value_type> const& items);
  Vector(const Vector& v);
  Vector(Vector&& v);
  ~Vector();
  Vector& operator=(const Vector&& v);

  // Vector& operator=(Vector& other) {
  //   if (this != &other) {
  //     delete[] container_;
  //     container_ = other.container_;
  //     size_ = other.size_;
  //     capacity_ = other.capacity_;
  //     other.container_ = nullptr;
  //     other.size_ = other.capacity_ = 0;
  //   }
  //   return *this;
  // }

  // Vector& operator=(Vector&& other) noexcept {
  //   if (this != &other) {
  //     delete[] container_;
  //     container_ = other.container_;
  //     size_ = other.size_;
  //     capacity_ = other.capacity_;
  //     other.container_ = nullptr;
  //     other.size_ = other.capacity_ = 0;
  //   }
  //   return *this;
  // }

  // helper
  void bring_to_zero();
  void add_memory();
  void copy_vector(const Vector& v);
  void remove();

 public:
  [[nodiscard]] bool isEmpty() const { return size_ == 0; }
  [[nodiscard]] size_t size() const { return size_; }
  [[nodiscard]] size_t capacity() const { return capacity_; }
  void pushBack(const_reference value) {
    if (size_ >= capacity_) add_memory();
    container_[size_++] = value;
  }
  void remove(size_t index) {
    for (size_t i = index + 1; i < size_; ++i) {
      container_[i - 1] = container_[i];
    }
    --size_;
  }

 public:
  value_type* begin() { return &container_[0]; }
  const value_type* begin() const { return &container_[0]; }
  value_type* end() { return &container_[size_]; }
  const value_type* end() const { return &container_[size_]; }

 public:
  reference operator[](size_t index) { return container_[index]; }
  const_reference operator[](size_t index) const { return container_[index]; }

 private:
  size_t size_;
  size_t capacity_;
  value_type* container_;
};
}  // namespace s21
#endif  // VECTOR_H