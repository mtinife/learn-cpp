#include <stdio.h>
#include <stdlib.h>

int main() {

  int *p, *q;
  int i;

  // Creating array p in heap memory with size 5
  p = (int *)malloc(5 * sizeof(int));
  p[0] = 3;
  p[1] = 5;
  p[2] = 7;
  p[3] = 9;
  p[4] = 11;

  // Create array q in heap memory with size 10
  q = (int *)malloc(10 * sizeof(int));

  // Copy p array index values into q array
  for (i = 0; i < 5; i++) {
    q[i] = p[i];
  }

  // Free pointer p
  free(p);

  // Move the size of q = 10 into to p which was size 5
  p = q;

  // Delete q array and set it as a null pointer
  q = NULL;

  for (i = 0; i < 5; i++) {
    printf("%d \n", p[i]);
  }

  return 0;
}
