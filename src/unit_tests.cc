#include <gtest/gtest.h>

#include <vector>

#include "s21_containers/s21_containers.h"
using namespace s21;

TEST(Vector, test1) {
  s21::Vector<int> s21_vector;
  std::vector<int> std_vector;
  s21_vector.push_back(0);
  s21_vector.push_back(1);
  s21_vector.push_back(2);

  std_vector.push_back(0);
  std_vector.push_back(1);
  std_vector.push_back(2);

  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}