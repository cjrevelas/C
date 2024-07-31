#ifndef STACK_OPERATOR_H
#define STACK_OPERATOR_H

void pushOperator(char *stackOfOperators, char ch, int *topOperatorIndex, int operators) {
  if ((*topOperatorIndex) == operators-1) {
    printf("ERROR: stack overflow! Need to POP a value to continue properly!\n");
  } else {
    (*topOperatorIndex)++;
    stackOfOperators[*topOperatorIndex] = ch;
  }
}


void popOperator(char *stackOfOperators, int *topOperatorIndex) {
  if ((*topOperatorIndex) == -1) {
    printf("ERROR: stack underflow! Need to push a value to continue properly!\n");
  } else {
    (*topOperatorIndex)--;
  }
}


void displayStackOfOperators(char *stackOfOperators, int topOperatorIndex){
  for (int ii=-1; ii<topOperatorIndex; ++ii) {
    printf("%c ", stackOfOperators[ii+1]);
  }
  printf("\n");
}

#endif // STACK_OPERATOR_H
