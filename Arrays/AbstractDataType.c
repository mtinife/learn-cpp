#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* Array Created in Heap memory
struct ArrayHeap {
  int *A;
  int size;
  int length;
};

void Display(struct ArrayHeap arr) {
  int i;
  printf("\nElemets are\n");
  for (i = 0; i < arr.length; i++) {
    printf("%d ", arr.A[i]);
  }
}

int main() {

  // Heap array implementation
  struct ArrayHeap arr;
  int n, i;
  printf("Enter size of an array: ");
  scanf("%d", &arr.size);
  arr.A = (int *)malloc(arr.size * sizeof(int));
  arr.length = 0;

  printf("Enter number of numbers: ");
  scanf("%d", &n);

  printf("Enter all Elements\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr.A[i]);
  }
  arr.length = n;

  Display(arr);

  return 0;
}
*/

// Array created in stack memory
struct Array {
  int A[20];
  int size;
  int length;
};

void Display(struct Array arr) {
  int i;
  printf("\nElements are\n");
  for (i = 0; i < arr.length; i++) {
    printf("%d ", arr.A[i]);
  }
}

void Append(struct Array *arr, int x) {
  if (arr->length < arr->size) {
    arr->A[arr->length++] = x;
  }
}

void Insert(struct Array *arr, int index, int x) {
  int i;
  if (index >= 0 && index <= arr->length) {
    for (i = arr->length; i > index; i--) {
      arr->A[i] = arr->A[i - 1];
    }
    arr->A[index] = x;
    arr->length++;
  }
}

int Delete(struct Array *arr, int index) {
  int x = 0;
  int i;

  if (index >= 0 && index < arr->length) {
    x = arr->A[index];
    for (i = index; i < arr->length - 1; i++) {
      arr->A[i] = arr->A[i + 1];
    }
    arr->length--;
    return x;
  }
  return 0;
}

void swap(int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

// Call by reference *arr and uses ->
// Call by value uses dot (.)
int LinearSearch(struct Array arr, int key) {
  int i;
  for (i = 0; i < arr.length; i++) {
    if (key == arr.A[i]) {
      return i;
    }
  }
  return -1;
}

int LinearSearchSwap(struct Array *arr, int key) {
  int i;
  for (i = 0; i < arr->length; i++) {
    if (key == arr->A[i]) {
      // swap with left index
      //  swap(&arr->A[i], &arr->A[i - 1]);

      // swap with array head or 0 index
      // swap(&arr->A[i], &arr->A[0]);

      // swap with array tail or the last index
      swap(&arr->A[i], &arr->A[arr->length - 1]);
      return i;
    }
  }
  return -1;
}

int BinarySearch(struct Array arr, int key) {
  int length, middle, height;
  length = 0;
  height = arr.length - 1;

  while (length <= height) {
    middle = (length + height) / 2;
    if (key == arr.A[middle]) {
      return middle;
    } else if (key < arr.A[middle]) {
      height = middle - 1;
    } else {
      length = middle + 1;
    }
  }
  return -1;
}

int RecursionBinarySearch(int a[], int length, int height, int key) {
  int middle;

  if (length <= height) {
    middle = (length + height) / 2;
    if (key == a[middle]) {
      return middle;
    } else if (key < a[middle]) {
      return RecursionBinarySearch(a, length, middle - 1, key);
    } else {
      return RecursionBinarySearch(a, middle + 1, height, key);
    }
  }
  return -1;
}

int Get(struct Array arr, int index) {
  if (index >= 0 && index < arr.length) {
    return arr.A[index];
  }
  return -1;
}

void Set(struct Array *arr, int index, int x) {
  if (index >= 0 && index < arr->length) {
    arr->A[index] = x;
    printf("Set: Value %d at Index %d\n", x, index);
  }
}

int Max(struct Array arr) {
  int max = arr.A[0];
  int index;
  for (index = 1; index < arr.length; index++) {
    if (arr.A[index] > max) {
      max = arr.A[index];
    }
  }
  return max;
}

int Min(struct Array arr) {
  int min = arr.A[0];
  int index;
  for (index = 1; index < arr.length; index++) {
    if (arr.A[index] < min) {
      min = arr.A[index];
    }
  }
  return min;
}

int Sum(struct Array arr) {
  int sum = 0;
  int index;
  for (index = 0; index < arr.length; index++) {
    sum += arr.A[index];
  }
  return sum;
}

float Avg(struct Array arr) { return (float)Sum(arr) / arr.length; }

void Reverse(struct Array *arr) {
  int *B;
  int i, j;
  B = (int *)malloc(arr->length * sizeof(int));
  for (i = arr->length - 1, j = 0; i >= 0; i--, j++) {
    B[j] = arr->A[i];
  }
  printf("Reversed List: ");
  for (i = 0; i < arr->length; i++) {
    arr->A[i] = B[i];
    printf("%d ", arr->A[i]);
  }
  printf("\n");
}

void ReverseSwap(struct Array *arr) {
  int i, j;
  printf("Reversed Using Swap: ");
  for (i = 0; j = arr->length - 1, i < j; i++, j--) {
    swap(&arr->A[i], &arr->A[j]);
    printf("%d ", arr->A[i]);
  }
  printf("\n");
}

void InsertSort(struct Array *arr, int x) {
  int i = arr->length - 1;
  if (arr->length == arr->size) {
    return;
  }
  while (i >= 0 && arr->A[i] > x) {
    arr->A[i + 1] = arr->A[i];
    printf("%d ", arr->A[i]);
    i--;
  }
  arr->A[i + 1] = x;
  arr->length++;
}

int main() {
  struct Array arr = {{2, 3, 4, 5, 6}, 20, 5};

  Display(arr);
  printf("\n");

  Append(&arr, 10);
  Insert(&arr, 2, 23);
  printf("Delete Element: %d\n", Delete(&arr, 4));
  printf("Linear Search: %d\n", LinearSearch(arr, 6));
  printf("Linear Search Swap: %d\n", LinearSearchSwap(&arr, 4));
  printf("Binary Search: %d\n", BinarySearch(arr, 11));
  printf("Recursion Binary Search: %d\n",
         RecursionBinarySearch(arr.A, 0, arr.length, 3));
  printf("Get: %d\n", Get(arr, 5));
  Set(&arr, 4, 7);
  printf("Max: %d\n", Max(arr));
  printf("Min: %d\n", Min(arr));
  printf("Avg: %0.2f\n", Avg(arr));
  printf("Sum: %d\n", Sum(arr));
  Reverse(&arr);
  ReverseSwap(&arr);
  InsertSort(&arr, 32);

  Display(arr);

  return 0;
}
