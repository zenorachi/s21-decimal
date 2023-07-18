#include "../s21_decimal.h"

int s21_is_less(s21_decimal value1, s21_decimal value2) {
  return !(s21_is_greater_or_equal(value1, value2));
}
