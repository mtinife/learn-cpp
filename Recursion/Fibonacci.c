#include <stdio.h>

// Iterative
int fib(int n) {
  int term0 = 0, term1 = 1, sum = 0, i;

  if (n <= 1)
    return n;

  for (i = 2; i <= n; i++) {
    sum = term0 + term1;
    term0 = term1;
    term1 = sum;
  }

  return sum;
}

// Recursive
int rfib(int n) {
  if (n <= 1)
    return n;
  return rfib(n - 2) + rfib(n - 1);
}

// Memoization
int F[10];

int mfib(int n) {
  if (n <= 1) {
    F[n] = n;
    return n;
  } else {
    if (F[n - 2] == -1) {
      F[n - 2] = mfib(n - 2);
    }
    if (F[n - 1] == -1) {
      F[n - 1] = mfib(n - 1);
    }
    F[n] = F[n - 2] + F[n - 1];
    return F[n - 2] + F[n - 1];
  }
}

int main() {

  int i;
  for (i = 0; i < 10; i++) {
    F[i] = -1;
  }

  printf("%d \n", mfib(10));

  return 0;
}
