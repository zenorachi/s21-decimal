#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_INF(X) (X == (1.0 / 0.0))
#define S21_NEG_INF(X) (X == (-1.0 / 0.0))

// INTEGERS
#define MAX_UINT 4294967295
#define MAX_INT 2147483647
#define MIN_INT 2147483648

// FLOATS
#define MAX_FLOAT 3.40282347e+38

enum DIGIT { LOW, MID, HIGH, SCALE };

enum VALUE_TYPE { OK, INF, NEG_INF, DIV_BY_0 };

enum BOOLEAN { FALSE, TRUE };

typedef struct S21_DECIMAL_T {
  unsigned int bits[4];
} s21_decimal;

// Arithmetic operators
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Comparison operators
int s21_is_less(s21_decimal value1, s21_decimal value2);
int s21_is_less_or_equal(s21_decimal value1, s21_decimal value2);
int s21_is_greater(s21_decimal value1, s21_decimal value2);
int s21_is_greater_or_equal(s21_decimal value1, s21_decimal value2);
int s21_is_equal(s21_decimal value1, s21_decimal value2);
int s21_is_not_equal(s21_decimal value1, s21_decimal value2);

// Converters
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// Another functions
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// Extra functions
int getBit(unsigned int digit, int i);
void setBit(unsigned int *digit, int i);
int getSign(s21_decimal decimal);
void setSign(s21_decimal *decimal);
void delSign(s21_decimal *decimal);
long double s21_powi(long double base, int exp);
unsigned int getScale(s21_decimal decimal);
void setScale(s21_decimal *decimal, int scale);
void delBit(unsigned int *digit, int i);
void resetDecimal(s21_decimal *decimal);
void increaseScale(s21_decimal *dst);
void decreaseScale(s21_decimal *value);
void equalScale(s21_decimal *dst1, s21_decimal *dst2);
void shiftLeft(s21_decimal *decimal);
int add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void convertToAdditionalCode(s21_decimal *value);
int isOverflow(s21_decimal value_1, s21_decimal value_2);
