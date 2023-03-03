#include "list"
#include "s21_list.tpp"

using namespace s21;
using namespace std;

int main() {
  int k = 0;

  s21::list<int> s21_l;
  s21::list<int> s21_l2;
  s21_l.push_back(10);
  s21_l.push_back(40);
  s21_l.push_back(20);
  s21_l2.push_back(1);
  s21_l2.push_back(2);
  s21_l2.push_back(3);
  s21_l.merge(s21_l2);
  std::cout << "s21: ";
  k = 0;
  for (auto i = s21_l.begin(); i != s21_l.end(); ++i) {
    k++;
    std::cout << *i << " ";
  }

  std::cout << std::endl;

  std::list<int> std_l;
  std::list<int> std_l2;
  std_l.push_back(10);
  std_l.push_back(40);
  std_l.push_back(20);
  std_l2.push_back(1);
  std_l2.push_back(2);
  std_l2.push_back(3);
  std_l.merge(std_l2);
  std::cout << "std: ";
  k = 0;
  for (auto i = std_l.begin(); i != std_l.end(); ++i) {
    k++;
    std::cout << *i << " ";
  }
}
