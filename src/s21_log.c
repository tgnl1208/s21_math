#include "s21_math.h"

long double s21_log(double x) {
  long double result = 0;
  int exp_pow = 0;
  if ((x > 0) && (x != s21_INF)) {
    for (; x >= s21_E; x /= s21_E, exp_pow++) continue;
    for (int i = 0; i < 100; i++) {
      long double temp = result;
      result = temp + 2 * (x - s21_exp(temp)) / (x + s21_exp(temp));
    }
  } else if ((x < 0) || (x != x))
    result = s21_NAN;
  else if (x == s21_INF)
    result = s21_INF;
  else
    result = s21_NINF;
  return result + exp_pow;
}  // fixed
