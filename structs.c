#include <stdio.h>

struct Employee {
  int age;
  float wage;
};

void function(struct Employee *employee);

int main() {
  int x;

  struct Employee employee1; // attributes
  struct Employee employee2;

  employee1.age = 25;
  employee1.wage = 2000.;


  employee2.wage = 2500.0;

  printf("Please give the age of employee 2: ");
  scanf("%d", &employee2.age);

  //printf("employee 1 is %d years old\n", employee1.age);


  printf("Printing age of employee 2:\n");
  function(&employee2);

  return 0;
}

void function(struct Employee* employee) { // struct Employee* employee = &employee1
  printf("employee 2 is %d years old\n", (*employee).age);
  printf("employee 2 is %d years old\n",  employee->age); // arrow operator
}
