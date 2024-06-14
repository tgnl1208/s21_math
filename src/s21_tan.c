#include "s21_math.h"

long double s21_tan(double x) {
  long double result = 0;
  long double sum_tan = s21_cos(x);
  if (s21_fabs(sum_tan) < s21_EPS) {
    if (x < 0) {
      result = s21_tan_NPI_2;
    } else
      result = s21_tan_PI_2;
  } else
    result = s21_sin(x) / sum_tan;
  return result;
}  // fixed