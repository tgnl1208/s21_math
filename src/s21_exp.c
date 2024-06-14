#include "s21_math.h"

long double s21_exp(double x) {
  long double result;
  if ((x == x) && (x != -s21_INF)) {
    result = 1;
    long double add = 1, i = 1;
    int check = 0;
    while ((s21_fabs(add) > s21_EPS) && !check) {
      add = add * s21_fabs(x) / i;
      i++;
      result = result + add;
      if (result > s21_DBL_MAX) {
        result = s21_INF;
        check = 1;
      }
    }
    if (x < 0) result = 1 / result;
  } else if (x == -s21_INF)
    result = 0;
  else
    result = s21_NAN;
  return result;
}  // fixed