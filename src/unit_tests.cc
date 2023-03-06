#include <gtest/gtest.h>

#include <list>
#include <vector>

#include "s21_containers/list/s21_list.tpp"
#include "s21_containers/s21_containers.h"
using namespace s21;

// vector test
/*
TEST(vector, Constructor_default) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.data(), std_v.data());
  EXPECT_EQ(s21_v.empty(), std_v.empty());
}

TEST(vector, Constructor_n) {
  s21::vector<int> s21_v(5);
  std::vector<int> std_v(5);
  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.empty(), std_v.empty());
}

TEST(vector, Constructor_n_throw) {
  try {
    s21::vector<int> s21_v(-1);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(),
              std::string("cannot create s21::vector larger than max_size()"));
  }
}

TEST(vector, Constructor_initializer_list_1) {
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

TEST(vector, Constructor_initializer_list_2) {
  std::initializer_list<int> b;
  s21::vector<int> s21_v{b};
  std::vector<int> std_v{b};
  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.empty(), std_v.empty());
}

TEST(vector, Constructor_copy_1) {
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

TEST(vector, Constructor_copy_2) {
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

TEST(vector, Constructor_move_1) {
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

TEST(vector, Constructor_move_2) {
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

TEST(vector, Destructor) {
  s21::vector<int> s21_v{1, 2, 3, 4, 5};
  s21_v.~vector();

  EXPECT_EQ(0, s21_v.size());
  EXPECT_EQ(0, s21_v.capacity());
  EXPECT_EQ(0, s21_v.data());
}

TEST(vector, Operator_move_1) {
  s21::vector<int> s21_v1{1, 2, 3};
  s21::vector<int> s21_v2;
  s21_v2 = std::move(s21_v1);
  EXPECT_EQ(s21_v2.size(), 3);
  EXPECT_EQ(s21_v2.at(0), 1);
  EXPECT_EQ(s21_v2.at(1), 2);
  EXPECT_EQ(s21_v2.at(2), 3);
}

TEST(vector, Operator_move_2) {
  s21::vector<int> s21_v1{1, 2, 3};
  s21::vector<int> s21_v2{4, 5, 6};
  s21_v2 = std::move(s21_v1);
  EXPECT_EQ(s21_v2.size(), 3);
  EXPECT_EQ(s21_v2.at(0), 1);
  EXPECT_EQ(s21_v2.at(1), 2);
  EXPECT_EQ(s21_v2.at(2), 3);
}

TEST(vector, Element_at) {
  s21::vector<int> s21_v{1, 2, 3, 4, 5};
  std::vector<int> std_v{1, 2, 3, 4, 5};

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));
  EXPECT_EQ(s21_v.at(4), std_v.at(4));
}

TEST(vector, Element_at_throw) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_ANY_THROW(s21_v.at(1));
  EXPECT_ANY_THROW(std_v.at(1));
}

TEST(vector, Element_front) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  EXPECT_EQ(s21_v.front(), std_v.front());
}

TEST(vector, Element_front_throw) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_ANY_THROW(s21_v.front());
}

TEST(vector, Element_back) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  EXPECT_EQ(s21_v.back(), std_v.back());
}

TEST(vector, Element_back_throw) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_ANY_THROW(s21_v.back());
}

TEST(vector, Element_operator_square_brackets) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  EXPECT_EQ(s21_v[0], std_v[0]);
  EXPECT_EQ(s21_v[1], std_v[1]);
  EXPECT_EQ(s21_v[2], std_v[2]);
}

TEST(vector, Element_operator_square_brackets_throw_1) {
  s21::vector<int> s21_v{1, 2, 3};
  EXPECT_ANY_THROW(s21_v[5]);
}

TEST(vector, Element_operator_square_brackets_throw_2) {
  s21::vector<int> s21_v{1, 2, 3};
  EXPECT_ANY_THROW(s21_v[-1]);
}

TEST(vector, Element_data) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};

  EXPECT_EQ(*s21_v.data(), *std_v.data());
}

TEST(vector, Capacity_empty_1) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};

  EXPECT_EQ(s21_v.empty(), std_v.empty());
}

TEST(vector, Capacity_empty_2) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;

  EXPECT_EQ(s21_v.empty(), std_v.empty());
}

TEST(vector, Capacity_size_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;

  EXPECT_EQ(s21_v.size(), std_v.size());
}

TEST(vector, Capacity_size_2) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};

  EXPECT_EQ(s21_v.size(), std_v.size());
}

TEST(vector, Capacity_max_size_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_EQ(s21_v.max_size(), 0);
}

TEST(vector, Capacity_max_size_2) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};

  EXPECT_EQ(s21_v.max_size(), 12);
}

TEST(vector, Capacity_capacity_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;

  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(vector, Capacity_capacity_2) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};

  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(vector, Capacity_reserve_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  s21_v.reserve(2);
  std_v.reserve(2);
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(vector, Capacity_reserve_2) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.reserve(2);
  std_v.reserve(2);
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(vector, Capacity_reserve_3) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.reserve(10);
  std_v.reserve(10);
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(vector, Capacity_reserve_4_throw) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  EXPECT_ANY_THROW(s21_v.reserve(-2));
  EXPECT_ANY_THROW(std_v.reserve(-2));
}

TEST(vector, Capacity_shrink_to_fit_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  s21_v.reserve(10);
  std_v.reserve(10);
  s21_v.shrink_to_fit();
  std_v.shrink_to_fit();
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(vector, Capacity_shrink_to_fit_2) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.reserve(10);
  std_v.reserve(10);
  s21_v.shrink_to_fit();
  std_v.shrink_to_fit();
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(vector, Modifiers_clear_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  s21_v.clear();
  std_v.clear();

  EXPECT_EQ(s21_v.size(), std_v.size());
}

TEST(vector, Modifiers_clear_2) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.clear();
  std_v.clear();

  EXPECT_EQ(s21_v.size(), std_v.size());
}

TEST(vector, Modifiers_insert_1) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.insert(s21_v.begin() + 1, 5);
  std_v.insert(std_v.begin() + 1, 5);

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
}

TEST(vector, Modifiers_insert_2) {
  s21::vector<int> s21_v{50, 10, 40, 20, 30};
  std::vector<int> std_v{50, 10, 40, 20, 30};
  s21_v.insert(s21_v.begin() + s21_v.size(), 100);
  std_v.insert(std_v.begin() + std_v.size(), 100);

  EXPECT_EQ(s21_v.at(5), std_v.at(5));
}

TEST(vector, Modifiers_insert_3) {
  try {
    s21::vector<int> s21_v{50, 10, 40, 20, 30};
    s21_v.insert(s21_v.begin() + 10, 100);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("Index out ot range"));
  }
}

TEST(vector, Modifiers_insert_4) {
  try {
    s21::vector<int> s21_v{50, 10, 40, 20, 30};
    s21_v.insert(s21_v.begin() - 4, 100);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("Index out ot range"));
  }
}

TEST(vector, Modifiers_erase_1) {
  s21::vector<int> s21_v{1, 2, 3, 4};
  std::vector<int> std_v{1, 2, 3, 4};

  s21_v.erase(s21_v.begin() + 1);
  std_v.erase(std_v.begin() + 1);

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
}

TEST(vector, Modifiers_erase_2) {
  s21::vector<int> s21_v{50, 10, 40, 20, 30};
  std::vector<int> std_v{50, 10, 40, 20, 30};
  s21_v.erase(s21_v.begin());
  std_v.erase(std_v.begin());

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));
}

TEST(vector, Modifiers_erase_3) {
  s21::vector<int> s21_v{50, 10, 40, 20, 30};
  std::vector<int> std_v{50, 10, 40, 20, 30};
  s21_v.erase(s21_v.end() - 1);
  std_v.erase(std_v.end() - 1);

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));
}

TEST(vector, Modifiers_erase_4) {
  try {
    s21::vector<int> s21_v{50, 10, 40, 20, 30};
    s21_v.erase(s21_v.begin() - 1);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("Index out ot range"));
  }
}

TEST(vector, Modifiers_erase_5) {
  try {
    s21::vector<int> s21_v{50, 10, 40, 20, 30};
    s21_v.erase(s21_v.end() + 1);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("Index out ot range"));
  }
}

TEST(vector, Modifiers_push_back_1) {
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

TEST(vector, Modifiers_push_back_2) {
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

TEST(vector, Modifiers_pop_back_1) {
  s21::vector<int> s21_v{1, 2};

  s21_v.pop_back();
  s21_v.pop_back();
  s21_v.pop_back();
  s21_v.pop_back();

  EXPECT_EQ(s21_v.size(), 0);
  EXPECT_EQ(s21_v.capacity(), 2);
}

TEST(vector, Modifiers_pop_back_2) {
  s21::vector<int> s21_v;

  s21_v.pop_back();
  s21_v.pop_back();
  s21_v.pop_back();
  s21_v.pop_back();

  EXPECT_EQ(s21_v.size(), 0);
  EXPECT_EQ(s21_v.capacity(), 0);
}

TEST(vector, Modifiers_swap_1) {
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

TEST(vector, Modifiers_swap_2) {
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

TEST(vector, Modifiers_swap_3) {
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

TEST(vector, Modifiers_swap_4) {
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

TEST(vector, Helpers_add_memotysize_1) {
  int n = 1000;
  s21::vector<int> s21_v(n);
  s21_v.push_back(1);
  EXPECT_EQ(s21_v.size(), n + 1);
}

TEST(vector, Helpers_add_memotysize_2) {
  int n = 10000;
  s21::vector<int> s21_v(n);
  s21_v.push_back(1);

  EXPECT_EQ(s21_v.size(), n + 1);
}

TEST(vector, Helpers_add_memotysize_3) {
  int n = 100000;
  s21::vector<int> s21_v(n);
  s21_v.push_back(1);
  s21_v.push_back(1);
  s21_v.push_back(1);

  EXPECT_EQ(s21_v.size(), n + 3);
}
*/

// list test
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
  EXPECT_EQ(my_list.size(), 0);
  EXPECT_TRUE(my_list.empty());
  EXPECT_THROW(my_list.front(), std::out_of_range);
  EXPECT_THROW(my_list.back(), std::out_of_range);
}

// TEST(ListTest, SizeConstructor) {
//   s21::list<int> my_list(1000000);
//   EXPECT_EQ(my_list.size(), 1000000);
// }

TEST(ListTest, InitializerListConstructor) {
  s21::list<int> my_list{1, 2, 3};
  std::list<int> std_list{1, 2, 3};
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

// TEST(ListTest, MaxSize) {
//   s21::list<int> my_list_empty;
//   EXPECT_EQ(my_list_empty.max_size(),
//             std::numeric_limits<typename list<int>::size_type>::max());
// }

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

TEST(ListTest, Merge) {
  s21::list<int> my_list1{1, 9999, 20000};
  s21::list<int> my_list2{500, 15000, 30000};
  my_list1.merge(my_list2);

  std::list<int> std_list1{1, 9999, 20000};
  std::list<int> std_list2{500, 15000, 30000};
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Reverse) {
  s21::list<int> my_list{1, 2, 3, 4, 5};
  std::list<int> std_list{1, 2, 3, 4, 5};
  my_list.reverse();
  std_list.reverse();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Unique) {
  s21::list<int> my_list{90, 10, 3, 40, 30, 20, 10, 10, 90, 90, 3};
  std::list<int> std_list{90, 10, 3, 40, 30, 20, 10, 10, 90, 90, 3};
  my_list.unique();
  std_list.unique();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Sort) {
  s21::list<int> my_list{90, 10, 3, 40, 30, 20, 2000, 10, 90, 100, 3};
  std::list<int> std_list{90, 10, 3, 40, 30, 20, 2000, 10, 90, 100, 3};
  my_list.sort();
  std_list.sort();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

// ------------Above checked---------------------
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

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
