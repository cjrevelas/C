#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "precedence.h"
#include "isOperator.h"
#include "stackOperator.h"
#include "stackNumber.h"

int main() {

  char infixExpression[]   = "2+((10-3)*(8+3))";
  char postfixExpression[] = "          ";

  //--------------------------------------INFIX TO POSTFIX CONVERSION START--------------------------------------------------//
  int topOperatorIndex  = -1; // -1 means empty stack
  int numberOfOperators = 10;

  char stackOfOperators[numberOfOperators];

  int jj = 0;

  for (int ii=0; ii<strlen(infixExpression); ++ii) {
    char ch = infixExpression[ii];

    if ( !IsOperator(ch) ) {
      postfixExpression[jj] = ch;
      //printf("postfix expression %d: %c\n", jj, postfixExpression[jj]);
      ++jj;
    }

    else if ( IsOperator(ch) && (ch!='(') && (ch!=')') ) {
      while( (topOperatorIndex!=-1) && (HasHigherPrecedence(stackOfOperators[topOperatorIndex], ch)) && (stackOfOperators[topOperatorIndex] != '(') ) {

        postfixExpression[jj] = stackOfOperators[topOperatorIndex];
        popOperator(stackOfOperators, &topOperatorIndex);

        //printf("operator stack: ");
        //displayStackOfOperators(stackOfOperators, topOperatorIndex);

        //printf("postfix expression %d: %c\n", jj, postfixExpression[jj]);

        ++jj;
      }

      pushOperator(stackOfOperators, ch, &topOperatorIndex, numberOfOperators);

      //printf("operator stack: ");
      //displayStackOfOperators(stackOfOperators, topOperatorIndex);
    }
    else if (ch == '(') {
      pushOperator(stackOfOperators, ch, &topOperatorIndex, numberOfOperators);

      //printf("operator stack: ");
      //displayStackOfOperators(stackOfOperators, topOperatorIndex);
    }
    else if (ch == ')') {
      while( (topOperatorIndex!=-1) && (stackOfOperators[topOperatorIndex] != '(') ) {

        postfixExpression[jj] = stackOfOperators[topOperatorIndex];
        popOperator(stackOfOperators, &topOperatorIndex);

        //printf("operator stack: ");
        //displayStackOfOperators(stackOfOperators, topOperatorIndex);
        //printf("Postfix expression %d: %c\n", jj, postfixExpression[jj]);

        ++jj;
      }

      popOperator(stackOfOperators, &topOperatorIndex);

      //printf("operator stack: ");
      //displayStackOfOperators(stackOfOperators, topOperatorIndex);
    }
  }

  // jj = 9 = 10 - 1 = postfix_length - number of elements remaining in the operator stack

  for (int ii=jj; ii<strlen(postfixExpression); ++ii) {
    postfixExpression[ii] = stackOfOperators[topOperatorIndex];
    popOperator(stackOfOperators, &topOperatorIndex);

    //printf("postfix expression %d: %c\n", ii, postfixExpression[ii]);
  }

  //displayStackOfOperators(stackOfOperators, topOperatorIndex);

  printf("final postfix expression: ");
  for (int ii=0; ii<strlen(postfixExpression); ++ii) {
    printf("%c ", postfixExpression[ii]);
  }

  printf("\n");
  //--------------------------------------INFIX TO POSTFIX CONVERSION END--------------------------------------------------//

  //--------------------------------------EVALUATION OF POSTFIX EXPRESSION-------------------------------------------------//
  int numbers = 5;

  int digits[5] = {1,2,1,1,1}; // [2, 10, 3, 8, 3]

  int topNumberIndex = -1;

  int stackOfNumbers[numbers];

  int kk  = 0;
  int res = 0;

  printf("\n");
  printf("Evaluating expression using stack of numbers:\n");

  for (int ii=0; ii<strlen(postfixExpression)+0; ++ii) {
    char ch = postfixExpression[ii];

    if ( (!IsOperator(ch)) && (digits[kk] == 1) ) {
      char temp[2] = {ch}; // +null terminator
      pushNumber(stackOfNumbers, atoi(temp), &topNumberIndex, numbers);

      ++kk;

      displayStackOfNumbers(stackOfNumbers, topNumberIndex);
    }
    else if ( (!IsOperator(ch)) && (digits[kk] == 2) ) {
      ++ii;
      char temp[3] = {ch, postfixExpression[ii]}; // + null terminator
      pushNumber(stackOfNumbers, atoi(temp), &topNumberIndex, numbers);

      ++kk;

      displayStackOfNumbers(stackOfNumbers, topNumberIndex);
    }
    if (ch == '+') {

      res = stackOfNumbers[topNumberIndex-1] + stackOfNumbers[topNumberIndex];

      popNumber(stackOfNumbers, &topNumberIndex);
      popNumber(stackOfNumbers, &topNumberIndex);

      pushNumber(stackOfNumbers, res, &topNumberIndex, numbers);

      displayStackOfNumbers(stackOfNumbers, topNumberIndex);
    }
    if (ch == '-') {
      res = stackOfNumbers[topNumberIndex-1] - stackOfNumbers[topNumberIndex];

      popNumber(stackOfNumbers, &topNumberIndex);
      popNumber(stackOfNumbers, &topNumberIndex);

      pushNumber(stackOfNumbers, res, &topNumberIndex, numbers);

      displayStackOfNumbers(stackOfNumbers, topNumberIndex);
    }
    if (ch == '*') {
      res = stackOfNumbers[topNumberIndex-1] * stackOfNumbers[topNumberIndex];

      popNumber(stackOfNumbers, &topNumberIndex);
      popNumber(stackOfNumbers, &topNumberIndex);

      pushNumber(stackOfNumbers, res, &topNumberIndex, numbers);

      displayStackOfNumbers(stackOfNumbers, topNumberIndex);
    }
  }

  printf("\n");
  printf("Final result of the arithmetic expression: ");
  displayStackOfNumbers(stackOfNumbers, topNumberIndex);
  printf("\n");

  return 0;
}
