#ifndef AVL_MAP_H_
#define AVL_MAP_H_

#include <limits>

#include "../Iterators/Iterator.h"

namespace s21 {
template <typename T, typename V>
class Map {
 public:
  using mapped_type = V;
  using value_type = std::pair<const T, V>;
  using iterator = Iterator<T, V>;
  using constIterator = ConstIterator<T, V>;
  using size_type = size_t;
  using Allocator = std::allocator<T>;

 private:
};
}  // namespace s21
#endif  // AVL_MAP_H_