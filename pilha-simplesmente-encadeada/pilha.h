#include <stdio.h>

struct dados {
  int x;
  int y;
};

struct info {
  struct dados dados;
  struct info *abaixo;
};

struct descritorPSE {
  struct info *topo;
};

void inserirPSE(struct descritorPSE *pilha, struct dados dados);

void removerPSE(struct descritorPSE *pilha);

void inverterPSE(struct descritorPSE *pilha);

void exibirPSE(struct descritorPSE *pilha);

void exibirTamanhoPSE(struct descritorPSE *pilha);
