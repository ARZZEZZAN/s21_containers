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
  // my_list1.push_back(1);
  // my_list1.push_back(9999);
  // my_list1.push_back(20000);
  // my_list1.erase(--my_list1.end());

  std::list<int> std_list1{1, 9999, 20000};
  cout << *(std_list1.begin()++) << endl;
  // cout << *std_list1.begin() << endl;
  // std_list1.erase(std_list1.end().operator--());

  // cout << compare_lists(my_list1, std_list1) << endl;

  for (auto it = std_list1.begin(); it != std_list1.end(); it++) {
    std::cout << *it << ", ";
  }

  return 0;
}
