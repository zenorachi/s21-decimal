#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int state = OK;
  if (dst && !S21_INF(src) && !S21_NEG_INF(src)) {
    resetDecimal(dst);
    if (src < 0) {
      setSign(dst);
      src = -src;
    }
    dst->bits[LOW] = src;
  } else
    state = 1;
  return state;
}
