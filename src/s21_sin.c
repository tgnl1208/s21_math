#include "s21_math.h"

long double s21_sin(double x) {
  long double result = 0;
  if (x == 0.0 || x == s21_PI) {
    result = 0.0;
  } else if (x == s21_PI_2) {
    result = 1.0;
  } else if (x == -s21_PI_2) {
    result = -1.0;
  } else {
    x = s21_fmod(x, 2 * s21_PI);
    for (int i = 0; i < 100; i++) {
      long double numer, denom;
      numer = s21_pow_int(-1, i) * s21_pow_int(x, 2 * i + 1);
      denom = s21_factorial(2 * i + 1);
      result += numer / denom;
    }
  }
  return result;
}  // fixed