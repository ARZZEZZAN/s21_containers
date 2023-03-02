#include "list"
#include "s21_list.tpp"

using namespace s21;
using namespace std;

int main() {
  s21::list<int> s21_l;
  std::list<int> std_l;
  s21_l.push_back(1);
  s21_l.push_back(2);
  s21_l.push_back(3);
  // std::cout << s21_l.front() << std::endl;
  // s21_l.print_list();
}
