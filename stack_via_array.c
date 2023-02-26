// This code will implement a stack of integer
// values using an array.

#include <stdio.h>

void push(int* stack, int value, int* top, int size); // Adding "value" element at the top of the stack
void pop(int* stack, int* top);                       // Removing the top element of the stack
void display(int* stack, int* top);                   // Display current status of the stack


int main() {
  int size = 10;
  int stack[size];
  int top = -1; // Corresponds to empty stack
  int operation;
  int value;

  printf("-----------------------------------------------------\n");
  printf("Operation 1: Push new element to the stack\n");
  printf("Operation 2: Pop element from stack\n");
  printf("Operation 3: Terminate code execution\n");
  printf("-----------------------------------------------------\n");

  printf("Caution: The capacity of the stack is %d elements!\n\n", size);

  while (operation != 3) {
    printf("Select operation to be performed on the stack: ");
    scanf("%d", &operation);

    switch(operation) {
      case 1: {
        printf("Give an integer value to be stored in the stack: ");
        scanf("%d", &value);
        push(stack, value, &top, size);
        display(stack, &top);
        break;
      }
      case 2: {
        printf("Popping..\n");
        pop(stack, &top);
        display(stack, &top);
        break;
      }
      case 3: {
        printf("Exiting..\n");
        break;
      }
      default: {
        printf("Not valid operation, try again..\n");
      }
    }
  }

  return 0;
}

void push(int* stack, int value, int* top, int size) {
  if (*top == size-1) {
    printf("ERROR: stack overflow! Need to POP a value to continue properly!\n");
  } else {
    (*top)++;
    stack[*top] = value;
  }
}

void pop(int* stack, int* top) {
  if (*top == -1) {
    printf("ERROR: stack underflow! Need to push a value to continue properly!\n");
  } else {
    (*top)--;
  }
}

void display(int* stack, int* top){
  for (int ii=-1; ii<(*top); ++ii) {
    printf("%d ", stack[ii+1]);
  }
  printf("\n");
}
