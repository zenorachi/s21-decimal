#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  resetDecimal(result);
  int state = OK;
  int signTop = getSign(value_1), signBottom = getSign(value_2);
  delSign(&value_1);
  delSign(&value_2);
  equalScale(&value_1, &value_2);
  if (isOverflow(value_1, value_2))
    state = INF;
  else {
    if (signTop ^ signBottom) {
      s21_add(value_1, value_2, result);
      if (signTop) setSign(result);
    } else {
      if (s21_is_greater_or_equal(value_1, value_2)) {
        sub(value_1, value_2, result);
        if (signTop) setSign(result);
      } else {
        s21_sub(value_2, value_1, result);
        if (!signTop) setSign(result);
      }
      setScale(result, getScale(value_1));
    }
  }
  return state;
}
