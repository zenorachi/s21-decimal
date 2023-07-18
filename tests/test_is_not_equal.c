#include "test_decimal.h"

START_TEST(is_not_equal_1) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  int state = s21_is_not_equal(value1, value2);
  int state2 = s21_is_not_equal(value2, value1);
  ck_assert_int_eq(state, FALSE);
  ck_assert_int_eq(state2, FALSE);
  ck_assert_int_eq(state, state2);
}
END_TEST

START_TEST(is_not_equal_2) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  setSign(&value2);
  int state = s21_is_not_equal(value1, value2);
  int state2 = s21_is_not_equal(value2, value1);
  ck_assert_int_eq(state, FALSE);
  ck_assert_int_eq(state2, FALSE);
  ck_assert_int_eq(state, state2);
}
END_TEST

START_TEST(is_not_equal_3) {
  s21_decimal value1 = {{MAX_UINT, MAX_UINT, 0, MAX_INT}};
  s21_decimal value2 = {{MAX_UINT, MAX_UINT, 0, MAX_INT}};
  int state = s21_is_not_equal(value1, value2);
  int state2 = s21_is_not_equal(value2, value1);
  ck_assert_int_eq(state, FALSE);
  ck_assert_int_eq(state2, FALSE);
  ck_assert_int_eq(state, state2);
}
END_TEST

START_TEST(is_not_equal_4) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  float fNum = 4399438.0;
  s21_from_float_to_decimal(fNum, &value1);
  int iNum = 4399438;
  s21_from_int_to_decimal(iNum, &value2);
  int state = s21_is_not_equal(value1, value2);
  int state2 = s21_is_not_equal(value2, value1);
  ck_assert_int_eq(state, FALSE);
  ck_assert_int_eq(state2, FALSE);
  ck_assert_int_eq(state, state2);
}
END_TEST

START_TEST(is_not_equal_5) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  float fNum = 4399438.9;
  s21_from_float_to_decimal(fNum, &value1);
  int iNum = 4399438;
  s21_from_int_to_decimal(iNum, &value2);
  int state = s21_is_not_equal(value1, value2);
  int state2 = s21_is_not_equal(value2, value1);
  ck_assert_int_eq(state, TRUE);
  ck_assert_int_eq(state2, TRUE);
  ck_assert_int_eq(state, state2);
}
END_TEST

START_TEST(is_not_equal_6) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  float fNum = -2281337.0;
  s21_from_float_to_decimal(fNum, &value1);
  int iNum = -2281337;
  s21_from_int_to_decimal(iNum, &value2);
  int state = s21_is_not_equal(value1, value2);
  int state2 = s21_is_not_equal(value2, value1);
  ck_assert_int_eq(state, FALSE);
  ck_assert_int_eq(state2, FALSE);
  ck_assert_int_eq(state, state2);
}
END_TEST

START_TEST(is_not_equal_7) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  int iNum1 = -2281337;
  s21_from_int_to_decimal(iNum1, &value1);
  int iNum2 = -432281337;
  s21_from_int_to_decimal(iNum2, &value2);
  int state = s21_is_not_equal(value1, value2);
  int state2 = s21_is_not_equal(value2, value1);
  ck_assert_int_eq(state, TRUE);
  ck_assert_int_eq(state2, TRUE);
  ck_assert_int_eq(state, state2);
}
END_TEST

START_TEST(is_not_equal_8) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  float fNum1 = -93482.4378;
  s21_from_int_to_decimal(fNum1, &value1);
  float fNum2 = -93482.4378;
  s21_from_int_to_decimal(fNum2, &value2);
  int state = s21_is_not_equal(value1, value2);
  int state2 = s21_is_not_equal(value2, value1);
  ck_assert_int_eq(state, FALSE);
  ck_assert_int_eq(state2, FALSE);
  ck_assert_int_eq(state, state2);
}
END_TEST

START_TEST(is_not_equal_9) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  int iNum1 = -0;
  s21_from_int_to_decimal(iNum1, &value1);
  int iNum2 = -0;
  s21_from_int_to_decimal(iNum2, &value2);
  int state = s21_is_not_equal(value1, value2);
  int state2 = s21_is_not_equal(value2, value1);
  ck_assert_int_eq(state, FALSE);
  ck_assert_int_eq(state2, FALSE);
  ck_assert_int_eq(state, state2);
}
END_TEST

Suite *test_is_not_equal() {
  Suite *s = suite_create(color_text("S21_IS_NOT_EQUAL"));
  TCase *tc = tcase_create("is_not_equal");

  tcase_add_test(tc, is_not_equal_1);
  tcase_add_test(tc, is_not_equal_2);
  tcase_add_test(tc, is_not_equal_3);
  tcase_add_test(tc, is_not_equal_4);
  tcase_add_test(tc, is_not_equal_5);
  tcase_add_test(tc, is_not_equal_6);
  tcase_add_test(tc, is_not_equal_7);
  tcase_add_test(tc, is_not_equal_8);
  tcase_add_test(tc, is_not_equal_9);

  suite_add_tcase(s, tc);
  return s;
}
