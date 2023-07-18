#include "test_decimal.h"

START_TEST(truncate_1) {
  s21_decimal src = {{157, 0, 0, 0}};
  setScale(&src, 1);
  decreaseScale(&src);
  s21_decimal res = {{0, 0, 0, 0}};
  int state = s21_truncate(src, &res);
  ck_assert_int_eq(state, OK);
  ck_assert_int_eq(15, res.bits[LOW]);
}
END_TEST

START_TEST(truncate_2) {
  s21_decimal src = {{MAX_UINT, 0, 0, 0}};
  setScale(&src, 5);
  decreaseScale(&src);
  s21_decimal res = {{0, 0, 0, 0}};
  int state = s21_truncate(src, &res);
  ck_assert_int_eq(state, OK);
  ck_assert_int_eq(42949, res.bits[LOW]);
}
END_TEST

START_TEST(truncate_3) {
  s21_decimal src = {
      {MAX_UINT, 1, 0, 0}};  // (4294967296 + 4294967295) / 10^5 = 85899.34591
  setScale(&src, 5);
  decreaseScale(&src);
  s21_decimal res = {{0, 0, 0, 0}};
  int state = s21_truncate(src, &res);
  int test = 0;
  s21_from_decimal_to_int(res, &test);
  ck_assert_int_eq(state, OK);
  ck_assert_int_eq(85899, res.bits[LOW]);
}
END_TEST

START_TEST(truncate_0f) {
  s21_decimal val = {{7, 7, 7, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 129127208515966861312.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_1f) {
  s21_decimal val = {{2, 0, 0, ~(MAX_UINT / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = -2.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_2f) {
  s21_decimal val = {{2, 0, 0, ~(MAX_UINT / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = -2.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_3f) {
  s21_decimal val = {{2, 0, 0, ~(MAX_UINT / 2)}};
  s21_decimal res = {0};
  setScale(&val, 5);
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = -0.0;
  ck_assert_float_eq(need, fres);
}

START_TEST(truncate_4f) {
  s21_decimal val = {{128, 0, 0, 0}};
  s21_decimal res = {0};
  setScale(&val, 1);
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 12;
  ck_assert_float_eq(need, fres);
}

START_TEST(truncate_5f) {
  s21_decimal decimal = {0};
  float num = 111108940.3434;
  s21_from_float_to_decimal(num, &decimal);
  s21_decimal dst = {0};
  int state2 = s21_truncate(decimal, &dst);
  ck_assert_int_eq(state2, OK);
  float test = 0;
  s21_from_decimal_to_float(dst, &test);
  ck_assert_float_eq(test, num);
}
END_TEST

START_TEST(truncate_6f) {
  s21_decimal decimal = {0};
  float num = -MAX_UINT * 13.43;
  s21_from_float_to_decimal(num, &decimal);
  s21_decimal dst = {0};
  int state2 = s21_truncate(decimal, &dst);
  ck_assert_int_eq(state2, OK);
  float test = 0;
  s21_from_decimal_to_float(dst, &test);
  ck_assert_float_eq(test, num);
}
END_TEST

START_TEST(truncate_7f) {
  s21_decimal decimal = {0};
  float num = 92000108940.0;
  s21_from_float_to_decimal(num, &decimal);
  s21_decimal *dst = NULL;
  int state2 = s21_truncate(decimal, dst);
  ck_assert_int_eq(state2, 1);
}
END_TEST

START_TEST(truncate_8f) {
  s21_decimal decimal = {0};
  int num = MAX_UINT / 2;
  s21_from_int_to_decimal(num, &decimal);
  s21_decimal dst = {0};
  int state2 = s21_truncate(decimal, &dst);
  ck_assert_int_eq(state2, OK);
  int test = 0;
  s21_from_decimal_to_int(dst, &test);
  ck_assert_float_eq(test, num);
}
END_TEST

START_TEST(truncate_9f) {
  s21_decimal decimal = {0};
  int num = MAX_UINT / 2;
  s21_from_int_to_decimal(num, &decimal);
  s21_decimal dst = {0};
  int state2 = s21_truncate(decimal, &dst);
  ck_assert_int_eq(state2, OK);
  int test = 0;
  setSign(&dst);
  s21_from_decimal_to_int(dst, &test);
  ck_assert_float_eq(test, -num);
}
END_TEST

START_TEST(truncate_10f) {
  s21_decimal decimal = {0};
  int num = 0;
  s21_from_int_to_decimal(num, &decimal);
  s21_decimal dst = {0};
  int state2 = s21_truncate(decimal, &dst);
  ck_assert_int_eq(state2, OK);
  int test = 0;
  s21_from_decimal_to_int(dst, &test);
  ck_assert_float_eq(test, -num);
}
END_TEST

START_TEST(truncate_11f) {
  s21_decimal decimal = {0};
  s21_decimal *result = NULL;
  int state = s21_truncate(decimal, result);
  ck_assert_int_eq(state, 1);
}
END_TEST

Suite *test_truncate() {
  Suite *s = suite_create(color_text("S21_TRUNCATE"));
  TCase *tc = tcase_create("truncate_test");

  tcase_add_test(tc, truncate_1);
  tcase_add_test(tc, truncate_2);
  tcase_add_test(tc, truncate_3);
  tcase_add_test(tc, truncate_0f);
  tcase_add_test(tc, truncate_1f);
  tcase_add_test(tc, truncate_2f);
  tcase_add_test(tc, truncate_3f);
  tcase_add_test(tc, truncate_4f);
  tcase_add_test(tc, truncate_5f);
  tcase_add_test(tc, truncate_6f);
  tcase_add_test(tc, truncate_7f);
  tcase_add_test(tc, truncate_8f);
  tcase_add_test(tc, truncate_9f);
  tcase_add_test(tc, truncate_10f);
  tcase_add_test(tc, truncate_11f);

  suite_add_tcase(s, tc);
  return s;
}
