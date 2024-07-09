#ifndef STACK_NUMBER_H
#define STACK_NUMBER_H

void pushNumber(int* stackOfNumbers, int number, int* topNumberIndex, int numbers) {
  if ((*topNumberIndex) == numbers-1) {
    printf("ERROR: stack overflow! Need to POP a value to continue properly!\n");
  } else {
    (*topNumberIndex)++;
    stackOfNumbers[*topNumberIndex] = number;
  }
}

void popNumber(int* stackOfNumbers, int* topNumberIndex) {
  if ((*topNumberIndex) == -1) {
    printf("ERROR: stack underflow! Need to push a value to continue properly!\n");
  } else {
    (*topNumberIndex)--;
  }
}

void displayStackOfNumbers(int* stackOfNumbers, int topNumberIndex){
  for (int jj=-1; jj<topNumberIndex; ++jj) {
    printf("%d ", stackOfNumbers[jj+1]);
  }
  printf("\n");
}

#endif // STACK_NUMBER_H
