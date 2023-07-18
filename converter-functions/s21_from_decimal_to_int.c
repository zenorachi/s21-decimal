#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int result = OK;
  if (dst) {
    s21_decimal value = {{0, 0, 0, 0}};
    for (int i = LOW; i <= SCALE; i++) {
      value.bits[i] = src.bits[i];
    }
    s21_truncate(src, &value);
    long long int num = 0;
    int scale = getScale(value);
    long long int divider = pow(10, scale);
    int sign = getSign(value);
    num = (value.bits[LOW] + value.bits[MID] * (MAX_UINT + 1) +
           value.bits[HIGH] * (MAX_UINT + 1) * (MAX_UINT + 1)) /
          divider;
    if ((!sign) && num > MAX_INT) {
      result = 1;
    } else if (sign && num > MIN_INT) {
      result = 1;
    } else {
      *dst = sign ? (int)-num : (int)num;
    }
  } else
    result = 1;
  return result;
}
