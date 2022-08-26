#include <stdio.h>
#include <stdlib.h>
#include "multiLista.h"
#include <string.h>

int main(void) {
    Multilista *m = criarMultilista("arquivo.txt");
    int opcao = -1; //opcao do menu
    int linha, coluna; //variaveis p usar nos métodos que pedem p usuario informar linha e coluina;
    char *token; //usar variavel nos metodos que pedem pro usuario inserir uma palavra;
    
    do{
        printf("\n\n----------Gerenciador de MultiListas----------"
        "\n1 - Imprimir Conteudo"
        "\n2 - Buscar Palavra"
        "\n3 - Remover Palavra"
        "\n4 - Remover Palavra pelo Indice"
        "\n5 - Exibir Numero Total de Ocorrencias"
        "\n6 - Exibir Numero Total de Palavras"
        "\n7 - Editar Palavra"
        "\n8 - Inserir Palavra"
        "\n9 - Exibir Localizações"
        "\n10 -Salvar"
        "\n0 - SAIR"
        "\n\nInsira a opcao: ");
        scanf("%d", &opcao);
        system("clear");
        
        switch(opcao){
            case 0:
                break;
            case 1:
                imprimirConteudo(m);
                break;
            case 2:
                lerPalavra(token);
                obterPosicao(m, token);
                break;
            case 3:
                lerPalavra(token);
                removerPalavra(m, token);
               break;
            case 4:
                lerLinhaColuna(&linha, &coluna);
                removerPosicao(m, linha, coluna);
                break;
            case 5:
                lerPalavra(token);
                printf("Total de ocorrencias da palavra \"%s\": %d",token, obterOcorrencias(m, token));
                break;
            case 6:
                printf("Número de palavras no texto: %d", obterQtdPalavras(m));
                break;
            case 7:
                lerLinhaColuna(&linha, &coluna);
                lerPalavra(token);
                alterarPalavra(m,linha,coluna,token);
                break;
            case 8:
                lerPalavra(token);
                printf("Linha: ");
                scanf("%d", &linha);
                inserirPalavra(m, linha, token);
                break;
            case 9:
                lerPalavra(token);
                obterOcorrenciasDeSubstring(m, token);
                break;
            case 10:
                salvarArquivo(m);
                break;
            default:
                printf("Opcao invalida. Tente novamente");
                break;
        }
        
    }
    while(opcao != 0);
    
     
     
     return 0;
}