#include <stdio.h>
#include <stdlib.h>
#include "./PSE.h"

#include "./exercicio1/buscaNaBase.h"

int main(void) {
  Pilha pilha = novaPilha();

  ParOrdenado p1 = {1, 2};
  ParOrdenado p2 = {3, 4};
  ParOrdenado p3 = {5, 6};
  ParOrdenado p4 = {7, 8};
  ParOrdenado p5 = {9, 0};

  mostrarPilha(pilha);
  inserirElemento(&pilha, p1);
  mostrarPilha(pilha);
  inserirElemento(&pilha, p2);
  mostrarPilha(pilha);
  inserirElemento(&pilha, p5);
  mostrarPilha(pilha);
  inserirElemento(&pilha, p4);
  mostrarPilha(pilha);
  removerElemento(&pilha);
  mostrarPilha(pilha);
  // removerElemento(&pilha);
  // mostrarPilha(pilha);
  // removerElemento(&pilha);
  // mostrarPilha(pilha);

  Elem e = buscaNaBase(&pilha);

  mostrarElemento(buscaNaBase(&pilha));

  return 0;
}