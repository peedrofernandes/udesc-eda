#ifndef STACKS_H
#define STACKS_H

typedef struct linkedStackNode {
  double d;
  struct linkedStackNode *prev;
} LinkedStackNode;

typedef struct linkedStack {
  LinkedStackNode *head;
  int qtyNodes;
} LinkedStack;

LinkedStack *createLinkedStack();
void deleteLinkedStack(LinkedStack *stack);

void stackupLinked(LinkedStack *stack, double d);
double unstackLinked(LinkedStack *stack);

typedef struct vectorStack {
  int headIndex;
  int qtyNodes;
  double *stack;
} VectorStack;

VectorStack *createVectorStack();
void deleteVectorStack(VectorStack *stack);

void stackupVector(VectorStack *stack, double d);
char unstackVector(VectorStack *stack);

VectorStack *LStoVS(LinkedStack *stack);

void printLinkedStack(LinkedStack *stack);
void printVectorStack(VectorStack *stack);

#endif