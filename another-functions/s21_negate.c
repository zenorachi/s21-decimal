#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int state = OK;
  if (result) {
    resetDecimal(result);
    if (getSign(value)) {
      *result = value;
      delSign(result);
    } else {
      *result = value;
      setSign(result);
    }
  } else
    state = 1;
  return state;
}
