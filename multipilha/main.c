#include <stdio.h>
#include <stdlib.h>
#include "multipilha.h"

void mostrarMultipilha(struct multipilha *m) {
  int i = 0;

  printf("[");

  while (i <= m->topo1) {
    printf("(%d,%d),", m->vetor[i].x, m->vetor[i].y);
    i++;
  }

  while (i > m->topo1 && i < m->topo2) {
    printf("(-,-),");
    i++;
  }

  while (i >= m->topo2 && i < m->tamanho) {
    printf("(%d,%d),", m->vetor[i].x, m->vetor[i].y);
    i++;
  }

  printf("]");
}

int main(void) {
  struct multipilha *m = criarMultipilha(10);
  int op;

  do {
    system("clear");
    mostrarMultipilha(m);

    printf("[1] Inserir elemento na pilha 1\n");
    printf("[2] Inserir elemento na pilha 2\n");
    printf("[3] Remover elemento na pilha 1\n");
    printf("[4] Remover elemento na pilha 2\n");
    printf("[0] Sair do programa\n");
    printf("Sua opcao: ");
    scanf("%d", &op);

    switch (op) {
      case 1:

        break;
      case 2:
        break;
      case 3:
        break;
      default:
        break;
    }

  } while (op != 0);
}