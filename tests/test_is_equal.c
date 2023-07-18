#include "test_decimal.h"

START_TEST(is_equal_1) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  int state = s21_is_equal(value1, value2);
  int state2 = s21_is_equal(value2, value1);
  ck_assert_int_eq(state, TRUE);
  ck_assert_int_eq(state2, TRUE);
  ck_assert_int_eq(state, state2);
}
END_TEST

START_TEST(is_equal_2) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  setSign(&value2);
  int state = s21_is_equal(value1, value2);
  int state2 = s21_is_equal(value2, value1);
  ck_assert_int_eq(state, TRUE);
  ck_assert_int_eq(state2, TRUE);
  ck_assert_int_eq(state, state2);
}
END_TEST

START_TEST(is_equal_3) {
  s21_decimal value1 = {{MAX_UINT, MAX_UINT, 0, MAX_INT}};
  s21_decimal value2 = {{MAX_UINT, MAX_UINT, 0, MAX_INT}};
  int state = s21_is_equal(value1, value2);
  int state2 = s21_is_equal(value2, value1);
  ck_assert_int_eq(state, TRUE);
  ck_assert_int_eq(state2, TRUE);
  ck_assert_int_eq(state, state2);
}
END_TEST

START_TEST(is_equal_4) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  float fNum = 4399438.0;
  s21_from_float_to_decimal(fNum, &value1);
  int iNum = 4399438;
  s21_from_int_to_decimal(iNum, &value2);
  int state = s21_is_equal(value1, value2);
  int state2 = s21_is_equal(value2, value1);
  ck_assert_int_eq(state, TRUE);
  ck_assert_int_eq(state2, TRUE);
  ck_assert_int_eq(state, state2);
}
END_TEST

START_TEST(is_equal_5) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  float fNum = 4399438.9;
  s21_from_float_to_decimal(fNum, &value1);
  int iNum = 4399438;
  s21_from_int_to_decimal(iNum, &value2);
  int state = s21_is_equal(value1, value2);
  int state2 = s21_is_equal(value2, value1);
  ck_assert_int_eq(state, FALSE);
  ck_assert_int_eq(state2, FALSE);
  ck_assert_int_eq(state, state2);
}
END_TEST

START_TEST(is_equal_6) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  float fNum = -2281337.0;
  s21_from_float_to_decimal(fNum, &value1);
  int iNum = -2281337;
  s21_from_int_to_decimal(iNum, &value2);
  int state = s21_is_equal(value1, value2);
  int state2 = s21_is_equal(value2, value1);
  ck_assert_int_eq(state, TRUE);
  ck_assert_int_eq(state2, TRUE);
  ck_assert_int_eq(state, state2);
}
END_TEST

START_TEST(is_equal_7) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  int iNum1 = -2281337;
  s21_from_int_to_decimal(iNum1, &value1);
  int iNum2 = -432281337;
  s21_from_int_to_decimal(iNum2, &value2);
  int state = s21_is_equal(value1, value2);
  int state2 = s21_is_equal(value2, value1);
  ck_assert_int_eq(state, FALSE);
  ck_assert_int_eq(state2, FALSE);
  ck_assert_int_eq(state, state2);
}
END_TEST

START_TEST(is_equal_8) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  float fNum1 = -93482.4378;
  s21_from_int_to_decimal(fNum1, &value1);
  float fNum2 = -93482.4378;
  s21_from_int_to_decimal(fNum2, &value2);
  int state = s21_is_equal(value1, value2);
  int state2 = s21_is_equal(value2, value1);
  ck_assert_int_eq(state, TRUE);
  ck_assert_int_eq(state2, TRUE);
  ck_assert_int_eq(state, state2);
}
END_TEST

START_TEST(is_equal_9) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  int iNum1 = -0;
  s21_from_int_to_decimal(iNum1, &value1);
  int iNum2 = -0;
  s21_from_int_to_decimal(iNum2, &value2);
  int state = s21_is_equal(value1, value2);
  int state2 = s21_is_equal(value2, value1);
  ck_assert_int_eq(state, TRUE);
  ck_assert_int_eq(state2, TRUE);
  ck_assert_int_eq(state, state2);
}
END_TEST

START_TEST(is_equal_10) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  float fNum = 250.0;
  s21_from_float_to_decimal(fNum, &test_value_1);
  int iNum = 250;
  s21_from_int_to_decimal(iNum, &test_value_2);
  int state1 = s21_is_equal(test_value_1, test_value_2);
  ck_assert_int_eq(state1, TRUE);
  int state2 = s21_is_equal(test_value_2, test_value_1);
  ck_assert_int_eq(state2, TRUE);
}
END_TEST

START_TEST(is_equal_11) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  float fNum = 250.001;
  s21_from_float_to_decimal(fNum, &test_value_1);
  int iNum = 250;
  s21_from_int_to_decimal(iNum, &test_value_2);
  int state1 = s21_is_equal(test_value_1, test_value_2);
  ck_assert_int_eq(state1, FALSE);
  int state2 = s21_is_equal(test_value_2, test_value_1);
  ck_assert_int_eq(state2, FALSE);
}
END_TEST

START_TEST(is_equal_0f) {
  s21_decimal val1 = {{0, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  setSign(&val2);
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_1f) {
  s21_decimal val1 = {{0, 0, 0, 0}};
  s21_decimal val2 = {{3, 0, 0, 0}};
  ck_assert_int_eq(0, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_2f) {
  s21_decimal val1 = {{15, 15, 0, 0}};
  s21_decimal val2 = {{15, 15, 0, 0}};
  setSign(&val2);
  ck_assert_int_eq(0, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_3f) {
  s21_decimal val1 = {{12, 0, 0, 0}};
  s21_decimal val2 = {{12, 0, 0, 0}};
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_4f) {
  s21_decimal val1 = {{0b00000000000000000000000000000100, 0, 0, 0}};
  s21_decimal val2 = {{0b00000000000000000000000000001000, 0, 0, 0}};
  ck_assert_int_eq(0, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_5f) {
  s21_decimal val1 = {{0b00000000000100000000000000000000, 0, 0, 0}};
  s21_decimal val2 = {{0b00000000000100000000000000000000, 0, 0, 0}};
  setScale(&val1, 3);
  setScale(&val2, 3);
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_6f) {
  s21_decimal val1 = {{0b00000000000000000000000000000100, 0, 0, 0}};
  s21_decimal val2 = {{0b00000000000000000000000000001000, 0, 0, 0}};
  setScale(&val1, 3);
  setScale(&val2, 3);
  ck_assert_int_eq(0, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_7f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setScale(&val1, 3);
  setScale(&val2, 2);
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_8f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

Suite *test_is_equal() {
  Suite *s = suite_create(color_text("S21_IS_EQUAL"));
  TCase *tc = tcase_create("is_equal");

  tcase_add_test(tc, is_equal_1);
  tcase_add_test(tc, is_equal_2);
  tcase_add_test(tc, is_equal_3);
  tcase_add_test(tc, is_equal_4);
  tcase_add_test(tc, is_equal_5);
  tcase_add_test(tc, is_equal_6);
  tcase_add_test(tc, is_equal_7);
  tcase_add_test(tc, is_equal_8);
  tcase_add_test(tc, is_equal_9);
  tcase_add_test(tc, is_equal_10);
  tcase_add_test(tc, is_equal_11);

  tcase_add_test(tc, is_equal_0f);
  tcase_add_test(tc, is_equal_1f);
  tcase_add_test(tc, is_equal_2f);
  tcase_add_test(tc, is_equal_3f);
  tcase_add_test(tc, is_equal_4f);
  tcase_add_test(tc, is_equal_5f);
  tcase_add_test(tc, is_equal_6f);
  tcase_add_test(tc, is_equal_7f);
  tcase_add_test(tc, is_equal_8f);
  suite_add_tcase(s, tc);
  return s;
}
