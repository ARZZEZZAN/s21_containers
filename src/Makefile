
.PHONY : all clean test clang valgrind gcov_report rebuild

CC=gcc
CFLAGS=-Wall -Werror -Wextra
CPPFLAGS=-lstdc++ -std=c++17
TEST_FLAGS:=$(CFLAGS) -g #-fsanitize=address -O1 -fno-omit-frame-pointer
LINUX_FLAGS =-lrt -lpthread -lm -lsubunit
GCOV_FLAGS?=--coverage#-fprofile-arcs -ftest-coverage
LIBS=-lgtest
VALGRIND_FLAGS=--trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose
HEADER=s21_containers.h
TEST_SRC=unit_tests.cc

OS := $(shell uname -s)
USERNAME=$(shell whoami)

ifeq ($(OS),Linux)
  OPEN_CMD = xdg-open
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
endif

all: test gcov_report

rebuild:
	make clean
	make all

test: 
ifeq ($(OS), Darwin)
	$(CC) $(TEST_FLAGS) $(LIBS) $(CPPFLAGS) $(TEST_SRC) -o unit_test
else
	${CC} $(TEST_FLAGS) ${TEST_SRC} $(CPPFLAGS) -o unit_test $(LIBS) $(LINUX_FLAGS)
endif
	./unit_test

gcov_report: clean
ifeq ($(OS), Darwin)
	$(CC) $(TEST_FLAGS) $(GCOV_FLAGS) $(LIBS) $(CPPFLAGS) $(TEST_SRC) -o gcov_report 
else
	$(CC) $(TEST_FLAGS) $(GCOV_FLAGS) $(TEST_SRC) -o gcov_report $(LIBS) $(CPPFLAGS) $(LINUX_FLAGS)
endif
	./gcov_report
	lcov -t "stest" -o s21_test.info -c -d ./ --no-external
	genhtml -o report s21_test.info
	$(OPEN_CMD) ./report/index.html

clang:
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -style=Google -n $(HEADER) $(TEST_SRC)
	rm .clang-format

leaks: test
	leaks -atExit -- ./unit_test

valgrind: clean 
	${CC} $(TEST_FLAGS) ${TEST_SRC}  $(CPPFLAGS) -o valgrind_test $(LIBS) $(LINUX_FLAGS)
	CK_FORK=no valgrind $(VALGRIND_FLAGS) --log-file=RESULT_VALGRIND.txt ./valgrind_test
	$(OPEN_CMD) ./RESULT_VALGRIND.txt

clean_obj:
	rm -rf *.o

clean_lib: 
	rm -rf *.a

clean_test:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf report
	rm -rf gcov_report
	rm -rf valgrind_test
	rm -rf *.dSYM

clean: clean_lib clean_lib clean_test clean_obj
	rm -rf unit_test
	rm -rf RESULT_VALGRIND.txt
# .PHONY: all clean rebuild test leaks gcov_report
# CC = gcc
# GCOV = -fprofile-arcs -ftest-coverage
# CFLAGS = -lstdc++ -lgtest -std=c++17 -Wall -Werror -Wextra
# EXE = unit_tests
# TFN = unit_tests.cc

# all: test leaks gcov_report clean

# test: $(TFN)
# 	@${CC} $<  ${CFLAGS} -o $(EXE)
# 	@./$(BUILD)$(EXE)

# leaks: test
# 	leaks --atExit -- ./$(EXE)
 
# gcov_report:
# 	gcc  --coverage $(TFN) -o gcov_report -lgtest -lstdc++
# 	./gcov_report
# 	lcov -t "stest" -o s21_test.info -c -d .
# 	genhtml -o report s21_test.info
# 	open ./report/index.html

# clean:
# 	@/bin/rm -rf *.o *.a build *.gcno *gcda report *.info main *.dSYM *.out gcov_report $(EXE)

# rebuild: clean all
