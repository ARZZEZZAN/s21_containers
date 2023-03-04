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

  s21::list<int> my_list1{1, 2, 3, 4, 5};
  s21::list<int> my_list2{6, 7, 8, 9, 10, 11};

  my_list1.print_list();
  my_list2.print_list();
  std::cout << std::endl;

  my_list1.swap(my_list2);

  my_list1.print_list();
  my_list2.print_list();
  std::cout << "-------------------------------------------" << std::endl;
  std::cout << "-------------------------------------------" << std::endl;

  std::list<int> std_list1{1, 2, 3, 4, 5};
  std::list<int> std_list2{6, 7, 8, 9, 10, 11};

  print_std_list(std_list1);
  print_std_list(std_list2);
  std::cout << std::endl;

  std_list1.swap(std_list2);

  print_std_list(std_list1);
  print_std_list(std_list2);
  std::cout << "-------------------------------------------" << std::endl;

  return 0;
}
