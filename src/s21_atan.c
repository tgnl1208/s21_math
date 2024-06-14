#include "s21_math.h"

long double s21_atan(double x) {
  int is_valid = (x > -1 && x < 1);
  long double result = 0;
  if (x == s21_INF) {
    result = s21_PI_2;
  } else if (x == s21_NINF) {
    result = s21_NPI_2;
  } else if (x == 1) {
    result = s21_PI / 4.0;
  } else if (x == -1) {
    result = -s21_PI / 4.0;
  } else {
    result = is_valid ? x : 1.0 / x;
    for (int i = 1; i < 5000; i++) {
      double formal =
          s21_pow(-1, i) * s21_pow(x, (1 + 2 * i) * (is_valid ? 1 : -1));
      double nm = 1 + 2 * i;
      result += formal / nm;
    }
    if (!is_valid) result = (s21_PI * s21_fabs(x) / (2 * x)) - result;
  }
  return result;
}  // fixed