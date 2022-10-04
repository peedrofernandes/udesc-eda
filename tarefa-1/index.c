#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "stacks.h"

int charToInt(char c) {
  return ((int)c) - 48;
}
char intToChar(int i) {
  return (char)(i + 48);
}

int isOperator(char c) {
  int boolean = (
    c == '+' ||
    c == '-' ||
    c == '*' ||
    c == '/' ||
    c == '%' ||
    c == '^'
  );

  return boolean;
};

double applyOperation(char c, double v1, double v2) {
  int result;

  if (c == '+')
    return v1 + v2;
  if (c == '-')
    return v1 - v2;
  if (c == '*')
    return v1 * v2;
  if (c == '/')
    return v1 / v2;
  if (c == '%')
    return (double)((int)v1 % (int)v2);
  if (c == '^')
    return pow(v1, v2);
}

double getResult(LinkedStack *stack, char *str) {
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      stackupLinked(stack, (double)(charToInt(str[i])));
    } else if (isOperator(str[i])) {
      double d2 = unstackLinked(stack);
      double d1 = unstackLinked(stack);
      double result = applyOperation(str[i], d1, d2);
      stackupLinked(stack, result);
    }
  }

  return stack->head->d;
}

int main() {
  LinkedStack *stack = createLinkedStack();
  double result = getResult(stack, "34+9814*+++");
  deleteLinkedStack(stack);
  printf("%.4lf\n", result);

  LinkedStack *linkedStack = createLinkedStack();
  stackupLinked(linkedStack, 1);
  stackupLinked(linkedStack, 2);
  stackupLinked(linkedStack, 3);

  VectorStack *vectorStack = LStoVS(linkedStack);

  printVectorStack(vectorStack);
  printLinkedStack(linkedStack);

  deleteLinkedStack(linkedStack);
}