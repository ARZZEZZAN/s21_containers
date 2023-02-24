#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

template <typename T>
class Vector {
 public:
  Vector() {
    arr_ = new T[1];
    capacity_ = 1;
  }
  ~Vector() { delete[] arr_; }
  // Конструкторы с move семантикой
  Vector(Vector& other) {
    if (this != &other) {
      delete[] arr_;
      arr_ = new T[other.capacity_];
      for (size_t i = 0; i < other.size_; ++i) arr_[i] = other.arr_[i];
      size_ = other.size_;
      capacity_ = other.capacity_;
    }
  }

  Vector(Vector&& other) noexcept {
    if (this != &other) {
      delete[] arr_;
      arr_ = other.arr_;
      size_ = other.size_;
      capacity_ = other.capacity_;
      other.arr_ = nullptr;
      other.size_ = other.capacity_ = 0;
    }
  }

  // Метод, который проверяет пустой ли список
  [[nodiscard]] bool isEmpty() const { return size_ == 0; }

  // Метод получения размера вектора
  [[nodiscard]] size_t size() const { return size_; }

  // Метод получения максимального размера вектора
  [[nodiscard]] size_t capacity() const { return capacity_; }

  // Метод выделения новой памяти
  void addMemory() {
    capacity_ *= 2;
    T* tmp = arr_;
    arr_ = new T[capacity_];
    for (size_t i = 0; i < size_; ++i) arr_[i] = tmp[i];
    delete[] tmp;
  }

  // Метод добавления элемента
  void pushBack(const T& value) {
    if (size_ >= capacity_) addMemory();
    arr_[size_++] = value;
  }

  // Метод удаления элемента
  void remove(size_t index) {
    for (size_t i = index + 1; i < size_; ++i) {
      arr_[i - 1] = arr_[i];
    }
    --size_;
  }

  // Оператор, который возвращает обычную ссылку на элемент
  T& operator[](size_t index) { return arr_[index]; }

  // Оператор, который возвращает константную ссылку на элемент
  const T& operator[](size_t index) const { return arr_[index]; }

  // Операторы присваивания
  Vector& operator=(Vector& other) {
    if (this != &other) {
      delete[] arr_;
      arr_ = new T[other.capacity_];
      for (size_t i = 0; i < other.size_; ++i) arr_[i] = other.arr_[i];
      size_ = other.size_;
      capacity_ = other.capacity_;
    }
    return *this;
  }

  Vector& operator=(Vector&& other) noexcept {
    if (this != &other) {
      delete[] arr_;
      arr_ = other.arr_;
      size_ = other.size_;
      capacity_ = other.capacity_;
      other.arr_ = nullptr;
      other.size_ = other.capacity_ = 0;
    }
    return *this;
  }

  // Итераторы
  T* begin() { return &arr_[0]; }
  const T* begin() const { return &arr_[0]; }
  T* end() { return &arr_[size_]; }
  const T* end() const { return &arr_[size_]; }

 private:
  T* arr_;
  size_t size_{};
  size_t capacity_{};
};
// Оператор записи в поток
// Он нужен для того, чтобы мы смогли выводить весь вектор в консоль ...
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
  for (size_t i = 0; i < vec.size(); ++i) os << vec[i] << " ";
  return os;
}
#endif  // VECTOR_H
