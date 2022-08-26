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

  while(1) {
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

void obterPosicao(Multilista *multilista, char *token){
    int cont = 0; //Conta a quaantidade de palavras encontradas em toda a multilista;
    Linha *linhaAtual = multilista->primeiraLinha;
    
    printf("Ocorrencias da palavra \"%s\":", token);
    
    while (linhaAtual != NULL) {
        Palavra *palavraAtual = linhaAtual->primeiraPalavra;
        while (palavraAtual != NULL) {
          if(!strcmp(palavraAtual->palavra, token)){
            cont++;
            printf("\n%d°: [%d][%d]", cont, palavraAtual->nLinha, palavraAtual->nColuna);
           }
        palavraAtual = palavraAtual->prox;
        }
    linhaAtual = linhaAtual->prox;
    }
    if(!cont)
        printf("\nNao foi encontrada nenhuma palavra. ");
}

void removerPalavra(Multilista *multilista, char *token){
    int cont = 0; 
    Linha *linhaAtual = multilista->primeiraLinha;
    while (linhaAtual != NULL) {
        Palavra *palavraAtual = linhaAtual->primeiraPalavra;
        while (palavraAtual != NULL) {
          if(!strcmp(palavraAtual->palavra, token)){
            cont++;
            if(palavraAtual->ant != NULL)
                palavraAtual->ant->prox = palavraAtual->prox;
            else
                linhaAtual->primeiraPalavra = palavraAtual->prox;
            if(palavraAtual->prox != NULL)
                palavraAtual->prox->ant = palavraAtual->ant;
            atualizarIndices(palavraAtual);
            free(palavraAtual);
           }
        palavraAtual = palavraAtual->prox;
        }
    linhaAtual = linhaAtual->prox;
    }
    printf("\nRemovido com sucesso %d palavras \"%s\" do sistema. ", cont, token);
}

void removerPosicao(Multilista *multilista, int nLinha, int nColuna){
    int cont = 0;
    char token[30];
    if(nLinha <= multilista->qtdLinhas){
        Linha *linhaAtual = multilista->primeiraLinha;
        while (linhaAtual != NULL) {
            Palavra *palavraAtual = linhaAtual->primeiraPalavra;
            while (palavraAtual != NULL) {
              if(nLinha == palavraAtual->nLinha && nColuna == palavraAtual->nColuna){
                  if(cont == 0)
                    strcpy(token, palavraAtual->palavra);
                if(!strcmp(palavraAtual->palavra, token)){
                    cont++;
                    if(palavraAtual->ant != NULL)
                        palavraAtual->ant->prox = palavraAtual->prox;
                    else
                        linhaAtual->primeiraPalavra = palavraAtual->prox;
                    if(palavraAtual->prox != NULL)
                        palavraAtual->prox->ant = palavraAtual->ant;
                    atualizarIndices(palavraAtual);
                }
                
                
               }
            palavraAtual = palavraAtual->prox;
            }
        linhaAtual = linhaAtual->prox;
        }
    }
    printf("\nRemovido o total de %d palavras do sistema. ", cont);
}

int obterOcorrencias(Multilista *multilista, char *token){
    int cont = 0;
    Linha *linhaAtual = multilista->primeiraLinha;
    while (linhaAtual != NULL) {
        Palavra *palavraAtual = linhaAtual->primeiraPalavra;
        while (palavraAtual != NULL) {
          if(!strcmp(palavraAtual->palavra, token))
            cont++;
        palavraAtual = palavraAtual->prox;
        }
    linhaAtual = linhaAtual->prox;
    }
    return cont;
}

int obterQtdPalavras(Multilista *multilista){
    int cont = 0;
    Linha *linhaAtual = multilista->primeiraLinha;
    while (linhaAtual != NULL) {
        Palavra *palavraAtual = linhaAtual->primeiraPalavra;
        while (palavraAtual != NULL) {
            cont++;
            palavraAtual = palavraAtual->prox;
        }
    linhaAtual = linhaAtual->prox;
    }
    return cont;
}

void alterarPalavra(Multilista *multilista, int nLinha, int nColuna, char *token){
    if(nLinha <= multilista->qtdLinhas){
        Linha *linhaAtual = multilista->primeiraLinha;
        while (linhaAtual != NULL) {
            Palavra *palavraAtual = linhaAtual->primeiraPalavra;
            while (palavraAtual != NULL) {
              if(nLinha == palavraAtual->nLinha && nColuna == palavraAtual->nColuna){
                strcpy(palavraAtual->palavra, token);
              }
            palavraAtual = palavraAtual->prox;
            }
        linhaAtual = linhaAtual->prox;
        }
    }
}


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
//Funções auxiliares
void lerLinhaColuna(int *linha, int *coluna){
    printf("Informe a Linha: ");
    scanf("%d", linha);
    printf("\nInforme a Coluna: ");
    scanf("%d", coluna);
}

void lerPalavra(char *palavra){
    printf("Informe a palavra: ");
    scanf("%s", palavra);
}

void atualizarIndices(Palavra *palavra){
    Palavra *palavraAtual = palavra;
    while(palavraAtual != NULL){
        if(palavraAtual->prox != NULL)
            palavraAtual->prox->nColuna -= (strlen(palavra->palavra) + 1);
        palavraAtual = palavraAtual->prox;
    }
    
}
