#include <stdio.h>

struct Index {
  int lowerLimit;  // lower limit of the index
  int upperLimit;  // upper limit of the index
};

int address(int i1, int i2, int i3, int i4);

int main() {
  int i1 = 2;
  int i2 = 3;
  int i3 = 3;
  int i4 = 1;

  printf("The address of element (%d, %d, %d, %d) is: %d\n", i1, i2, i3, i4, address(i1,i2,i3,i4));

  return 0;
}

int address(int i1, int i2, int i3, int i4) {
  int baseAddress = 100;
  int length      = 6;

  struct Index index1;
  struct Index index2;
  struct Index index3;
  struct Index index4;

  // Size of first dimension = 2 - 1 = 1
  index1.lowerLimit = 1;
  index1.upperLimit = 2;

  // Size of second dimension = 3 - 1 = 2
  index2.lowerLimit = 1;
  index2.upperLimit = 3;

  // Size of third dimension = 3 - 3 = 0
  index3.lowerLimit = 3;
  index3.upperLimit = 3;

  // Size of fourth dimension = 2 - 1 = 1
  index4.lowerLimit = 1;
  index4.upperLimit = 2;

  int c4 = length;

  int c3 = (index4.upperLimit - index4.lowerLimit + 1) * c4;
  int c2 = (index3.upperLimit - index3.lowerLimit + 1) * c3; // Always c2 = c3, because index3.upperLimit = index3.lowerLimit
  int c1 = (index2.upperLimit - index2.lowerLimit + 1) * c2;

  int c0 = baseAddress - c1*(index1.lowerLimit) - c2*(index2.lowerLimit) - c3*(index3.lowerLimit) - c4*(index4.lowerLimit);

  return (c0 + c1*i1 + c2*i2 + c3*i3 + c4*i4);
}
