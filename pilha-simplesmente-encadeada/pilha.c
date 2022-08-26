#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// void inserirPSE(struct descritorPSE *pilha, struct dados dados);

// void removerPSE(struct descritorPSE *pilha);

// void inverterPSE(struct descritorPSE *pilha);

// void exibirPSE(struct descritorPSE *pilha);

void inserirPSE(struct descritorPSE *pilha, struct dados dados) {
  struct info *novo = malloc(sizeof(struct info));
  novo->dados = dados;
  novo->abaixo = pilha->topo;
  pilha->topo = novo;
}

void removerPSE(struct descritorPSE *pilha) {
  if (pilha->topo == NULL)
    return;

  if (pilha->topo->abaixo == NULL) {
    free(pilha->topo);
    pilha->topo = NULL;
    return;
  }

  struct info *aux = pilha->topo->abaixo;
  free(pilha->topo);
  pilha->topo = aux;
}

void inverterPSE(struct descritorPSE *pilha) {
  struct info *aux = pilha->topo;
  struct info *proximo;
  struct info *anterior = NULL;

  while (aux != NULL) {
    proximo = aux->abaixo;
    aux->abaixo = anterior;
    anterior = aux;
    aux = proximo;
  }

  pilha->topo = anterior;
}

void exibirPSE(struct descritorPSE *pilha) {
  struct info *noPSE = pilha->topo;

  if (noPSE == NULL) {
    printf("[]\n");
    return;
  }

  printf("[");

  while (noPSE->abaixo != NULL) {
    printf("(%d,%d),", noPSE->dados.x, noPSE->dados.y);
    noPSE = noPSE->abaixo;
  }
  printf("(%d,%d)", noPSE->dados.x, noPSE->dados.y);

  printf("]\n");
}

void exibirTamanhoPSE(struct descritorPSE *pilha) {
  struct info *noPSE = pilha->topo;
  int qtd = 0;

  while (noPSE != NULL) {
    qtd++;
    noPSE = noPSE->abaixo;
  }

  printf("Tamanho atual da pilha: %d\n\n", qtd);
}
