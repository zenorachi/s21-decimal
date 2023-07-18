#include "test_decimal.h"

START_TEST(is_less_or_equal_1) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  int state = s21_is_less_or_equal(value1, value2);
  int state2 = s21_is_less_or_equal(value2, value1);
  ck_assert_int_eq(state, TRUE);
  ck_assert_int_eq(state2, TRUE);
  ck_assert_int_eq(state, state2);
}
END_TEST

START_TEST(is_less_or_equal_2) {
  s21_decimal value1 = {{1, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  int state = s21_is_less_or_equal(value1, value2);
  int state2 = s21_is_less_or_equal(value2, value1);
  ck_assert_int_eq(state, FALSE);
  ck_assert_int_eq(state2, TRUE);
}
END_TEST

START_TEST(is_less_or_equal_3) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  value1.bits[MID] = 1;
  value2.bits[LOW] = MAX_UINT;
  int state = s21_is_less_or_equal(value1, value2);
  int state2 = s21_is_less_or_equal(value2, value1);
  ck_assert_int_eq(state, FALSE);
  ck_assert_int_eq(state2, TRUE);
}
END_TEST

START_TEST(is_less_or_equal_4) {
  s21_decimal dst1 = {{0, 1, 0, 0}}, dst2 = {{4294967295, 0, 0, 0}};
  float kek = 0;
  s21_from_decimal_to_float(dst1, &kek);
  float mem = 0;
  s21_from_decimal_to_float(dst2, &mem);
  ck_assert_int_eq(s21_is_less_or_equal(dst1, dst2), FALSE);
  ck_assert_int_eq(s21_is_less_or_equal(dst2, dst1), TRUE);
}
END_TEST

START_TEST(is_less_or_equal_5) {
  s21_decimal dst1, dst2;
  s21_from_float_to_decimal(-1.21, &dst1);
  s21_from_float_to_decimal(-1.2, &dst2);
  ck_assert_int_eq(s21_is_less_or_equal(dst1, dst2), TRUE);
  ck_assert_int_eq(s21_is_less_or_equal(dst2, dst1), FALSE);
}
END_TEST

START_TEST(is_less_or_equal_6) {
  s21_decimal dst1, dst2;
  s21_from_float_to_decimal(1.2345, &dst1);
  s21_from_float_to_decimal(-1.2, &dst2);
  ck_assert_int_eq(s21_is_less_or_equal(dst1, dst2), FALSE);
  ck_assert_int_eq(s21_is_less_or_equal(dst2, dst1), TRUE);
}
END_TEST

START_TEST(is_less_or_equal_7) {
  s21_decimal dst1, dst2;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  ck_assert_int_eq(s21_is_less_or_equal(dst1, dst2), TRUE);
}
END_TEST

START_TEST(is_less_or_equal_8) {
  s21_decimal test_value_1 = {{5000, 0, 0, 0}};
  s21_decimal test_value_2 = {{5000, 0, 0, 2147483648}};
  int state1 = s21_is_less_or_equal(test_value_1, test_value_2);
  ck_assert_int_eq(state1, FALSE);
  int state2 = s21_is_less_or_equal(test_value_2, test_value_1);
  ck_assert_int_eq(state2, TRUE);
}
END_TEST

START_TEST(is_less_or_equal_9) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  float fNum = 250.0;
  s21_from_float_to_decimal(fNum, &test_value_1);
  int iNum = 250;
  s21_from_int_to_decimal(iNum, &test_value_2);
  int state1 = s21_is_less_or_equal(test_value_1, test_value_2);
  ck_assert_int_eq(state1, TRUE);
  int state2 = s21_is_less_or_equal(test_value_2, test_value_1);
  ck_assert_int_eq(state2, TRUE);
}
END_TEST

START_TEST(is_less_or_equal_10) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  float fNum = 250.001;
  s21_from_float_to_decimal(fNum, &test_value_1);
  int iNum = 250;
  s21_from_int_to_decimal(iNum, &test_value_2);
  int state1 = s21_is_less_or_equal(test_value_1, test_value_2);
  ck_assert_int_eq(state1, FALSE);
  int state2 = s21_is_less_or_equal(test_value_2, test_value_1);
  ck_assert_int_eq(state2, TRUE);
}
END_TEST

START_TEST(is_less_or_equal_11) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  float fNum = -MAX_INT;
  s21_from_float_to_decimal(fNum, &test_value_1);
  int iNum = MAX_INT;
  s21_from_int_to_decimal(iNum, &test_value_2);
  int state1 = s21_is_less_or_equal(test_value_1, test_value_2);
  ck_assert_int_eq(state1, TRUE);
  int state2 = s21_is_less_or_equal(test_value_2, test_value_1);
  ck_assert_int_eq(state2, FALSE);
}
END_TEST

START_TEST(is_less_or_equal_12) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  float fNum1 = -0.000011;
  s21_from_float_to_decimal(fNum1, &test_value_1);
  float fNum2 = -0.000012;
  s21_from_float_to_decimal(fNum2, &test_value_2);
  int state1 = s21_is_less_or_equal(test_value_1, test_value_2);
  ck_assert_int_eq(state1, FALSE);
  int state2 = s21_is_less_or_equal(test_value_2, test_value_1);
  ck_assert_int_eq(state2, TRUE);
}
END_TEST

START_TEST(is_less_or_equal_13) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  float fNum1 = -0.000011;
  s21_from_float_to_decimal(fNum1, &test_value_1);
  float fNum2 = -0.000011;
  s21_from_float_to_decimal(fNum2, &test_value_2);
  int state1 = s21_is_less_or_equal(test_value_1, test_value_2);
  ck_assert_int_eq(state1, TRUE);
  int state2 = s21_is_less_or_equal(test_value_2, test_value_1);
  ck_assert_int_eq(state2, TRUE);
}
END_TEST

START_TEST(is_less_or_equal_14) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  float fNum1 = -0.0;
  s21_from_float_to_decimal(fNum1, &test_value_1);
  float fNum2 = 0.0;
  s21_from_float_to_decimal(fNum2, &test_value_2);
  int state1 = s21_is_less_or_equal(test_value_1, test_value_2);
  ck_assert_int_eq(state1, TRUE);
  int state2 = s21_is_less_or_equal(test_value_2, test_value_1);
  ck_assert_int_eq(state2, TRUE);
}
END_TEST

Suite *test_is_less_or_equal() {
  Suite *s = suite_create(color_text("S21_IS_LESS_OR_EQUAL"));
  TCase *tc = tcase_create("is_less_or_equal");

  tcase_add_test(tc, is_less_or_equal_1);
  tcase_add_test(tc, is_less_or_equal_2);
  tcase_add_test(tc, is_less_or_equal_3);
  tcase_add_test(tc, is_less_or_equal_4);
  tcase_add_test(tc, is_less_or_equal_5);
  tcase_add_test(tc, is_less_or_equal_6);
  tcase_add_test(tc, is_less_or_equal_7);
  tcase_add_test(tc, is_less_or_equal_8);
  tcase_add_test(tc, is_less_or_equal_9);
  tcase_add_test(tc, is_less_or_equal_10);
  tcase_add_test(tc, is_less_or_equal_11);
  tcase_add_test(tc, is_less_or_equal_12);
  tcase_add_test(tc, is_less_or_equal_13);
  tcase_add_test(tc, is_less_or_equal_14);

  suite_add_tcase(s, tc);
  return s;
}
