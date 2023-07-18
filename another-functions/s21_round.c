#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int state = OK;
  if (result) {
    resetDecimal(result);
    s21_decimal copy1 = value, copy2 = value;
    int sign = getSign(value);
    if (sign) {
      delSign(&copy1);
      delSign(&copy2);
    }
    s21_decimal resultSubtraction = {{0, 0, 0, 0}};
    s21_decimal zeroPointFive = {{5, 0, 0, 0}};
    setScale(&zeroPointFive, 1);
    s21_truncate(copy2, &copy1);
    s21_sub(copy2, copy1, &resultSubtraction);
    if (s21_is_greater_or_equal(resultSubtraction, zeroPointFive)) {
      s21_decimal one = {{1, 0, 0, 0}};
      if (isOverflow(copy1, one))
        state = 1;
      else
        s21_add(copy1, one, result);
    } else
      *result = copy1;
    if (sign) setSign(result);
  } else
    state = 1;
  return state;
}
