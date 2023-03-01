#include "s21_vector.tpp"
#include "vector"
using namespace s21;
using namespace std;

int main() {
  s21::vector<int> s21_v{110};

  // s21_v.push_back(5);
  std::cout << s21_v.size() << std::endl;
  // EXPECT_EQ(s21_v.size(), 1001);
  return 0;
}

// int main() {
//   s21::vector<int> s21_v;
//   s21_v.push_back(50);
//   s21_v.push_back(10);
//   s21_v.push_back(40);
//   s21_v.push_back(20);
//   s21_v.push_back(30);

//   // s21_v.erase(s21_v.begin() - 2);
//   std::cout << "size = " << s21_v.size() << std::endl;
//   std::cout << "capacity = " << s21_v.capacity() << std::endl;

//   s21_v.insert(s21_v.begin() + 6, 5);

//   std::cout << std::endl;
//   std::cout << "size = " << s21_v.size() << std::endl;
//   std::cout << "capacity = " << s21_v.capacity() << std::endl;

//   for (int i = 0; i < int(s21_v.size()); i++) {
//     std::cout << s21_v.at(i) << std::endl;
//   }
//   return 0;
// }