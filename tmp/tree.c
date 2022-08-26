#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  int orderedList[] = {1, 2, 3, 4, 7, 8, 11, 14, 17, 20, 21, 25, 30, 31, 50};
  int nHeights = 3;
  int nLines = 7;

  printf("--- ");
  for (int i = 1; i <= nHeights; i++)
    printf(" h-%d ", i);
  printf("\n\n");

  int indexElem = 0;

  for (int l = 1; l <= nLines; l++) {
    printf("%02d) ", l);
    for (int h = 1; h <= nHeights; h++) {
      // l == 1, h == 2
      int p1 = (int)pow(2, (h - 1)); // 2
      int p2 = (int)pow(2, h);       // 4

      int resto = (l - p1) % p2;      // -1 % 4 == -1
      int divInteira = (l - p1) / p2; // -1 / 2 == 0

      int fe = resto == 0 ? 1 : 0;                                                // 0
      int fl = (nLines > p1 * 3) && (resto > 0) && (divInteira % 2 == 0) ? 1 : 0; // 0
      int flc = resto == p1 ? 1 : 0;                                              //

      if (fe == 1)
        printf("(%03d)", indexElem);
      else if (fl == 1)
      {
        if (flc == 1)
          printf("  |--");
        else
          printf("  |  ");
      }
      else
        printf("     ");
    }
    indexElem++;
    printf("\n");
  }
}