#ifndef PSE_H

#define PSE_H

#include <stdio.h>
#include <stdlib.h>


// Programa: Manipulador de pilhas

// Features:
// - Definição da estrutura da pilha (pilha de pares ordenados);;
// - Métodos de manipulação da pilha;
// - Implementação de interface no terminal para o usuário manipular a pilha;

typedef struct parOrdenado {
	int x;
	int y;
} ParOrdenado;

typedef struct elemPSE {
	ParOrdenado po;
	struct elemPSE *proximo;
} ElemPSE;

typedef struct elemPDE {
  struct elemPDE *anterior;
  ParOrdenado po;
  struct elemPDE *proximo;
} ElemPDE;

typedef struct pse {
  ElemPSE *topo;
	int tamanho;
} PSE;

void inserirElementoPSE(PSE *p, ParOrdenado po) {
	ElemPSE *novoElemPSE = malloc(sizeof(ElemPSE));

	novoElemPSE->po = po;
	novoElemPSE->proximo = p->topo;

	p->topo = novoElemPSE;
	p->tamanho++;
}

void removerElementoPSE(PSE *p) {
	if (p->topo == NULL)
		return;

	Elem *e = p->topo;
	p->topo = p->topo->proximo;
	free(e);
	p->tamanho--;
}

void inserirElementoPDE(PDE *p) {
  
}

void mostrarElemento(Elem e) {
  printf("(%d,%d)", e.po.x, e.po.y);
}

void mostrarPSE(PSE p) {
	Elem *e = p.topo;

	printf("Elementos da pilha: [");
	while (e != NULL) {
    mostrarElemento(*e);
    e = e->proximo;
  }
	printf("]\n");
}

PSE novaPSE() {
	PSE p = {NULL, 0};
	
	return p;
}

#endif