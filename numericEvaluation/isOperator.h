#ifndef IS_OPERATOR_H
#define IS_OPERATOR_H

bool IsOperator(char ch) {
  bool oper = false;

  if ( (ch == '+') || (ch == '-') || (ch == '*') || (ch == '(') || (ch == ')') ) {
    oper = true;
  }

  return oper;
}

#endif // IS_OPERATOR_H
