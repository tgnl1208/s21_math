#include "s21_math.h"

long double s21_cos(double x) {
  long double result = 0;
  if (x != s21_INF || x != s21_NINF || !s21_IS_NAN(x))
    result = s21_sin(s21_PI / 2 - x);
  return result;
}  // fixed