#include <stdio.h>

void myPrintingFunction(int z1, int z2); // Declaration of printing function
int mySummingFunction(int z1, int z2);   // Declaration of summing function

int main() {
  int x = 3;
  int y = 5;

  myPrintingFunction(5,6);
  myPrintingFunction(x,y);

  int k = mySummingFunction(x,y);

  myPrintingFunction(mySummingFunction(5,6),mySummingFunction(x,y));

  printf("the value of k is: %d", k);

  return 0;
}

void myPrintingFunction(int z1, int z2) { // Definition (body) of printing function
  int xLocal = z1 + 1;
  int yLocal = z2 + 1;
  printf("my variable values is %d %d \n", xLocal, yLocal);
}

int mySummingFunction(int z1, int z2) { // Definition (body) of summing function
  int kLocal = z1 + z2;

  return kLocal;
}
