#include <stdio.h>
#include <stdlib.h>

int main() {

  // 2D array creation: Method 1
  // 2D array created in stack memory
  int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {1, 3, 5, 7}};

  // 2D array creation: Method 2
  // 2D array rows in stack memory
  int *B[3];

  // 2D array creation: Method 3
  // 2D array double ponters
  int **C;

  // Variable declaration
  int rows, columns;

  // Method 2 array values created in heap memory
  B[0] = (int *)malloc(4 * sizeof(int));
  B[1] = (int *)malloc(4 * sizeof(int));
  B[2] = (int *)malloc(4 * sizeof(int));

  // Method 3 row creations
  // Array of pointers
  C = (int **)malloc(3 * sizeof(int *));

  // Method 3 array values created in heap memory
  C[0] = (int *)malloc(4 * sizeof(int));
  C[1] = (int *)malloc(4 * sizeof(int));
  C[2] = (int *)malloc(4 * sizeof(int));

  // Access rows and columns of arrays
  for (rows = 0; rows < 3; rows++) {
    for (columns = 0; columns < 4; columns++) {
      printf("%d ", C[rows][columns]);
    }
    printf("\n");
  }

  return 0;
}
