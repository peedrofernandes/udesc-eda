#ifndef BUSCA_NA_BASE_H
#define BUSCA_NA_BASE_H

#include <stdio.h>
#include <stdlib.h>
#include "../PSE.h"

Elem buscaNaBase(Pilha *p) {
  Elem *elemento = p->topo;

  // if (elemento == NULL)
  //   return;

  while (1) {
    if (elemento->proximo == NULL)
      break;
    elemento = elemento->proximo;
  }
 
  return *elemento;
}

#endif