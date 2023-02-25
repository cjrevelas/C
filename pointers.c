#include <stdio.h>

int main() {

  // Pointers are essential, because we need to store addresses in variables.
  // A pointer is a variable that can store the address of another variable.
  // To retrieve the value stored in that variable, we have to dereference the pointer.


  int x = 5;

  int *y = &x;

  printf("x variable is stored in address: %p\n\n", y);
  printf("x value is %d\n\n", x);
  printf("by dereferencing the pointer we get the value of x: %d\n", *y);

  return 0;
}
