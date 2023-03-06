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
  // s21::list<int> my_list1;
  // s21::list<int> my_list2{500, 15000, 30000};
  // my_list1.splice(my_list1.begin(), my_list2);
  // my_list1.print_list();

  std::list<int> std_list1;
  std::list<int> std_list2{500, 15000, 30000};
  std_list1.splice(std_list1.begin(), std_list2);

  std::cout << "[";
  for (auto it = std_list1.begin(); it != std_list1.end(); ++it) {
    std::cout << *it << ", ";
  }
  std::cout << "]\n";

  std::cout << "[";
  for (auto it = std_list2.begin(); it != std_list2.end(); ++it) {
    std::cout << *it << ", ";
  }

  std::cout << "]\n";
  return 0;
}
