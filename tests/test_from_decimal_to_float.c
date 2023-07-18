#include "test_decimal.h"

START_TEST(from_decimal_to_float_1) {
  float num = 0.0;
  s21_decimal decimal = {{24932, 0, 0, 2147680256}};
  int result = s21_from_decimal_to_float(decimal, &num);
  ck_assert_int_eq(result, OK);
  ck_assert_float_eq(num, -24.932);
}
END_TEST

START_TEST(from_decimal_to_float_2) {
  float num = 0.0;
  s21_decimal decimal = {{0, 0, 0, 2147680256}};
  int result = s21_from_decimal_to_float(decimal, &num);
  ck_assert_int_eq(result, OK);
  ck_assert_float_eq(num, 0.0);
}
END_TEST

START_TEST(from_decimal_to_float_3) {
  float num = 0.0;
  s21_decimal decimal = {{1, 0, 0, 2147680256}};
  int result = s21_from_decimal_to_float(decimal, &num);
  ck_assert_int_eq(result, OK);
  ck_assert_float_eq(num, -0.001);
}
END_TEST

START_TEST(from_decimal_to_float_4) {
  float num = 0.0;
  s21_decimal decimal = {{1, 1, 1, 1}};
  resetDecimal(&decimal);
  decimal.bits[MID] = 1000099999;
  int result = s21_from_decimal_to_float(decimal, &num);
  ck_assert_int_eq(result, OK);
  ck_assert_float_eq(num, (MAX_UINT + 1) * 1000099999.0);
  s21_decimal dst = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(num, &dst);
  float num2 = 0;
  s21_from_decimal_to_float(decimal, &num2);
  ck_assert_float_eq(num2, (MAX_UINT + 1) * 1000099999.0);
}
END_TEST

START_TEST(from_decimal_to_float_5) {
  float num = 0.0;
  s21_decimal decimal = {{1, 1, 1, 1}};
  resetDecimal(&decimal);
  decimal.bits[MID] = 43107;
  setSign(&decimal);
  unsigned int mult = decimal.bits[MID];
  int result = s21_from_decimal_to_float(decimal, &num);
  ck_assert_int_eq(result, OK);
  ck_assert_float_eq(num, (MAX_UINT + 1) * mult * -1);
  s21_decimal dst = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(num, &dst);
  float num2 = 0;
  s21_from_decimal_to_float(decimal, &num2);
  ck_assert_float_eq(num2, (MAX_UINT + 1) * mult * -1);
}
END_TEST

START_TEST(from_decimal_to_float_6) {
  float num = 0.0;
  s21_decimal decimal = {{1, 1, 1, 1}};
  resetDecimal(&decimal);
  decimal.bits[LOW] = MAX_UINT;
  int result = s21_from_decimal_to_float(decimal, &num);
  ck_assert_int_eq(result, OK);
  ck_assert_float_eq(num, MAX_UINT);
  s21_decimal dst = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(num, &dst);
  float num2 = 0;
  s21_from_decimal_to_float(decimal, &num2);
  ck_assert_float_eq(num2, MAX_UINT);
  ck_assert_float_eq(num2, num);
}
END_TEST

START_TEST(from_decimal_to_float_7) {
  s21_decimal val = {{123456789, 0, 0, 0}};
  setScale(&val, 5);
  float res = 1234.56789;
  float tmp = 0.;
  float *dst = &tmp;
  s21_from_decimal_to_float(val, dst);
  ck_assert_float_eq(*dst, res);
}
END_TEST

START_TEST(from_decimal_to_float_8) {
  s21_decimal val = {{123456789, 0, 0, 0}};
  setSign(&val);
  setScale(&val, 5);
  float res = -1234.56789;
  float tmp = 0.;
  float *dst = &tmp;
  s21_from_decimal_to_float(val, dst);
  ck_assert_float_eq(*dst, res);
}
END_TEST

Suite *test_from_decimal_to_float() {
  Suite *s = suite_create(color_text("S21_FROM_DECIMAL_TO_FLOAT"));
  TCase *tc = tcase_create("from_decimal_to_float_test");

  tcase_add_test(tc, from_decimal_to_float_1);
  tcase_add_test(tc, from_decimal_to_float_2);
  tcase_add_test(tc, from_decimal_to_float_3);
  tcase_add_test(tc, from_decimal_to_float_4);
  tcase_add_test(tc, from_decimal_to_float_5);
  tcase_add_test(tc, from_decimal_to_float_6);
  tcase_add_test(tc, from_decimal_to_float_7);
  tcase_add_test(tc, from_decimal_to_float_8);

  suite_add_tcase(s, tc);
  return s;
}
