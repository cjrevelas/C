#include <stdio.h>

typedef struct _Calculator {
    int (*Add)(int xx, int yy);
    int (*Subtract)(int xx, int yy);
    int (*Multiply)(int xx, int yy);
    int (*Divide)(int xx, int yy);
} Calculator;

int Add(int xx, int yy) { return xx + yy; }
int Subtract(int xx, int yy) { return xx - yy; }
int Multiply(int xx, int yy) { return xx * yy; }
int Divide(int xx, int yy) { return xx / yy; }

int main() {
    Calculator calc = {&Add, &Subtract, &Multiply, &Divide};
    Calculator *pCalc = &calc;
    printf("The sum is equal to: %d\n", pCalc->Add(5,2));
    printf("The difference is equal to %d\n", pCalc->Subtract(5,2));
    printf("The product is equal to %d\n", pCalc->Multiply(5,2));
    printf("The quotient is equal to %d\n", pCalc->Divide(5,2));

    return 0;
}