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

// Funções - Pedro

// h)

void inserirPalavra(Multilista *m, int nLinha, char *palavra) {
  Linha *ptrLinha = m->primeiraLinha;
  Palavra *ptrUltimaPalavra = ptrLinha->primeiraPalavra;

  for (int i = 2; i <= nLinha; i++)
    ptrLinha = ptrLinha->prox;
  while (ptrUltimaPalavra->prox != NULL)
    ptrUltimaPalavra = ptrUltimaPalavra->prox;

  int nColuna = ptrUltimaPalavra->nColuna + strlen(ptrUltimaPalavra->palavra) + 1;

  Palavra *p = criarPalavra(palavra, nLinha, nColuna);

  ptrUltimaPalavra->prox = p;
  ptrLinha->qtdPalavras++;
}

// i)

// OcorrenciasSubstrings *obterOcorrenciasDeSubstring(Multilista *m, char *substr) {
//   OcorrenciasSubstrings *lista = malloc(sizeof(OcorrenciasSubstrings));
//   lista->primeiraPalavra = malloc(sizeof(Palavra));
//   lista->qtdPalavras = 0;
//   Palavra *ptrPalavraOcorrencias = lista->primeiraPalavra;

//   Linha *ptrLinhaMultilista = m->primeiraLinha;
//   Palavra *ptrPalavraMultilista;

//   while (ptrLinhaMultilista != NULL) {
//     ptrPalavraMultilista = ptrLinhaMultilista->primeiraPalavra;

//     while (ptrPalavraMultilista != NULL) {
//       char *token = strstr(ptrPalavraMultilista->palavra, substr);

//       if (token != NULL) {
//         if (ptrPalavraOcorrencias != lista->primeiraPalavra) {
//           ptrPalavraOcorrencias->prox = malloc(sizeof(Palavra));
//           ptrPalavraOcorrencias->prox->ant = ptrPalavraOcorrencias;
//           ptrPalavraOcorrencias = ptrPalavraOcorrencias->prox;
//         }

//         memcpy(ptrPalavraOcorrencias->palavra, ptrPalavraMultilista->palavra, sizeof(Palavra));
//         ptrPalavraOcorrencias->nLinha = ptrPalavraMultilista->nLinha;
//         ptrPalavraOcorrencias->nColuna = ptrPalavraMultilista->nColuna;
//         lista->qtdPalavras++;
//       }

//       ptrPalavraMultilista = ptrPalavraMultilista->prox;
//     }

//     ptrLinhaMultilista = ptrLinhaMultilista->prox;
//   }

//   return lista;
// }

OcorrenciasSubstrings *obterOcorrenciasDeSubstring(Multilista *m, char *substr) {
  OcorrenciasSubstrings *lista = malloc(sizeof(OcorrenciasSubstrings));
  lista->primeiraPalavra = NULL;
  Palavra *ptrPalavraOcorrencias;
  lista->qtdPalavras = 0;

  Linha *ptrLinha = m->primeiraLinha;
  Palavra *ptrPalavra;

  while (ptrLinha != NULL) {
    ptrPalavra = ptrLinha->primeiraPalavra;

    while (ptrPalavra != NULL) {
      char *token = strstr(ptrPalavra->palavra, substr);

      if (token != NULL) {
        if (lista->primeiraPalavra == NULL) {
          lista->primeiraPalavra = malloc(sizeof(Palavra));
          ptrPalavraOcorrencias = lista->primeiraPalavra;
        } else {
          ptrPalavraOcorrencias->prox = malloc(sizeof(Palavra));
          ptrPalavraOcorrencias->prox->ant = ptrPalavraOcorrencias;
          ptrPalavraOcorrencias = ptrPalavraOcorrencias->prox;
        }
        strcpy(ptrPalavraOcorrencias->palavra, ptrPalavra->palavra);
        ptrPalavraOcorrencias->nLinha = ptrPalavra->nLinha;
        ptrPalavraOcorrencias->nColuna = ptrPalavra->nColuna;
      }

      ptrPalavra = ptrPalavra->prox;
    }

    ptrLinha = ptrLinha->prox;
  }

  return lista;
}

#include <stdio.h>
#include <stdlib.h>
#include "multiLista.h"

int main(void) {
  Multilista *m = criarMultilista("arquivo.txt");

  imprimirConteudo(m);

  inserirPalavra(m, 2, "EEEITA");
  printf("\n\n INSERCAO DE PALAVRA \n\n");

  imprimirConteudo(m);

  printf(" OCORRENCIAS DA SUBSTRING 'ato'\n");
  OcorrenciasSubstrings *palavras = obterOcorrenciasDeSubstring(m, "ato");
  Palavra *ptrPalavra = palavras->primeiraPalavra;
  int qtd = 0;

  while (ptrPalavra != NULL) {
    qtd++;
    printf("Ocorrencia n %d\n", qtd);
    printf("Palavra: %s\n", ptrPalavra->palavra);
    printf("(Linha, coluna): (%d,%d)\n\n", ptrPalavra->nLinha, ptrPalavra->nColuna);
    ptrPalavra = ptrPalavra->prox;
  }

  return 0;
}