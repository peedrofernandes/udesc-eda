#include <stdio.h>
#include <stdlib.h>
#include "multiLista.h"

int main(void) {
  Multilista *m = criarMultilista("arquivo.txt");

  imprimirConteudo(m);

  return 0;
}

