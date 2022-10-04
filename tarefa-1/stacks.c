#include <stdio.h>
#include <stdlib.h>
#include "stacks.h"

LinkedStack *createLinkedStack() {
  LinkedStack *stack = malloc(sizeof(LinkedStack));
  stack->qtyNodes = 0;
  return stack;
};


void deleteLinkedStack(LinkedStack *stack) {
  LinkedStackNode *aux1 = stack->head, *aux2 = stack->head;

  while (aux1 != NULL) {
    aux1 = aux1->prev;
    free(aux2);
    aux2 = aux1;
  }

  free(stack);
};


void stackupLinked(LinkedStack *stack, double d) {
  LinkedStackNode *newElem = malloc(sizeof(LinkedStackNode));
  newElem->d = d;
  newElem->prev = stack->head;
  stack->head = newElem;
  stack->qtyNodes++;
};


double unstackLinked(LinkedStack *stack) {
  if (stack->qtyNodes == 0)
    return '.';

  double d = stack->head->d;
  LinkedStackNode *newHead = stack->head->prev;
  free(stack->head);
  stack->head = newHead;
  stack->qtyNodes--;
  return d;
};


VectorStack *LStoVS(LinkedStack *stack) {
  VectorStack *vectorStack = malloc(sizeof(VectorStack));
  LinkedStackNode *aux = stack->head;
  int margin = 10;
  int sizeLS = 0;

  while (aux != NULL) {
    sizeLS++;
    aux = aux->prev;
  }

  double *v = malloc((sizeLS + margin) * sizeof(double));
  aux = stack->head;
  for (int i = sizeLS - 1; i >= 0; i--) {
    v[i] = aux->d;
    aux = aux->prev;
  }
  vectorStack->headIndex = sizeLS - 1;
  vectorStack->qtyNodes = sizeLS;
  vectorStack->stack = v;

  return vectorStack;
}


void printLinkedStack(LinkedStack *stack) {
  LinkedStackNode *aux = stack->head;

  LinkedStack *reverseStack = createLinkedStack();
  while (aux != NULL) {
    stackupLinked(reverseStack, aux->d);
    aux = aux->prev;
  }
  aux = reverseStack->head;

  printf("Pilha Encadeada\n");
  printf("[");
  while (aux != NULL) {
    printf("%.2lf", aux->d);
    if (aux->prev != NULL)
      printf("<-");
    aux = aux->prev;
  }
  printf(" (Head)]\n\n");
  deleteLinkedStack(reverseStack);
}


void printVectorStack(VectorStack *stack) {

  printf("Pilha sobre vetor\n");
  printf("[");
  for (int i = 0; i < stack->qtyNodes; i++) {
    printf("%.2lf", stack->stack[i]);
    if (i != stack->qtyNodes - 1)
      printf(",");
  }
  printf(" (Head)]\n\n");
}