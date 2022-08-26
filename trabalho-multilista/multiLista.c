#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "multiLista.h"

Palavra *criarPalavra(char *token, int nLinha, int nColuna) {
  Palavra *p = malloc(sizeof(Palavra));
  p->nLinha = nLinha;
  p->nColuna = nColuna;
  strcpy(p->palavra, token);

  return p;
}

Linha *criarLinha(char *linha, int nLinha) {
  Linha *l = malloc(sizeof(Linha));
  int qtdPalavras = 0;
  int nColuna = 1;
  char *token;

  token = strtok(linha, " ");

  if (token == NULL) return NULL;

  l->primeiraPalavra = criarPalavra(token, nLinha, nColuna);
  Palavra *palavraAtual = l->primeiraPalavra;
  nColuna += strlen(token) + 1;
  qtdPalavras++;

  token = strtok(NULL, " ");

  while (token != NULL) {
    Palavra *p = criarPalavra(token, nLinha, nColuna);

    palavraAtual->prox = p;
    p->ant = palavraAtual;
    palavraAtual = palavraAtual->prox;

    qtdPalavras++;
    nColuna += strlen(token) + 1;

    token = strtok(NULL, " ");
  }

  l->qtdPalavras = qtdPalavras;
  l->nLinha = nLinha;

  return l;
}

Multilista *criarMultilista(char *nomeArquivo) {
  Multilista *m = malloc(sizeof(Multilista));
  FILE *arquivo = fopen(nomeArquivo, "rt");
  char *strLinha = malloc(100 * sizeof(char));
  int qtdLinhas = 0;

  if (feof(arquivo)) return NULL;

  qtdLinhas++;
  fgets(strLinha, 100, arquivo);
  strLinha[strcspn(strLinha, "\n")] = 0;
  m->primeiraLinha = criarLinha(strLinha, qtdLinhas);
  Linha *linhaAtual = m->primeiraLinha;

  while(!feof(arquivo)) {
    qtdLinhas++;

    fgets(strLinha, 100, arquivo);
    strLinha[strcspn(strLinha, "\n")] = 0;
    Linha *l = criarLinha(strLinha, qtdLinhas);

    linhaAtual->prox = l;
    l->ant = linhaAtual;
    linhaAtual = linhaAtual->prox;
  }

  m->qtdLinhas = qtdLinhas;

  fclose(arquivo);

  return m;
}

void imprimirConteudo(Multilista *multilista) {
  Linha *linhaAtual = multilista->primeiraLinha;

  printf("------------ MULTILISTA ------------\n");
  printf("- legenda : (coluna) - \"palavra\" -\n\n");

  while (linhaAtual != NULL) {
    printf("------------ LINHA %d ------------\n", linhaAtual->nLinha);
    Palavra *palavraAtual = linhaAtual->primeiraPalavra;
    while (palavraAtual != NULL) {
      printf("(%d) - \"%s\", ", palavraAtual->nColuna, palavraAtual->palavra);
      palavraAtual = palavraAtual->prox;
    }
    printf("\n");
    linhaAtual = linhaAtual->prox;
  }
}

// MultiList *createMultiList(char *fileName) {
//   MultiList *multiList;
//   FILE *file = fopen(fileName, "rt");

//   multiList->qtyLines = 0;

//   char *linha = malloc(100 * sizeof(char));
//   char *token;

//   while (!feof(file)) {
//     fgets(linha, 100, file);

//     List

//     token = strtok(linha, " ");

//     while (token != NULL) {

//     }
//   }
// }

// Multilista *criarMultilista(char *nomeArquivo) {
//   FILE *arquivo = fopen(nomeArquivo, "rt");
//   Multilista *multilista;

//   multilista->qtdLinhas = 0;
//   multilista->primeira = malloc(sizeof(Linha));
//   Linha *linhaAtual = multilista->primeira;

//   int nLinhaAtual = 0;
//   int nColunaAtual = 0;

//   while (!feof(arquivo)) {
//     char *linha = malloc(100 * sizeof(char));
//     char *token;
//     Palavra *palavraAtual = linhaAtual->primeira;

//     fgets(linha, 100, arquivo);
//     token = strtok(linha, " ");

//     while (token != NULL) {
//       Palavra *novaPalavra = malloc(sizeof(Palavra));
//       novaPalavra->palavra = token;
//       novaPalavra->ant = palavraAtual;
//       novaPalavra->pos = {}
//     }

//     free(linha);
//     free(token);
//   }
// }

/*

x
|-x
x

x
|-x
x

(x)
 |-(x)
(x) |
    |-(x)
(x) |  |
 |-(x) |
(x)    |
       |-(x)
(x)    |
 |-(x) |
(x) |  |
    |-(x)
(x) |
 |-(x)
(x)

(---)
  |--(---)
(---)  |
       |--(---)
(---)  |    |
  |--(---)  |
(---)       |
            |--(---)
(---)       |    |
  |--(---)  |    |
(---)  |    |    |
       |--(---)  |
(---)  |         |
  |--(---)       |
(---)            |
                 |--(---)
(---)            |
  |--(---)       |
(---)  |         |
       |--(---)  |
(---)  |    |    |
  |--(---)  |    |
(---)       |    |
            |--(---)
(---)       |
  |--(---)  |
(---)  |    | 
       |--(---)
(---)  |
  |--(---)
(---)

*/