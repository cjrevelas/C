#include <stdio.h>

int myFunction(int *x);

int main() {

  int myArray[5] = {2, 5, 7, 10, 15};

  // arrayLength = (size of the whole array / size of an element of the array)
  // in this example: arrayLength = (20 bytes) / (4 bytes) = 5

  printf("size of array: %d \n", sizeof(myArray)/sizeof(myArray[0]));

  // Note: the brackets [x] are a C operator to dereference the address where the element x is stored in memory.
  // myArray[1] = *(myArray+1);

  //myFunction(*myArray);
  printf("Address of first element: %p \n", myArray);
  printf("Value   of first element: %d \n", *myArray);

  printf("Address of second element: %p \n", myArray+2);
  printf("Value   of first  element: %d \n", *(myArray+1));

  // Printing the sum of array elements
  printf("The sum of the array elements is: %d \n", myFunction(myArray));

  return 0;
}
