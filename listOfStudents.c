#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining here a struct to store the data of each student
struct Student {
  char index_[15];
  char name_[15];
  char surname_[15];
  char fathername_[15];
  char address_[15];
  char homeNumber_[15];
  char mobileNumber_[15];
  char course_[];
};

// Defining here a linked list of students
struct Node {
  struct Student *student_; // The item of each node of the list is the address of a student
  struct Node *next_;       // Points to the node which finds itself next to the current node
};

// Forward declarations
void readStudentData(struct Student *student);
void printStudentData(struct Student *student);
void display(struct Node *headNode);

struct Node *createNewNode(struct Node *studentList, struct Student *student);


int main()
{
  int numberOfStudents;

  printf("Please specify the number of students: ");
  scanf("%d", &numberOfStudents);

  // Dynamic allocation of student array
  struct Student *studentArray = (struct Student *)malloc(sizeof(struct Student) * numberOfStudents);

  // Create an instance of the list here
  struct Node *studentList = NULL; // We can think of this as being the head of the list

  for (int ii=0; ii<numberOfStudents; ++ii)
  {
    readStudentData(&studentArray[ii]);

    if (!strcmp(studentArray[ii].course_, "python"))
    {
      studentList = createNewNode(studentList, &studentArray[ii]);
    }
  }

  //printf("studentList address is %p\n", studentList); // Keep this line for debugging

  for (int ii=0; ii<numberOfStudents; ++ii)
  {
    printStudentData(&studentArray[ii]);
  }

  printf("---------------------------\n");
  printf("The following students chose python:\n");
  display(studentList);

  free(studentList); // FIXME: List is not properly deallocated here -> all nodes of the list need to be deallocated (not just the head)
  free(studentArray);

  return 0;
}

struct Node *createNewNode(struct Node *headNode, struct Student *student)
{
  struct Node *newNode;
  struct Node *tempNode;

  // Allocate memory for the new node of the list
  newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->student_ = student;
  newNode->next_    = NULL;

  // printf("newNode address is %p\n", newNode); // Keep this line for debugging

  if (headNode == NULL)
  { // Case of empty list
    headNode = newNode;
  }
  else
  { // Case of non-empty list
    tempNode = headNode;  // Assign tempNode to head to start traversing the list

    while(tempNode->next_ != NULL)
    {
      tempNode = tempNode->next_; // Traverse the list until tempNode is the last node (last node always points to NULL)
    }

    tempNode->next_ = newNode;
  }

  // printf("headNode address is %p\n", headNode); // Keep this line for debugging

  return headNode; // return headNode (start of the list) to main
                   // the starting node is always the same but the last node is always new and the size of the list is increased by one node
}


void readStudentData(struct Student *student)
{
  printf("Insert index of new student: ");
  scanf("%s", student->index_);
  printf("Insert name of new student: ");
  scanf("%s", student->name_);
  printf("Insert surname of new student: ");
  scanf("%s", student->surname_);
  printf("Insert fathername of new student: ");
  scanf("%s", student->fathername_);
  printf("Insert address of new student: ");
  scanf("%s", student->address_);
  printf("Insert homeNumber of new student: ");
  scanf("%s", student->homeNumber_);
  printf("Insert mobileNumber of new student: ");
  scanf("%s", student->mobileNumber_);
  printf("Insert course selected by the new student: ");
  scanf("%s", student->course_);
  printf("\n");
}

void printStudentData(struct Student *student)
{
  printf("---------------------------\n");
  printf("Printing data of student %s below:\n\n", student->index_);
  printf("Name: %s\n", student->name_);
  printf("Surname: %s\n", student->surname_);
  printf("Fathername: %s\n", student->fathername_);
  printf("Address: %s\n", student->address_);
  printf("Home number: %s\n", student->homeNumber_);
  printf("Mobile number: %s\n", student->mobileNumber_);
  printf("Course: %s\n", student->course_);
}

void display(struct Node *headNode)
{
  if (headNode == NULL)
  {
    printf("Empty list\n");
  }

  while (headNode != NULL)
  {
    printf("%s  ", headNode->student_->name_);
    headNode = headNode->next_;
  }

  printf("\n");
}
