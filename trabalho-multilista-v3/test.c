#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE *arquivo = fopen("arquivo.txt", "rt");
  char *string = malloc(100 * sizeof(char));

  while (1) {
    fgets(string, 100, arquivo);
    if (feof(arquivo)) break;
    printf("%s\n", string);
  }

  return 0;
}