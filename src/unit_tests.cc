#include <gtest/gtest.h>

#include "s21_containers/list/s21_list.tpp"

TEST(ListTest, DefaultConstructor) {
  s21::list<int> lst;
  EXPECT_EQ(lst.size(), 0);
  EXPECT_TRUE(lst.empty());
  EXPECT_THROW(lst.front(), std::out_of_range);
  EXPECT_THROW(lst.back(), std::out_of_range);
}

TEST(ListTest, InitializerListConstructor) {
  s21::list<int> lst{1, 2, 3};
  EXPECT_EQ(lst.size(), 3);
  EXPECT_FALSE(lst.empty());
  EXPECT_EQ(lst.front(), 1);
  EXPECT_EQ(lst.back(), 3);
}

TEST(ListTest, CopyConstructor) {
  s21::list<int> lst{1, 2, 3};
  s21::list<int> lst_copy(lst);
  EXPECT_EQ(lst.size(), lst_copy.size());
  EXPECT_EQ(lst.front(), lst_copy.front());
  EXPECT_EQ(lst.back(), lst_copy.back());
}

TEST(ListTest, MoveConstructor) {
  s21::list<int> lst{1, 2, 3};
  s21::list<int> lst_copy(lst);
  s21::list<int> lst_move(std::move(lst));
  EXPECT_EQ(lst_copy.size(), lst_move.size());
  EXPECT_EQ(lst_copy.front(), lst_move.front());
  EXPECT_EQ(lst_copy.back(), lst_move.back());
}

TEST(ListTest, MoveAssignmentOperator) {
  s21::list<int> lst{1, 2, 3};
  s21::list<int> lst_copy(lst);
  s21::list<int> lst_move;
  lst_move = std::move(lst);
  EXPECT_EQ(lst_copy.size(), lst_move.size());
  EXPECT_EQ(lst_copy.front(), lst_move.front());
  EXPECT_EQ(lst_copy.back(), lst_move.back());
}

TEST(ListTest, PushBackPopBack) {
  s21::list<int> lst;
  lst.push_back(1);
  lst.push_back(2);
  lst.push_back(3);
  EXPECT_EQ(lst.size(), 3);
  EXPECT_FALSE(lst.empty());
  EXPECT_EQ(lst.front(), 1);
  EXPECT_EQ(lst.back(), 3);
  lst.pop_back();
  EXPECT_EQ(lst.size(), 2);
  EXPECT_EQ(lst.back(), 2);
  lst.pop_back();
  EXPECT_EQ(lst.size(), 1);
  EXPECT_EQ(lst.back(), 1);
  lst.pop_back();
  EXPECT_EQ(lst.size(), 0);
  EXPECT_TRUE(lst.empty());
  EXPECT_THROW(lst.front(), std::out_of_range);
  EXPECT_THROW(lst.back(), std::out_of_range);
}

TEST(ListTest, Clear) {
  s21::list<int> lst{1, 2, 3};
  lst.clear();
  EXPECT_EQ(lst.size(), 0);
  EXPECT_TRUE(lst.empty());
  EXPECT_THROW(lst.front(), std::out_of_range);
  EXPECT_THROW(lst.back(), std::out_of_range);
}

// TEST(ListTest, Insert) {
//   s21::list<int> lst {1, 3, 4};
//   auto it = lst.insert(++lst.begin(), 2);
//   EXPECT_EQ(lst.size(), 4);
//   EXPECT_FALSE(lst.empty());
//   EXPECT_EQ(lst.front(), 1);

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}