#include "list"
#include "s21_list.tpp"

using namespace s21;
using namespace std;

int main() {
  s21::list<int> s21_l;
  s21_l.push_back(10);
  s21_l.push_back(20);
  s21_l.push_back(30);
  q s21_l.insert(s21_l.end().operator++(), 100);
  int k = 0;
  for (auto i = s21_l.begin(); k < int(s21_l.size()); i++) {
    k++;
    std::cout << *i << " ";
  }
  std::cout << std::endl;

  std::list<int> std_l;
  std_l.push_back(10);
  std_l.push_back(20);
  std_l.push_back(30);
  std_l.insert(std_l.end().operator++(), 100);
  k = 0;
  for (auto i = std_l.begin(); k < int(std_l.size()); i++) {
    k++;
    std::cout << *i << " ";
  }
  std::cout << std::endl;
}
