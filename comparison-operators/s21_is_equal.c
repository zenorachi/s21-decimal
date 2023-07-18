#include "../s21_decimal.h"

int s21_is_equal(s21_decimal value1, s21_decimal value2) {
  equalScale(&value1, &value2);
  int state = FALSE;
  if (!value1.bits[LOW] && !value1.bits[MID] && !value1.bits[HIGH] &&
      !value2.bits[LOW] && !value2.bits[MID] && !value2.bits[HIGH]) {
    state = TRUE;
  } else if (value1.bits[LOW] == value2.bits[LOW] &&
             value1.bits[MID] == value2.bits[MID] &&
             value1.bits[HIGH] == value2.bits[HIGH] &&
             value1.bits[SCALE] == value2.bits[SCALE]) {
    state = TRUE;
  }
  return state;
}
