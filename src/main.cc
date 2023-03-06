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
  std::cout << "-------------------------------------------" << std::endl;

  s21::list<int> my_list{90, 10, 3, 40, 30, 20, 10, 10, 90, 90, 3};

  my_list.print_list();
  std::cout << std::endl;

  my_list.unique();

  my_list.print_list();

  std::cout << "-------------------------------------------" << std::endl;
  std::cout << "-------------------------------------------" << std::endl;

  std::list<int> std_list{90, 10, 3, 40, 30, 20, 10, 10, 90, 90, 3};

  print_std_list(std_list);
  std::cout << std::endl;

  std_list.unique();

  print_std_list(std_list);

  std::cout << "-------------------------------------------" << std::endl;

  // std::list<int> std_list2(-1);

  return 0;
}
