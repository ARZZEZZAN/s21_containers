// #include <iostream>
#include <list>

#include "s21_containers/list/s21_list.tpp"

void print_std_list(std::list<int>& l) {
  for (auto i = l.begin(); i != l.end(); ++i) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
}

int main() {
  // std::cout << "-------------------------------------------" << std::endl;

  // s21::list<int> my_list;

  // // my_list.print_list();
  // std::cout << std::endl;

  // my_list.front();

  // // my_list.print_list();

  // std::cout << "-------------------------------------------" << std::endl;
  // std::cout << "-------------------------------------------" << std::endl;

  // std::list<int> std_list;

  // // print_std_list(std_list);
  // std::cout << std::endl;

  // std_list.front();

  // // print_std_list(std_list);

  // std::cout << "-------------------------------------------" << std::endl;

  // // std::list<int> std_list2(-1);
  s21::list<size_t> my_list_empty;
  std::list<size_t> std_list_empty;
  std::cout << "-------------------------------------------" << std::endl;
  std::cout << my_list_empty.max_size();
  std::cout << "-------------------------------------------" << std::endl;
  std::cout << std_list_empty.max_size();
  std::cout << "-------------------------------------------" << std::endl;
  return 0;
}
