#include <stdio.h>

int main() {
  // Writing to file
  FILE *fp_output;

  fp_output = fopen("io.txt", "w");

  fputs("A string\n", fp_output);

  int data = 5;
  fprintf(fp_output, "data: %d\n", data);

  for (int ii=0; ii<9; ++ii) {
    fprintf(fp_output, "%d\n", ii);
  }

  fclose(fp_output);

  // Reading from file
  FILE *fp_input;

  fp_input = fopen("io.txt", "r");

  fscanf(fp_input, "%d", &data);
  printf("new data value %d\n", data);

  fclose(fp_input);

  FILE *fp_input_string;

  fp_input_string = fopen("strings.txt", "r");

  char str1[40];
  char str2[40];

  fscanf(fp_input_string, "%s", str1);
  fscanf(fp_input_string, "%s", str2);

  printf("%s\n", str1);
  printf("%s\n", str2);

  fclose(fp_input_string);

  printf("Done!\n");

  return 0;
}
