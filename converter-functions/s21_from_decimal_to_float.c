#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int result = OK;
  if (dst) {
    double num = 0;
    for (int i = 0; i < 96; i++) {
      if (getBit(src.bits[i / 32], (i % 32))) {
        num += pow(2, i);
      }
    }
    unsigned int scale = getScale(src);
    num /= pow(10, scale);
    if (getSign(src)) num = -num;
    *dst = (float)num;
  } else
    result = 1;
  return result;
}
