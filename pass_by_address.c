void addTwo(int k);

int main() {

  int x = 5;

  int* y = &x; // Pointer declaration and initialization

  printf("The value of x is: %d\n", x);
  printf("The value of x is: %d\n\n", *y);

  printf("The address of x is: %p\n", &x);
  printf("The address of x is: %p\n\n", y);

  addTwo(x);  // This is exactly the same as writing addTwo(5)

  printf("adding..\n");
  printf("The value of x is: %d\n", x);

  return 0;
}

void addTwo(int k) { // This creates a new variable k and just gives it the value 5
  printf("Getting inside the function.\n");
  k += 2; // k = k + 2
  printf("The value of k is: %d\n",k);
  printf("Getting out of the function and returning to main.\n");
}

void addTwoNew(int* y) {  // Reminder: asterisk here is used for pointer declaration
  *y = *y + 2;            // Reminder: asterisk here is used for pointer dereferencing
}


// Dereferencing of the pointer
//int z = *y; // equivalent to: int z = 5;  (this is pointer dereferencing)

//int* z = y; // equivalent to: int* z = &x; (this is pointer declaration)