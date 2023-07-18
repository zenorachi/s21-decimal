#include <check.h>

#include "../s21_decimal.h"

#define color_start(start_end) "\033[0;41m" #start_end "\033[0m"
#define color_text(test_name) "\033[0;44m" #test_name "\033[0m"

// Converters
Suite *test_from_decimal_to_int();
Suite *test_from_decimal_to_float();
Suite *test_from_int_to_decimal();
Suite *test_from_float_to_decimal();

// Arithmetic operators
Suite *test_add();
Suite *test_sub();

// Another functions
Suite *test_negate();
Suite *test_truncate();
Suite *test_floor();
Suite *test_round();

// Comparison operators
Suite *test_is_equal();
Suite *test_is_not_equal();
Suite *test_is_greater();
Suite *test_is_greater_or_equal();
Suite *test_is_less();
Suite *test_is_less_or_equal();
