#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int state = OK;
  resetDecimal(dst);
  if (dst && !(S21_INF(src)) && !S21_NEG_INF(src) && fabs(src) > 1e-28) {
    int exp = 0, scale = 0, sign = 0;
    if (src < 0) {
      sign = 1;
      src = -src;
    }
    frexp(src, &exp);
    --exp;
    if (exp > 95 || exp < -94)
      state = 1;
    else {
      double tmp = (double)src;
      for (; !((int)tmp / (int)pow(2, 21)); tmp *= 10, scale++)
        ;
      /*
      MY SOLUTION (probably correct, but one test fails)
      for (; !((int) tmp / 10000000); tmp *= 10, scale++);
      */
      if (scale > 28)
        state = 1;
      else {
        tmp = (float)tmp;
        for (; !fmod(tmp, 10) && scale > 0; scale--, tmp /= 10)
          ;
        float mantissa = frexp(tmp, &exp);
        --exp;
        setBit(&dst->bits[exp / 32], (exp % 32));
        unsigned int fBits = *((unsigned int *)&mantissa);
        for (int i = exp - 1, j = 22; j >= 0; i--, j--) {
          if (getBit(fBits, j)) setBit(&dst->bits[i / 32], (i % 32));
        }
        if (sign) setSign(dst);
        setScale(dst, scale);
      }
    }
  } else
    state = 1;
  return state;
}
