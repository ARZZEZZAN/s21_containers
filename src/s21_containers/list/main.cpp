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

  std_l.push_back(1);
  std_l.push_back(2);
  std_l.push_back(3);

  // s21_l.insert(s21_l.begin(), 100);
  // s21_l.insert(s21_l.begin() + 1, 100);
  // s21_l.insert(s21_l.begin() + 2, 100);
  s21_l.insert(s21_l.begin() + 4, 100);
  // s21_l.insert(s21_l.end(), 100);
  // std_l.begin()++;
  // std_l.begin()++;
  // std_l.begin()++;
  // std_l.insert(std_l.end()., 5);
  // for (auto i = std_l.begin(); i != std_l.end(); ++i) {
  //   std::cout << *i << " ";
  // }
  // std_l.end().operator--()
  // std::cout << std::endl;
  print_list(s21_l);
}
