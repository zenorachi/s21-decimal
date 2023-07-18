#include "test_decimal.h"

START_TEST(from_float_to_decimal_1) {
  s21_decimal decimal = {0};
  float num = 92000108940.0;
  int state = s21_from_float_to_decimal(num, &decimal);
  ck_assert_int_eq(state, OK);
  float test = 0;
  int result = s21_from_decimal_to_float(decimal, &test);
  ck_assert_int_eq(result, OK);
  ck_assert_float_eq(test, num);
}
END_TEST

START_TEST(from_float_to_decimal_2) {
  s21_decimal decimal = {0};
  float num = 17.000000000000;
  int state = s21_from_float_to_decimal(num, &decimal);
  ck_assert_int_eq(state, OK);
  float test = 0;
  int result = s21_from_decimal_to_float(decimal, &test);
  ck_assert_int_eq(result, OK);
  ck_assert_float_eq(test, num);
}
END_TEST

START_TEST(from_float_to_decimal_3) {
  s21_decimal decimal = {0};
  float num = 1743839.0;
  int state = s21_from_float_to_decimal(num, &decimal);
  ck_assert_int_eq(state, OK);
  float test = 0;
  int result = s21_from_decimal_to_float(decimal, &test);
  ck_assert_int_eq(result, OK);
  ck_assert_float_eq(test, num);
}
END_TEST

START_TEST(from_float_to_decimal_4) {
  s21_decimal decimal = {0};
  float num = 3849 * 1090009.0;
  int state = s21_from_float_to_decimal(num, &decimal);
  ck_assert_int_eq(state, OK);
  float test = 0;
  int result = s21_from_decimal_to_float(decimal, &test);
  ck_assert_int_eq(result, OK);
  ck_assert_float_eq(test, num);
}
END_TEST

START_TEST(from_float_to_decimal_5) {
  s21_decimal decimal = {0};
  float num = -10.0;
  int state = s21_from_float_to_decimal(num, &decimal);
  ck_assert_int_eq(state, OK);
  float test = 0;
  int result = s21_from_decimal_to_float(decimal, &test);
  ck_assert_int_eq(result, OK);
  ck_assert_float_eq(test, num);
}
END_TEST

START_TEST(from_float_to_decimal_6) {
  s21_decimal decimal = {0};
  float num = -17.0;
  int state = s21_from_float_to_decimal(num, &decimal);
  ck_assert_int_eq(state, OK);
  float test = 0;
  int result = s21_from_decimal_to_float(decimal, &test);
  ck_assert_int_eq(result, OK);
  ck_assert_float_eq(test, num);
}
END_TEST

START_TEST(from_float_to_decimal_7) {
  s21_decimal decimal = {0};
  float num = -1743839.0;
  int state = s21_from_float_to_decimal(num, &decimal);
  ck_assert_int_eq(state, OK);
  float test = 0;
  int result = s21_from_decimal_to_float(decimal, &test);
  ck_assert_int_eq(result, OK);
  ck_assert_float_eq(test, num);
}
END_TEST

START_TEST(from_float_to_decimal_8) {
  s21_decimal decimal = {0};
  float num = -599999000.0;
  int state = s21_from_float_to_decimal(num, &decimal);
  ck_assert_int_eq(state, OK);
  float test = 0;
  int result = s21_from_decimal_to_float(decimal, &test);
  ck_assert_int_eq(result, OK);
  ck_assert_float_eq(test, num);
}
END_TEST

START_TEST(from_float_to_decimal_9) {
  s21_decimal decimal = {0};
  float num = 4.5;
  int state = s21_from_float_to_decimal(num, &decimal);
  ck_assert_int_eq(state, OK);
  float test = 0;
  int result = s21_from_decimal_to_float(decimal, &test);
  ck_assert_int_eq(result, OK);
  ck_assert_float_eq_tol(test, num, 1e-06);
}
END_TEST

START_TEST(from_float_to_decimal_10) {
  s21_decimal decimal = {0};
  float num = 443.5112;
  int state = s21_from_float_to_decimal(num, &decimal);
  ck_assert_int_eq(state, OK);
  float test = 0;
  int result = s21_from_decimal_to_float(decimal, &test);
  ck_assert_int_eq(result, OK);
  ck_assert_float_eq_tol(test, num, 1e-07);
}
END_TEST

START_TEST(from_float_to_decimal_11) {
  s21_decimal decimal = {0};
  float num = 449223.913294;
  int state = s21_from_float_to_decimal(num, &decimal);
  ck_assert_int_eq(state, OK);
  float test = 0;
  int result = s21_from_decimal_to_float(decimal, &test);
  ck_assert_int_eq(result, OK);
  ck_assert_float_eq_tol(test, num, 1e-07);
}
END_TEST

START_TEST(from_float_to_decimal_12) {
  s21_decimal decimal = {0};
  float num = 43348.91;
  int state = s21_from_float_to_decimal(num, &decimal);
  ck_assert_int_eq(state, OK);
  float test = 0;
  int result = s21_from_decimal_to_float(decimal, &test);
  ck_assert_int_eq(result, OK);
  ck_assert_float_eq_tol(test, num, 1e-02);
}
END_TEST

START_TEST(from_float_to_decimal_13) {
  s21_decimal decimal = {0};
  float num = 127.1234;
  int state = s21_from_float_to_decimal(num, &decimal);
  ck_assert_int_eq(state, OK);
  float test = 0;
  int result = s21_from_decimal_to_float(decimal, &test);
  ck_assert_int_eq(result, OK);
  ck_assert_float_eq(test, num);
}
END_TEST

START_TEST(from_float_to_decimal_14) {
  s21_decimal decimal = {0};
  float num = 127.1234;
  int state = s21_from_float_to_decimal(num, &decimal);
  ck_assert_int_eq(state, OK);
  float *test = NULL;
  int result = s21_from_decimal_to_float(decimal, test);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(from_float_to_decimal_15) {
  s21_decimal *decimal = NULL;
  float num = 127.1234;
  int state = s21_from_float_to_decimal(num, decimal);
  ck_assert_int_eq(state, 1);
}
END_TEST

START_TEST(from_float_to_decimal_16) {
  float inp = 1. / 0.;
  s21_decimal out;
  int error = s21_from_float_to_decimal(inp, &out);
  for (int i = LOW; i <= HIGH; i++) ck_assert_int_eq(out.bits[i], 0);
  ck_assert_int_eq(error, 1);
}

START_TEST(from_float_to_decimal_17) {
  float inp = 2;
  s21_decimal *out = NULL;
  int error = s21_from_float_to_decimal(inp, out);
  ck_assert_ptr_eq(out, NULL);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(from_float_to_decimal_18) {
  float inp = 2;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000002, 0, 0, 0}};
  for (int i = LOW; i <= HIGH; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_float_to_decimal_19) {
  float inp = -321.2;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000C8C, 0, 0, 0x80010000}};
  for (int i = LOW; i <= HIGH; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_float_to_decimal_20) {
  float inp = 321.2;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000C8C, 0, 0, 0x00010000}};
  for (int i = LOW; i <= HIGH; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_float_to_decimal_21) {
  s21_decimal decimal = {0};
  float num = 14433489223.913293843944;
  int state = s21_from_float_to_decimal(num, &decimal);
  ck_assert_int_eq(state, OK);
  float test = 0;
  int result = s21_from_decimal_to_float(decimal, &test);
  ck_assert_int_eq(result, OK);
  ck_assert_float_eq_tol(test, num, 1e-07);
}
END_TEST

START_TEST(from_float_to_decimal_24) {
  s21_decimal decimal = {0};
  float num = 1e12;
  int state = s21_from_float_to_decimal(num, &decimal);
  ck_assert_int_eq(state, OK);
  float test = 0;
  int result = s21_from_decimal_to_float(decimal, &test);
  ck_assert_int_eq(result, 0);
  ck_assert_float_eq(test, num);
}
END_TEST

START_TEST(from_float_to_decimal_25) {
  s21_decimal decimal = {0};
  float num = 0.000000899;
  int state = s21_from_float_to_decimal(num, &decimal);
  ck_assert_int_eq(state, OK);
  float test = 0;
  int result = s21_from_decimal_to_float(decimal, &test);
  ck_assert_int_eq(result, 0);
  ck_assert_float_eq(test, num);
}
END_TEST

START_TEST(from_float_to_decimal_26) {
  s21_decimal val = {{0, 0, 0, 0}};
  float res = 0.;
  float tmp = -1234.56789;
  s21_from_float_to_decimal(tmp, &val);
  printf(" ");
  s21_from_decimal_to_float(val, &res);
  ck_assert_float_eq(res, tmp);
}
END_TEST

START_TEST(from_float_to_decimal_27) {
  s21_decimal val = {{0, 0, 0, 0}};
  float res = 0.;
  float tmp = 1234.56789;
  s21_from_float_to_decimal(tmp, &val);
  printf(" ");
  s21_from_decimal_to_float(val, &res);
  ck_assert_float_eq(res, tmp);
}
END_TEST

Suite *test_from_float_to_decimal() {
  Suite *s = suite_create(color_text("S21_FROM_FLOAT_TO_DECIMAL"));
  TCase *tc = tcase_create("from_float_to_decimal_test");

  tcase_add_test(tc, from_float_to_decimal_1);
  tcase_add_test(tc, from_float_to_decimal_2);
  tcase_add_test(tc, from_float_to_decimal_3);
  tcase_add_test(tc, from_float_to_decimal_4);
  tcase_add_test(tc, from_float_to_decimal_5);
  tcase_add_test(tc, from_float_to_decimal_6);
  tcase_add_test(tc, from_float_to_decimal_7);
  tcase_add_test(tc, from_float_to_decimal_8);
  tcase_add_test(tc, from_float_to_decimal_9);
  tcase_add_test(tc, from_float_to_decimal_10);
  tcase_add_test(tc, from_float_to_decimal_11);
  tcase_add_test(tc, from_float_to_decimal_12);
  tcase_add_test(tc, from_float_to_decimal_13);
  tcase_add_test(tc, from_float_to_decimal_14);
  tcase_add_test(tc, from_float_to_decimal_15);
  tcase_add_test(tc, from_float_to_decimal_16);
  tcase_add_test(tc, from_float_to_decimal_17);
  tcase_add_test(tc, from_float_to_decimal_18);
  tcase_add_test(tc, from_float_to_decimal_19);
  tcase_add_test(tc, from_float_to_decimal_20);
  tcase_add_test(tc, from_float_to_decimal_21);
  tcase_add_test(tc, from_float_to_decimal_24);
  tcase_add_test(tc, from_float_to_decimal_25);
  tcase_add_test(tc, from_float_to_decimal_26);
  tcase_add_test(tc, from_float_to_decimal_27);

  suite_add_tcase(s, tc);
  return s;
}
