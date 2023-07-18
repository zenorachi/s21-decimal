#include "test_decimal.h"

START_TEST(is_less_1) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  int state = s21_is_less(value1, value2);
  int state2 = s21_is_less(value2, value1);
  ck_assert_int_eq(state, FALSE);
  ck_assert_int_eq(state2, FALSE);
  ck_assert_int_eq(state, state2);
}
END_TEST

START_TEST(is_less_2) {
  s21_decimal value1 = {{1, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  int state = s21_is_less(value1, value2);
  int state2 = s21_is_less(value2, value1);
  ck_assert_int_eq(state, FALSE);
  ck_assert_int_eq(state2, TRUE);
}
END_TEST

START_TEST(is_less_3) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  value1.bits[MID] = 1;
  value2.bits[LOW] = MAX_UINT;
  int state = s21_is_less(value1, value2);
  int state2 = s21_is_less(value2, value1);
  ck_assert_int_eq(state, FALSE);
  ck_assert_int_eq(state2, TRUE);
}
END_TEST

START_TEST(is_less_4) {
  s21_decimal dst1 = {{0, 1, 0, 0}}, dst2 = {{4294967295, 0, 0, 0}};
  float kek = 0;
  s21_from_decimal_to_float(dst1, &kek);
  float mem = 0;
  s21_from_decimal_to_float(dst2, &mem);
  ck_assert_int_eq(s21_is_less(dst1, dst2), FALSE);
  ck_assert_int_eq(s21_is_less(dst2, dst1), TRUE);
}
END_TEST

START_TEST(is_less_5) {
  s21_decimal dst1, dst2;
  s21_from_float_to_decimal(-1.21, &dst1);
  s21_from_float_to_decimal(-1.2, &dst2);
  ck_assert_int_eq(s21_is_less(dst1, dst2), TRUE);
  ck_assert_int_eq(s21_is_less(dst2, dst1), FALSE);
}
END_TEST

START_TEST(is_less_6) {
  s21_decimal dst1, dst2;
  s21_from_float_to_decimal(1.2345, &dst1);
  s21_from_float_to_decimal(-1.2, &dst2);
  ck_assert_int_eq(s21_is_less(dst1, dst2), FALSE);
  ck_assert_int_eq(s21_is_less(dst2, dst1), TRUE);
}
END_TEST

START_TEST(is_less_7) {
  s21_decimal dst1, dst2;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  ck_assert_int_eq(s21_is_less(dst1, dst2), FALSE);
}
END_TEST

START_TEST(is_less_8) {
  s21_decimal test_value_1 = {{5000, 0, 0, 0}};
  s21_decimal test_value_2 = {{5000, 0, 0, 2147483648}};
  int state1 = s21_is_less(test_value_1, test_value_2);
  ck_assert_int_eq(state1, FALSE);
  int state2 = s21_is_less(test_value_2, test_value_1);
  ck_assert_int_eq(state2, TRUE);
}
END_TEST

START_TEST(is_less_9) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  float fNum = 250.0;
  s21_from_float_to_decimal(fNum, &test_value_1);
  int iNum = 250;
  s21_from_int_to_decimal(iNum, &test_value_2);
  int state1 = s21_is_less(test_value_1, test_value_2);
  ck_assert_int_eq(state1, FALSE);
  int state2 = s21_is_less(test_value_2, test_value_1);
  ck_assert_int_eq(state2, FALSE);
}
END_TEST

START_TEST(is_less_10) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  float fNum = 250.001;
  s21_from_float_to_decimal(fNum, &test_value_1);
  int iNum = 250;
  s21_from_int_to_decimal(iNum, &test_value_2);
  int state1 = s21_is_less(test_value_1, test_value_2);
  ck_assert_int_eq(state1, FALSE);
  int state2 = s21_is_less(test_value_2, test_value_1);
  ck_assert_int_eq(state2, TRUE);
}
END_TEST

START_TEST(is_less_11) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  float fNum = -MAX_INT;
  s21_from_float_to_decimal(fNum, &test_value_1);
  int iNum = MAX_INT;
  s21_from_int_to_decimal(iNum, &test_value_2);
  int state1 = s21_is_less(test_value_1, test_value_2);
  ck_assert_int_eq(state1, TRUE);
  int state2 = s21_is_less(test_value_2, test_value_1);
  ck_assert_int_eq(state2, FALSE);
}
END_TEST

START_TEST(is_less_12) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  float fNum1 = -0.000011;
  s21_from_float_to_decimal(fNum1, &test_value_1);
  float fNum2 = -0.000012;
  s21_from_float_to_decimal(fNum2, &test_value_2);
  int state1 = s21_is_less(test_value_1, test_value_2);
  ck_assert_int_eq(state1, FALSE);
  int state2 = s21_is_less(test_value_2, test_value_1);
  ck_assert_int_eq(state2, TRUE);
}
END_TEST

START_TEST(is_less_0f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_1f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_2f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_3f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_4f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setSign(&val1);
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_5f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  setScale(&val1, 11);
  setScale(&val2, 10);
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_6f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  setScale(&val1, 10);
  setScale(&val2, 11);
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_7f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val2.bits[2] = 257;
  setSign(&val1);
  setSign(&val2);
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_8f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setSign(&val1);
  setSign(&val2);
  setBit(&val1.bits[HIGH], 83 % 32);
  setScale(&val1, 12);
  setScale(&val2, 11);
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_9f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setSign(&val1);
  setSign(&val2);
  setBit(&val1.bits[HIGH], 83 % 32);
  setBit(&val2.bits[HIGH], 83 % 32);
  setScale(&val1, 10);
  setScale(&val2, 11);
  int res = s21_is_less(val1, val2);
  ck_assert_int_eq(1, res);
}
END_TEST

START_TEST(is_less_10f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setSign(&val1);
  setSign(&val2);
  setBit(&val1.bits[HIGH], 83 % 32);
  setScale(&val1, 10);
  setScale(&val2, 10);
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_11f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setSign(&val1);
  delSign(&val2);
  setBit(&val1.bits[HIGH], 83 % 32);
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_12f) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setSign(&val1);
  delSign(&val2);
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

Suite *test_is_less() {
  Suite *s = suite_create(color_text("S21_IS_LESS"));
  TCase *tc = tcase_create("is_less");

  tcase_add_test(tc, is_less_1);
  tcase_add_test(tc, is_less_2);
  tcase_add_test(tc, is_less_3);
  tcase_add_test(tc, is_less_4);
  tcase_add_test(tc, is_less_5);
  tcase_add_test(tc, is_less_6);
  tcase_add_test(tc, is_less_7);
  tcase_add_test(tc, is_less_8);
  tcase_add_test(tc, is_less_9);
  tcase_add_test(tc, is_less_10);
  tcase_add_test(tc, is_less_11);
  tcase_add_test(tc, is_less_12);

  tcase_add_test(tc, is_less_0f);
  tcase_add_test(tc, is_less_1f);
  tcase_add_test(tc, is_less_2f);
  tcase_add_test(tc, is_less_3f);
  tcase_add_test(tc, is_less_4f);
  tcase_add_test(tc, is_less_5f);
  tcase_add_test(tc, is_less_6f);
  tcase_add_test(tc, is_less_7f);
  tcase_add_test(tc, is_less_8f);
  tcase_add_test(tc, is_less_9f);
  tcase_add_test(tc, is_less_10f);
  tcase_add_test(tc, is_less_11f);
  tcase_add_test(tc, is_less_12f);
  suite_add_tcase(s, tc);
  return s;
}
