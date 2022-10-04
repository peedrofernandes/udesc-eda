#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers/pilhas.h"
#include "headers/posfixo.h"
#include "headers/uteis.h"

// Substitua a string aqui!
#define stringPosfixa "452*+5+"

int main() {
  // Operação com notação pós-fixa (Item 1)
  // -----------------------------------------------------
  printf("Operacao pos-fixa\n");
  printf("String: %s\n", stringPosfixa);
  PSE *pilha = criarPSE();
  double result = obterResultado(pilha, stringPosfixa);
  excluirPSE(pilha);
  printf("Resultado: %.4lf\n\n", result);
  // -----------------------------------------------------


  // Criação de uma Pilha Estática a partir de uma pilha simplesmente encadeada (Item 2)
  // -----------------------------------------------------
  PSE *pse = criarPSE();
  empilharPSE(pse, 1);
  empilharPSE(pse, 2);
  empilharPSE(pse, 3);

  PE *pe = PSE_PE(pse);

  printf("PSE original: \n");
  imprimirPSE(pse);
  printf("PE criada:\n");
  imprimirPE(pe);

  excluirPSE(pse);
  // -----------------------------------------------------
}