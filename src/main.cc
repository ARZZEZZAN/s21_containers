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
  s21::list<int> l1 = {99, 9, 1, 2, 3};
  std::list<int> l2 = {99, 9, 1, 2, 3};

  l1.print_list();
  print_std_list(l2);

  l1.sort();
  l2.sort();

  l1.print_list();
  print_std_list(l2);

  std::cout << "-------------------------------------------" << std::endl;

  s21::list<int> l3 = {10000000, 9, 10000, 2, 10000000, 20000000};
  std::list<int> l4 = {10000000, 9, 10000, 2, 10000000, 20000000};

  l3.insert(l3.begin() + 2, 99999999);
  auto it = l4.begin();
  it++;
  it++;
  l4.insert(l4.begin(), 99999999);
  l3.print_list();
  print_std_list(l4);

  l3.sort();
  l4.sort();

  l3.print_list();
  print_std_list(l4);

  std::cout << "-------------------------------------------" << std::endl;

  s21::list<int> lcopy(l3);
  lcopy.print_list();
  return 0;
}
