CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
MATH_FLAG = -lm
EXECUTABLE = test
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	GFLAGS = -lcheck -lsubunit $(MATH_FLAG)
endif

ifeq ($(UNAME), Darwin)
	GFLAGS = -lcheck
endif

SRC_EXTRA_FUNCTIONS = $(wildcard extra-functions/extra_functions.c)
SRC_ARITHMETIC = $(wildcard arithmetic-operators/*.c)
SRC_COMPARISON = $(wildcard comparison-operators/*.c)
SRC_CONVERTERS = $(wildcard converter-functions/*.c)
SRC_ANOTHER = $(wildcard another-functions/*.c)
SRC_TESTS = $(wildcard tests/*.c)

OBJ_EXTRA_FUNCTIONS = $(patsubst %.c, %.o, $(SRC_EXTRA_FUNCTIONS))
OBJ_ARITHMETIC = $(patsubst %.c, %.o, $(SRC_ARITHMETIC))
OBJ_COMPARISON = $(patsubst %.c, %.o, $(SRC_COMPARISON))
OBJ_CONVERTERS = $(patsubst %.c, %.o, $(SRC_CONVERTERS))
OBJ_ANOTHER = $(patsubst %.c, %.o, $(SRC_ANOTHER))
OBJ_TESTS = $(patsubst %.c, %.o, $(SRC_TESTS))

all: clean s21_decimal.a

clean:
	@rm -rf s21_decimal.a
	@rm -rf $(EXECUTABLE)
	@rm -rf ./report
	@rm -rf *.gcno *.gcda *.gcov *.info
	@rm -rf $(OBJ_EXTRA_FUNCTIONS) $(OBJ_ARITHMETIC) $(OBJ_COMPARISON) $(OBJ_CONVERTERS) $(OBJ_ANOTHER) $(OBJ_TESTS)

test: clean s21_decimal.a $(OBJ_TESTS)
	@$(CC) $(CFLAGS) $(OBJ_TESTS) $(GFLAGS) s21_decimal.a -o $(EXECUTABLE)
	@./$(EXECUTABLE)

s21_decimal.a: clean $(OBJ_EXTRA_FUNCTIONS) $(OBJ_ARITHMETIC) $(OBJ_COMPARISON) $(OBJ_CONVERTERS) $(OBJ_ANOTHER)
	ar rc s21_decimal.a $(OBJ_EXTRA_FUNCTIONS) $(OBJ_ARITHMETIC) $(OBJ_COMPARISON) $(OBJ_CONVERTERS) $(OBJ_ANOTHER)
	ranlib s21_decimal.a


gcov_report: clean s21_decimal.a
	@$(CC) $(CFLAGS) $(SRC_ARITHMETIC) $(SRC_COMPARISON) $(SRC_CONVERTERS) $(SRC_ANOTHER) $(SRC_TESTS) $(GFLAGS) s21_decimal.a -o $(EXECUTABLE) --coverage
	@./$(EXECUTABLE)
	@rm -rf test-test* test_*
	@lcov -t "tests" -o tests.info -c -d .
	genhtml -o report tests.info
	open report/index.html

style: clean
	@cp ../materials/linters/.clang-format ./
	clang-format -n ./another-functions/*.c ./arithmetic-operators/*.c ./comparison-operators/*.c ./converter-functions/*.c ./extra-functions/*.c ./tests/*.c
	clang-format -n *.h ./tests/*.h
	@rm .clang-format

clang-format: clean
	@cp ../materials/linters/.clang-format ./
	clang-format -i ./another-functions/*.c ./arithmetic-operators/*.c ./comparison-operators/*.c ./converter-functions/*.c ./extra-functions/*.c ./tests/*.c
	clang-format -i *.h ./tests/*.h
	@rm .clang-format

.PHONY: all clean test s21_decimal.a gcov_report style clang-format
