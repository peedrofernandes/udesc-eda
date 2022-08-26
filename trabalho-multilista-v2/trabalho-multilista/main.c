#include <stdio.h>
#include <stdlib.h>
#include "multiLista.h"

int main(void) {
  Multilista *m = criarMultilista("arquivo.txt");

  imprimirConteudo(m);

  inserirPalavra(m, 1, "palavraLinha1");
  inserirPalavra(m, 2, "palavraLinha2");
  inserirPalavra(m, 2, "segundaPalavraLinha2");
  inserirPalavra(m, 3, "palavraLinha3");

  imprimirConteudo(m);

  salvarArquivo(m);

  obterOcorrenciasDeSubstring(m, "et");

  return 0;
}