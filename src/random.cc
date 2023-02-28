
>>>>>>> VECTOR <<<<<<<<

class Test_vector {
 public:
  s21::Vector<int> empty_Vector;
  s21::Vector<int> five_Vector{1, 2, 3, 4, 5};
  s21::Vector<int> four_Vector{1, 2, 3, 4};
  s21::Vector<char> char_Vector;
  s21::Vector<float> float_Vector;
  s21::Vector<double> double_Vector;
  std::vector<int> origin_five_vector{1, 2, 3, 4, 5};
  std::vector<int> origin_four_vector{1, 2, 3, 4};
  std::vector<int> origin_int;
  std::vector<char> origin_char;
  std::vector<float> origin_float;
  std::vector<double> origin_double;
  std::vector<int>::iterator it_origin = origin_five_vector.begin();
  s21::Vector<int> s21_vector_lesser{534789,   2479056, 987654, 110101024,
                                     62348710, 1,       35674};
  std::vector<int> std_vector_lesser{534789,   2479056, 987654, 110101024,
                                     62348710, 1,       35674};
  s21::Vector<int> s21_vector_copy_lesser{1, 2};
  std::vector<int> std_vector_copy_lesser{1, 2};
  s21::Vector<int> s21_vector_copy_larger{9, 8, 7, 6, 5, 4, 3};
  std::vector<int> std_vector_copy_larger{9, 8, 7, 6, 5, 4, 3};
  s21::Vector<int> s21_vector_larger{1, 2};
  std::vector<int> std_vector_larger{1, 2};
  s21::Vector<int> s21_vector_ass{-333, -999, 123, 11765, 3};
  std::vector<int> std_vector_ass{-333, -999, 123, 11765, 3};
  s21::Vector<int> s21_vector_move{1, 2};
  std::vector<int> std_vector_move{1, 2};
  s21::Vector<int> s21_vector_s{111, 222, 333, 444, 555};
  std::vector<int> std_vector_s{111, 222, 333, 444, 555};
  s21::Vector<int> s21_vector_swap{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> std_vector_swap{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
};

TEST(Vector, constructor_default) {
  Test_vector logger;
  EXPECT_EQ(logger.empty_Vector.size(), logger.origin_int.size());
  EXPECT_EQ(logger.empty_Vector.capacity(), logger.origin_int.capacity());
  EXPECT_EQ(logger.empty_Vector.empty(), logger.origin_int.empty());
}

TEST(Vector, constructor_init) {
  s21::Vector<int> s21_vector(3);
  std::vector<int> std_vector(3);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, constructor_initializer_lit) {
  Test_vector logger;
  EXPECT_EQ(logger.five_Vector[0], logger.origin_five_vector[0]);
  EXPECT_EQ(logger.five_Vector[4], logger.origin_five_vector[4]);
  EXPECT_EQ(logger.five_Vector.size(), logger.origin_five_vector.size());
  EXPECT_EQ(logger.five_Vector.capacity(),
            logger.origin_five_vector.capacity());
  EXPECT_EQ(logger.five_Vector.empty(), logger.origin_five_vector.empty());
}

TEST(Vector, constructor_copy_empty) {
  Test_vector logger;
  s21::Vector<int> s21_copy(logger.empty_Vector);
  std::vector<int> std_copy(logger.origin_int);
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(Vector, constructor_copy_not_empty) {
  Test_vector logger;
  s21::Vector<int> s21_copy(logger.five_Vector);
  std::vector<int> std_copy(logger.origin_five_vector);
  EXPECT_EQ(s21_copy[0], std_copy[0]);
  EXPECT_EQ(s21_copy[s21_copy.size() - 1], std_copy[std_copy.size() - 1]);
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(Vector, constructor_move_not_empty) {
  Test_vector logger;
  s21::Vector<int> s21_copy(std::move(logger.five_Vector));
  std::vector<int> std_copy(std::move(logger.origin_five_vector));
  EXPECT_EQ(s21_copy[0], std_copy[0]);
  EXPECT_EQ(s21_copy[s21_copy.size() - 1], std_copy[std_copy.size() - 1]);
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(Vector, constructor_move_empty) {
  Test_vector logger;
  s21::Vector<int> s21_copy(std::move(logger.empty_Vector));
  std::vector<int> std_copy(std::move(logger.origin_int));
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(Vector, operator_copy_empty) {
  Test_vector logger;
  s21::Vector<int> s21_copy;
  std::vector<int> std_copy;
  s21_copy = logger.empty_Vector;
  std_copy = logger.origin_int;
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(Vector, operator_copy_not_empty) {
  Test_vector logger;
  s21::Vector<int> s21_copy;
  std::vector<int> std_copy;
  s21_copy = logger.five_Vector;
  std_copy = logger.origin_five_vector;
  EXPECT_EQ(s21_copy[0], std_copy[0]);
  EXPECT_EQ(s21_copy[s21_copy.size() - 1], std_copy[std_copy.size() - 1]);
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(Vector, operator_move_not_empty) {
  Test_vector logger;
  s21::Vector<int> s21_copy;
  std::vector<int> std_copy;
  s21_copy = std::move(logger.five_Vector);
  std_copy = std::move(logger.origin_five_vector);
  EXPECT_EQ(s21_copy[0], std_copy[0]);
  EXPECT_EQ(s21_copy[s21_copy.size() - 1], std_copy[std_copy.size() - 1]);
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(Vector, operator_move_empty) {
  Test_vector logger;
  s21::Vector<int> s21_copy;
  std::vector<int> std_copy;
  s21_copy = std::move(logger.empty_Vector);
  std_copy = std::move(logger.origin_int);

  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(Vector, copy_assignment_lesser_buffer) {
  Test_vector logger;
  logger.s21_vector_copy_lesser = logger.s21_vector_lesser;
  logger.std_vector_copy_lesser = logger.std_vector_lesser;
  EXPECT_EQ(logger.s21_vector_copy_lesser[0], logger.std_vector_copy_lesser[0]);
  EXPECT_EQ(logger.s21_vector_copy_lesser[1], logger.std_vector_copy_lesser[1]);
  EXPECT_EQ(logger.s21_vector_copy_lesser[2], logger.std_vector_copy_lesser[2]);
  EXPECT_EQ(logger.s21_vector_copy_lesser[3], logger.std_vector_copy_lesser[3]);
  EXPECT_EQ(logger.s21_vector_copy_lesser[4], logger.std_vector_copy_lesser[4]);
  EXPECT_EQ(logger.s21_vector_copy_lesser[5], logger.std_vector_copy_lesser[5]);
  EXPECT_EQ(logger.s21_vector_copy_lesser[6], logger.std_vector_copy_lesser[6]);
  EXPECT_EQ(logger.s21_vector_copy_lesser.size(),
            logger.std_vector_copy_lesser.size());
  EXPECT_EQ(logger.s21_vector_copy_lesser.capacity(),
            logger.std_vector_copy_lesser.capacity());
  EXPECT_EQ(logger.s21_vector_copy_lesser.empty(),
            logger.std_vector_copy_lesser.empty());
}

TEST(Vector, copy_assignment_larger_buffer) {
  Test_vector logger;
  logger.s21_vector_copy_larger = logger.s21_vector_copy_larger;
  logger.std_vector_copy_larger = logger.std_vector_copy_larger;
  EXPECT_EQ(logger.s21_vector_copy_larger[0], logger.std_vector_copy_larger[0]);
  EXPECT_EQ(logger.s21_vector_copy_larger[1], logger.std_vector_copy_larger[1]);
  EXPECT_EQ(logger.s21_vector_copy_larger.size(),
            logger.std_vector_copy_larger.size());
  EXPECT_EQ(logger.s21_vector_copy_larger.capacity(),
            logger.std_vector_copy_larger.capacity());
  EXPECT_EQ(logger.s21_vector_copy_larger.empty(),
            logger.std_vector_copy_larger.empty());
}

TEST(Vector, move_assigment) {
  Test_vector logger;
  logger.s21_vector_move = std::move(logger.s21_vector_ass);
  logger.std_vector_move = std::move(logger.std_vector_ass);
  EXPECT_EQ(logger.s21_vector_move[0], logger.std_vector_move[0]);
  EXPECT_EQ(logger.s21_vector_move[1], logger.std_vector_move[1]);
  EXPECT_EQ(logger.s21_vector_move[2], logger.std_vector_move[2]);
  EXPECT_EQ(logger.s21_vector_move[3], logger.std_vector_move[3]);
  EXPECT_EQ(logger.s21_vector_move[4], logger.std_vector_move[4]);
  EXPECT_EQ(logger.s21_vector_move.size(), logger.std_vector_move.size());
  EXPECT_EQ(logger.s21_vector_move.capacity(),
            logger.std_vector_move.capacity());
  EXPECT_EQ(logger.s21_vector_move.empty(), logger.std_vector_move.empty());
  EXPECT_EQ(logger.s21_vector_ass.size(), logger.std_vector_ass.size());
  EXPECT_EQ(logger.s21_vector_ass.capacity(), logger.std_vector_ass.capacity());
  EXPECT_EQ(logger.s21_vector_ass.empty(), logger.std_vector_ass.empty());
}

TEST(Vector, function_at) {
  Test_vector logger;
  EXPECT_EQ(logger.five_Vector.at(0), logger.origin_five_vector.at(0));
  EXPECT_EQ(logger.five_Vector.at(1), logger.origin_five_vector.at(1));
  EXPECT_EQ(logger.five_Vector.at(2), logger.origin_five_vector.at(2));
  EXPECT_EQ(logger.five_Vector.at(3), logger.origin_five_vector.at(3));
}

TEST(Vector, operator_square) {
  Test_vector logger;
  EXPECT_EQ(logger.five_Vector[0], logger.origin_five_vector[0]);
  EXPECT_EQ(logger.five_Vector[1], logger.origin_five_vector[1]);
  EXPECT_EQ(logger.five_Vector[2], logger.origin_five_vector[2]);
  EXPECT_EQ(logger.five_Vector[3], logger.origin_five_vector[3]);
}

TEST(Vector, function_front) {
  Test_vector logger;
  EXPECT_EQ(logger.origin_five_vector.front(), logger.five_Vector.front());
}

TEST(Vector, function_back) {
  Test_vector logger;
  EXPECT_EQ(logger.five_Vector.back(), logger.origin_five_vector.back());
}

TEST(Vector, iterator_element_access) {
  s21::Vector<char> s21_vector{'p', 'e', 'r', 'f', 'o',
                               'r', 'a', 't', 'o', 'r'};
  std::vector<char> std_vector{'p', 'e', 'r', 'f', 'o',
                               'r', 'a', 't', 'o', 'r'};
  s21::Vector<char>::iterator s21_it = s21_vector.begin();
  std::vector<char>::iterator std_it = std_vector.begin();
  while (s21_it != s21_vector.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(vector_iterator_suit, const_iterator_element_access) {
  s21::Vector<char> s21_vector{'p', 'e', 'r', 'f', 'o',
                               'r', 'a', 't', 'o', 'r'};
  std::vector<char> std_vector{'p', 'e', 'r', 'f', 'o',
                               'r', 'a', 't', 'o', 'r'};
  s21::Vector<char>::const_iterator s21_it = s21_vector.begin();
  std::vector<char>::const_iterator std_it = std_vector.begin();
  while (s21_it != s21_vector.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(Vector, function_data) {
  Test_vector logger;
  EXPECT_EQ(*logger.five_Vector.data(), *logger.origin_five_vector.data());
}

TEST(Vector, function_data_e) {
  s21::Vector<char> s21_vector_empty;
  std::vector<char> std_vector_empty;
  EXPECT_EQ(s21_vector_empty.data(), nullptr);
  EXPECT_EQ(std_vector_empty.data(), nullptr);
  s21::Vector<char> s21_vector{'L', 'I', 'Z', 'A'};
  std::vector<char> std_vector{'L', 'I', 'Z', 'A'};
  EXPECT_NE(s21_vector.data(), nullptr);
  EXPECT_NE(std_vector.data(), nullptr);
}

TEST(Vector, function_insert_begin) {
  s21::Vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::Vector<int>::iterator s21_it = s21_vector.begin();
  std::vector<int>::iterator std_it = std_vector.begin();
  s21_it = s21_vector.insert(s21_it, 666);
  std_it = std_vector.insert(std_it, 666);
  EXPECT_EQ(*s21_it, *std_it);
  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.at(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.at(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.at(5), std_vector.at(5));
  EXPECT_EQ(s21_vector.at(6), std_vector.at(6));
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_insert_mid) {
  s21::Vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::Vector<int>::iterator s21_it = s21_vector.begin();
  std::vector<int>::iterator std_it = std_vector.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_it = s21_vector.insert(s21_it, 666);
  std_it = std_vector.insert(std_it, 666);
  EXPECT_EQ(*s21_it, *std_it);
  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.at(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.at(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.at(5), std_vector.at(5));
  EXPECT_EQ(s21_vector.at(6), std_vector.at(6));
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_insert_end) {
  s21::Vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::Vector<int>::iterator s21_it = s21_vector.end();
  std::vector<int>::iterator std_it = std_vector.end();
  s21_it = s21_vector.insert(s21_it, 666);
  std_it = std_vector.insert(std_it, 666);
  EXPECT_EQ(*s21_it, *std_it);
  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.at(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.at(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.at(5), std_vector.at(5));
  EXPECT_EQ(s21_vector.at(6), std_vector.at(6));
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_insert_multi) {
  s21::Vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::Vector<int>::iterator s21_it = s21_vector.begin();
  std::vector<int>::iterator std_it = std_vector.begin();
  s21_it = s21_vector.insert(s21_it, 666);
  std_it = std_vector.insert(std_it, 666);
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_it = s21_vector.insert(s21_it, 666);
  std_it = std_vector.insert(std_it, 666);
  EXPECT_EQ(*s21_it, *std_it);
  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.at(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.at(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.at(5), std_vector.at(5));
  EXPECT_EQ(s21_vector.at(6), std_vector.at(6));
  EXPECT_EQ(s21_vector.at(7), std_vector.at(7));
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_erase_begin) {
  s21::Vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::Vector<int>::iterator s21_it = s21_vector.begin();
  std::vector<int>::iterator std_it = std_vector.begin();
  s21_vector.erase(s21_it);
  std_vector.erase(std_it);
  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.at(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.at(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_erase_mid) {
  s21::Vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::Vector<int>::iterator s21_it = s21_vector.begin();
  std::vector<int>::iterator std_it = std_vector.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_vector.erase(s21_it);
  std_vector.erase(std_it);
  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.at(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.at(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_erase_end) {
  s21::Vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::Vector<int>::iterator s21_it = s21_vector.end() - 1;
  std::vector<int>::iterator std_it = std_vector.end() - 1;
  s21_vector.erase(s21_it);
  std_vector.erase(std_it);
  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.at(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.at(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_erase_multi) {
  s21::Vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::Vector<int>::iterator s21_it = s21_vector.begin();
  std::vector<int>::iterator std_it = std_vector.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_vector.erase(s21_it);
  std_vector.erase(std_it);
  s21_it = s21_vector.begin();
  std_it = std_vector.begin();
  s21_vector.erase(s21_it);
  std_vector.erase(std_it);
  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.at(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, empty_testing) {
  Test_vector logger;
  EXPECT_FALSE(logger.five_Vector.empty());
  EXPECT_TRUE(logger.empty_Vector.empty());
}

TEST(Vector, size_testing) {
  Test_vector logger;
  EXPECT_EQ(logger.empty_Vector.size(), 0);
  EXPECT_EQ(logger.five_Vector.size(), 5);
}

TEST(Vector, max_size_testing) {
  Test_vector logger;
  EXPECT_EQ(logger.empty_Vector.max_size(), logger.origin_int.max_size());
  EXPECT_EQ(logger.char_Vector.max_size(), logger.origin_char.max_size());
  EXPECT_EQ(logger.float_Vector.max_size(), logger.origin_float.max_size());
  EXPECT_EQ(logger.double_Vector.max_size(), logger.origin_double.max_size());
}

TEST(Vector, reserve_testing) {
  Test_vector logger;
  logger.five_Vector.reserve(2);
  logger.origin_five_vector.reserve(2);
  EXPECT_EQ(logger.five_Vector.capacity(),
            logger.origin_five_vector.capacity());
  logger.five_Vector.reserve(1000);
  logger.origin_five_vector.reserve(1000);
  EXPECT_EQ(logger.five_Vector.capacity(),
            logger.origin_five_vector.capacity());
  logger.five_Vector.reserve(0);
  logger.origin_five_vector.reserve(0);
  EXPECT_EQ(logger.five_Vector.capacity(),
            logger.origin_five_vector.capacity());
  //        EXPECT_ANY_THROW(logger.five_Vector.reserve(-1));  // google
  leaks
}

TEST(Vector, capacity_testing) {
  Test_vector logger;
  EXPECT_EQ(logger.five_Vector.capacity(),
            logger.origin_five_vector.capacity());
  logger.five_Vector.push_back(3);
  logger.origin_five_vector.push_back(4);
  EXPECT_EQ(logger.five_Vector.capacity(),
            logger.origin_five_vector.capacity());
  logger.five_Vector.pop_back();
  logger.origin_five_vector.pop_back();
  EXPECT_EQ(logger.five_Vector.capacity(),
            logger.origin_five_vector.capacity());
}

TEST(Vector, shrink_to_fit_testing) {
  Test_vector logger;
  logger.five_Vector.reserve(3);
  logger.origin_five_vector.reserve(3);
  logger.five_Vector.shrink_to_fit();
  logger.origin_five_vector.shrink_to_fit();
  EXPECT_EQ(logger.five_Vector.capacity(),
            logger.origin_five_vector.capacity());
  EXPECT_EQ(logger.five_Vector.size(), logger.origin_five_vector.size());
  logger.five_Vector.reserve(100);
  logger.origin_five_vector.reserve(100);
  logger.five_Vector.shrink_to_fit();
  logger.origin_five_vector.shrink_to_fit();
  EXPECT_EQ(logger.five_Vector.capacity(),
            logger.origin_five_vector.capacity());
  EXPECT_EQ(logger.five_Vector.size(), logger.origin_five_vector.size());
  logger.five_Vector.reserve(0);
  logger.origin_five_vector.reserve(0);
  logger.five_Vector.shrink_to_fit();
  logger.origin_five_vector.shrink_to_fit();
  EXPECT_EQ(logger.five_Vector.capacity(),
            logger.origin_five_vector.capacity());
  EXPECT_EQ(logger.five_Vector.size(), logger.origin_five_vector.size());
}

TEST(Vector, clear_testing) {
  Test_vector logger;
  logger.five_Vector.clear();
  logger.origin_five_vector.clear();
  EXPECT_EQ(logger.five_Vector.capacity(),
            logger.origin_five_vector.capacity());
  EXPECT_EQ(logger.five_Vector.size(), logger.origin_five_vector.size());
}

TEST(Vector, function_swap) {
  Test_vector logger;
  logger.s21_vector_s.swap(logger.s21_vector_swap);
  logger.std_vector_s.swap(logger.std_vector_swap);
  EXPECT_EQ(logger.s21_vector_swap.at(0), logger.std_vector_swap.at(0));
  EXPECT_EQ(logger.s21_vector_swap.at(1), logger.std_vector_swap.at(1));
  EXPECT_EQ(logger.s21_vector_swap.at(2), logger.std_vector_swap.at(2));
  EXPECT_EQ(logger.s21_vector_swap.at(3), logger.std_vector_swap.at(3));
  EXPECT_EQ(logger.s21_vector_swap.at(4), logger.std_vector_swap.at(4));
  EXPECT_EQ(logger.s21_vector_swap.size(), logger.std_vector_swap.size());
  EXPECT_EQ(logger.s21_vector_swap.capacity(),
            logger.std_vector_swap.capacity());
  EXPECT_EQ(logger.std_vector_s.at(0), logger.std_vector_s.at(0));
  EXPECT_EQ(logger.std_vector_s.at(1), logger.std_vector_s.at(1));
  EXPECT_EQ(logger.std_vector_s.at(2), logger.std_vector_s.at(2));
  EXPECT_EQ(logger.std_vector_s.at(3), logger.std_vector_s.at(3));
  EXPECT_EQ(logger.std_vector_s.at(4), logger.std_vector_s.at(4));
  EXPECT_EQ(logger.std_vector_s.at(5), logger.std_vector_s.at(5));
  EXPECT_EQ(logger.std_vector_s.at(6), logger.std_vector_s.at(6));
  EXPECT_EQ(logger.std_vector_s.at(7), logger.std_vector_s.at(7));
  EXPECT_EQ(logger.std_vector_s.at(8), logger.std_vector_s.at(8));
  EXPECT_EQ(logger.std_vector_s.at(9), logger.std_vector_s.at(9));
  EXPECT_EQ(logger.std_vector_s.size(), logger.std_vector_s.size());
  EXPECT_EQ(logger.std_vector_s.capacity(), logger.std_vector_s.capacity());
  EXPECT_EQ(logger.std_vector_s.empty(), logger.std_vector_s.empty());
}

TEST(Vector, function_push_back) {
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  s21_vector.push_back(666);
  std_vector.push_back(666);
  s21_vector.push_back(123);
  std_vector.push_back(123);
  ASSERT_EQ(s21_vector.at(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.at(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.at(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.at(3), std_vector.at(3));
  ASSERT_EQ(s21_vector.at(4), std_vector.at(4));
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
  ASSERT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_pop_back) {
  s21::Vector<int> s21_vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_vector.pop_back();
  std_vector.pop_back();
  s21_vector.pop_back();
  std_vector.pop_back();
  ASSERT_EQ(s21_vector.at(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.at(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.at(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.at(3), std_vector.at(3));
  ASSERT_EQ(s21_vector.at(4), std_vector.at(4));
  ASSERT_EQ(s21_vector.at(5), std_vector.at(5));
  ASSERT_EQ(s21_vector.at(6), std_vector.at(6));
  ASSERT_EQ(s21_vector.at(7), std_vector.at(7));
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
  ASSERT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_reserve) {
  s21::Vector<double> s21_vector_empty;
  std::vector<double> std_vector_empty;
  s21_vector_empty.reserve(100);
  std_vector_empty.reserve(100);
  ASSERT_EQ(s21_vector_empty.size(), std_vector_empty.size());
  ASSERT_EQ(s21_vector_empty.capacity(), std_vector_empty.capacity());
  ASSERT_EQ(s21_vector_empty.empty(), std_vector_empty.empty());
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  s21_vector.reserve(50);
  std_vector.reserve(50);
  ASSERT_EQ(s21_vector.at(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.at(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.at(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
  ASSERT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_shrink_to_fit) {
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  s21_vector.reserve(50);
  std_vector.reserve(50);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  ASSERT_EQ(s21_vector.at(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.at(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.at(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
  ASSERT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_emplace_begin) {
  s21::Vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::Vector<int>::const_iterator s21_it = s21_vector.begin();
  std::vector<int>::iterator std_it = std_vector.begin();
  s21_it = s21_vector.emplace(s21_it, 666);
  std_it = std_vector.emplace(std_it, 666);
  EXPECT_EQ(*s21_it, *std_it);
  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.at(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.at(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.at(5), std_vector.at(5));
  EXPECT_EQ(s21_vector.at(6), std_vector.at(6));
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}