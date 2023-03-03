#include "list"
#include "s21_list.tpp"

using namespace s21;
using namespace std;

int main() {
  int n = 5;
  int k = 0;

  s21::list<int> s21_l;
  // s21_l.push_back(10);
  // s21_l.push_back(20);
  // s21_l.push_back(30);
  s21_l.insert(s21_l.end() - 1, 100);
  std::cout << "s21: ";
  k = 0;
  for (auto i = s21_l.begin(); k < n; ++i) {
    k++;
    std::cout << *i << " ";
  }

  std::cout << std::endl;

  std::list<int> std_l;
  std_l.push_back(10);
  std_l.push_back(20);
  std_l.push_back(30);
  std_l.insert(std_l.end().operator--(), 100);
  // .operator++().operator++().operator++().operator++()
  std::cout << "std: ";
  k = 0;
  for (auto i = std_l.begin(); k < n; ++i) {
    k++;
    std::cout << *i << " ";
  }
}
