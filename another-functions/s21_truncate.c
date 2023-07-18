#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int state = OK;
  if (result) {
    resetDecimal(result);
    if (getSign(value)) setSign(result);
    for (int i = LOW; i <= HIGH; i++) {
      result->bits[i] = value.bits[i];
    }
    unsigned int scale = getScale(value);
    while (scale) {
      decreaseScale(result);
      --scale;
    }
    setScale(result, 0);
  } else
    state = 1;
  return state;
}
