#include <stdio.h>

double hornerRule(int x, int n) {

  static double s;
  if (n == 0) {
    return s;
  }
  s = 1 + x * s / n;
  return hornerRule(x, n - 1);
}

int main() {

  printf("%lf \n", hornerRule(2, 10));

  return 0;
}
