#include "s21_math.h"

long double s21_asin(double x) {
  long double result;
  if (x > 1 || x < -1) {
    result = s21_NAN;
  } else if (x == 1 || x == -1) {
    result = s21_PI / (2 * x);
  } else {
    result = s21_PI / 2 - s21_acos(x);
  }
  return result;
}  // fixed
