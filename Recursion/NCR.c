#include <stdio.h>

int fact(int n) {
  if (n == 0)
    return 1;
  return fact(n - 1) * n;
}

int nCr(int n, int r) {
  int num, den;

  num = fact(n);
  den = fact(r) * fact(n - r);

  return num / den;
}

// Recursion
int rnCr(int n, int r) {
  if (n == r || r == 0) {
    return 1;
  }
  return rnCr(n - 1, r - 1) + rnCr(n - 1, r);
}

int main() {

  printf("%d \n", rnCr(4, 2));

  return 0;
}
