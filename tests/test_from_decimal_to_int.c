#include "test_decimal.h"

START_TEST(from_decimal_to_int_1) {
  s21_decimal decimal = {0};
  decimal.bits[LOW] = 19;
  int num = 0;
  int result = s21_from_decimal_to_int(decimal, &num);
  ck_assert_int_eq(num, 19);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(from_decimal_to_int_2) {
  s21_decimal decimal = {0};
  decimal.bits[LOW] = 1344398;
  int num = 0;
  int result = s21_from_decimal_to_int(decimal, &num);
  ck_assert_int_eq(num, 1344398);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(from_decimal_to_int_3) {
  s21_decimal decimal = {0};
  decimal.bits[LOW] = MAX_INT;
  int num = 0;
  int result = s21_from_decimal_to_int(decimal, &num);
  ck_assert_int_eq(num, MAX_INT);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(from_decimal_to_int_4) {
  s21_decimal decimal = {0};
  resetDecimal(&decimal);
  decimal.bits[LOW] = MAX_INT;
  setSign(&decimal);
  int num = 0;
  int result = s21_from_decimal_to_int(decimal, &num);
  ck_assert_int_eq(num, -MAX_INT);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(from_decimal_to_int_5) {
  s21_decimal decimal = {0};
  resetDecimal(&decimal);
  decimal.bits[LOW] = MIN_INT;
  setSign(&decimal);
  int num = 0;
  int result = s21_from_decimal_to_int(decimal, &num);
  ck_assert_int_eq(num, -MIN_INT);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(from_decimal_to_int_6) {
  s21_decimal decimal = {0};
  resetDecimal(&decimal);
  decimal.bits[LOW] = MAX_UINT;
  setSign(&decimal);
  int num = 0;
  int result = s21_from_decimal_to_int(decimal, &num);
  ck_assert_int_eq(num, 0);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(from_decimal_to_int_7) {
  s21_decimal decimal = {0};
  resetDecimal(&decimal);
  decimal.bits[LOW] = MAX_UINT;
  int num = 0;
  int result = s21_from_decimal_to_int(decimal, &num);
  ck_assert_int_eq(num, 0);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(from_decimal_to_int_8) {
  s21_decimal decimal = {0};
  resetDecimal(&decimal);
  decimal.bits[LOW] = 2;
  int num = 0;
  int result = s21_from_decimal_to_int(decimal, &num);
  ck_assert_int_eq(num, 2);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(from_decimal_to_int_9) {
  s21_decimal decimal = {0};
  resetDecimal(&decimal);
  decimal.bits[LOW] = 2;
  setSign(&decimal);
  int num = 0;
  int result = s21_from_decimal_to_int(decimal, &num);
  ck_assert_int_eq(num, -2);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(from_decimal_to_int_10) {
  s21_decimal decimal = {0};
  resetDecimal(&decimal);
  decimal.bits[LOW] = 0;
  int num = 0;
  int result = s21_from_decimal_to_int(decimal, &num);
  ck_assert_int_eq(num, 0);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(from_decimal_to_int_11) {
  s21_decimal decimal = {0};
  resetDecimal(&decimal);
  decimal.bits[LOW] = 0;
  int *num = NULL;
  int result = s21_from_decimal_to_int(decimal, num);
  ck_assert_int_eq(result, 1);
}
END_TEST

Suite *test_from_decimal_to_int() {
  Suite *s = suite_create(color_text("S21_FROM_DECIMAL_TO_INT"));
  TCase *tc = tcase_create("from_decimal_to_int_test");

  tcase_add_test(tc, from_decimal_to_int_1);
  tcase_add_test(tc, from_decimal_to_int_2);
  tcase_add_test(tc, from_decimal_to_int_3);
  tcase_add_test(tc, from_decimal_to_int_4);
  tcase_add_test(tc, from_decimal_to_int_5);
  tcase_add_test(tc, from_decimal_to_int_6);
  tcase_add_test(tc, from_decimal_to_int_7);
  tcase_add_test(tc, from_decimal_to_int_8);
  tcase_add_test(tc, from_decimal_to_int_9);
  tcase_add_test(tc, from_decimal_to_int_10);
  tcase_add_test(tc, from_decimal_to_int_11);

  suite_add_tcase(s, tc);
  return s;
}
