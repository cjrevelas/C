#include <stdio.h>

void add_number(int x);
void modify_array(int array[]);
int sum_of_array_elements(int array[]);

int main() {
  int x = 5;
  add_number(x);
  printf("x: %d\n", x);


  int array[5] = {1, 2, 3, 4, 5};

  printf("initial array: \n");

  for (int i = 0; i<5; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");

  modify_array(array); // decays to a pointer at this point, so effectively it is passed by address (not value)
  printf("array[0]: %d\n", array[0]);

  printf("modified array: \n");

  for (int i = 0; i<5; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");


  printf("the sum of the array elements is %d \n", sum_of_array_elements(array));

  return 0;
}

void add_number(int x) {
  x += 1;
}

void modify_array(int array[]) {
  array[0] +=1 ;
  array[2] = 4 ;
}

int sum_of_array_elements(int array[]) {
  int sum_of_array;
  for (int i = 0; i<5; ++i) {
    sum_of_array += array[i];
  }

  return sum_of_array;
}
