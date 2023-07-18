#include "../s21_decimal.h"

int getBit(unsigned int digit, int i) {
  unsigned int mask = 1 << (i % 32);
  return (!!(digit & mask));
}

void setBit(unsigned int *digit, int i) {
  unsigned int mask = 1 << (i % 32);
  *digit |= mask;
}

void delBit(unsigned int *digit, int i) {
  unsigned int mask = ~(1 << (i % 32));
  *digit &= mask;
}

int getSign(s21_decimal decimal) {
  return (!!(decimal.bits[SCALE] & (1 << 31)));
}

void setSign(s21_decimal *decimal) { decimal->bits[SCALE] |= (1 << 31); }

void delSign(s21_decimal *decimal) { delBit(&(decimal->bits[SCALE]), 31); }

unsigned int getScale(s21_decimal decimal) {
  unsigned int scale = 0;
  int i = 0;
  for (int j = 16; j <= 23; j++) {
    if (getBit(decimal.bits[SCALE], j)) {
      scale += pow(2, i);
    }
    i++;
  }
  return scale;
}

void setScale(s21_decimal *decimal, int scale) {
  if (scale >= 0 && scale <= 28) {
    int index = 0;
    for (int i = 16; i <= 23; i++) {
      if (getBit(scale, index))
        setBit(&decimal->bits[SCALE], i);
      else
        delBit(&decimal->bits[SCALE], i);
      ++index;
    }
  } else
    setScale(decimal, 0);
}

void resetDecimal(s21_decimal *decimal) {
  if (decimal) {
    for (int i = LOW; i <= SCALE; i++) {
      for (int j = 0; j < 32; j++) {
        delBit(&decimal->bits[i], j);
      }
    }
  }
}

void shiftLeft(s21_decimal *decimal) {
  int low_bit_remember = 0;
  int mid_bit_remember = 0;
  // int high_bit_remember = 0;
  low_bit_remember = getBit(decimal->bits[LOW], 31);
  mid_bit_remember = getBit(decimal->bits[MID], 31);
  // high_bit_remember = getBit(decimal->bits[HIGH], 31);
  decimal->bits[LOW] = decimal->bits[LOW] << 1;
  decimal->bits[MID] = decimal->bits[MID] << 1;
  if (low_bit_remember) {
    setBit(&decimal->bits[MID], 0);
  }
  decimal->bits[HIGH] = decimal->bits[HIGH] << 1;
  if (mid_bit_remember) {
    setBit(&decimal->bits[HIGH], 0);
  }
}

void increaseScale(s21_decimal *dst) {
  /*
  FIRST SOLUTION
  */
  // unsigned long long overflow = dst->bits[2];
  // for (int x = 2; x >= 0; x -= 1) {
  //   dst->bits[x] = overflow * 10;
  //   overflow =
  //       (overflow % 10) * (MAX_UINT + 1) + dst->bits[x ? x - 1 : x];
  // }
  // setScale(dst, (getScale(*dst) + 1));

  /*
  SECOND SOLUTION
  */
  unsigned int scale = getScale(*dst);
  s21_decimal dstCopy, dstCopy2;
  int sign = getSign(*dst);
  resetDecimal(&dstCopy);
  resetDecimal(&dstCopy2);
  for (int i = LOW; i <= HIGH; i++) {
    dstCopy.bits[i] = dst->bits[i];
    dstCopy2.bits[i] = dst->bits[i];
  }
  for (int i = 0; i < 3; i++) {
    shiftLeft(&dstCopy2);
  }
  shiftLeft(&dstCopy);
  s21_add(dstCopy2, dstCopy, dst);
  if (sign) setSign(dst);
  setScale(dst, (scale + 1));
}

void decreaseScale(s21_decimal *value) {
  unsigned long long overflow = value->bits[2];
  for (int x = 2; x >= 0; x -= 1) {
    value->bits[x] = overflow / 10;
    overflow = (overflow % 10) * (MAX_UINT + 1) + value->bits[x ? x - 1 : x];
  }
  setScale(value, (getScale(*value) - 1));
}

void equalScale(s21_decimal *dst1, s21_decimal *dst2) {
  unsigned int scale1 = getScale(*dst1);
  unsigned int scale2 = getScale(*dst2);
  if (scale1 > scale2) {
    for (; ((scale1 - scale2) != 0) && getBit(dst2->bits[HIGH], 31) != 1;
         scale2++) {
      increaseScale(dst2);
    }
    for (; ((scale1 - scale2) != 0); scale1--) {
      decreaseScale(dst1);
    }
  } else {
    for (; ((scale2 - scale1) != 0) && getBit(dst1->bits[HIGH], 31) != 1;
         scale1++) {
      increaseScale(dst1);
    }
    for (; ((scale2 - scale1) != 0); scale2--) {
      decreaseScale(dst2);
    }
  }
}

int add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int flag = 0;
  int top = 0, bottom = 0;
  for (int i = 0; i < 96; i++) {
    top = getBit(value_2.bits[i / 32], (i % 32));
    bottom = getBit(value_1.bits[i / 32], (i % 32));
    if (top && bottom) {
      if (flag) setBit(&(result->bits[i / 32]), (i % 32));
      flag = 1;
    } else if (top ^ bottom) {
      if (flag)
        flag = 1;
      else
        setBit(&(result->bits[i / 32]), (i % 32));
    } else {
      if (flag) setBit(&(result->bits[i / 32]), (i % 32));
      flag = 0;
    }
  }
  return flag;
}

void sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int flag = 0;
  for (int i = 0; i < 96; i++) {
    int top = getBit(value_1.bits[i / 32], (i % 32));
    int bottom = getBit(value_2.bits[i / 32], (i % 32));
    if (top && bottom) {
      if (flag) setBit(&result->bits[i / 32], (i % 32));
    } else if (top && !bottom) {
      if (!flag)
        setBit(&result->bits[i / 32], (i % 32));
      else
        flag = 0;
    } else if (!top && bottom) {
      if (!flag) {
        setBit(&result->bits[i / 32], (i % 32));
        flag = 1;
      }
    } else {
      if (flag) setBit(&result->bits[i / 32], (i % 32));
    }
  }
}

int isOverflow(s21_decimal value_1, s21_decimal value_2) {
  int state = 0;
  int scale1 = getScale(value_1), scale2 = getScale(value_2);
  if (scale1 > scale2) {
    for (int i = 96; i < 96 - (scale1 - scale2); i--) {
      if (getBit(value_2.bits[i / 32], (i % 32))) state = 1;
    }
  } else {
    for (int i = 96; i < 96 - (scale2 - scale1); i--) {
      if (getBit(value_1.bits[i / 32], (i % 32))) state = 1;
    }
  }
  return state;
}
