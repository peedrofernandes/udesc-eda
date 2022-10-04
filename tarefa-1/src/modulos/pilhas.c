#include <stdio.h>
#include <stdlib.h>
#include "../headers/pilhas.h"

// -----------------------------------------------------
// Implementação de todas as funções do arquivo pilhas.h
// -----------------------------------------------------


// Funções de manipulação da Pilha Simplesmente Encadeada

PSE *criarPSE() {
  PSE *pilha = malloc(sizeof(PSE));
  pilha->qtdElems = 0;
  pilha->frente = NULL;
  return pilha;
};

void excluirPSE(PSE *pilha) {
  NoPSE *aux1 = pilha->frente, *aux2 = pilha->frente;

  while (aux1 != NULL) {
    aux1 = aux1->ant;
    free(aux2);
    aux2 = aux1;
  }

  free(pilha);
};

void empilharPSE(PSE *stack, double d) {
  NoPSE *novoElem = malloc(sizeof(NoPSE));
  novoElem->d = d;
  novoElem->ant = stack->frente;
  stack->frente = novoElem;
  stack->qtdElems++;
};

double desempilharPSE(PSE *pilha) {
  if (pilha->qtdElems == 0)
    return '.';

  double d = pilha->frente->d;
  NoPSE *novaFrente = pilha->frente->ant;
  free(pilha->frente);
  pilha->frente = novaFrente;
  pilha->qtdElems--;
  return d;
};


PE *PSE_PE(PSE *pilha) {
  PE *pe = malloc(sizeof(PE));
  NoPSE *aux = pilha->frente;
  int margem = 10;
  int tamPSE = 0;

  while (aux != NULL) {
    tamPSE++;
    aux = aux->ant;
  }

  double *v = malloc((tamPSE + margem) * sizeof(double));
  aux = pilha->frente;
  for (int i = tamPSE - 1; i >= 0; i--) {
    v[i] = aux->d;
    aux = aux->ant;
  }
  pe->indexFrente = tamPSE - 1;
  pe->qtdElems = tamPSE;
  pe->vet = v;

  return pe;
}


void imprimirPSE(PSE *stack) {
  NoPSE *aux = stack->frente;

  PSE *pseReversa = criarPSE();
  while (aux != NULL) {
    empilharPSE(pseReversa, aux->d);
    aux = aux->ant;
  }
  aux = pseReversa->frente;

  printf("[");
  while (aux != NULL) {
    printf("%.2lf", aux->d);
    if (aux->ant != NULL)
      printf("<-");
    aux = aux->ant;
  }
  printf(" (Frente)]\n\n");
  excluirPSE(pseReversa);
}


void imprimirPE(PE *pilha) {
  printf("[");
  for (int i = 0; i < pilha->qtdElems; i++) {
    printf("%.2lf", pilha->vet[i]);
    if (i != pilha->qtdElems - 1)
      printf(",");
  }
  printf(" (Frente)]\n\n");
}