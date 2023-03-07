.PHONY: all clean rebuild test leaks gcov_report
CC = gcc
GCOV = -fprofile-arcs -ftest-coverage
CFLAGS = -lstdc++ -lgtest -std=c++17 -Wall -Werror -Wextra
EXE = unit_tests
TFN = unit_tests.cc

all: test leaks gcov_report clean

test: $(TFN)
	@${CC} $<  ${CFLAGS} -o $(EXE)
	@./$(BUILD)$(EXE)

leaks: test
	leaks --atExit -- ./$(EXE)
 
gcov_report:
	gcc  --coverage $(TFN) -o gcov_report -lgtest -lstdc++
	./gcov_report
	lcov -t "stest" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open ./report/index.html

clean:
	@/bin/rm -rf *.o *.a build *.gcno *gcda report *.info main *.dSYM *.out gcov_report $(EXE)

rebuild: clean all
