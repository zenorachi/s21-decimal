#include "test_decimal.h"

START_TEST(from_int_to_decimal_1) {
  int num = 1340;
  s21_decimal decimal = {{0, 0, 0, 0}};
  int result = s21_from_int_to_decimal(num, &decimal);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(decimal.bits[LOW], num);
}
END_TEST

START_TEST(from_int_to_decimal_2) {
  int num = -MIN_INT;
  s21_decimal decimal = {{0, 0, 0, 0}};
  int result = s21_from_int_to_decimal(num, &decimal);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(decimal.bits[LOW], MIN_INT);
  ck_assert_int_eq(getSign(decimal), 1);
}
END_TEST

START_TEST(from_int_to_decimal_3) {
  int num = MAX_INT;
  s21_decimal decimal = {{0, 0, 0, 0}};
  int result = s21_from_int_to_decimal(num, &decimal);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(decimal.bits[LOW], MAX_INT);
  ck_assert_int_eq(getSign(decimal), 0);
}
END_TEST

START_TEST(from_int_to_decimal_4) {
  int num = MAX_INT;
  s21_decimal *decimal = NULL;
  int result = s21_from_int_to_decimal(num, decimal);
  ck_assert_int_eq(result, 1);
}
END_TEST

Suite *test_from_int_to_decimal() {
  Suite *s = suite_create(color_text("S21_FROM_INT_TO_DECIMAL"));
  TCase *tc = tcase_create("add");

  tcase_add_test(tc, from_int_to_decimal_1);
  tcase_add_test(tc, from_int_to_decimal_2);
  tcase_add_test(tc, from_int_to_decimal_3);
  tcase_add_test(tc, from_int_to_decimal_4);

  suite_add_tcase(s, tc);
  return s;
}
