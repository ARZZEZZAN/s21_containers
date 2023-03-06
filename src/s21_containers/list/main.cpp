#include <iostream>

#include "list"
#include "s21_list.tpp"
using namespace s21;
using namespace std;

template <typename value_type>
bool compare_lists(s21::list<value_type> my_list,
                   std::list<value_type> std_list) {
  bool result = true;
  if (my_list.size() == std_list.size()) {
    auto my_it = my_list.begin();
    auto std_it = std_list.begin();
    for (size_t i = 0; i != my_list.size(); ++i) {
      if (*my_it != *std_it) {
        result = false;
        break;
      }
      my_it++;
      std_it++;
    }
  } else {
    result = false;
  }
  return result;
}

int main() {
  s21::list<int> my_list1;

  *my_list1.begin();
  cout << *my_list1.begin() << endl;

  std::list<int> std_list2;
  cout << *std_list2.begin() << endl;
  // std::cout << "[";
  // for (auto it = std_list1.begin(); it != std_list1.end(); ++it) {
  //   std::cout << *it << ", ";
  // }
  // std::cout << "]\n";
  return 0;
}
