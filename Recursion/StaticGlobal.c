#include <stdio.h>

// Default:
/*
int fun(int n) {
  if (n > 0) {
    return fun(n - 1) + n;
  }
  return 0;
}

int main() {

  int r;

  r = fun(5);
  printf("%d", r); // Output: 15

  return 0;
}
*/

// Static
/*
int fun(int n) {
  static int x = 0; -- Makes this a static Recursion
  if (n > 0) {
    x++;
    return fun(n - 1) + x;
  }
  return 0;
}

int main() {
  int r;

  r = fun(5);
  printf("%d", r); // Output: 25

  return 0;
}
*/

// Global

//-- Brings the value of the function scope into the global scope
int x = 0;

int fun(int n) {
  if (n > 0) {
    x++;
    return fun(n - 1) + x;
  }
  return 0;
}

int main() {
  int r;

  r = fun(5);
  printf("%d\n", r); // Output: 25

  //-- Doubles the output
  r = fun(5);
  printf("%d\n", r); // Output: 50

  return 0;
}
