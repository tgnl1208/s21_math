#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double result;
  if ((x != 0) && (y != 0) && (s21_fabs(x) != s21_INF) &&
      (s21_fabs(y) != s21_INF)) {
    long double mod = s21_floor(s21_fabs((long double)x / (long double)y));
    if (mod != 0) mod--;
    if (mod != s21_INF) {
      result = s21_fabs((long double)x) - s21_fabs((mod * (long double)y));
      while (s21_fabs(result) >= s21_fabs(y)) {
        result = result - s21_fabs((long double)y);
      }
      if (x < 0) result = -result;
    } else
      result = 0;
  } else if ((x == 0) && (y != 0) && (y == y))
    result = 0;
  else if (s21_fabs(y) == s21_INF)
    result = x;
  else
    result = s21_NAN;
  return result;
}  // fixed
