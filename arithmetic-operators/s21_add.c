#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  equalScale(&value_1, &value_2);
  resetDecimal(result);
  int state = OK;
  int signTop = getSign(value_1), signBottom = getSign(value_2);
  int flag = 0;
  if (signTop == signBottom) {
    equalScale(&value_1, &value_2);
    flag = add(value_1, value_2, result);
    unsigned int scaleTop = getScale(value_1);
    setScale(result, scaleTop);
  } else {
    if (signTop) {
      delSign(&value_1);
      s21_sub(value_2, value_1, result);
    } else {
      delSign(&value_2);
      s21_sub(value_1, value_2, result);
    }
  }
  if (signTop && signBottom) setSign(result);
  if (flag) {
    resetDecimal(result);
    state = (signTop && signBottom) ? NEG_INF : INF;
  }
  return state;
}
