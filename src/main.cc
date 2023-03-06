// #include <iostream>
#include <queue>

#include "s21_containers/queue/s21_queue.h"

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
  s21::queue<size_t> my_queue_empty;
  std::queue<size_t> std_queue_empty;
  std::cout << "-------------------------------------------" << std::endl;
  std::cout << my_queue_empty.front();
  std::cout << "-------------------------------------------" << std::endl;
  std::cout << std_queue_empty.front();
  std::cout << "-------------------------------------------" << std::endl;
  return 0;
}
