#include "test_decimal.h"

START_TEST(floor_1) {
  s21_decimal src = {{157, 0, 0, 0}};
  setScale(&src, 1);
  decreaseScale(&src);
  s21_decimal res = {{0, 0, 0, 0}};
  int state = s21_floor(src, &res);
  ck_assert_int_eq(state, OK);
  ck_assert_int_eq(15, res.bits[LOW]);
}
END_TEST

START_TEST(floor_2) {
  s21_decimal src = {{MAX_UINT, 0, 0, 0}};
  setScale(&src, 5);
  decreaseScale(&src);
  s21_decimal res = {{0, 0, 0, 0}};
  int state = s21_floor(src, &res);
  ck_assert_int_eq(state, OK);
  ck_assert_int_eq(42949, res.bits[LOW]);
}
END_TEST

START_TEST(floor_3) {
  s21_decimal src = {
      {MAX_UINT, 1, 0, 0}};  // (4294967296 + 4294967295) / 10^5 = 85899.34591
  setScale(&src, 5);
  decreaseScale(&src);
  s21_decimal res = {{0, 0, 0, 0}};
  int state = s21_floor(src, &res);
  int test = 0;
  s21_from_decimal_to_int(res, &test);
  ck_assert_int_eq(state, OK);
  ck_assert_int_eq(85899, res.bits[LOW]);
}
END_TEST

START_TEST(floor_0f) {
  s21_decimal val = {{7, 7, 7, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_floor(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 129127208515966861312.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(floor_1f) {
  s21_decimal val = {{21, 0, 0, 0}};
  setScale(&val, 1);
  setSign(&val);
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_floor(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = -3.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(floor_2f) {
  s21_decimal val = {{4334341, 0, 0, 0}};
  setScale(&val, 1);
  setSign(&val);
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_floor(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = -433435;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(floor_4f) {
  s21_decimal val = {{128, 0, 0, 0}};
  s21_decimal res = {0};
  setScale(&val, 1);
  ck_assert_int_eq(0, s21_floor(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 12;
  ck_assert_float_eq(need, fres);
}

START_TEST(floor_8f) {
  s21_decimal decimal = {0};
  int num = MAX_UINT / 2;
  s21_from_int_to_decimal(num, &decimal);
  s21_decimal dst = {0};
  int state2 = s21_floor(decimal, &dst);
  ck_assert_int_eq(state2, OK);
  int test = 0;
  s21_from_decimal_to_int(dst, &test);
  ck_assert_float_eq(test, num);
}
END_TEST

START_TEST(floor_9f) {
  s21_decimal decimal = {0};
  int num = MAX_UINT / 2;
  s21_from_int_to_decimal(num, &decimal);
  s21_decimal dst = {0};
  int state2 = s21_floor(decimal, &dst);
  ck_assert_int_eq(state2, OK);
  int test = 0;
  setSign(&dst);
  s21_from_decimal_to_int(dst, &test);
  ck_assert_float_eq(test, -num);
}
END_TEST

START_TEST(floor_10f) {
  s21_decimal decimal = {0};
  int num = 0;
  s21_from_int_to_decimal(num, &decimal);
  s21_decimal dst = {0};
  int state2 = s21_floor(decimal, &dst);
  ck_assert_int_eq(state2, OK);
  int test = 0;
  s21_from_decimal_to_int(dst, &test);
  ck_assert_float_eq(test, -num);
}
END_TEST

START_TEST(floor_11f) {
  s21_decimal decimal = {0};
  s21_decimal *result = NULL;
  int state = s21_floor(decimal, result);
  ck_assert_int_eq(state, 1);
}
END_TEST

START_TEST(test_s21_floor_1) {
  s21_decimal value_1 = {{673988, 0, 0, 262144}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_floor(value_1, &result);
  ck_assert_float_eq(result.bits[0], 67);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_floor_2) {
  s21_decimal value_1 = {{679988, 0, 0, 262144}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_floor(value_1, &result);
  ck_assert_float_eq(result.bits[0], 67);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_floor_3) {
  s21_decimal value_1 = {{679988, 0, 0, 2147745796}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_floor(value_1, &result);
  ck_assert_float_eq(result.bits[0], 68);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(test_s21_floor_4) {
  s21_decimal value_1 = {{2555, 0, 0, 0}};
  setScale(&value_1, 2);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_floor(value_1, &result);
  ck_assert_float_eq(result.bits[0], 25);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

Suite *test_floor() {
  Suite *s = suite_create(color_text("S21_FLOOR"));
  TCase *tc = tcase_create("floor_test");

  tcase_add_test(tc, floor_1);
  tcase_add_test(tc, floor_2);
  tcase_add_test(tc, floor_3);

  tcase_add_test(tc, floor_0f);
  tcase_add_test(tc, floor_1f);
  tcase_add_test(tc, floor_2f);
  tcase_add_test(tc, floor_4f);
  tcase_add_test(tc, floor_8f);
  tcase_add_test(tc, floor_9f);
  tcase_add_test(tc, floor_10f);
  tcase_add_test(tc, floor_11f);

  tcase_add_test(tc, test_s21_floor_1);
  tcase_add_test(tc, test_s21_floor_2);
  tcase_add_test(tc, test_s21_floor_3);
  tcase_add_test(tc, test_s21_floor_4);

  suite_add_tcase(s, tc);
  return s;
}
