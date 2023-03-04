#include "list"
#include "s21_list.tpp"
using namespace s21;
using namespace std;
int main() {
  // s21::list<int> s21_l{1, 2, 3};
  // s21::list<int> s21_l2;

  // s21_l2.push_back(10);
  // s21_l2.push_back(20);
  // s21_l2.push_back(30);
  // s21_l.splice((s21_l.begin()), s21_l2);
  // cout << *(s21_l.begin()) << endl;
  // std::list<int> std_l{1, 2, 3};
  // std_l.insert(std_l.begin(), 5);

  // cout << *(std_l.begin()) << endl;

  s21::list<int> list1 = {1, 2, 3, 4, 5};
  s21::list<int> list2 = {10, 20, 30, 40, 50};

  auto it = list1.begin();

  list1.splice(it, list2);

  std::cout << "list1:" << *(list1.begin()) << "\n";
  std::cout << "list1:" << list1 << "\n";
  std::cout << "list2:" << list2 << "\n";

  list2.splice(list2.begin(), list1, it, list1.end());

  std::cout << "list1:" << list1 << "\n";
  std::cout << "list2:" << list2 << "\n";
}
