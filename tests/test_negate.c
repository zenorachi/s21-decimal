#include "test_decimal.h"

START_TEST(negate_1) {
  s21_decimal decimal = {0};
  float num = 92000108940.0;
  s21_from_float_to_decimal(num, &decimal);
  s21_decimal dst = {0};
  int state2 = s21_negate(decimal, &dst);
  ck_assert_int_eq(state2, OK);
  float test = 0;
  s21_from_decimal_to_float(dst, &test);
  ck_assert_float_eq(test, -num);
}
END_TEST

START_TEST(negate_2) {
  s21_decimal decimal = {0};
  float num = 111108940.3434;
  s21_from_float_to_decimal(num, &decimal);
  s21_decimal dst = {0};
  int state2 = s21_negate(decimal, &dst);
  ck_assert_int_eq(state2, OK);
  float test = 0;
  s21_from_decimal_to_float(dst, &test);
  ck_assert_float_eq(test, -num);
}
END_TEST

START_TEST(negate_3) {
  s21_decimal decimal = {0};
  float num = -MAX_UINT * 13.43;
  s21_from_float_to_decimal(num, &decimal);
  s21_decimal dst = {0};
  int state2 = s21_negate(decimal, &dst);
  ck_assert_int_eq(state2, OK);
  float test = 0;
  s21_from_decimal_to_float(dst, &test);
  ck_assert_float_eq(test, -num);
}
END_TEST

START_TEST(negate_4) {
  s21_decimal decimal = {0};
  float num = 92000108940.0;
  s21_from_float_to_decimal(num, &decimal);
  s21_decimal *dst = NULL;
  int state2 = s21_negate(decimal, dst);
  ck_assert_int_eq(state2, 1);
}
END_TEST

START_TEST(negate_5) {
  s21_decimal decimal = {0};
  int num = MAX_UINT / 2;
  s21_from_int_to_decimal(num, &decimal);
  s21_decimal dst = {0};
  int state2 = s21_negate(decimal, &dst);
  ck_assert_int_eq(state2, OK);
  int test = 0;
  s21_from_decimal_to_int(dst, &test);
  ck_assert_float_eq(test, -num);
}
END_TEST

START_TEST(negate_6) {
  s21_decimal decimal = {0};
  int num = -MAX_UINT / 2;
  s21_from_int_to_decimal(num, &decimal);
  s21_decimal dst = {0};
  int state2 = s21_negate(decimal, &dst);
  ck_assert_int_eq(state2, OK);
  int test = 0;
  s21_from_decimal_to_int(dst, &test);
  ck_assert_float_eq(test, -num);
}
END_TEST

START_TEST(negate_7) {
  s21_decimal decimal = {0};
  int num = 0;
  s21_from_int_to_decimal(num, &decimal);
  s21_decimal dst = {0};
  int state2 = s21_negate(decimal, &dst);
  ck_assert_int_eq(state2, OK);
  int test = 0;
  s21_from_decimal_to_int(dst, &test);
  ck_assert_float_eq(test, -num);
}
END_TEST

Suite *test_negate() {
  Suite *s = suite_create(color_text("S21_NEGATE"));
  TCase *tc = tcase_create("negate_test");

  tcase_add_test(tc, negate_1);
  tcase_add_test(tc, negate_2);
  tcase_add_test(tc, negate_3);
  tcase_add_test(tc, negate_4);
  tcase_add_test(tc, negate_5);
  tcase_add_test(tc, negate_6);
  tcase_add_test(tc, negate_7);

  suite_add_tcase(s, tc);
  return s;
}
