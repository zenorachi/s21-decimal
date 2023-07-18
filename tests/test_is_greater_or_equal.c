#include "test_decimal.h"

START_TEST(is_greater_or_equal_1) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  int state = s21_is_greater_or_equal(value1, value2);
  int state2 = s21_is_greater_or_equal(value2, value1);
  ck_assert_int_eq(state, TRUE);
  ck_assert_int_eq(state2, TRUE);
  ck_assert_int_eq(state, state2);
}
END_TEST

START_TEST(is_greater_or_equal_2) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2), TRUE);
}
END_TEST

START_TEST(is_greater_or_equal_3) {
  s21_decimal test_value_1 = {{5000, 0, 0, 0}};
  s21_decimal test_value_2 = {{5001, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2), FALSE);
}
END_TEST

START_TEST(is_greater_or_equal_4) {
  s21_decimal test_value_1 = {{MAX_UINT, MAX_UINT / 10, MAX_UINT / 100, 0}};
  s21_decimal test_value_2 = {{MAX_UINT, MAX_UINT / 10, MAX_UINT / 100, 0}};
  setSign(&test_value_2);
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2), TRUE);
}
END_TEST

START_TEST(is_greater_or_equal_5) {
  s21_decimal test_value_1 = {{5000, 0, 0, 0}};
  s21_decimal test_value_2 = {{5000, 0, 0, 2147483648}};
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2), TRUE);
}
END_TEST

START_TEST(is_greater_or_equal_6) {
  s21_decimal test_value_1 = {{5000, 0, 0, 0}};
  s21_decimal test_value_2 = {{5000, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2), TRUE);
}
END_TEST

Suite *test_is_greater_or_equal() {
  Suite *s = suite_create(color_text("S21_IS_GREATER_OR_EQUAL"));
  TCase *tc = tcase_create("is_greater_or_equal");

  tcase_add_test(tc, is_greater_or_equal_1);
  tcase_add_test(tc, is_greater_or_equal_2);
  tcase_add_test(tc, is_greater_or_equal_3);
  tcase_add_test(tc, is_greater_or_equal_4);
  tcase_add_test(tc, is_greater_or_equal_5);
  tcase_add_test(tc, is_greater_or_equal_6);

  suite_add_tcase(s, tc);
  return s;
}
