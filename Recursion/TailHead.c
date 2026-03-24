#include <stdio.h>

// Tail Recursion output: 3 2 1
void fun(int n) {
  if (n > 0) {
    printf("%d ", n);
    fun(n - 1);
  }
}

// Head Recursion output: 1 2 3
void fun1(int n) {
  if (n > 0) {
    fun1(n - 1);
    printf("%d ", n);
  }
}

int main() {
  int x = 3;

  fun(x);  // Output: 3 2 1
  fun1(x); // Output: 1 2 3

  return 0;
}
