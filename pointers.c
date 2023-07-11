#include <stdio.h>

float multiply(float *, float *);

int main() {

  // Pointers are essential, because we need to store addresses in variables.
  // A pointer is a variable that can store the address of another variable.
  // To retrieve the value stored in that variable, we have to dereference the pointer.
  {
    int x = 5;

    int *y = &x;

    printf("x variable is stored in address: %p\n\n", y);
    printf("x value is %d\n\n", x);
    printf("by dereferencing the pointer we get the value of x: %d\n", *y);
  }

  {
    float x = 2.0;
    float y = 3.0;

    float z = multiply(&x, &y);

    printf("\n The product %f * %f = %f", x, y, z);
  }

  return 0;
}


float multiply(float *x_p, float *y_p) {
  float prod = (*x_p) * (*y_p);

  return prod;
}
