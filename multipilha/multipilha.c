#include "multipilha.h"
#include <stdlib.h>

struct multipilha *criarMultipilha(int tam) {
  struct multipilha *m = malloc(sizeof(struct multipilha));
  m->tamanho = tam;
  m->topo1 = -1;
  m->topo2 = tam;
  m->vetor = malloc(tam * sizeof(struct dados));

  return m;
}

void destruirMultipilha(struct multipilha *m) {
  free(m->vetor);
  free(m);
}

void reiniciarMultipilha(struct multipilha *m) {
  m->topo1 = -1;
  m->topo2 = m->tamanho;
}

void reiniciarP1(struct multipilha *m) {
  m->topo1 = -1;
}

void reiniciarP2(struct multipilha *m) {
  m->topo2 = m->tamanho;
}

void inserirP1(struct multipilha *m, struct dados d) {
  if (m->topo1 >= m->topo2 - 1)
    return;

  m->topo1++;
  m->vetor[m->topo1] = d;
}

void inserirP2(struct multipilha *m, struct dados d) {
  if (m->topo2 <= m->topo1 + 1)
    return;

  m->topo2--;
  m->vetor[m->topo2] = d;
}

void removerP1(struct multipilha *m) {
  if (m->topo1 == -1)
    return;

  m->topo1--;
}

void removerP2(struct multipilha *m) {
  if (m->topo2 == m->tamanho)
    return;

  m->topo2++;
}

int pilhaCheia(struct multipilha *m) {
  if (m->topo1 == m->topo2 - 1)
    return 1;
  else
    return 0;
}

int pilhaVazia(struct multipilha *m) {
  if (m->topo1 == -1 && m->topo2 == m->tamanho)
    return 1;
  else
    return 0;
}

struct dados buscaTopoP1(struct multipilha *m) {
  if (m->topo1 == -1)
    return;

  struct dados d = m->vetor[m->topo1];
  return d;
}

struct dados buscaTopoP2(struct multipilha *m) {
  if (m->topo2 == m->tamanho)
    return;

  struct dados d = m->vetor[m->topo2];
  return d;
}

int obterQtd(struct multipilha *m) {
  int qtd = (m->topo1 + 1) + (m->tamanho - m->topo2);
  return qtd;
}

int obterQtdP1(struct multipilha *m) {
  int qtd = m->topo1 + 1;
  return qtd;
}

int obterQtdP2(struct multipilha *m) {
  int qtd = m->tamanho - m->topo2;
  return qtd;
}