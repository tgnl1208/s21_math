#include "s21_math.h"

long double s21_sqrt(double x) {
  long double result = 0;
  if (x == s21_NINF) {
    result = s21_NAN;
  } else {
    result = s21_pow(x, 0.5);
  }
  return result;
}  // fixed