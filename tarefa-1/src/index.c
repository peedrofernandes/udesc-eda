#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "headers/pilhas.h"

int main() {
  PSE *pilha = criarPSE();
  double result = getResult(pilha, "34+9814*+++");
  excluirPSE(pilha);
  printf("%.4lf\n", result);

  PSE *s = criarPSE();
  excluirPSE(s);

  PSE *pse = criarPSE();
  empilharPSE(pse, 1);
  empilharPSE(pse, 2);
  empilharPSE(pse, 3);

  PE *pe = PSE_PE(pse);

  imprimirPE(pe);
  imprimirPSE(pse);

  excluirPSE(pse);
}