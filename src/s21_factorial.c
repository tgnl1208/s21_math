#include "s21_math.h"

long double s21_factorial(long long int x) {
  long double result = 0;
  if (x == 1 || x == 0)
    result = 1;
  else if (x < 0)
    result = s21_INF;
  else
    result = x * s21_factorial(x - 1);
  return result;
}  // fixed
