#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = 0, temp = (long double)base;
  if ((s21_fabs(temp) != s21_INF) && (exp != 0) && (s21_fabs(exp) != s21_INF) &&
      (temp == temp) && (exp == exp) && (temp != 0)) {
    if (temp < 0) {
      if (exp == s21_ceil(exp)) {
        temp = -temp;
        result = s21_exp(exp * s21_log(temp));
        if ((s21_fmod(exp, 2) != 0) && (s21_fabs(exp) != s21_INF))
          result = -result;
      } else
        result = s21_NAN;
    } else {
      result = s21_exp(exp * s21_log(base));
    }
  } else if (((exp == s21_INF) && (s21_fabs(temp) < 1)) ||
             ((exp == -s21_INF) && (s21_fabs(temp) > 1)) ||
             ((exp < 0) && (s21_fabs(temp) == s21_INF)) ||
             ((exp > 0) && (temp == 0)))
    result = 0;
  else if (((exp == -s21_INF) && (s21_fabs(temp) < 1)) ||
           ((exp == s21_INF) && (s21_fabs(temp) > 1)) ||
           ((exp > 0) && (s21_fabs(temp) == s21_INF)) ||
           ((exp < 0) && (temp == 0)))
    result = s21_INF;
  else if ((exp != 0) && (temp != 1) && ((exp != exp) || (temp != temp)))
    result = s21_NAN;
  else {
    result = 1;
  }
  return result;
}
// fixed