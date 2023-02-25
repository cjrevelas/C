// This code will implement a stack of integer
// values using a linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data_;
  struct Node* next_;
};

struct Node* push(struct Node* headNode, int value); // Adding new node at the top of the stack
struct Node* pop(struct Node* headNode);             // Removing the top node of the stack
void display(struct Node* headNode);                 // Display current status of the stack


int main() {
  int operation;
  int value;

  printf("-----------------------------------------------------\n");
  printf("Operation 1: Push new element to the stack\n");
  printf("Operation 2: Pop element from stack\n");
  printf("Operation 3: Display current status of the stack\n");
  printf("-----------------------------------------------------\n");

  // Initialize stack/list here
  struct Node* headNode   = NULL;
  struct Node* topNodeNew = NULL;

  while (operation != 3) {
    printf("Select operation to be performed on the stack: ");
    scanf("%d", &operation);

    switch(operation) {
      case 1: {
        printf("Give an integer value to be stored in the stack: ");
        scanf("%d", &value);
        headNode = push(headNode, value);
        display(headNode);
        break;
      }
      case 2: {
        printf("Popping..\n");
        headNode = pop(headNode);
        display(headNode);
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

struct Node* push(struct Node* headNode, int value) {
  struct Node* topNode;
  struct Node* tempNode;

  // Allocate memory for the new node of the list
  topNode = (struct Node*)malloc(sizeof(struct Node));

  topNode->data_ = value;
  topNode->next_ = NULL;

  if (headNode == NULL) { // Case of empty list
    headNode = topNode;
  } else {                // Case of non-empty list
    tempNode = headNode;  // Assign tempNode to head to start traversing the list

    while(tempNode->next_ != NULL) {
      tempNode = tempNode->next_; // Traverse the list until tempNode is the last node (last node always points to NULL)
    }

    tempNode->next_ = topNode;
  }

  return headNode;
}

struct Node* pop(struct Node* headNode) {
  struct Node* tempNode;
  struct Node* tempNodeNext;

  if (headNode == NULL) {
    printf("ERROR: stack underflow!\n");
  }
  else if (headNode->next_ == NULL) { // we need an addition special case when we have to pop the headNode (and therefore headNode->next_ == NULL)
    free(headNode->next_);
    headNode = NULL;
  }
  else {

    tempNode     = headNode;
    tempNodeNext = headNode->next_;

    while (tempNodeNext->next_ != NULL) { // if headNode->next_ == NULL (case 2), we are dereferencing a null pointer here!!!
      tempNode     = tempNodeNext;
      tempNodeNext = tempNodeNext->next_;
    }

    // at this point tempNodeNext->next_ == NULL
    //               tempNode->next_     == tempNodeNext
    free(tempNodeNext);
    tempNode->next_ = NULL;
  }

  return headNode;
}

void display(struct Node* headNode){
  if (headNode == NULL) {
    printf("Empty stack\n");
  }

  while (headNode != NULL) {
    printf("%d ", headNode->data_);
    headNode = headNode->next_;
  }

  printf("\n");
}
