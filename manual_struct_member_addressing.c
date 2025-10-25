#include <stdio.h>
#include <stdlib.h>

typedef struct Employee {
    unsigned int id;
    unsigned int age;
    unsigned int *salary;
} Employee;

int main()
{
    unsigned int emp1_salary[3] = { 100, 200, 300 };
    unsigned int emp2_salary[3] = { 400, 500, 600 };

    printf("-----------------------------------\n");
    printf("pointer size: %d\n", sizeof((void *)emp1_salary));
    printf("-----------------------------------\n");
    printf("array1: %x\n", emp1_salary);
    printf("&array1: %x\n", &emp1_salary);
    printf("array2: %x\n", emp2_salary);
    printf("&array2: %x\n", &emp2_salary);
    printf("-----------------------------------\n");

    Employee *emp1 = (Employee *)malloc(sizeof(Employee));
    Employee *emp2 = (Employee *)malloc(sizeof(Employee));

    emp1->id = 20;
    emp1->age = 25;
    emp1->salary = emp1_salary;

    emp2->id = 30;
    emp2->age = 35;

    printf( "&emp1: %x\n", &emp1 );
    printf( "&(*emp1): %x\n", &(*emp1) );
    printf( "&(emp1->id): %x\n", &(emp1->id) );
    printf( "&(emp1->age): %x\n", &(emp1->age) );
    printf( "&(emp1->salary): %x\n", &(emp1->salary) );
    printf( "emp1->id: %u\n", emp1->id );
    printf( "emp1->age: %u\n", emp1->age );
    printf( "emp1->salary: %x\n", emp1->salary );
    printf( "emp1: %x\n", emp1 );
    printf( "&emp1->salary: %x\n", (unsigned int *)(emp1)+2 );
    printf( "emp1->salary: %x\n", *( (unsigned int *)(emp1)+2 ) ); // = &emp1->salary[0]
    printf( "&emp1->salary[0]: %x\n", &emp1->salary[0] ); // = &emp1->salary[0]
    printf( "emp1->salary[0]: %u\n", *(unsigned int *)( *( (unsigned int *)(emp1)+2 ) + 0*4 ) );
    printf( "&emp1->salary[1]: %x\n", ( *( (unsigned int *)(emp1)+2 ) + 1*4 ) );
    printf( "emp1->salary[1]: %u\n", *(unsigned int *)( *( (unsigned int *)(emp1)+2 ) + 1*4 ) );
    printf( "&emp1->salary[2]: %x\n", ( *( (unsigned int *)(emp1)+2 ) + 2*4 ) );
    printf( "&emp1->salary[2]: %x\n", &emp1_salary[2] );
    printf( "emp1->salary[2]: %u\n", *(unsigned int *)( *( (unsigned int *)(emp1)+2 ) + 2*4 ) );
    printf( "emp1->salary[2]: %u\n", emp1_salary[2] );
    printf( "%x\n", &(emp1->age)-(unsigned int *)(emp1) );
    printf("-----------------------------------\n");


    // R3 = emp1                                                                 : address of struct storing the data of employee 1
    // L_SALARY_POINTER(R3)  = (unsigned int *)(emp1) + 2      = &(emp1->salary) : address of the pointer member 
    // @L_SALARY_POINTER(R3) = *( (unsigned int *)(emp1) + 2 ) = emp1->salary    : address of the array of salaries of employee 1
    // Accessing the third element of the arrays



    return 0;
}

