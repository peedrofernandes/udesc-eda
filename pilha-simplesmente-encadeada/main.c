#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// void inserirPSE(struct descritorPSE *pilha, struct dados dados);

// void removerPSE(struct descritorPSE *pilha);

// void inverterPSE(struct descritorPSE *pilha);

// void exibirPSE(struct descritorPSE *pilha);

int main(void) {
  struct descritorPSE *pilha = malloc(sizeof(struct descritorPSE));
  int op;

  do {
    system("clear");
    exibirPSE(pilha);
    exibirTamanhoPSE(pilha);

    printf("Escolha sua opcao: \n");
    printf("[1] Inserir um novo elemento na pilha;\n");
    printf("[2] Remover o ultimo elemento da pilha;\n");
    printf("[3] Inverter toda a pilha;\n");
    printf("[0] Sair do programa.\n");
    printf("Sua opcao: ");
    scanf("%d", &op);

    switch (op) {
      case 1:
        int x, y;
        printf("Digite o valor de x: ");
        scanf("%d", &x);
        printf("Digite o valor de y: ");
        scanf("%d", &y);
        struct dados dados = {x, y};
        inserirPSE(pilha, dados);
        break;
      case 2:
        removerPSE(pilha);
        break;
      case 3:
        inverterPSE(pilha);
        break;
      case 0:
        printf("Encerrando o programa, ate a proxima!\n");
        break;
      default:
        printf("Opcao invalida, tente novamente!\n");
        break;
      }

  } while (op != 0);
}