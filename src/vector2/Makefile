FLAGS:=-lgtest -lpthread -fprofile-arcs -ftest-coverage

all: test gcov_report

build:
	mkdir -p build
	g++ -g -Wall -Werror -Wextra $(FLAGS) -std=c++17 -Wpedantic *.cc *.hpp

test: build
	build/./out
ifeq ($(shell uname), Darwin)
	mv *gcda build/
	mv *gcno build/
endif
	
gcov_report: test
	lcov/bin/./lcov -q -c -d build/. -o build/coverage.info
	@lcov/bin/./lcov -q --remove build/coverage.info '*/src/test*' '*/include/*' '11*' \
    -o build/coverage.info
	lcov/bin/./genhtml build/coverage.info --output-directory out

lint:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.hpp

clean:
	rm -rf a.out .clang-format build \
	*gcda *gcno out

docker:
	docker build --no-cache .

docker_clean:
	docker rm $$(docker ps -a -q) || true
	docker rmi -f $$(docker images -q) || true

valgrind:
	valgrind --track-origins=yes \
	--show-leak-kinds=all --leak-check=full build/./out

rebuild: clean test

.SILENT : test clean lint gcov_report