#include <stdio.h>

#ifndef MULTI_LISTA_H

#define MULTI_LISTA_H

typedef struct palavra {
  struct palavra *ant;
  char palavra[50];
  int nLinha;
  int nColuna;
  struct palavra *prox;
} Palavra; // Nó da lista que representa uma linha

typedef struct linha {
  struct linha *ant;
  Palavra *primeiraPalavra;
  int nLinha;
  int qtdPalavras;
  struct linha *prox;
} Linha; // Descritor da lista que representa uma linha (nó: palavra)

typedef struct multilista {
  Linha *primeiraLinha;
  int qtdLinhas;
} Multilista; // Descritor da lista cujos nós serão outros descritores de listas que representam linhas

// Criação da lista com base no arquivo
Palavra *criarPalavra(char *palavra, int nLinha, int nColuna);
Linha *criarLinha(char *linha, int nLinha);
Multilista *criarMultilista(char *nomeArquivo);

// a)
void imprimirConteudo(Multilista *m);

// b)
void obterPosicao(Multilista *multilista, char *token);

// c)
void removerPalavra(Multilista *multilista, char *token);
// d)
void removerPosicao(Multilista *m, int nLinha, int nColuna);

// e)
int obterOcorrencias(Multilista *m, char *token);

// f)
int obterQtdPalavras(Multilista *m);

// g)
void alterarPalavra(Multilista *m, int nLinha, int nColuna, char *palavra);

// h)
void inserirPalavra(Multilista *m, int nLinha, char *palavra);

// i
void obterOcorrenciasDeSubstring(Multilista *m, char *substr);

// j)
void salvarArquivo(Multilista *m);

//Funções Auxiliares
void lerLinhaColuna(int *linha, int *coluna);

void lerPalavra(char *palavra);

void atualizarIndices(Palavra *p);

#endif
