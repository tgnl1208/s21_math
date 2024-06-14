#include "s21_math.h"

long double s21_floor(double x) {
  long double result;
  if (s21_IS_INF(x) || s21_IS_NAN(x))
    result = x;
  else {
    int int_part = (int)x;
    int_part -= (x < 0 && (x - int_part));
    result = (long double)int_part;
  }
  return result;
}  // fixed
