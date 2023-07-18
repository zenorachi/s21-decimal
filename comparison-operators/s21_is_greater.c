#include "../s21_decimal.h"

int comparePositive(s21_decimal value1, s21_decimal value2);

int s21_is_greater(s21_decimal value1, s21_decimal value2) {
  equalScale(&value1, &value2);
  int state = FALSE;
  if (s21_is_equal(value1, value2))
    state = FALSE;  // (-0 = 0)
  else {
    int signValue1 = getSign(value1), signValue2 = getSign(value2);
    if (signValue2 && !signValue1)
      state = TRUE;
    else if (signValue1 && !signValue2)
      state = FALSE;
    else {
      if (!signValue1 && !signValue2) {
        state = comparePositive(value1, value2);
      } else {
        state = !comparePositive(value1, value2);
      }
    }
  }
  return state;
}

int comparePositive(s21_decimal value1, s21_decimal value2) {
  int state = FALSE;
  if (value1.bits[HIGH] > value2.bits[HIGH])
    state = TRUE;
  else if (value1.bits[HIGH] < value2.bits[HIGH])
    state = FALSE;
  else if (value1.bits[MID] > value2.bits[MID])
    state = TRUE;
  else if (value1.bits[MID] < value2.bits[MID])
    state = FALSE;
  else if (value1.bits[LOW] > value2.bits[LOW])
    state = TRUE;
  else if (value1.bits[LOW] < value2.bits[LOW])
    state = FALSE;
  return state;
}
