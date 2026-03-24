#include <stdio.h>

int main() {
  int A[5];                     // Output: 0 0 0 0 -272632584 (Garbage value)
  int B[5] = {1, 2, 3, 4, 5};   // Output: 1 2 3 4 5
  int C[10] = {2, 4, 6};        // Output: 2 4 6 0 0 0 0 0 0 0
  int D[5] = {0};               // Output: 0 0 0 0 0
  int E[] = {1, 2, 3, 4, 5, 6}; // Output: [6] 1 2 3 4 5 6

  // Get array index address
  int i;
  for (i = 0; i < 5; i++) {
    printf("%u \n", &A[i]);
  }

  return 0;
}
