#include <gtest/gtest.h>

#include <map>
#include <set>

#include "./Map/s21_map.tpp"
#include "./Set/s21_set.tpp"
using namespace std;
using namespace s21;
TEST(SetTest, DefaultConstructor) {
  Set<int> s;
  EXPECT_TRUE(s.empty());
  EXPECT_EQ(s.size(), 0);
}

TEST(SetTest, InitializerListConstructor) {
  s21::Set<int> s = {1, 2, 3};
  EXPECT_EQ(s.size(), 3);
  EXPECT_TRUE(s.contains(1));
  EXPECT_TRUE(s.contains(2));
  EXPECT_TRUE(s.contains(3));
}

TEST(SetTest, CopyConstructor) {
  s21::Set<int> s1 = {1, 2, 3};
  s21::Set<int> s2(s1);
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(SetTest, MoveConstructor) {
  s21::Set<int> s1 = {1, 2, 3};
  s21::Set<int> s2(std::move(s1));
  EXPECT_EQ(s2.size(), 3);
  EXPECT_TRUE(s2.contains(1));
  EXPECT_TRUE(s2.contains(2));
  EXPECT_TRUE(s2.contains(3));
}
TEST(SetTest, BeginEnd) {
  s21::Set<int> s{3, 5, 1, 4, 2};
  auto it = s.begin();
  ASSERT_EQ(*it, 1);

  it = s.end();
  ASSERT_EQ(it, nullptr);

  s.clear();
  it = s.begin();
  ASSERT_EQ(it, nullptr);
}

TEST(SetTest, SizeMaxSize) {
  s21::Set<int> s{3, 5, 1, 4, 2};
  std::set<int> s1{3, 5, 1, 4, 2};
  ASSERT_EQ(s.size(), 5);
  ASSERT_GE(s.max_size(), s1.max_size());

  s.clear();
  ASSERT_EQ(s.size(), 0);
}
TEST(SetTest, Erase) {
  s21::Set<int> s{1, 2, 3, 4, 5};
  auto it = s.find(3);
  s.erase(it);
  EXPECT_EQ(s.size(), 4);
  EXPECT_FALSE(s.contains(3));
}

TEST(SetTest, Swap) {
  s21::Set<int> s1{1, 2, 3};
  s21::Set<int> s2{4, 5, 6};
  s1.swap(s2);
  EXPECT_EQ(s1.size(), 3);
  EXPECT_EQ(s2.size(), 3);
  EXPECT_TRUE(s2.contains(1));
  EXPECT_TRUE(s1.contains(4));
}

TEST(SetTest, Merge) {
  s21::Set<int> s1{1, 2, 3};
  s21::Set<int> s2{3, 4, 5};
  s1.merge(s2);
  EXPECT_EQ(s1.size(), 5);
  EXPECT_EQ(s2.size(), 0);
  EXPECT_TRUE(s1.contains(4));
  EXPECT_FALSE(s2.contains(3));
}

TEST(SetTest, Find) {
  s21::Set<int> s{1, 2, 3};
  auto it1 = s.find(2);
  EXPECT_EQ(*it1, 2);
  auto it2 = s.find(4);
  EXPECT_EQ(it2, s.end());
}

TEST(MapConstructorTest, DefaultConstructor) {
  Map<int, std::string> m;
  EXPECT_EQ(m.size(), 0);
  EXPECT_TRUE(m.empty());
}

TEST(MapConstructorTest, InitializerListConstructor) {
  Map<int, std::string> m{{1, "one"}, {2, "two"}, {3, "three"}};
  EXPECT_EQ(m.size(), 3);
  EXPECT_FALSE(m.empty());
  EXPECT_EQ(m.at(1), "one");
  EXPECT_EQ(m.at(2), "two");
  EXPECT_EQ(m.at(3), "three");
}

TEST(MapConstructorTest, CopyConstructor) {
  Map<int, std::string> m{{1, "one"}, {2, "two"}, {3, "three"}};
  Map<int, std::string> copy_m(m);
  EXPECT_EQ(copy_m.size(), 3);
  EXPECT_FALSE(copy_m.empty());
  EXPECT_EQ(copy_m.at(1), "one");
  // EXPECT_EQ(copy_m.at(2), "two");
  // EXPECT_EQ(copy_m.at(3), "three");
}
// Test the insert(key, value) function
TEST(MapTest, InsertKeyValue) {
  s21::Map<int, std::string> map;
  // Insert a single key-value pair
  map.insert(1, "one");
  // Check that the size is correct
  EXPECT_EQ(map.size(), 1);
  // Check that the inserted key-value pair is in the map
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");
  // Insert another key-value pair
  map.insert(2, "two");
  // Check that the size is correct
  EXPECT_EQ(map.size(), 2);
  // Check that both inserted key-value pairs are in the map
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");
  EXPECT_EQ(map.contains(2), true);
  EXPECT_EQ(map[2], "two");
}
// Test the insert(pair) function
TEST(MapTest, InsertPair) {
  s21::Map<int, std::string> map;
  // Insert a single key-value pair using a pair object
  map.insert(std::make_pair(1, "one"));
  // Check that the size is correct
  EXPECT_EQ(map.size(), 1);
  // Check that the inserted key-value pair is in the map
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");
  // Insert another key-value pair using a pair object
  map.insert(std::make_pair(2, "two"));
  // Check that the size is correct
  EXPECT_EQ(map.size(), 2);
  // Check that both inserted key-value pairs are in the map
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");
  EXPECT_EQ(map.contains(2), true);
  EXPECT_EQ(map[2], "two");
}
TEST(MapTest, InsertOrAssign) {
  Map<int, std::string> map;
  // Insert a new element with a key that does not exist.
  auto [it1, inserted1] = map.insert_or_assign(1, "one");
  EXPECT_TRUE(inserted1);
  EXPECT_EQ(it1->first, 1);
  EXPECT_EQ(it1->second, "one");
  // Insert a new element with a key that already exists.
  auto [it2, inserted2] = map.insert_or_assign(1, "ONE");
  EXPECT_FALSE(inserted2);
  EXPECT_EQ(it2->first, 1);
  EXPECT_EQ(it2->second, "ONE");
  // Insert multiple elements.
  map.insert_or_assign(2, "two");
  map.insert_or_assign(3, "three");
  map.insert_or_assign(4, "four");
  map.insert_or_assign(5, "five");
  EXPECT_EQ(map.size(), 5);
  EXPECT_EQ(map[1], "ONE");
  EXPECT_EQ(map[2], "two");
  EXPECT_EQ(map[3], "three");
  EXPECT_EQ(map[4], "four");
  EXPECT_EQ(map[5], "five");
}
TEST(MapTest, AtAndOperatorBrackets) {
  Map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};

  EXPECT_EQ(map.at(1), "one");
  EXPECT_EQ(map[2], "two");
  EXPECT_THROW(map.at(4), std::invalid_argument);
  map[4] = "four";
  EXPECT_EQ(map[4], "four");
  map[2] = "TWO";
  EXPECT_EQ(map[2], "TWO");
}

TEST(MapTest, EmptyAndSize) {
  Map<int, std::string> empty_map;
  Map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};

  EXPECT_TRUE(empty_map.empty());
  EXPECT_EQ(empty_map.size(), 0);

  EXPECT_FALSE(map.empty());
  EXPECT_EQ(map.size(), 3);
}

TEST(MapTest, MaxSize) {
  Map<int, std::string> map;
  std::map<int, std::string> map1;

  // Max size is implementation-dependent, but it should be greater than 0
  EXPECT_GT(map.max_size(), map1.max_size());
}
// TEST(MapTest, Erase) {
//   Map<int, std::string> map;

//   map.insert({1, "one"});
//   map.insert({2, "two"});
//   map.insert({3, "three"});

//   // Erase an existing element.
//   auto it1 = map.getTree().Search(2);
//   EXPECT_NE(it1, map.end());
//   map.erase(it1);
//   EXPECT_EQ(map.size(), 2);
//   EXPECT_FALSE(map.contains(2));

//   // Erase a non-existing element.
//   auto it2 = map.find(4);
//   EXPECT_EQ(it2, map.end());
//   map.erase(it2);
//   EXPECT_EQ(map.size(), 2);
// }

TEST(MapTest, Swap) {
  Map<int, std::string> map1;
  map1.insert({1, "one"});
  map1.insert({2, "two"});

  Map<int, std::string> map2;
  map2.insert({3, "three"});
  map2.insert({4, "four"});

  map1.swap(map2);

  EXPECT_EQ(map1.size(), 2);
  EXPECT_TRUE(map1.contains(3));
  EXPECT_TRUE(map1.contains(4));

  EXPECT_EQ(map2.size(), 2);
  EXPECT_TRUE(map2.contains(1));
  EXPECT_TRUE(map2.contains(2));
}

TEST(MapTest, Merge) {
  Map<int, std::string> map1;
  map1.insert({1, "one"});
  map1.insert({2, "two"});

  Map<int, std::string> map2;
  map2.insert({3, "three"});
  map2.insert({4, "four"});

  map1.merge(map2);

  EXPECT_EQ(map1.size(), 4);
  EXPECT_TRUE(map1.contains(1));
  EXPECT_TRUE(map1.contains(2));
  EXPECT_TRUE(map1.contains(3));
  EXPECT_TRUE(map1.contains(4));

  EXPECT_EQ(map2.size(), 0);
}

TEST(MapTest, Contains) {
  Map<int, std::string> map;

  map.insert({1, "one"});
  map.insert({2, "two"});

  EXPECT_TRUE(map.contains(1));
  EXPECT_TRUE(map.contains(2));
  EXPECT_FALSE(map.contains(3));
}

// TEST(MapConstructorTest, MoveConstructor) {
//   Map<int, std::string> m{{1, "one"}, {2, "two"}, {3, "three"}};
//   Map<int, std::string> moved_m(std::move(m));
//   EXPECT_EQ(moved_m.size(), 3);
//   EXPECT_FALSE(moved_m.empty());
//   EXPECT_EQ(moved_m.at(1), "one");
//   EXPECT_EQ(moved_m.at(2), "two");
//   EXPECT_EQ(moved_m.at(3), "three");
//   EXPECT_EQ(m.size(), 0);
//   EXPECT_TRUE(m.empty());
// }
// TEST(SetTest, MoveAssignmentOperator) {
//   s21::Set<int> s1{1, 2, 3, 4};
//   s21::Set<int> s2{5, 6, 7, 8};
//   EXPECT_EQ(s2.size(), 4);
//   EXPECT_EQ(s1.size(), 4);

//   s1 = std::move(s2);
//   // EXPECT_TRUE(s1.contains(5));
//   // EXPECT_TRUE(s1.contains(6));
//   // EXPECT_TRUE(s1.contains(7));
//   // EXPECT_TRUE(s1.contains(8));
// }
int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
