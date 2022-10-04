#ifndef POSFIXO_H
#define POSFIXO_H

#include "pilhas.h"

int caractereOperador(char c);

double aplicarOperacao(char c, double v1, double v2);

double obterResultado(PSE *pilha, char *str);

#endif