// #include <iostream>
#include <list>
#include <queue>

#include "s21_containers/queue/s21_queue.h"

int main() {
  s21::queue<int> my_queue{1, 2, 3, 4, 5, 6, 7, 8};
  std::initializer_list<int> il = {1, 2, 3, 4, 5, 6, 7, 8};
  std::queue<int> std_queue{il};
  my_queue.pop();
  my_queue.pop();
  std_queue.pop();
  std_queue.pop();
  std::cout << "my_queue: " << my_queue.front() << std::endl;
  std::cout << "std_queue: " << std_queue.front() << std::endl;

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
  // s21::queue<int> my_queue{1, 2, 3};
  // std::queue<int, std::list<int>> std_queue{std::list<int>{1, 2, 3}};
  // std::cout << "-------------------------------------------" << std::endl;
  // std::cout << my_queue.front() << std::endl;
  // std::cout << "-------------------------------------------" << std::endl;
  // std::cout << std_queue.front() << std::endl;
  // std::cout << "-------------------------------------------" << std::endl;
  return 0;
}
