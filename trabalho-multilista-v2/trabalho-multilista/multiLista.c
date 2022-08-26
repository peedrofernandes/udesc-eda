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
  int qtdLinhas = 0;
  char *strLinha = malloc(100 * sizeof(char));

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

// c)

void removerPalavra(Multilista *m, char *palavra) {

}

// Funções - Pedro

// h)

void inserirPalavra(Multilista *m, int nLinha, char *palavra) {
  Linha *ptrLinha = m->primeiraLinha;

  for (int i = 2; i <= nLinha; i++)
    ptrLinha = ptrLinha->prox;

  Palavra *ptrUltimaPalavra = ptrLinha->primeiraPalavra;

  while (ptrUltimaPalavra->prox != NULL)
    ptrUltimaPalavra = ptrUltimaPalavra->prox;

  int nColuna = ptrUltimaPalavra->nColuna + strlen(ptrUltimaPalavra->palavra) + 1;

  Palavra *p = criarPalavra(palavra, nLinha, nColuna);

  ptrUltimaPalavra->prox = p;
  ptrLinha->qtdPalavras++;
}

// i)

void obterOcorrenciasDeSubstring(Multilista *m, char *substr) {
  Linha *ptrLinha = m->primeiraLinha;
  Palavra *ptrPalavra;
  int nOcorrencias = 0;

  printf("\n\nOcorrencias da substring '%s'\n\n", substr);

  while (ptrLinha != NULL) {
    ptrPalavra = ptrLinha->primeiraPalavra;
    
    while (ptrPalavra != NULL) {
      char *token = strstr(ptrPalavra->palavra, substr);

      if (token != NULL) {
        nOcorrencias++;
        printf("OCORRENCIA %d \n", nOcorrencias);
        printf("Palavra: %s\n", ptrPalavra->palavra);
        printf("(Linha, coluna): (%d,%d)\n", ptrPalavra->nLinha, ptrPalavra->nColuna);
      }

      ptrPalavra = ptrPalavra->prox;
    }

    ptrLinha = ptrLinha->prox;
  }
}

// j)

void salvarArquivo(Multilista *m) {
  FILE *arqTemp = fopen("arqTemp.txt", "wt");

  Linha *ptrLinha = m->primeiraLinha;
  Palavra *ptrPalavra;

  while (ptrLinha != NULL) {
    ptrPalavra = ptrLinha->primeiraPalavra;
    while (ptrPalavra != NULL) {
      fputs(ptrPalavra->palavra, arqTemp);
      fputc(' ', arqTemp);
      ptrPalavra = ptrPalavra->prox;
    }
    fputc('\n', arqTemp);
    ptrLinha = ptrLinha->prox;
  }

  fclose(arqTemp);

  rename("arquivo.txt", "arquivoOLD.txt");
  rename("arqTemp.txt", "arquivo.txt");
}