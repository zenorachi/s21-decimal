#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int state = OK;
  if (result) {
    resetDecimal(result);
    s21_truncate(value, result);  // 1
    if (getSign(value)) {
      s21_decimal src = {{1, 0, 0, 0}};
      if (isOverflow(*result, src))
        state = 1;
      else
        s21_sub(*result, src, result);
    }
  } else
    state = 1;
  return state;
}
