#include "test_decimal.h"

START_TEST(round_1) {
  s21_decimal value_1 = {{5, 0, 1, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(value_1, &result);
  ck_assert_float_eq(result.bits[0], 5);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 1);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(round_2) {
  s21_decimal value_1 = {{155, 1, 1, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(value_1, &result);
  ck_assert_float_eq(result.bits[0], 155);
  ck_assert_float_eq(result.bits[1], 1);
  ck_assert_float_eq(result.bits[2], 1);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(round_3) {
  s21_decimal value_1 = {{155, 1, 1, 2147483648}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(value_1, &result);
  ck_assert_float_eq(result.bits[0], 155);
  ck_assert_float_eq(result.bits[1], 1);
  ck_assert_float_eq(result.bits[2], 1);
  ck_assert_float_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(round_4) {
  s21_decimal value_1 = {{0, 1, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(value_1, &result);
  ck_assert_float_eq(result.bits[0], 0);
  ck_assert_float_eq(result.bits[1], 1);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(round_5) {
  s21_decimal value_1 = {{2555, 0, 0, 0}};
  setScale(&value_1, 2);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(value_1, &result);
  ck_assert_float_eq(result.bits[0], 26);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(round_6) {
  s21_decimal val = {{7, 7, 7, 0}};
  s21_decimal res = {0};
  s21_round(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 129127208515966861312.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(round_7) {
  s21_decimal val = {{3, 3, 3, ~(MAX_UINT / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(round_8) {
  s21_decimal val = {{128, 0, 0, 0}};
  s21_decimal res = {0};
  setScale(&val, 1);
  s21_round(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 13;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(round_9) {
  s21_decimal val = {{53455, 0, 0, 0}};
  s21_decimal res = {0};
  setScale(&val, 1);
  setSign(&val);
  s21_round(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = -5346.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(round_10) {
  s21_decimal val = {{53455, 0, 0, 0}};
  s21_decimal res = {0};
  setScale(&val, 1);
  s21_round(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 5346.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(round_11) {
  s21_decimal val = {{435, 0, 0, 0}};
  s21_decimal res = {0};
  setScale(&val, 1);
  setSign(&val);
  s21_round(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = -44;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(round_12) {
  s21_decimal val = {{534593545, 0, 0, 0}};
  s21_decimal res = {0};
  setScale(&val, 1);
  s21_round(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 53459355.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(round_13) {
  s21_decimal val = {0};
  s21_decimal *res = NULL;
  setScale(&val, 1);
  int state = s21_round(val, res);
  ck_assert_int_eq(state, 1);
}
END_TEST

Suite *test_round() {
  Suite *s = suite_create(color_text("S21_ROUND"));
  TCase *tc = tcase_create("round");

  tcase_add_test(tc, round_1);
  tcase_add_test(tc, round_2);
  tcase_add_test(tc, round_3);
  tcase_add_test(tc, round_4);
  tcase_add_test(tc, round_5);
  tcase_add_test(tc, round_6);
  tcase_add_test(tc, round_7);
  tcase_add_test(tc, round_8);
  tcase_add_test(tc, round_9);
  tcase_add_test(tc, round_10);
  tcase_add_test(tc, round_11);
  tcase_add_test(tc, round_12);
  tcase_add_test(tc, round_13);

  suite_add_tcase(s, tc);
  return s;
}
