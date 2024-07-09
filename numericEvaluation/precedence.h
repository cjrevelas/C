#ifndef PRECEDENCE_H
#define PRECEDENCE_H

bool HasHigherPrecedence(char ch1, char ch2) {  // ch1: top of stackOper, ch2: current operator in infix scanning
  bool precedence = false;

  if ( (ch1=='-') && (ch2=='*') ) {
    precedence = false;
  }
  else if ( (ch1=='+') && (ch2=='*') ) {
    precedence = false;
  }
  else if ( (ch1=='*') && (ch2=='-') ) {
    precedence = true;
  }
  else if ( (ch1=='*') && (ch2=='+') ) {
    precedence = true;
  }
  else if ( (ch1=='+') && (ch2=='-') ) {
    precedence = true;
  }
  else if ( (ch1=='-') && (ch2=='+') ) {
    precedence = true;
  }
  else if ( (ch1=='(') && (ch2=='+') ) {
    precedence = false;
  }
  else if ( (ch1=='(') && (ch2=='-') ) {
    precedence = false;
  }
  else if ( (ch1=='(') && (ch2=='*') ) {
    precedence = false;
  }
  else if ( (ch1==')') && (ch2=='-') ) {
    precedence = false;
  }
  else if ( (ch1==')') && (ch2=='+') ) {
    precedence = false;
  }
  else if ( (ch1==')') && (ch2=='-') ) {
    precedence = false;
  }
  else if ( (ch1=='+') && (ch2=='(') ) {
    precedence = true;
  }
  else if ( (ch1=='-') && (ch2=='(') ) {
    precedence = true;
  }
  else if ( (ch1=='*') && (ch2=='(') ) {
    precedence = true;
  }
  else if ( (ch1=='+') && (ch2==')') ) {
    precedence = true;
  }
  else if ( (ch1=='-') && (ch2==')') ) {
    precedence = true;
  }
  else if ( (ch1=='*') && (ch2==')') ) {
    precedence = true;
  }

  return precedence;
}

#endif // PRECEDENCE_H
