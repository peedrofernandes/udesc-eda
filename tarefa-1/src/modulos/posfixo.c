#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "../headers/pilhas.h"
#include "../headers/posfixo.h"
#include "../headers/uteis.h"

int caractereOperador(char c) {
  int boolean = (
    c == '+' ||
    c == '-' ||
    c == '*' ||
    c == '/' ||
    c == '%' ||
    c == '^'
  );

  return boolean;
};

double aplicarOperacao(char c, double v1, double v2) {
  int result;

  if (c == '+')
    return v1 + v2;
  if (c == '-')
    return v1 - v2;
  if (c == '*')
    return v1 * v2;
  if (c == '/')
    return v1 / v2;
  if (c == '%')
    return (double)((int)v1 % (int)v2);
  if (c == '^')
    return pow(v1, v2);
}

double obterResultado(PSE *pilha, char *str) {
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      empilharPSE(pilha, (double)(charToInt(str[i])));
    } else if (caractereOperador(str[i])) {
      double d2 = desempilharPSE(pilha);
      double d1 = desempilharPSE(pilha);
      double result = aplicarOperacao(str[i], d1, d2);
      empilharPSE(pilha, result);
    }
  }

  return pilha->frente->d;
}