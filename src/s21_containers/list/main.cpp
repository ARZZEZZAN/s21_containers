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
  s21::list<int> my_list;
  my_list.push_back(90);
  my_list.push_back(10);
  my_list.push_back(3);
  my_list.push_back(40);
  my_list.push_back(30);
  my_list.push_back(20);
  my_list.push_back(10);  // del
  my_list.push_back(10);
  my_list.push_back(90);  // del
  my_list.push_back(90);
  my_list.push_back(3);

  std::list<int> std_list;
  std_list.push_back(90);
  std_list.push_back(10);
  std_list.push_back(3);
  std_list.push_back(40);
  std_list.push_back(30);
  std_list.push_back(20);
  std_list.push_back(10);
  std_list.push_back(10);
  std_list.push_back(90);
  std_list.push_back(90);
  std_list.push_back(3);

  my_list.unique();
  std_list.unique();

  cout << compare_lists(my_list, std_list) << endl;

  return 0;
}
