.PHONY: all clean test s21_list.a check rebuild main

CC = gcc
CPP = g++
CFLAGS = -Wall -Werror -Wextra -std=c++17 --language=c++ -I h -I /usr/local/include/gtest/ -c
LFLAGS = -std=c++17 -I h -pthread -lstdc++
UNAME:=$(shell uname -s)

all: s21_list.a main
	
main: s21_list.a
	@$(CC) $(LFLAGS) main.cc list/s21_list.a -o main
	@./main
	@make clean

clean:
	@rm -rf *.o
	@rm -rf *.h.gch
	@rm -rf *.a
	@rm -rf *.out
	@rm -rf test
	@rm -rf *.gcda
	@rm -rf *.dSYM
	@rm -rf .clang-format

test: build_test
	@./test

build_test: clean s21_list.a
ifeq ($(UNAME), Linux)
	@$(CPP) $(LFLAGS) gtests.cc s21_list.a -lgtest -lpthread -o test
else
	@$(CC) $(LFLAGS) gtests.cc s21_list.a -lgtest -lpthread -o test
endif
#the -lstdc++ flag doesn't help when compiling with gcc on Linux, so I just use g++ for build tests

s21_list.a:
	@$(CC) ${CFLAGS} list/s21_list.h -c list/s21_list.tpp
# @ar rcs s21_list.a s21_*.o
	@ar rcs list/s21_list.a s21_list.o
	@ranlib list/s21_list.a
	@rm -rf **/*.o

check:
	@cp ../materials/linters/.clang-format .
	clang-format -n *.cc *.tpp *.h

rebuild: clean clean s21_list.a
