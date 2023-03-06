#include <iostream>

#include "s21_stack.tpp"
#include "stack"

using namespace s21;
using namespace std;

int main() {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;

  s21_stack.push(4);
  cout << s21_stack.top() << endl;

  std_stack.push(4);
  cout << std_stack.top() << endl;
  return 0;
}
