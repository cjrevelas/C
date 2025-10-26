#include <stdio.h>

void swap(int a, int b);
void swap_correct(int *a, int *b);

int main() {
  int x = 10;
  int y = 20;

  printf("x: %d, y: %d\n", x, y);

  printf("swapping variables..\n");
  swap(x, y);

  printf("x: %d, y: %d\n", x, y);

  printf("let's try again..\n");
  swap_correct(&x, &y);

  printf("x: %d, y: %d\n", x, y);

  return 0;
}

// Passing by value: swapping of variables will not affect the caller.
void swap(int a, int b) {
  int temp;

  temp = a;
  a    = b;
  b    = temp;
}

// Passing by address: swapping of variables DOES affect the caller.
void swap_correct(int *a, int *b) {
  int temp;

  temp = *a;
  *a   = *b;
  *b   = temp;
}


