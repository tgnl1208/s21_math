#include "s21_math.h"

long double s21_pow_int(double base, int expx) {
  long double result = 1;
  while (expx > 0) {
    result = result * base;
    expx = expx - 1;
  }
  return result;
}  // fixed
