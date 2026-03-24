#include <stdio.h>

double taylorSeries(int x, int n) {
  static double p = 1, f = 1;
  double r;

  if (n == 0) {
    return 1;
  }

  r = taylorSeries(x, n - 1);
  p = p * x;
  f = f * n;
  return r + p / f;
}

// Taylor Series Iterative
double taylorSeriesIterative(int x, int n) {
  double s = 1;
  int i;
  double num = 1;
  double den = 1;

  for (i = 1; i <= n; i++) {
    num *= x;
    den *= i;
    s += num / den;
  }

  return s;
}

int main() {

  printf("%lf \n", taylorSeriesIterative(1, 10));

  return 0;
}
