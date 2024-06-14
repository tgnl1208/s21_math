#include "s21_math.h"

long double s21_ceil(double x) {
  long double result;
  if (s21_IS_NAN(x) || s21_IS_INF(x))
    result = x;
  else {
    int int_part = (int)x;
    int_part += (x > 0 && (x - int_part));
    result = int_part;
  }
  if (result == 0 && x < 0) result = -result;
  return result;
}  // fixed
