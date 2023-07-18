#include "test_decimal.h"

START_TEST(is_greater_1) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  int state = s21_is_greater(value1, value2);
  int state2 = s21_is_greater(value2, value1);
  ck_assert_int_eq(state, FALSE);
  ck_assert_int_eq(state2, FALSE);
  ck_assert_int_eq(state, state2);
}
END_TEST

START_TEST(is_greater_2) {
  s21_decimal value1 = {{1, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  int state = s21_is_greater(value1, value2);
  int state2 = s21_is_greater(value2, value1);
  ck_assert_int_eq(state, TRUE);
  ck_assert_int_eq(state2, FALSE);
}
END_TEST

START_TEST(is_greater_3) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  value1.bits[MID] = 1;
  value2.bits[LOW] = MAX_UINT;
  int state = s21_is_greater(value1, value2);
  int state2 = s21_is_greater(value2, value1);
  ck_assert_int_eq(state, TRUE);
  ck_assert_int_eq(state2, FALSE);
}
END_TEST

START_TEST(is_greater_4) {
  s21_decimal dst1 = {{0, 1, 0, 0}}, dst2 = {{4294967295, 0, 0, 0}};
  float kek = 0;
  s21_from_decimal_to_float(dst1, &kek);
  float mem = 0;
  s21_from_decimal_to_float(dst2, &mem);
  ck_assert_int_eq(s21_is_greater(dst1, dst2), 1);
  ck_assert_int_eq(s21_is_greater(dst2, dst1), 0);
}
END_TEST

START_TEST(is_greater_5) {
  s21_decimal dst1, dst2;
  s21_from_float_to_decimal(-1.21, &dst1);
  s21_from_float_to_decimal(-1.2, &dst2);
  ck_assert_int_eq(s21_is_greater(dst1, dst2), 0);
  ck_assert_int_eq(s21_is_greater(dst2, dst1), 1);
}
END_TEST

START_TEST(is_greater_6) {
  s21_decimal dst1, dst2;
  s21_from_float_to_decimal(1.2345, &dst1);
  s21_from_float_to_decimal(-1.2, &dst2);
  ck_assert_int_eq(s21_is_greater(dst1, dst2), 1);
  ck_assert_int_eq(s21_is_greater(dst2, dst1), 0);
}
END_TEST

START_TEST(is_greater_7) {
  s21_decimal dst1, dst2;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  ck_assert_int_eq(s21_is_greater(dst1, dst2), 0);
}
END_TEST

START_TEST(is_greater_8) {
  s21_decimal test_value_1 = {{5000, 0, 0, 0}};
  s21_decimal test_value_2 = {{5000, 0, 0, 2147483648}};
  int state1 = s21_is_greater(test_value_1, test_value_2);
  ck_assert_int_eq(state1, TRUE);
  int state2 = s21_is_greater(test_value_2, test_value_1);
  ck_assert_int_eq(state2, FALSE);
}
END_TEST

START_TEST(is_greater_9) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  float fNum = 250.0;
  s21_from_float_to_decimal(fNum, &test_value_1);
  int iNum = 250;
  s21_from_int_to_decimal(iNum, &test_value_2);
  int state1 = s21_is_greater(test_value_1, test_value_2);
  ck_assert_int_eq(state1, FALSE);
  int state2 = s21_is_greater(test_value_2, test_value_1);
  ck_assert_int_eq(state2, FALSE);
}
END_TEST

START_TEST(is_greater_10) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  float fNum = 250.001;
  s21_from_float_to_decimal(fNum, &test_value_1);
  int iNum = 250;
  s21_from_int_to_decimal(iNum, &test_value_2);
  int state1 = s21_is_greater(test_value_1, test_value_2);
  ck_assert_int_eq(state1, TRUE);
  int state2 = s21_is_greater(test_value_2, test_value_1);
  ck_assert_int_eq(state2, FALSE);
}
END_TEST

START_TEST(is_greater_11) {
  s21_decimal test_value_1 = {{1434, 0, 0, 0}};
  setScale(&test_value_1, 1);
  s21_decimal test_value_2 = {{14343434, 0, 0, 0}};
  setScale(&test_value_2, 6);
  int state1 = s21_is_greater(test_value_1, test_value_2);
  ck_assert_int_eq(state1, TRUE);
  int state2 = s21_is_greater(test_value_2, test_value_1);
  ck_assert_int_eq(state2, FALSE);
}
END_TEST

START_TEST(is_greater_0f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_1f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_2f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_3f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_4f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setSign(&val1);
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_5f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  setScale(&val1, 11);
  setScale(&val2, 10);
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_6f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  setScale(&val1, 10);
  setScale(&val2, 11);
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_7f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val2.bits[2] = 257;
  setSign(&val1);
  setSign(&val2);
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_8f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val2.bits[2] = 257;
  setSign(&val1);
  delSign(&val1);
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

Suite *test_is_greater() {
  Suite *s = suite_create(color_text("S21_IS_GREATER"));
  TCase *tc = tcase_create("is_greater");

  tcase_add_test(tc, is_greater_1);
  tcase_add_test(tc, is_greater_2);
  tcase_add_test(tc, is_greater_3);
  tcase_add_test(tc, is_greater_4);
  tcase_add_test(tc, is_greater_5);
  tcase_add_test(tc, is_greater_6);
  tcase_add_test(tc, is_greater_7);
  tcase_add_test(tc, is_greater_8);
  tcase_add_test(tc, is_greater_9);
  tcase_add_test(tc, is_greater_10);
  tcase_add_test(tc, is_greater_11);

  tcase_add_test(tc, is_greater_0f);
  tcase_add_test(tc, is_greater_1f);
  tcase_add_test(tc, is_greater_2f);
  tcase_add_test(tc, is_greater_3f);
  tcase_add_test(tc, is_greater_4f);
  tcase_add_test(tc, is_greater_5f);
  tcase_add_test(tc, is_greater_6f);
  tcase_add_test(tc, is_greater_7f);
  tcase_add_test(tc, is_greater_8f);

  suite_add_tcase(s, tc);
  return s;
}
