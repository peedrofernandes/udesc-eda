#ifndef PILHAS_H
#define PILHAS_H

// Estrutura dos nós da Pilha Simplesmente Encadeada
typedef struct noPSE {
  double d;
  struct noPSE *ant;
} NoPSE;

// Estrutura do descritor da Pilha Simplesmente Encadeada
typedef struct pse {
  NoPSE *frente;
  int qtdElems;
} PSE;

// Estrutura da Pilha Estática
typedef struct pe {
  int indexFrente;
  int qtdElems;
  double *vet;
} PE;

// Funções de manipulação da Pilha Simplesmente Encadeada
PSE *criarPSE();
void excluirPSE(PSE *pilha);
void empilharPSE(PSE *pilha, double d);
double desempilharPSE(PSE *pilha);

// Funções de manipulação da Pilha Estática
PE *criarPE();
void excluirPE(PE *pilha);
void empilharPE(PE *pilha, double d);
char desempilharPE(PE *pilha);

// Função de transformação de PSE para PE
PE *PSE_PE(PSE *pilha);

// Funções de impressão das pilhas
void imprimirPSE(PSE *pilha);
void imprimirPE(PE *pilha);

#endif