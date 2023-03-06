#include <gtest/gtest.h>

#include <list>

#include "s21_containers/list/s21_list.tpp"

template <typename value_type>
bool compare_lists(s21::list<value_type> my_list,
                   std::list<value_type> std_list) {
  bool result = true;
  if (my_list.size() == std_list.size()) {
    auto my_it = my_list.begin();
    auto std_it = std_list.begin();
    for (size_t i = 0; i != my_list.size(); ++i) {
      if (*my_it != *std_it) {
        result = false;
        break;
      }
      my_it++;
      std_it++;
    }
  } else {
    result = false;
  }
  return result;
}

TEST(ListTest, CompareLists) {
  s21::list<int> my_list{1, 2, 3, 4, 5};
  std::list<int> std_list{1, 2, 3, 4, 5};
  EXPECT_TRUE(compare_lists(my_list, std_list));
  std_list.push_back(6);
  EXPECT_FALSE(compare_lists(my_list, std_list));
  std_list.pop_back();
  my_list.push_front(0);
  std_list.push_front(0);
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, DefaultConstructor) {
  s21::list<int> my_list;
  std::list<int> std_list;
  EXPECT_EQ(my_list.size(), 0);
  EXPECT_TRUE(my_list.empty());
  EXPECT_THROW(my_list.front(), std::out_of_range);
  EXPECT_THROW(my_list.back(), std::out_of_range);
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, SizeConstructor) {
  s21::list<int> my_list(1000000);
  std::list<int> std_list(1000000);
  EXPECT_EQ(my_list.size(), 1000000);
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, SizeConstructorThrow) {
  try {
    s21::list<int> my_list(-1);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("Limit of the container is exceeded"));
  }
}

TEST(ListTest, InitializerListConstructor) {
  s21::list<int> my_list{1, 2, 3, 7, 9};
  std::list<int> std_list{1, 2, 3, 7, 9};
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, InitializerListConstructor_2) {
  std::initializer_list<int> b;
  s21::list<int> my_list{b};
  std::list<int> std_list{b};
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, CopyConstructor) {
  s21::list<int> my_list{1, 2, 3};
  s21::list<int> my_list_copy(my_list);
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_list_copy(std_list);
  EXPECT_TRUE(compare_lists(my_list_copy, std_list_copy));
}

TEST(ListTest, MoveConstructor) {
  s21::list<int> my_list{1, 2, 3};
  s21::list<int> my_list_copy(my_list);
  s21::list<int> my_list_move(std::move(my_list));
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_list_copy(std_list);
  std::list<int> std_list_move(std::move(std_list));
  EXPECT_TRUE(compare_lists(my_list_copy, std_list_copy));
}

TEST(ListTest, MoveAssignmentOperator) {
  s21::list<int> my_list{1, 2, 3};
  s21::list<int> my_list_copy(my_list);
  s21::list<int> my_list_move = std::move(my_list);
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_list_copy(std_list);
  std::list<int> std_list_move = std::move(std_list);
  EXPECT_TRUE(compare_lists(my_list_move, std_list_move));
}

TEST(ListTest, Front) {
  s21::list<int> my_list{99, 2, 3, 4, 5};
  std::list<int> std_list{99, 2, 3, 4, 5};
  EXPECT_EQ(my_list.front(), std_list.front());
}

TEST(ListTest, Back) {
  s21::list<int> my_list{1, 2, 3, 4, 99};
  std::list<int> std_list{1, 2, 3, 4, 99};
  EXPECT_EQ(my_list.back(), std_list.back());
}

TEST(ListTest, Empty) {
  s21::list<int> my_list;
  std::list<int> std_list;
  EXPECT_EQ(my_list.empty(), std_list.empty());
  my_list.push_back(10);
  std_list.push_back(10);
  EXPECT_EQ(my_list.empty(), std_list.empty());
}

TEST(ListTest, Size) {
  s21::list<int> my_list{1, 2, 3, 4, 5, 6, 7, 8};
  std::list<int> std_list{1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(my_list.size(), std_list.size());
}

TEST(ListTest, MaxSize) {
  s21::list<size_t> my_list_empty;
  EXPECT_EQ(my_list_empty.max_size(), std::numeric_limits<size_t>::max());
}

TEST(ListTest, Clear) {
  s21::list<int> my_list{1, 2, 3};
  my_list.clear();
  std::list<int> std_list{1, 2, 5, 4, 3};
  std_list.clear();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, PushBack) {
  s21::list<int> my_list{1, 2, 3, 4, 5};
  my_list.push_back(6);
  std::list<int> std_list{1, 2, 3, 4, 5};
  std_list.push_back(6);
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, PopBack) {
  s21::list<int> my_list{1, 2, 3, 4, 5};
  my_list.pop_back();
  std::list<int> std_list{1, 2, 3, 4, 5};
  std_list.pop_back();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, PushFront) {
  s21::list<int> my_list{1, 2, 3, 4, 5};
  my_list.push_front(0);
  std::list<int> std_list{1, 2, 3, 4, 5};
  std_list.push_front(0);
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, PopFront) {
  s21::list<int> my_list{1, 2, 3, 4, 5};
  my_list.pop_front();
  std::list<int> std_list{1, 2, 3, 4, 5};
  std_list.pop_front();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Swap) {
  s21::list<int> my_list1{1, 2, 3, 4, 5};
  s21::list<int> my_list2{6, 7, 8, 9, 10, 11};
  my_list1.swap(my_list2);

  std::list<int> std_list1{1, 2, 3, 4, 5};
  std::list<int> std_list2{6, 7, 8, 9, 10, 11};
  std_list1.swap(std_list2);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
  EXPECT_TRUE(compare_lists(my_list2, std_list2));
}

TEST(ListTest, begin_1) {
  s21::list<int> my_list1{500, 15000, 30000};

  std::list<int> std_list2{500, 15000, 30000};
  EXPECT_EQ(*my_list1.begin(), *std_list2.begin());
}

TEST(ListTest, begin_2) {
  s21::list<int> my_list1(4);

  std::list<int> std_list2(4);
  EXPECT_EQ(*my_list1.begin(), *std_list2.begin());
}

TEST(ListTest, begin_3_throw) {
  s21::list<int> my_list1;
  std::list<int> std_list2;

  EXPECT_THROW(*my_list1.begin(), std::invalid_argument);
}

TEST(ListTest, end_1) {
  s21::list<int> my_list1{500, 15000, 30000};

  std::list<int> std_list2{500, 15000, 30000};
  EXPECT_EQ(*my_list1.begin(), *std_list2.begin());
}

TEST(ListTest, end_2) {
  s21::list<int> my_list1(4);

  std::list<int> std_list2(4);
  EXPECT_EQ(*my_list1.end(), *std_list2.end());
}

TEST(ListTest, end_3) {
  s21::list<int> my_list1;

  std::list<int> std_list2;
  EXPECT_EQ(*my_list1.end(), *std_list2.end());
}

TEST(ListTest, Merge_1) {
  s21::list<int> my_list1{1, 9999, 20000};
  s21::list<int> my_list2{500, 15000, 30000};
  my_list1.merge(my_list2);

  std::list<int> std_list1{1, 9999, 20000};
  std::list<int> std_list2{500, 15000, 30000};
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Merge_2) {
  s21::list<int> my_list1{1, 9999, 20000};
  s21::list<int> my_list2{15000, 30000};
  my_list1.merge(my_list2);

  std::list<int> std_list1{1, 9999, 20000};
  std::list<int> std_list2{15000, 30000};
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Merge_3) {
  s21::list<int> my_list1{1, 20000, 666};
  s21::list<int> my_list2{15000, 154, 124, 30000};
  my_list1.merge(my_list2);

  std::list<int> std_list1{1, 20000, 666};
  std::list<int> std_list2{15000, 154, 124, 30000};
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Merge_4) {
  s21::list<int> my_list1;
  s21::list<int> my_list2{15000, 154, 124, 30000};
  my_list1.merge(my_list2);

  std::list<int> std_list1;
  std::list<int> std_list2{15000, 154, 124, 30000};
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Merge_5) {
  s21::list<int> my_list1{1, 20000, 666};
  s21::list<int> my_list2;
  my_list1.merge(my_list2);

  std::list<int> std_list1{1, 20000, 666};
  std::list<int> std_list2;
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Merge_6) {
  s21::list<int> my_list1;
  s21::list<int> my_list2;
  my_list1.merge(my_list2);

  std::list<int> std_list1;
  std::list<int> std_list2;
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Reverse_1) {
  s21::list<int> my_list{1, 2, 3, 4, 5};
  std::list<int> std_list{1, 2, 3, 4, 5};
  my_list.reverse();
  std_list.reverse();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Reverse_2) {
  s21::list<int> my_list(4);
  std::list<int> std_list(4);
  my_list.reverse();
  std_list.reverse();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Reverse_3) {
  s21::list<int> my_list;
  std::list<int> std_list;
  my_list.reverse();
  std_list.reverse();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Unique_1) {
  s21::list<int> my_list{90, 10, 3, 40, 30, 20, 10, 10, 90, 90, 90};
  std::list<int> std_list{90, 10, 3, 40, 30, 20, 10, 10, 90, 90, 90};
  my_list.unique();
  std_list.unique();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Unique_2) {
  s21::list<int> my_list(3);
  std::list<int> std_list(3);
  my_list.unique();
  std_list.unique();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Unique_3) {
  s21::list<int> my_list;
  std::list<int> std_list;
  my_list.unique();
  std_list.unique();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Splice_1) {
  s21::list<int> my_list1{1, 9999, 20000};
  s21::list<int> my_list2{500, 15000, 30000};
  my_list1.splice(my_list1.begin(), my_list2);

  std::list<int> std_list1{1, 9999, 20000};
  std::list<int> std_list2{500, 15000, 30000};
  std_list1.splice(std_list1.begin(), std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Splice_2) {
  s21::list<int> my_list1;
  s21::list<int> my_list2{500, 15000, 30000};
  my_list1.splice(my_list1.begin(), my_list2);

  std::list<int> std_list1;
  std::list<int> std_list2{500, 15000, 30000};
  std_list1.splice(std_list1.begin(), std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Splice_3) {
  s21::list<int> my_list1{1, 9999, 20000};
  s21::list<int> my_list2;
  my_list1.splice(my_list1.begin(), my_list2);

  std::list<int> std_list1{1, 9999, 20000};
  std::list<int> std_list2;
  std_list1.splice(std_list1.begin(), std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Splice_4) {
  s21::list<int> my_list1;
  s21::list<int> my_list2;
  my_list1.splice(my_list1.begin(), my_list2);

  std::list<int> std_list1;
  std::list<int> std_list2;
  std_list1.splice(std_list1.begin(), std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Sort) {
  s21::list<int> my_list{90, 10, 3, 40, 30, 20, 2000, 10, 90, 100, 3};
  std::list<int> std_list{90, 10, 3, 40, 30, 20, 2000, 10, 90, 100, 3};
  my_list.sort();
  std_list.sort();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

// ------------Above checked---------------------

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

// TEST(ListTest, PushBackPopBack) {
//   s21::list<int> list;
//   list.push_back(1);
//   list.push_back(2);
//   list.push_back(3);
//   EXPECT_EQ(list.size(), 3);
//   EXPECT_FALSE(list.empty());
//   EXPECT_EQ(list.front(), 1);
//   EXPECT_EQ(list.back(), 3);
//   list.pop_back();
//   EXPECT_EQ(list.size(), 2);
//   EXPECT_EQ(list.back(), 2);
//   list.pop_back();
//   EXPECT_EQ(list.size(), 1);
//   EXPECT_EQ(list.back(), 1);
//   list.pop_back();
//   EXPECT_EQ(list.size(), 0);
//   EXPECT_TRUE(list.empty());
//   EXPECT_THROW(list.front(), std::out_of_range);
//   EXPECT_THROW(list.back(), std::out_of_range);
// }

// TEST(ListTest, Clear) {
//   s21::list<int> list{1, 2, 3};
//   list.clear();
//   EXPECT_EQ(list.size(), 0);
//   EXPECT_TRUE(list.empty());
//   EXPECT_THROW(list.front(), std::out_of_range);
//   EXPECT_THROW(list.back(), std::out_of_range);
// }

// TEST(ListTest, Insert) {
//   list<int> my_list{1, 2, 3, 4, 5};
//   auto it = my_list.insert(my_list.begin(), 6);
//   EXPECT_EQ(*it, 6);
//   EXPECT_EQ(my_list.size(), 6);
// }

// TEST(ListTest, Erase) {
//   list<int> my_list{1, 2, 3, 4, 5};
//   my_list.erase(my_list.begin());
//   EXPECT_EQ(my_list.front(), 2);
//   EXPECT_EQ(my_list.size(), 4);
// }
// // TODO
// // TEST(ListTest, Splice) {
// //   const list<int> my_list1{1, 2, 3, 4, 5};
// //   list<int> my_list2{6, 7, 8, 9, 10};
// //   auto it = my_list1.begin();
// //   my_list1.splice(++it, my_list2);
// //   EXPECT_EQ(my_list1.size(), 10);
// //   EXPECT_TRUE(my_list2.empty());
// // }

// // TEST(ListTest, Reverse) {
// //   list<int> my_list{1, 2, 3, 4, 5};
// //   my_list.reverse();
// //   EXPECT_EQ(my_list.front(), 5
