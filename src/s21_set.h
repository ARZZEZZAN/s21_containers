#ifndef S21_SET_H
#define S21_SET_H

#include <cstddef>  // for std::size_t

namespace s21 {

template <typename T>
class set {
 public:
  // types:
  using value_type = T;
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;

  // constructors and destructor:
  set() = default;
  set(const set& other);
  set(set&& other) noexcept;
  set(std::initializer_list<T> init);
  ~set();

  // assignment:
  set& operator=(const set& other);
  set& operator=(set&& other) noexcept;
  set& operator=(std::initializer_list<T> init);

  // iterators:
  // TODO: Define iterator and const_iterator classes

  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;

  // capacity:
  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  // modifiers:
  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert(value_type&& value);
  iterator insert(const_iterator hint, const value_type& value);
  iterator insert(const_iterator hint, value_type&& value);
  template <typename InputIt>
  void insert(InputIt first, InputIt last);
  void insert(std::initializer_list<T> ilist);
  iterator erase(const_iterator pos);
  size_type erase(const value_type& value);
  iterator erase(const_iterator first, const_iterator last);
  void swap(set& other);
  void clear();

  // lookup:
  size_type count(const value_type& value) const;
  iterator find(const value_type& value);
  const_iterator find(const value_type& value) const;
  std::pair<iterator, iterator> equal_range(const value_type& value);
  std::pair<const_iterator, const_iterator> equal_range(
      const value_type& value) const;
  iterator lower_bound(const value_type& value);
  const_iterator lower_bound(const value_type& value) const;
  iterator upper_bound(const value_type& value);
  const_iterator upper_bound(const value_type& value) const;

  // TODO: Define comparison operators

 private:
  // TODO: Define Red-Black Tree implementation details
};

}  // namespace s21

#endif  // S21_SET_H