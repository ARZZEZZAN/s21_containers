#include <gtest/gtest.h>

#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include "./s21_containers/s21_containers.h"

// VECTOR
TEST(VectorTest, Constructor_default) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.data(), std_v.data());
  EXPECT_EQ(s21_v.empty(), std_v.empty());
}

TEST(VectorTest, Constructor_n) {
  s21::vector<int> s21_v(5);
  std::vector<int> std_v(5);
  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.empty(), std_v.empty());
}

TEST(VectorTest, Constructor_n_throw) {
  try {
    s21::vector<int> s21_v(-1);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(),
              std::string("cannot create s21::vector larger than max_size()"));
  }
}

TEST(VectorTest, Constructor_initializer_list_1) {
  s21::vector<int> s21_v{2, 3, 5, 7, 1};
  std::vector<int> std_v{2, 3, 5, 7, 1};
  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.empty(), std_v.empty());
  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));
  EXPECT_EQ(s21_v.at(4), std_v.at(4));
}

TEST(VectorTest, Constructor_initializer_list_2) {
  std::initializer_list<int> b;
  s21::vector<int> s21_v{b};
  std::vector<int> std_v{b};
  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.empty(), std_v.empty());
}

TEST(VectorTest, Constructor_copy_1) {
  s21::vector<int> s21_v{2, 3, 5, 7, 1};
  std::vector<int> std_v{2, 3, 5, 7, 1};
  s21::vector<int> s21_copy(s21_v);
  std::vector<int> std_copy(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.empty(), std_v.empty());
  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));
  EXPECT_EQ(s21_v.at(4), std_v.at(4));

  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
  EXPECT_EQ(s21_copy.at(0), std_copy.at(0));
  EXPECT_EQ(s21_copy.at(1), std_copy.at(1));
  EXPECT_EQ(s21_copy.at(2), std_copy.at(2));
  EXPECT_EQ(s21_copy.at(3), std_copy.at(3));
  EXPECT_EQ(s21_copy.at(4), std_copy.at(4));
}

TEST(VectorTest, Constructor_copy_2) {
  s21::vector<int> s21_v;
  s21::vector<int> s21_copy(s21_v);
  std::vector<int> std_v;
  std::vector<int> std_copy(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.empty(), std_v.empty());

  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(VectorTest, Constructor_move_1) {
  s21::vector<int> s21_v;
  s21::vector<int> s21_move(s21_v);
  std::vector<int> std_v;
  std::vector<int> std_move(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.empty(), std_v.empty());

  EXPECT_EQ(s21_move.size(), std_move.size());
  EXPECT_EQ(s21_move.capacity(), std_move.capacity());
  EXPECT_EQ(s21_move.empty(), std_move.empty());
}

TEST(VectorTest, Constructor_move_2) {
  s21::vector<int> s21_v{1, 2, 3, 4, 5};
  s21::vector<int> s21_move(s21_v);
  std::vector<int> std_v{1, 2, 3, 4, 5};
  std::vector<int> std_move(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.empty(), std_v.empty());

  EXPECT_EQ(s21_move.size(), std_move.size());
  EXPECT_EQ(s21_move.capacity(), std_move.capacity());
  EXPECT_EQ(s21_move.empty(), std_move.empty());
}

TEST(VectorTest, Destructor) {
  s21::vector<int> s21_v{1, 2, 3, 4, 5};
  s21_v.~vector();

  EXPECT_EQ(0, s21_v.size());
  EXPECT_EQ(0, s21_v.capacity());
  EXPECT_EQ(0, s21_v.data());
}

TEST(VectorTest, Operator_move_1) {
  s21::vector<int> s21_v1{1, 2, 3};
  s21::vector<int> s21_v2;
  s21_v2 = std::move(s21_v1);
  EXPECT_EQ(s21_v2.size(), 3);
  EXPECT_EQ(s21_v2.at(0), 1);
  EXPECT_EQ(s21_v2.at(1), 2);
  EXPECT_EQ(s21_v2.at(2), 3);
}

TEST(VectorTest, Operator_move_2) {
  s21::vector<int> s21_v1{1, 2, 3};
  s21::vector<int> s21_v2{4, 5, 6};
  s21_v2 = std::move(s21_v1);
  EXPECT_EQ(s21_v2.size(), 3);
  EXPECT_EQ(s21_v2.at(0), 1);
  EXPECT_EQ(s21_v2.at(1), 2);
  EXPECT_EQ(s21_v2.at(2), 3);
}

TEST(VectorTest, Element_at) {
  s21::vector<int> s21_v{1, 2, 3, 4, 5};
  std::vector<int> std_v{1, 2, 3, 4, 5};

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));
  EXPECT_EQ(s21_v.at(4), std_v.at(4));
}

TEST(VectorTest, Element_at_throw) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_ANY_THROW(s21_v.at(1));
  EXPECT_ANY_THROW(std_v.at(1));
}

TEST(VectorTest, Element_front) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  EXPECT_EQ(s21_v.front(), std_v.front());
}

TEST(VectorTest, Element_front_throw) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_ANY_THROW(s21_v.front());
}

TEST(VectorTest, Element_back) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  EXPECT_EQ(s21_v.back(), std_v.back());
}

TEST(VectorTest, Element_back_throw) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_ANY_THROW(s21_v.back());
}

TEST(VectorTest, Element_operator_square_brackets) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  EXPECT_EQ(s21_v[0], std_v[0]);
  EXPECT_EQ(s21_v[1], std_v[1]);
  EXPECT_EQ(s21_v[2], std_v[2]);
}

TEST(VectorTest, Element_operator_square_brackets_throw_1) {
  s21::vector<int> s21_v{1, 2, 3};
  EXPECT_ANY_THROW(s21_v[5]);
}

TEST(VectorTest, Element_operator_square_brackets_throw_2) {
  s21::vector<int> s21_v{1, 2, 3};
  EXPECT_ANY_THROW(s21_v[-1]);
}

TEST(VectorTest, Element_data) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};

  EXPECT_EQ(*s21_v.data(), *std_v.data());
}

TEST(VectorTest, Capacity_empty_1) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};

  EXPECT_EQ(s21_v.empty(), std_v.empty());
}

TEST(VectorTest, Capacity_empty_2) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;

  EXPECT_EQ(s21_v.empty(), std_v.empty());
}

TEST(VectorTest, Capacity_size_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;

  EXPECT_EQ(s21_v.size(), std_v.size());
}

TEST(VectorTest, Capacity_size_2) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};

  EXPECT_EQ(s21_v.size(), std_v.size());
}

TEST(VectorTest, Capacity_capacity_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;

  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_capacity_2) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};

  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_reserve_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  s21_v.reserve(2);
  std_v.reserve(2);
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_reserve_2) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.reserve(2);
  std_v.reserve(2);
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_reserve_3) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.reserve(10);
  std_v.reserve(10);
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_reserve_4_throw) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  EXPECT_ANY_THROW(s21_v.reserve(-2));
  EXPECT_ANY_THROW(std_v.reserve(-2));
}

TEST(VectorTest, Capacity_shrink_to_fit_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  s21_v.reserve(10);
  std_v.reserve(10);
  s21_v.shrink_to_fit();
  std_v.shrink_to_fit();
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_shrink_to_fit_2) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.reserve(10);
  std_v.reserve(10);
  s21_v.shrink_to_fit();
  std_v.shrink_to_fit();
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(VectorTest, Modifiers_clear_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  s21_v.clear();
  std_v.clear();

  EXPECT_EQ(s21_v.size(), std_v.size());
}

TEST(VectorTest, Modifiers_clear_2) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.clear();
  std_v.clear();

  EXPECT_EQ(s21_v.size(), std_v.size());
}

TEST(VectorTest, Modifiers_insert_1) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.insert(s21_v.begin() + 1, 5);
  std_v.insert(std_v.begin() + 1, 5);

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
}

TEST(VectorTest, Modifiers_insert_2) {
  s21::vector<int> s21_v{50, 10, 40, 20, 30};
  std::vector<int> std_v{50, 10, 40, 20, 30};
  s21_v.insert(s21_v.begin() + s21_v.size(), 100);
  std_v.insert(std_v.begin() + std_v.size(), 100);

  EXPECT_EQ(s21_v.at(5), std_v.at(5));
}

TEST(VectorTest, Modifiers_insert_3) {
  try {
    s21::vector<int> s21_v{50, 10, 40, 20, 30};
    s21_v.insert(s21_v.begin() + 10, 100);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("Index out ot range"));
  }
}

TEST(VectorTest, Modifiers_insert_4) {
  try {
    s21::vector<int> s21_v{50, 10, 40, 20, 30};
    s21_v.insert(s21_v.begin() - 4, 100);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("Index out ot range"));
  }
}

TEST(VectorTest, Modifiers_erase_1) {
  s21::vector<int> s21_v{1, 2, 3, 4};
  std::vector<int> std_v{1, 2, 3, 4};

  s21_v.erase(s21_v.begin() + 1);
  std_v.erase(std_v.begin() + 1);

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
}

TEST(VectorTest, Modifiers_erase_2) {
  s21::vector<int> s21_v{50, 10, 40, 20, 30};
  std::vector<int> std_v{50, 10, 40, 20, 30};
  s21_v.erase(s21_v.begin());
  std_v.erase(std_v.begin());

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));
}

TEST(VectorTest, Modifiers_erase_3) {
  s21::vector<int> s21_v{50, 10, 40, 20, 30};
  std::vector<int> std_v{50, 10, 40, 20, 30};
  s21_v.erase(s21_v.end() - 1);
  std_v.erase(std_v.end() - 1);

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));
}

TEST(VectorTest, Modifiers_erase_4) {
  try {
    s21::vector<int> s21_v{50, 10, 40, 20, 30};
    s21_v.erase(s21_v.begin() - 1);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("Index out ot range"));
  }
}

TEST(VectorTest, Modifiers_erase_5) {
  try {
    s21::vector<int> s21_v{50, 10, 40, 20, 30};
    s21_v.erase(s21_v.end() + 1);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("Index out ot range"));
  }
}

TEST(VectorTest, Modifiers_push_back_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;

  s21_v.push_back(2);
  s21_v.push_back(3);
  s21_v.push_back(4);
  s21_v.push_back(5);

  std_v.push_back(2);
  std_v.push_back(3);
  std_v.push_back(4);
  std_v.push_back(5);

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));
}

TEST(VectorTest, Modifiers_push_back_2) {
  s21::vector<int> s21_v{1, 2};
  std::vector<int> std_v{1, 2};

  s21_v.push_back(2);
  s21_v.push_back(3);
  s21_v.push_back(4);
  s21_v.push_back(5);

  std_v.push_back(2);
  std_v.push_back(3);
  std_v.push_back(4);
  std_v.push_back(5);

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));
  EXPECT_EQ(s21_v.at(4), std_v.at(4));
  EXPECT_EQ(s21_v.at(5), std_v.at(5));
}

TEST(VectorTest, Modifiers_pop_back_1) {
  s21::vector<int> s21_v{1, 2};

  s21_v.pop_back();
  s21_v.pop_back();
  s21_v.pop_back();
  s21_v.pop_back();

  EXPECT_EQ(s21_v.size(), 0);
  EXPECT_EQ(s21_v.capacity(), 2);
}

TEST(VectorTest, Modifiers_pop_back_2) {
  s21::vector<int> s21_v;

  s21_v.pop_back();
  s21_v.pop_back();
  s21_v.pop_back();
  s21_v.pop_back();

  EXPECT_EQ(s21_v.size(), 0);
  EXPECT_EQ(s21_v.capacity(), 0);
}

TEST(VectorTest, Modifiers_swap_1) {
  s21::vector<int> s21_v;
  s21::vector<int> s21_v_copy;

  std::vector<int> std_v;
  std::vector<int> std_v_copy;

  s21_v_copy.swap(s21_v);
  std_v_copy.swap(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());

  EXPECT_EQ(s21_v_copy.size(), std_v_copy.size());
  EXPECT_EQ(s21_v_copy.capacity(), std_v_copy.capacity());
}

TEST(VectorTest, Modifiers_swap_2) {
  s21::vector<int> s21_v{1, 2, 3, 4};
  s21::vector<int> s21_v_copy;

  std::vector<int> std_v{1, 2, 3, 4};
  std::vector<int> std_v_copy;

  s21_v_copy.swap(s21_v);
  std_v_copy.swap(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());

  EXPECT_EQ(s21_v_copy.size(), std_v_copy.size());
  EXPECT_EQ(s21_v_copy.capacity(), std_v_copy.capacity());
}

TEST(VectorTest, Modifiers_swap_3) {
  s21::vector<int> s21_v{1, 2, 3, 4};
  s21::vector<int> s21_v_copy{1, 2};

  std::vector<int> std_v{1, 2, 3, 4};
  std::vector<int> std_v_copy{1, 2};

  s21_v_copy.swap(s21_v);
  std_v_copy.swap(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());

  EXPECT_EQ(s21_v_copy.size(), std_v_copy.size());
  EXPECT_EQ(s21_v_copy.capacity(), std_v_copy.capacity());
}

TEST(VectorTest, Modifiers_swap_4) {
  s21::vector<int> s21_v{1, 2, 3, 4};
  s21::vector<int> s21_v_copy{1, 2, 3, 4, 5, 6};

  std::vector<int> std_v{1, 2, 3, 4};
  std::vector<int> std_v_copy{1, 2, 3, 4, 5, 6};

  s21_v_copy.swap(s21_v);
  std_v_copy.swap(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());

  EXPECT_EQ(s21_v_copy.size(), std_v_copy.size());
  EXPECT_EQ(s21_v_copy.capacity(), std_v_copy.capacity());
}

TEST(VectorTest, Helpers_add_memotysize_1) {
  int n = 1000;
  s21::vector<int> s21_v(n);
  s21_v.push_back(1);
  EXPECT_EQ(s21_v.size(), n + 1);
}

TEST(VectorTest, Helpers_add_memotysize_2) {
  int n = 10000;
  s21::vector<int> s21_v(n);
  s21_v.push_back(1);

  EXPECT_EQ(s21_v.size(), n + 1);
}

TEST(VectorTest, Helpers_add_memotysize_3) {
  int n = 100000;
  s21::vector<int> s21_v(n);
  s21_v.push_back(1);
  s21_v.push_back(1);
  s21_v.push_back(1);

  EXPECT_EQ(s21_v.size(), n + 3);
}

// STACK
TEST(StackTest, Constructor_default) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Constructor_initializer_list_1) {
  s21::stack<int> s21_stack{1, 2, 4};
  EXPECT_EQ(s21_stack.size(), 3);
  EXPECT_EQ(s21_stack.top(), 4);
}

TEST(StackTest, Constructor_initializer_list_2) {
  std::initializer_list<int> b;
  s21::stack<int> s21_stack{b};
  std::stack<int> std_stack{b};
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Constructor_copy_1) {
  std::initializer_list<int> il1 = {1, 2, 3};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_copy{s21_stack};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_copy{std_stack};
  EXPECT_EQ(s21_stack_copy.size(), std_stack_copy.size());
  EXPECT_EQ(s21_stack_copy.top(), std_stack_copy.top());
}

TEST(StackTest, Constructor_move_1) {
  std::initializer_list<int> il1 = {1, 2, 3};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_move{s21_stack};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{std_stack};
  EXPECT_EQ(s21_stack_move.size(), std_stack_move.size());
  EXPECT_EQ(s21_stack_move.top(), std_stack_move.top());
}

TEST(StackTest, Opertator_move_1) {
  std::initializer_list<int> il1 = {1, 2, 3};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_move{il2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Opertator_move_2) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {1, 2, 3};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_move{il2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Opertator_move_3) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_move{il2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Top_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};

  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Top_2_throw) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};

  EXPECT_THROW(s21_stack.top(), std::out_of_range);
}

TEST(StackTest, Empty_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(StackTest, Empty_2) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(StackTest, Size_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Size_2) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Push_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Push_2) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Pop_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Pop_2) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), 0);
}

TEST(StackTest, Swap_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {1, 2, 3};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

TEST(StackTest, Swap_2) {
  std::initializer_list<int> il1 = {1, 2, 3};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

TEST(StackTest, Swap_3) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2;

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, Swap_4) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, Swap_5) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2;

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, Swap_6) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

// LIST

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

TEST(ListTest, CopyConstructorEmpty) {
  s21::list<int> my_list;
  s21::list<int> my_list_copy(my_list);
  std::list<int> std_list;
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

TEST(ListTest, MoveConstructorEmpty) {
  s21::list<int> my_list;
  s21::list<int> my_list_copy(my_list);
  s21::list<int> my_list_move(std::move(my_list));
  std::list<int> std_list;
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

TEST(ListTest, MoveAssignmentOperatorEmpty) {
  s21::list<int> my_list;
  s21::list<int> my_list_copy(my_list);
  s21::list<int> my_list_move = std::move(my_list);
  std::list<int> std_list;
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

TEST(ListTest, SizeEmpty) {
  s21::list<int> my_list;
  std::list<int> std_list;
  EXPECT_EQ(my_list.size(), std_list.size());
}

TEST(ListTest, MaxSize) {
  s21::list<size_t> my_list_empty;
  std::list<size_t> std_list_empty;
  EXPECT_EQ(my_list_empty.max_size(), std_list_empty.max_size());
}

TEST(ListTest, Clear) {
  s21::list<int> my_list{1, 2, 3, 4};
  my_list.clear();
  std::list<int> std_list{1, 2, 5, 4, 3};
  std_list.clear();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, ClearEmpty) {
  s21::list<int> my_list;
  my_list.clear();
  std::list<int> std_list;
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

TEST(ListTest, Swap_2) {
  s21::list<int> my_list1{1, 5, 8, 100};
  s21::list<int> my_list2;
  my_list1.swap(my_list2);

  std::list<int> std_list1{1, 5, 8, 100};
  std::list<int> std_list2;
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

  EXPECT_EQ(*my_list1.begin(), 0);
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

TEST(ListTest, Insert_1) {
  s21::list<int> my_list1{1, 9999, 20000};
  my_list1.insert(my_list1.begin(), 5);

  std::list<int> std_list1{1, 9999, 20000};
  std_list1.insert(std_list1.begin(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Insert_2) {
  s21::list<int> my_list1{1, 9999, 20000};
  my_list1.insert(my_list1.end(), 5);

  std::list<int> std_list1{1, 9999, 20000};
  std_list1.insert(std_list1.end(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Insert_3) {
  s21::list<int> my_list1;
  my_list1.insert(my_list1.begin(), 5);

  std::list<int> std_list1;
  std_list1.insert(std_list1.begin(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Insert_4) {
  s21::list<int> my_list1;
  my_list1.insert(my_list1.end(), 5);

  std::list<int> std_list1;
  std_list1.insert(std_list1.end(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Insert_5) {
  s21::list<int> my_list1(4);
  my_list1.insert(my_list1.begin(), 5);

  std::list<int> std_list1(4);
  std_list1.insert(std_list1.begin(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Insert_6) {
  s21::list<int> my_list1(4);
  my_list1.insert(my_list1.end(), 5);

  std::list<int> std_list1(4);
  std_list1.insert(std_list1.end(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Erase_1) {
  s21::list<int> my_list1{1, 9999, 20000};
  my_list1.erase(my_list1.begin());

  std::list<int> std_list1{1, 9999, 20000};
  std_list1.erase(std_list1.begin());

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Erase_2_throw) {
  s21::list<int> my_list1{1, 9999, 20000};

  EXPECT_THROW(my_list1.erase(my_list1.end()), std::invalid_argument);
}

TEST(ListTest, Erase_3) {
  s21::list<int> my_list1{1, 9999, 20000};
  my_list1.erase(--my_list1.end());

  std::list<int> std_list1{1, 9999, 20000};
  std_list1.erase(std_list1.end().operator--());

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Erase_4_throw) {
  s21::list<int> my_list1;

  EXPECT_THROW(my_list1.erase(my_list1.end()--), std::invalid_argument);
}

TEST(ListTest, Erase_5) {
  s21::list<int> my_list1(5);
  my_list1.erase(--my_list1.end());

  std::list<int> std_list1(5);
  std_list1.erase(std_list1.end().operator--());

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

// QUEUE

template <typename value_type>
bool compare_queues(s21::queue<value_type> my_queue,
                    std::queue<value_type> std_queue) {
  bool result = true;
  if (my_queue.size() == std_queue.size()) {
    while (!my_queue.empty() && !std_queue.empty()) {
      if (my_queue.front() != std_queue.front()) {
        result = false;
        break;
      }
      my_queue.pop();
      std_queue.pop();
    }
  } else {
    result = false;
  }
  return result;
}

TEST(QueueTest, CompareQueues) {
  s21::queue<int> my_queue{1, 3, 10, -5, 20};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(3);
  std_queue.push(10);
  std_queue.push(-5);
  std_queue.push(20);
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
  std_queue.push(20);
  EXPECT_FALSE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, CompareQueues_2) {
  s21::queue<int> my_queue{1, 3, 10, -5, 20};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(3);
  std_queue.push(10);
  std_queue.push(-5);
  std_queue.push(100);
  EXPECT_FALSE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, DefaultConstructor) {
  s21::queue<int> my_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(my_queue.size(), 0);
  EXPECT_TRUE(my_queue.empty());
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, InitializerqueueConstructor) {
  s21::queue<int> my_queue{1, 2, 3, 7, 9};
  std::initializer_list<int> il = {1, 2, 3, 7, 9};
  std::queue<int> std_queue{il};
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, InitializerqueueConstructor_2) {
  std::initializer_list<int> b;
  s21::queue<int> my_queue{b};
  std::queue<int> std_queue{b};
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, CopyConstructor) {
  s21::queue<int> my_queue{1, 2, 3, 7, 9};
  s21::queue<int> my_queue_copy(my_queue);
  std::initializer_list<int> il = {1, 2, 3, 7, 9};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, CopyConstructorEmpty) {
  s21::queue<int> my_queue;
  s21::queue<int> my_queue_copy(my_queue);
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveConstructor) {
  s21::queue<int> my_queue{1, 2, 3, 7, 20};
  s21::queue<int> my_queue_copy(my_queue);
  s21::queue<int> my_queue_move(std::move(my_queue));
  std::initializer_list<int> il = {1, 2, 3, 7, 20};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move(std::move(std_queue));
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveConstructorEmpty) {
  s21::queue<int> my_queue;
  s21::queue<int> my_queue_copy(my_queue);
  s21::queue<int> my_queue_move(std::move(my_queue));
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move(std::move(std_queue));
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveAssignmentOperator) {
  s21::queue<int> my_queue{1, 2, 3, 7, 20};
  s21::queue<int> my_queue_copy(my_queue);
  s21::queue<int> my_queue_move = std::move(my_queue);
  std::initializer_list<int> il = {1, 2, 3, 7, 20};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move = std::move(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_move, std_queue_move));
}

TEST(QueueTest, MoveAssignmentOperatorEmpty) {
  s21::queue<int> my_queue;
  s21::queue<int> my_queue_copy(my_queue);
  s21::queue<int> my_queue_move = std::move(my_queue);
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move = std::move(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_move, std_queue_move));
}

TEST(QueueTest, Front) {
  s21::queue<int> my_queue{99, 2, 3, 4, 5};
  std::initializer_list<int> il = {99, 1, 3, 7, 20};
  std::queue<int> std_queue{il};
  EXPECT_EQ(my_queue.front(), std_queue.front());
}

TEST(QueueTest, Back) {
  s21::queue<int> my_queue{1, 2, 3, 3, 4, 99};
  std::initializer_list<int> il = {99, 1, 3, 5, 4, 7, 99};
  std::queue<int> std_queue{il};
  EXPECT_EQ(my_queue.back(), std_queue.back());
}

TEST(QueueTest, Empty) {
  s21::queue<int> my_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(my_queue.empty(), std_queue.empty());
  my_queue.push(2354);
  std_queue.push(2354);
  EXPECT_EQ(my_queue.empty(), std_queue.empty());
}

TEST(QueueTest, Size) {
  s21::queue<int> my_queue{1, 2, 3, 4, 5, 6, 7, 8};
  std::initializer_list<int> il = {1, 2, 3, 4, 5, 6, 7, 8};
  std::queue<int> std_queue{il};
  EXPECT_EQ(my_queue.size(), std_queue.size());
}

TEST(QueueTest, Push) {
  s21::queue<int> my_queue;
  std::queue<int> std_queue;
  my_queue.push(627);
  std_queue.push(627);
  my_queue.push(2354);
  std_queue.push(2354);
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, Pop) {
  s21::queue<int> my_queue{1, 2, 3, 4, 5, 6, 7, 8};
  std::initializer_list<int> il = {1, 2, 3, 4, 5, 6, 7, 8};
  std::queue<int> std_queue{il};
  my_queue.pop();
  my_queue.pop();
  std_queue.pop();
  std_queue.pop();
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
  EXPECT_EQ(my_queue.front(), 3);
}

TEST(QueueTest, Swap) {
  s21::queue<int> my_queue1{1, 2, 3, 4, 5};
  s21::queue<int> my_queue2{6, 7, 8, 9, 10, 11};
  my_queue1.swap(my_queue2);

  std::initializer_list<int> il1 = {1, 2, 3, 4, 5};
  std::initializer_list<int> il2 = {6, 7, 8, 9, 10, 11};
  std::queue<int> std_queue1{il1};
  std::queue<int> std_queue2{il2};
  std_queue1.swap(std_queue2);

  EXPECT_TRUE(compare_queues(my_queue1, std_queue1));
  EXPECT_TRUE(compare_queues(my_queue2, std_queue2));
}

TEST(QueueTest, Swap_2) {
  s21::queue<int> my_queue1{1, 2, 99, 4, 242};
  s21::queue<int> my_queue2;
  my_queue1.swap(my_queue2);

  std::initializer_list<int> il = {1, 2, 99, 4, 242};
  std::queue<int> std_queue1{il};
  std::queue<int> std_queue2;
  std_queue1.swap(std_queue2);

  EXPECT_TRUE(compare_queues(my_queue1, std_queue1));
  EXPECT_TRUE(compare_queues(my_queue2, std_queue2));
}
// SET
class TestSet {
 public:
  s21::set<int> s21_set_empty;
  s21::set<int> s21_set_ten{1, 2, 56, 76, 123, 53, 78, 43, 21, 100};
  s21::set<int> s21_set_copy;
  std::set<int> std_set_copy;
  s21::set<int> s21_move;
  std::set<int> std_move;
  s21::set<int> s21_set_swap{95, 94, 93, 92};
  std::set<int> std_set_swap{95, 94, 93, 92};
  s21::set<int> s21_set_merge{1, 2, 3, 4, 5};
  std::set<int> std_set_merge{1, 2, 3, 4, 5};

  std::set<int> std_set_empty;
  std::set<int> std_set_ten{1, 2, 56, 76, 123, 53, 78, 43, 21, 100};
};

TEST(Set, constructor_default) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_empty.size(), tester.std_set_empty.size());
  EXPECT_EQ(tester.s21_set_empty.empty(), tester.std_set_empty.empty());
}

TEST(Set, constructor_initialazer) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.s21_set_ten.find(1) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(1) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(2) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(2) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(3) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(3) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(4) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(4) != tester.std_set_ten.end());
}

TEST(Set, constructor_copy) {
  TestSet tester;
  s21::set<int> s21_empty(tester.s21_set_ten);
  std::set<int> std_empty(tester.std_set_ten);
  EXPECT_EQ(s21_empty.find(1) != s21_empty.end(),
            std_empty.find(1) != std_empty.end());
  EXPECT_EQ(s21_empty.find(2) != s21_empty.end(),
            std_empty.find(2) != std_empty.end());
  EXPECT_EQ(s21_empty.find(3) != s21_empty.end(),
            std_empty.find(3) != std_empty.end());
  EXPECT_EQ(s21_empty.find(4) != s21_empty.end(),
            std_empty.find(4) != std_empty.end());
  EXPECT_EQ(s21_empty.size(), std_empty.size());
  EXPECT_EQ(s21_empty.empty(), std_empty.empty());
}

TEST(Set, construct_move) {
  TestSet tester;
  s21::set<int> s21_move = std::move(tester.s21_set_ten);
  std::set<int> std_move = std::move(tester.std_set_ten);
  EXPECT_EQ(s21_move.find(1) != s21_move.end(),
            std_move.find(1) != std_move.end());
  EXPECT_EQ(s21_move.find(2) != s21_move.end(),
            std_move.find(2) != std_move.end());
  EXPECT_EQ(s21_move.find(3) != s21_move.end(),
            std_move.find(3) != std_move.end());
  EXPECT_EQ(s21_move.find(4) != s21_move.end(),
            std_move.find(4) != std_move.end());
  EXPECT_EQ(s21_move.size(), std_move.size());
  EXPECT_EQ(s21_move.empty(), std_move.empty());
}

TEST(Set, operator_move) {
  TestSet tester;
  tester.s21_move = std::move(tester.s21_set_ten);
  tester.std_move = std::move(tester.std_set_ten);
  EXPECT_EQ(tester.s21_move.find(1) != tester.s21_move.end(),
            tester.std_move.find(1) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.find(2) != tester.s21_move.end(),
            tester.std_move.find(2) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.find(3) != tester.s21_move.end(),
            tester.std_move.find(3) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.find(4) != tester.s21_move.end(),
            tester.std_move.find(4) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.size(), tester.std_move.size());
  EXPECT_EQ(tester.s21_move.empty(), tester.std_move.empty());
}

TEST(Set, function_not_empty) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.s21_set_ten.empty(), tester.std_set_ten.empty());
}

TEST(Set, function_empty) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_empty.size(), tester.std_set_empty.size());
  EXPECT_EQ(tester.s21_set_empty.empty(), tester.std_set_empty.empty());
}

TEST(Set, function_size_empty) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_empty.size(), tester.std_set_empty.size());
}

TEST(Set, function_size_not_empty) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
}

TEST(Set, function_max_sez_empty) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_empty.max_size(), tester.std_set_empty.max_size());
}

TEST(Set, function_max_siez_not_empty) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_ten.max_size(), tester.std_set_ten.max_size());
}

TEST(Set, function_max_size_float_empty) {
  s21::set<float> s21_float_empty;
  std::set<float> std_float_empty;
  EXPECT_EQ(s21_float_empty.max_size(), std_float_empty.max_size());
}

TEST(Set, function_swap_not_empty) {
  TestSet tester;
  tester.s21_set_swap.swap(tester.s21_set_ten);
  tester.std_set_swap.swap(tester.std_set_ten);
  EXPECT_EQ(tester.s21_set_swap.find(1) != tester.s21_set_swap.end(),
            tester.std_set_swap.find(1) != tester.std_set_swap.end());
  EXPECT_EQ(tester.s21_set_swap.find(56) != tester.s21_set_swap.end(),
            tester.std_set_swap.find(56) != tester.std_set_swap.end());
  EXPECT_EQ(tester.s21_set_swap.find(76) != tester.s21_set_swap.end(),
            tester.std_set_swap.find(76) != tester.std_set_swap.end());
  EXPECT_EQ(tester.s21_set_ten.find(95) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(95) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(94) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(94) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(93) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(93) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_swap.size(), tester.std_set_swap.size());
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
}

TEST(Set, function_swap_empty) {
  TestSet tester;
  tester.s21_set_empty.swap(tester.s21_set_swap);
  tester.std_set_empty.swap(tester.std_set_swap);

  EXPECT_EQ(tester.s21_set_empty.find(95) != tester.s21_set_empty.end(),
            tester.std_set_empty.find(95) != tester.std_set_empty.end());
  EXPECT_EQ(tester.s21_set_empty.find(94) != tester.s21_set_empty.end(),
            tester.std_set_empty.find(94) != tester.std_set_empty.end());
  EXPECT_EQ(tester.s21_set_empty.find(93) != tester.s21_set_empty.end(),
            tester.std_set_empty.find(93) != tester.std_set_empty.end());

  EXPECT_EQ(tester.s21_set_empty.size(), tester.std_set_empty.size());
  EXPECT_EQ(tester.s21_set_empty.empty(), tester.std_set_empty.empty());
  EXPECT_EQ(tester.s21_set_swap.size(), tester.std_set_swap.size());
  EXPECT_EQ(tester.s21_set_swap.empty(), tester.std_set_swap.empty());
}
TEST(Set, function_merge_with_duplicates) {
  TestSet tester;
  tester.s21_set_merge.merge(tester.s21_set_ten);
  tester.std_set_merge.merge(tester.std_set_ten);

  EXPECT_EQ(tester.s21_set_merge.find(1) != tester.s21_set_merge.end(),
            tester.std_set_merge.find(1) != tester.std_set_merge.end());
  EXPECT_EQ(tester.s21_set_merge.find(2) != tester.s21_set_merge.end(),
            tester.std_set_merge.find(2) != tester.std_set_merge.end());
  EXPECT_EQ(tester.s21_set_merge.find(76) != tester.s21_set_merge.end(),
            tester.std_set_merge.find(76) != tester.std_set_merge.end());

  EXPECT_EQ(tester.s21_set_merge.size(), tester.std_set_merge.size());
  EXPECT_EQ(tester.s21_set_merge.empty(), tester.std_set_merge.empty());
}

TEST(Set, function_merge_wihout_duplicates) {
  TestSet tester;
  tester.s21_set_ten.merge(tester.s21_set_swap);
  tester.std_set_ten.merge(tester.std_set_swap);

  EXPECT_EQ(tester.s21_set_ten.find(95) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(95) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(1) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(1) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(94) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(94) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(76) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(76) != tester.std_set_ten.end());

  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.std_set_ten.empty(), tester.std_set_ten.empty());
  EXPECT_EQ(tester.s21_set_swap.size(), tester.std_set_swap.size());
  EXPECT_EQ(tester.s21_set_swap.empty(), tester.std_set_swap.empty());
}

TEST(Set, function_clear_not_empty) {
  TestSet tester;
  tester.s21_set_ten.clear();
  tester.std_set_ten.clear();
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.s21_set_ten.empty(), tester.std_set_ten.empty());
}

TEST(Set, function_begin_not_empty) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_ten.begin();
  std::set<int>::iterator j = tester.std_set_ten.begin();
  EXPECT_EQ(*i, *j);
}

TEST(Set, function_begin_empty) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_empty.begin();
  std::set<int>::iterator j = tester.std_set_empty.begin();
  EXPECT_EQ(*i, *j);
}

TEST(Set, function_end_empty) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_empty.end();
  std::set<int>::iterator j = tester.std_set_empty.end();
  EXPECT_EQ(*i, *j);
}
TEST(Set, function_end_not_empty) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_ten.end();
  std::set<int>::iterator j = tester.std_set_ten.end();
  --i;
  --j;
  EXPECT_EQ(*i, *j);
}

TEST(Set, operator_plus) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_ten.begin();
  std::set<int>::iterator j = tester.std_set_ten.begin();
  while (i != tester.s21_set_ten.end() && j != tester.std_set_ten.end()) {
    EXPECT_EQ(*i, *j);
    ++i;
    ++j;
  }
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.std_set_ten.empty(), tester.std_set_ten.empty());
}

TEST(Set, operator_minus) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_ten.end();
  std::set<int>::iterator j = tester.std_set_ten.end();
  while (i != tester.s21_set_ten.begin() && j != tester.std_set_ten.begin()) {
    --i;
    --j;
    EXPECT_EQ(*i, *j);
  }
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.s21_set_ten.empty(), tester.std_set_ten.empty());
}

TEST(Set, operation_assignment) {
  TestSet tester;
  s21::set<int>::iterator iter_1 = tester.s21_set_ten.begin();
  s21::set<int>::iterator iter_3 = iter_1;
  std::set<int>::iterator iter_2 = tester.std_set_ten.begin();
  std::set<int>::iterator iter_4 = iter_2;
  ASSERT_EQ(*iter_1, *iter_3);
  ASSERT_EQ(*iter_2, *iter_4);
}
TEST(Set, operation_equal) {
  TestSet tester;
  s21::set<int>::iterator it1 = tester.s21_set_ten.begin();
  s21::set<int>::iterator it3 = tester.s21_set_ten.begin();
  std::set<int>::iterator it2 = tester.std_set_ten.begin();
  std::set<int>::iterator it4 = tester.std_set_ten.begin();
  ASSERT_EQ(it1 == it3, it2 == it4);
}
TEST(Set, operation_not_equal) {
  TestSet tester;
  s21::set<int>::iterator iter_1 = tester.s21_set_ten.begin();
  std::set<int>::iterator iter_2 = tester.std_set_ten.begin();
  ASSERT_EQ(iter_1 != tester.s21_set_ten.end(),
            iter_2 != tester.std_set_ten.end());
}

TEST(Set, function_insert) {
  TestSet tester;
  std::pair<s21::set<int>::iterator, bool> iter_1 =
      tester.s21_set_ten.insert(45);
  std::pair<std::set<int>::iterator, bool> iter_2 =
      tester.std_set_ten.insert(45);
  EXPECT_EQ(*(iter_1.first), *(iter_2.first));
  EXPECT_EQ(iter_1.second, iter_2.second);
}

TEST(Set, function_find_have) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_ten.find(1);
  std::set<int>::iterator j = tester.std_set_ten.find(1);
  EXPECT_EQ(i != tester.s21_set_ten.end(), j != tester.std_set_ten.end());
}

TEST(Set, function_find_dont_have) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_ten.find(100);
  std::set<int>::iterator j = tester.std_set_ten.find(100);
  EXPECT_EQ(i == tester.s21_set_ten.end(), j == tester.std_set_ten.end());
}

TEST(Set, function_erase) {
  TestSet tester;
  tester.s21_set_ten.erase(tester.s21_set_ten.begin());
  tester.std_set_ten.erase(tester.std_set_ten.begin());
  s21::set<int>::iterator iter_1 = tester.s21_set_ten.find(1);
  std::set<int>::iterator iter_2 = tester.std_set_ten.find(1);
  ASSERT_EQ(iter_1 == tester.s21_set_ten.end(),
            iter_2 == tester.std_set_ten.end());
}
TEST(Set, functions_erase_alot) {
  TestSet tester;
  s21::set<int>::iterator it1 = tester.s21_set_ten.find(76);
  std::set<int>::iterator it2 = tester.std_set_ten.find(76);
  tester.s21_set_ten.erase(it1);
  tester.std_set_ten.erase(it2);
  it1 = tester.s21_set_ten.find(123);
  it2 = tester.std_set_ten.find(123);
  tester.s21_set_ten.erase(it1);
  tester.std_set_ten.erase(it2);
  it1 = tester.s21_set_ten.find(43);
  it2 = tester.std_set_ten.find(43);
  tester.s21_set_ten.erase(it1);
  tester.std_set_ten.erase(it2);
  ASSERT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
}
// MAP
class TestMap {
 public:
  s21::map<int, int> s21_map_empty;
  s21::map<int, int> s21_map_four{{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  s21::map<int, int> s21_map_swap{{1, 95}, {2, 94}, {3, 93}};

  std::map<int, int> std_map_empty;
  std::map<int, int> std_map_four{{
                                      1,
                                      1,
                                  },
                                  {2, 2},
                                  {3, 3},
                                  {4, 4}};
  std::map<int, int> std_map_swap{{1, 95}, {2, 95}, {3, 95}};
};

TEST(Map, construcor_default) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
}

TEST(Map, construcot_initializer) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_four[1], tester.std_map_four[1]);
  EXPECT_EQ(tester.s21_map_four[4], tester.std_map_four[4]);
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.std_map_four.empty(), tester.std_map_four.empty());
}

TEST(Map, constructor_copy_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_copy(tester.s21_map_empty);
  std::map<int, int> std_map_copy(tester.std_map_empty);
  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());
  EXPECT_EQ(std_map_copy.empty(), std_map_copy.empty());
}

TEST(Map, constructor_copy_not_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_copy(tester.s21_map_four);
  std::map<int, int> std_map_copy(tester.std_map_four);
  EXPECT_EQ(s21_map_copy[1], std_map_copy[1]);
  EXPECT_EQ(s21_map_copy[4], std_map_copy[4]);
  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());
  EXPECT_EQ(std_map_copy.empty(), std_map_copy.empty());
}

TEST(Map, constructor_move_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_move = std::move(tester.s21_map_empty);
  std::map<int, int> std_map_move = std::move(tester.std_map_empty);
  EXPECT_EQ(s21_map_move.size(), std_map_move.size());
  EXPECT_EQ(s21_map_move.empty(), std_map_move.empty());
}

TEST(Map, constructor_move_not_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_move = std::move(tester.s21_map_four);
  std::map<int, int> std_map_move = std::move(tester.std_map_four);
  EXPECT_EQ(s21_map_move[1], std_map_move[1]);
  EXPECT_EQ(s21_map_move[4], std_map_move[4]);
  EXPECT_EQ(s21_map_move.size(), std_map_move.size());
  EXPECT_EQ(s21_map_move.empty(), std_map_move.empty());
}

TEST(Map, operator_move_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_move;
  std::map<int, int> std_map_move;
  s21_map_move = std::move(tester.s21_map_four);
  std_map_move = std::move(tester.std_map_four);
  EXPECT_EQ(s21_map_move[1], std_map_move[1]);
  EXPECT_EQ(std_map_move[4], std_map_move[4]);
  EXPECT_EQ(s21_map_move.size(), std_map_move.size());
  EXPECT_EQ(s21_map_move.empty(), std_map_move.empty());
}

TEST(Map, function_empty_empty) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
  EXPECT_EQ(tester.s21_map_empty[1], tester.std_map_empty[1]);
}

TEST(Map, function_empty_not_empty) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ(tester.s21_map_four[1], tester.std_map_four[1]);
}

TEST(Map, function_size_empty) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
  EXPECT_EQ(tester.s21_map_empty[1], tester.std_map_empty[1]);
}

TEST(Map, function_size_not_empty) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.std_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ(tester.s21_map_four[1], tester.std_map_four[1]);
  EXPECT_EQ(tester.s21_map_four[4], tester.std_map_four[4]);
}

TEST(Map, function_swap_empty) {
  s21::map<int, int> m1({{1, 8}, {4, 2}, {2, 3}});
  s21::map<int, int> m2;
  m1.swap(m2);

  std::map<int, int> m3({{1, 8}, {4, 2}, {2, 3}});
  std::map<int, int> m4;
  m3.swap(m4);

  ASSERT_EQ(m2[1], m4[1]);
  ASSERT_EQ(m2[2], m4[2]);
  ASSERT_EQ(m2[4], m4[4]);

  ASSERT_EQ(m1.size(), m3.size());
  ASSERT_EQ(m2.size(), m4.size());
}

TEST(Map, function_swap_not_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_swap{{1, 1}, {2, 2}};
  std::map<int, int> std_map_swap{{1, 1}, {2, 2}};
  s21_map_swap.swap(tester.s21_map_four);
  std_map_swap.swap(tester.std_map_four);
  EXPECT_EQ(s21_map_swap[1], std_map_swap[1]);
  EXPECT_EQ(s21_map_swap[4], std_map_swap[4]);
  EXPECT_EQ(s21_map_swap.size(), std_map_swap.size());
  EXPECT_EQ(s21_map_swap.empty(), std_map_swap.empty());
}

TEST(Map, WithDuplicatesCase) {
  s21::map<int, int> m1({{1, 8}, {4, 2}, {2, 3}});
  s21::map<int, int> m2({{1, 3}, {2, 2}});
  m1.merge(m2);

  std::map<int, int> m3({{1, 8}, {4, 2}, {2, 3}});
  std::map<int, int> m4({{1, 3}, {2, 2}});
  m3.merge(m4);
  ASSERT_EQ(m1[1], m3[1]);
  ASSERT_EQ(m1[2], m3[2]);
  ASSERT_EQ(m1[4], m3[4]);

  ASSERT_EQ(m2[1], m4[1]);
  ASSERT_EQ(m2[2], m4[2]);

  ASSERT_EQ(m1.size(), m3.size());
  ASSERT_EQ(m2.size(), m4.size());
}
TEST(Map, WithoutDuplicatesCase) {
  s21::map<int, int> m1({{1, 2}, {3, 4}, {4, 5}});
  s21::map<int, int> m2({{5, 6}, {7, 7}});
  m1.merge(m2);

  std::map<int, int> m3({{1, 2}, {3, 4}, {4, 5}});
  std::map<int, int> m4({{5, 6}, {7, 7}});
  m3.merge(m4);
  ASSERT_EQ(m1[1], m3[1]);
  ASSERT_EQ(m1[3], m3[3]);
  ASSERT_EQ(m1[4], m3[4]);
  ASSERT_EQ(m1[5], m3[5]);
  ASSERT_EQ(m1[7], m3[7]);
  ASSERT_EQ(m1.size(), m3.size());
  ASSERT_EQ(m2.size(), m4.size());
}
TEST(Map, function_clear_empty) {
  TestMap tester;
  tester.s21_map_empty.clear();
  tester.std_map_empty.clear();
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
}
TEST(Map, function_clear_not_empty) {
  TestMap tester;
  tester.s21_map_four.clear();
  tester.std_map_four.clear();
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
}
TEST(Map, function_begin_empty) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_empty.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_empty.begin();
  EXPECT_EQ(iter_1 == tester.s21_map_empty.end(),
            iter_2 == tester.std_map_empty.end());
}

TEST(Map, function_begin_not_empty) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ(iter_1 != tester.s21_map_four.end(),
            iter_2 != tester.std_map_four.end());
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}

TEST(Map, operator_plus) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}
TEST(Map, operator_minus) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  --iter_1;
  --iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}

TEST(Map, operator_assignment) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  s21::map<int, int>::iterator iter_3 = iter_1;
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  std::map<int, int>::iterator iter_4 = iter_2;
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ((*iter_1).second, (*iter_3).second);
  EXPECT_EQ((*iter_2).second, (*iter_4).second);
}
TEST(Map, operator_equal) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  s21::map<int, int>::iterator iter_3 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_empty.begin();
  std::map<int, int>::iterator iter_4 = tester.std_map_empty.begin();
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
  EXPECT_EQ(iter_1 == iter_3, iter_2 == iter_4);
}
TEST(Map, operatort_not_equal) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ(iter_1 != tester.s21_map_four.end(),
            iter_2 != tester.std_map_empty.end());
}

TEST(Map, function_insert_without_duplicate) {
  TestMap tester;
  std::pair<s21::map<int, int>::iterator, bool> iter_1 =
      tester.s21_map_four.insert({5, 2});
  std::pair<std::map<int, int>::iterator, bool> iter_2 =
      tester.std_map_four.insert({5, 2});
  EXPECT_EQ((*(iter_1.first)).second, (*(iter_2.first)).second);
  EXPECT_TRUE(iter_1.second == iter_2.second);
}

TEST(Map, function_insert_with_duplicate) {
  TestMap tester;
  std::pair<s21::map<int, int>::iterator, bool> iter_1 =
      tester.s21_map_four.insert({1, 2});
  std::pair<std::map<int, int>::iterator, bool> iter_2 =
      tester.std_map_four.insert({1, 2});
  EXPECT_TRUE(iter_1.second == iter_2.second);
}

TEST(Map, function_insert_key_value_without_duplicate) {
  TestMap tester;
  std::pair<s21::map<int, int>::iterator, bool> iter_1 =
      tester.s21_map_four.insert(7, 7);
  std::pair<std::map<int, int>::iterator, bool> iter_2 =
      tester.std_map_four.insert({7, 7});
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ((*(iter_1.first)).second, (*(iter_2.first)).second);
  EXPECT_TRUE(iter_1.second == iter_2.second);
}

TEST(Map, function_insert_key_value_with_duplicate) {
  TestMap tester;
  std::pair<s21::map<int, int>::iterator, bool> iter_1 =
      tester.s21_map_four.insert(1, 7);
  std::pair<std::map<int, int>::iterator, bool> iter_2 =
      tester.std_map_four.insert({1, 7});
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_TRUE(iter_1.second == iter_2.second);
}
TEST(Map, function_insert_or_assign_value) {
  s21::map<int, int> m1({{1, 3}, {4, 2}});
  std::map<int, int> m2({{1, 3}, {4, 2}});
  std::pair<s21::map<int, int>::iterator, bool> it1 = m1.insert_or_assign(5, 2);
  std::pair<std::map<int, int>::iterator, bool> it2 = m2.insert_or_assign(5, 2);
  ASSERT_TRUE(it1.second == it2.second);
}

TEST(Map, function_insert_or_assign) {
  s21::map<int, int> m1({{1, 3}, {4, 2}});
  std::map<int, int> m2({{1, 3}, {4, 2}});
  std::pair<s21::map<int, int>::iterator, bool> it1 = m1.insert_or_assign(1, 2);
  std::pair<std::map<int, int>::iterator, bool> it2 = m2.insert_or_assign(1, 2);
  ASSERT_EQ((*(it1.first)).second, (*(it2.first)).second);
  ASSERT_TRUE(it1.second == it2.second);
}
TEST(Map, function_insert_s) {
  s21::map<int, int> m1({{1, 3}, {4, 2}});
  std::pair<s21::map<int, int>::iterator, bool> it1 = m1.insert(5, 2);
  ASSERT_EQ((*(it1.first)).second, 2);
  ASSERT_TRUE(it1.second);
}

TEST(Map, function_at) {
  s21::map<int, int> m1({{1, 3}, {4, 2}});
  std::map<int, int> m2({{1, 3}, {4, 2}});
  ASSERT_EQ(m1.at(1), m2.at(1));
}
TEST(Map, function_erase) {
  s21::map<int, int> m1({{1, 3}, {4, 2}});
  std::map<int, int> m2({{1, 3}, {4, 2}});
  m1.erase(m1.begin());
  m2.erase(m2.begin());
  ASSERT_EQ(m1[1], m2[1]);
}
TEST(Map, function_ontains) {
  s21::map<int, int> s1({{1, 3}, {4, 2}});
  ASSERT_TRUE(s1.contains(1));
  ASSERT_TRUE(s1.contains(4));
  ASSERT_FALSE(s1.contains(3));
}
// AVLTree
TEST(AVLTreeTest, InsertAndSearch) {
  s21::AVLTree<int, int> tree;

  tree.Insert(5);
  tree.Insert(10);
  tree.Insert(3);
  tree.Insert(1);
  tree.Insert(4);

  EXPECT_NE(tree.Search(5), nullptr);
  EXPECT_NE(tree.Search(10), nullptr);
  EXPECT_NE(tree.Search(3), nullptr);
  EXPECT_NE(tree.Search(1), nullptr);
  EXPECT_NE(tree.Search(4), nullptr);

  EXPECT_EQ(tree.Search(2), nullptr);
  EXPECT_EQ(tree.Search(6), nullptr);
}

TEST(AVLTreeTest, Remove) {
  s21::AVLTree<int, int> tree;

  tree.Insert(5);
  tree.Insert(10);
  tree.Insert(3);
  tree.Insert(1);
  tree.Insert(4);

  tree.Remove(1);
  EXPECT_EQ(tree.Search(1), nullptr);

  tree.Remove(10);
  EXPECT_EQ(tree.Search(10), nullptr);

  tree.Remove(3);
  EXPECT_EQ(tree.Search(3), nullptr);

  EXPECT_NE(tree.Search(5), nullptr);
  EXPECT_NE(tree.Search(4), nullptr);
}

TEST(AVLTreeTest, Clear) {
  s21::AVLTree<int, int> tree;

  tree.Insert(5);
  tree.Insert(10);
  tree.Insert(3);

  tree.Clear(tree.GetRoot());

  EXPECT_EQ(tree.Search(5), nullptr);
  EXPECT_EQ(tree.Search(10), nullptr);
  EXPECT_EQ(tree.Search(3), nullptr);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
