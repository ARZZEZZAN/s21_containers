#include "list"
#include "s21_list.tpp"
using namespace s21;
using namespace std;

int main() {
  s21::list<int> my_list1;
  my_list1.push_back(1);
  my_list1.push_back(3);
  my_list1.push_back(5);
  s21::list<int> my_list2;
  my_list2.push_back(2);
  my_list2.push_back(4);
  my_list2.push_back(6);
  my_list1.merge(my_list2);

  for (auto it = my_list1.begin(); it != my_list1.end(); ++it) {
    std::cout << *it << " ";
  }
  // EXPECT_EQ(my_list1.size(), 6);
  // EXPECT_TRUE(my_list2.empty());
  // EXPECT_EQ(my_list1.front(), 1);
  // EXPECT_EQ(my_list1.back(), 6);
}
