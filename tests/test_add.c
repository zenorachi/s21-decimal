#include "test_decimal.h"

START_TEST(add_int_1) {
  s21_decimal decimal_1 = {{17, 0, 0, 0}};
  s21_decimal decimal_2 = {{16, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int state = s21_add(decimal_1, decimal_2, &result);
  int dst = 0;
  int test = s21_from_decimal_to_int(result, &dst);
  ck_assert_int_eq(state, OK);
  ck_assert_int_eq(dst, 33);
  ck_assert_int_eq(test, OK);
}
END_TEST

START_TEST(add_int_2) {
  s21_decimal decimal_1 = {{17, 0, 0, 0}};
  setSign(&decimal_1);
  s21_decimal decimal_2 = {{2, 0, 0, 0}};
  setSign(&decimal_2);
  s21_decimal result = {{0, 0, 0, 0}};
  int state = s21_add(decimal_1, decimal_2, &result);
  int dst = 0;
  int test = s21_from_decimal_to_int(result, &dst);
  ck_assert_int_eq(state, OK);
  ck_assert_int_eq(dst, -19);
  ck_assert_int_eq(test, OK);
}
END_TEST

START_TEST(add_int_3) {
  s21_decimal decimal_1 = {{1000, 0, 0, 0}};
  setSign(&decimal_1);
  s21_decimal decimal_2 = {{1000, 0, 0, 0}};
  setSign(&decimal_2);
  s21_decimal result = {{0, 0, 0, 0}};
  int state = s21_add(decimal_1, decimal_2, &result);
  int dst = 0;
  int test = s21_from_decimal_to_int(result, &dst);
  ck_assert_int_eq(state, OK);
  ck_assert_int_eq(dst, -2000);
  ck_assert_int_eq(test, OK);
}
END_TEST

START_TEST(add_int_4) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};
  s21_decimal decimal_2 = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int state = s21_add(decimal_1, decimal_2, &result);
  int dst = 0;
  int test = s21_from_decimal_to_int(result, &dst);
  ck_assert_int_eq(state, OK);
  ck_assert_int_eq(dst, 2);
  ck_assert_int_eq(test, OK);
}
END_TEST

START_TEST(add_int_5) {
  s21_decimal decimal_1 = {{MAX_INT - 1, 0, 0, 0}};
  s21_decimal decimal_2 = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int state = s21_add(decimal_1, decimal_2, &result);
  int dst = 0;
  int test = s21_from_decimal_to_int(result, &dst);
  ck_assert_int_eq(state, OK);
  ck_assert_int_eq(dst, MAX_INT);
  ck_assert_int_eq(test, OK);
}
END_TEST

START_TEST(add_int_6) {
  s21_decimal decimal_1 = {{1e9, 0, 0, 0}};
  setSign(&decimal_1);
  s21_decimal decimal_2 = {{1e9, 0, 0, 0}};
  setSign(&decimal_2);
  s21_decimal result = {{0, 0, 0, 0}};
  int state = s21_add(decimal_1, decimal_2, &result);
  int dst = 0;
  int test = s21_from_decimal_to_int(result, &dst);
  ck_assert_int_eq(state, OK);
  ck_assert_int_eq(dst, -2e9);
  ck_assert_int_eq(test, OK);
}
END_TEST

START_TEST(add_int_7) {
  s21_decimal decimal_1 = {{MIN_INT, 0, 0, 0}};
  setSign(&decimal_1);
  s21_decimal decimal_2 = {{0, 0, 0, 0}};
  setSign(&decimal_2);
  s21_decimal result = {{0, 0, 0, 0}};
  int state = s21_add(decimal_1, decimal_2, &result);
  int dst = 0;
  int test = s21_from_decimal_to_int(result, &dst);
  ck_assert_int_eq(state, OK);
  ck_assert_int_eq(dst, -MIN_INT);
  ck_assert_int_eq(test, OK);
}
END_TEST

START_TEST(add_int_8) {
  s21_decimal decimal_1 = {{MAX_UINT, MAX_UINT, MAX_UINT, 0}};
  s21_decimal decimal_2 = {{MAX_UINT, MAX_UINT, MAX_UINT, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int state = s21_add(decimal_1, decimal_2, &result);
  ck_assert_int_eq(state, INF);
}
END_TEST

START_TEST(add_int_9) {
  s21_decimal decimal_1 = {{MAX_UINT, MAX_UINT, MAX_UINT, 0}};
  setSign(&decimal_1);
  s21_decimal decimal_2 = {{MAX_UINT, MAX_UINT, MAX_UINT, 0}};
  setSign(&decimal_2);
  s21_decimal result = {{0, 0, 0, 0}};
  int state = s21_add(decimal_1, decimal_2, &result);
  ck_assert_int_eq(state, NEG_INF);
}
END_TEST

START_TEST(add_int_10) {
  s21_decimal decimal_1 = {{MAX_INT, 0, 0, 0}};
  setSign(&decimal_1);
  s21_decimal decimal_2 = {{1, 0, 0, 0}};
  setSign(&decimal_2);
  s21_decimal result = {{0, 0, 0, 0}};
  int state = s21_add(decimal_1, decimal_2, &result);
  ck_assert_int_eq(state, 0);
}
END_TEST

START_TEST(add_int_11) {
  s21_decimal decimal_1 = {{104, 0, 0, 0}};
  s21_decimal decimal_2 = {{26, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int state = s21_add(decimal_1, decimal_2, &result);
  ck_assert_int_eq(state, OK);
  ck_assert_int_eq(result.bits[LOW], 130);
}
END_TEST

START_TEST(add_int_12) {
  s21_decimal decimal_1 = {{104, 0, 0, 0}};
  setScale(&decimal_1, 2);
  s21_decimal decimal_2 = {{267, 0, 0, 0}};
  setScale(&decimal_2, 1);
  s21_decimal result = {{0, 0, 0, 0}};
  int state = s21_add(decimal_1, decimal_2, &result);
  ck_assert_int_eq(state, OK);
  float dst = 0;
  s21_from_decimal_to_float(result, &dst);
  ck_assert_float_eq(dst, (1.04 + 26.7));
}
END_TEST
START_TEST(add_int_13) {
  s21_decimal decimal_1 = {{MAX_UINT, 0, 0, 0}};
  s21_decimal decimal_2 = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal true_result = {{0, 1, 0, 0}};
  int state = s21_add(decimal_1, decimal_2, &result);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(result.bits[i], true_result.bits[i]);
  }

  ck_assert_int_eq(state, OK);
}
END_TEST

START_TEST(add_0) {
  s21_decimal val1 = {{15, 0, 0, ~(MAX_UINT / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_1) {
  s21_decimal val1 = {{15, 0, 0, 0}};
  s21_decimal val2 = {{15, 0, 0, ~(MAX_UINT / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_2) {
  s21_decimal val1 = {{MAX_UINT, MAX_UINT, MAX_UINT, 0}};
  s21_decimal val2 = {{1, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(1, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_3) {
  s21_decimal val1 = {{MAX_UINT, MAX_UINT, MAX_UINT, ~(MAX_UINT / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(MAX_UINT / 2)}};
  s21_decimal res;
  ck_assert_int_eq(2, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_4) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_5) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_6) {
  s21_decimal val1 = {{8, 0, 0, ~(MAX_UINT / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_7) {
  s21_decimal val1 = {{2, 0, 0, ~(MAX_UINT / 2)}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_8) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_9) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, ~(MAX_UINT / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_10) {
  s21_decimal val1 = {{8, 0, 0, ~(MAX_UINT / 2)}};
  s21_decimal val2 = {{0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_11) {
  s21_decimal val1 = {{MAX_UINT, MAX_UINT, MAX_UINT, ~(MAX_UINT / 2)}};
  s21_decimal val2 = {{4, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_12) {
  s21_decimal val1 = {{MAX_UINT, MAX_UINT, MAX_UINT, ~(MAX_UINT / 2)}};
  s21_decimal val2 = {{4, 0, 0, ~(MAX_UINT / 2)}};
  s21_decimal res;
  ck_assert_int_eq(2, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_13) {
  s21_decimal val1 = {{MAX_UINT, MAX_UINT, MAX_UINT, 0}};
  s21_decimal val2 = {{4, 0, 0, ~(MAX_UINT / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_14) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{MAX_UINT, MAX_UINT, MAX_UINT, ~(MAX_UINT / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_15) {
  s21_decimal val1 = {{4, 0, 0, ~(MAX_UINT / 2)}};
  s21_decimal val2 = {{MAX_UINT, MAX_UINT, MAX_UINT, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_16) {
  s21_decimal val1 = {{4, 0, 0, ~(MAX_UINT / 2)}};
  s21_decimal val2 = {{MAX_UINT, MAX_UINT, MAX_UINT, ~(MAX_UINT / 2)}};
  s21_decimal res;
  ck_assert_int_eq(2, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_19) {
  s21_decimal decimal_1 = {{20, 0, 0, 0}};
  s21_decimal decimal_2 = {{17, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int state = s21_add(decimal_1, decimal_2, &result);
  ck_assert_int_eq(state, OK);
  int dst = 0;
  s21_from_decimal_to_int(result, &dst);
  ck_assert_int_eq(dst, 37);
}
END_TEST

START_TEST(add_20) {
  s21_decimal decimal_1 = {{20, 0, 0, 0}};
  setSign(&decimal_1);
  s21_decimal decimal_2 = {{17, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int state = s21_add(decimal_1, decimal_2, &result);
  ck_assert_int_eq(state, OK);
  int dst = 0;
  s21_from_decimal_to_int(result, &dst);
  ck_assert_int_eq(dst, (-20 + 17));
}
END_TEST

START_TEST(add_21) {
  s21_decimal decimal_1 = {{20, 0, 0, 0}};
  s21_decimal decimal_2 = {{17, 0, 0, 0}};
  setSign(&decimal_2);
  s21_decimal result = {{0, 0, 0, 0}};
  int state = s21_add(decimal_1, decimal_2, &result);
  ck_assert_int_eq(state, OK);
  int dst = 0;
  s21_from_decimal_to_int(result, &dst);
  ck_assert_int_eq(dst, (20 + (-17)));
}
END_TEST

START_TEST(test_s21_add_21) {
  s21_decimal src1, src2, result;
  src1.bits[3] = 0x30000;
  src1.bits[2] = 0;
  src1.bits[1] = 0xFF;
  src1.bits[0] = 0x67E4F;
  src2.bits[3] = 0x60000;
  src2.bits[2] = 0;
  src2.bits[1] = 0xEA;
  src2.bits[0] = 0x67E4F;
  s21_decimal result_origin;
  result_origin.bits[3] = 0x60000;
  result_origin.bits[2] = 0;
  result_origin.bits[1] = 0x3E502;
  result_origin.bits[0] = 0x1963E2E7;
  s21_add(src1, src2, &result);
  ck_assert_int_eq(result_origin.bits[3], result.bits[3]);
  ck_assert_int_eq(result_origin.bits[2], result.bits[2]);
  ck_assert_int_eq(result_origin.bits[1], result.bits[1]);
  ck_assert_int_eq(result_origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_s21_add_22) {
  s21_decimal test_value_1 = {{4294967295, 4294967295, 4294967290, 0}};
  s21_decimal test_value_2 = {{100, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_add(test_value_1, test_value_2, &result_dec);
  ck_assert_int_eq(result_dec.bits[0], 99);
  ck_assert_int_eq(result_dec.bits[1], 0);
  ck_assert_int_eq(result_dec.bits[2], 4294967291);
  ck_assert_int_eq(result_dec.bits[3], 0);
}
END_TEST

START_TEST(test_s21_add_23) {
  s21_decimal test_value_1 = {{4294967295, 4294967295, 4294967290, 131072}};
  s21_decimal test_value_2 = {{0, 1, 0, 131072}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_add(test_value_1, test_value_2, &result_dec);
  ck_assert_int_eq(result_dec.bits[0], 4294967295);
  ck_assert_int_eq(result_dec.bits[1], 0);
  ck_assert_int_eq(result_dec.bits[2], 4294967291);
  ck_assert_int_eq(result_dec.bits[3], 131072);
}
END_TEST

START_TEST(test_s21_add_24) {
  s21_decimal test_value_1 = {{4294967295, 4294967295, 4294967290, 131072}};
  s21_decimal test_value_2 = {{5, 0, 1, 131072}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_add(test_value_1, test_value_2, &result_dec);
  ck_assert_int_eq(result_dec.bits[0], 4);
  ck_assert_int_eq(result_dec.bits[1], 0);
  ck_assert_int_eq(result_dec.bits[2], 4294967292);
  ck_assert_int_eq(result_dec.bits[3], 131072);
}
END_TEST

START_TEST(test_s21_add_25) {
  s21_decimal test_value_1 = {{428, 0, 0, 0}};
  s21_decimal test_value_2 = {{165, 0, 0, 131072}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_add(test_value_1, test_value_2, &result_dec);
  ck_assert_int_eq(result_dec.bits[0], 42965);
  ck_assert_int_eq(result_dec.bits[1], 0);
  ck_assert_int_eq(result_dec.bits[2], 0);
  ck_assert_int_eq(result_dec.bits[3], 131072);
}
END_TEST

START_TEST(add_25) {
  s21_decimal src1, src2, result;
  int a = -1234;
  float b = 1.234;
  float res_origin = -1232.766;
  float res_our;
  s21_from_int_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(add_26) {
  s21_decimal src1, src2, result;
  int a = -1234;
  float b = -1.234;
  float res_origin = -1235.234;
  float res_our;
  s21_from_int_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(add_27) {
  s21_decimal src1, src2, result;
  float a = -1234;
  float b = -221.23401;
  float res_origin = -1455.234;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(add_28) {
  s21_decimal src1, src2, result;
  float a = -9403;
  float b = 0.00234;
  float res_origin = -9402.9976600;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(add_29) {
  s21_decimal src1, src2, result;
  float a = -940.3;
  float b = 0.234;
  float res_origin = -940.0660000;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(add_30) {
  s21_decimal src1, src2, result;
  double a = -0.9401;
  double b = 22.02397;
  float res_origin = 21.08387;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(add_31) {
  s21_decimal src1, src2, result;
  float a = -0.9403;
  float b = -112.0234;
  float res_origin = -112.9637;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(add_32) {
  s21_decimal src1, src2, result;
  float a = -0.94e03;
  float b = -112.0234;
  float res_origin = -1052.0234;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(add_33) {
  s21_decimal src1, src2, result;
  float a = -0.94e03;
  float b = -112.0e2;
  float res_origin = -12140;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

Suite *test_add() {
  Suite *s = suite_create(color_text("S21_ADD"));
  TCase *tc = tcase_create("add");

  tcase_add_test(tc, add_int_1);
  tcase_add_test(tc, add_int_2);
  tcase_add_test(tc, add_int_3);
  tcase_add_test(tc, add_int_4);
  tcase_add_test(tc, add_int_5);
  tcase_add_test(tc, add_int_6);
  tcase_add_test(tc, add_int_7);
  tcase_add_test(tc, add_int_8);
  tcase_add_test(tc, add_int_9);
  tcase_add_test(tc, add_int_10);
  tcase_add_test(tc, add_int_11);
  tcase_add_test(tc, add_int_12);
  tcase_add_test(tc, add_int_13);
  tcase_add_test(tc, add_0);
  tcase_add_test(tc, add_1);
  tcase_add_test(tc, add_2);
  tcase_add_test(tc, add_3);
  tcase_add_test(tc, add_4);
  tcase_add_test(tc, add_5);
  tcase_add_test(tc, add_6);
  tcase_add_test(tc, add_7);
  tcase_add_test(tc, add_8);
  tcase_add_test(tc, add_9);
  tcase_add_test(tc, add_10);
  tcase_add_test(tc, add_11);
  tcase_add_test(tc, add_12);
  tcase_add_test(tc, add_13);
  tcase_add_test(tc, add_14);
  tcase_add_test(tc, add_15);
  tcase_add_test(tc, add_16);
  tcase_add_test(tc, add_19);
  tcase_add_test(tc, add_20);
  tcase_add_test(tc, add_21);
  tcase_add_test(tc, test_s21_add_21);
  tcase_add_test(tc, test_s21_add_22);
  tcase_add_test(tc, test_s21_add_23);
  tcase_add_test(tc, test_s21_add_24);
  tcase_add_test(tc, test_s21_add_25);
  tcase_add_test(tc, add_25);
  tcase_add_test(tc, add_26);
  tcase_add_test(tc, add_27);
  tcase_add_test(tc, add_28);
  tcase_add_test(tc, add_29);
  tcase_add_test(tc, add_30);
  tcase_add_test(tc, add_31);
  tcase_add_test(tc, add_32);
  tcase_add_test(tc, add_33);

  suite_add_tcase(s, tc);
  return s;
}
