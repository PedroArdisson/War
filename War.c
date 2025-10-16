#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERRITORIO 5

struct Territorio
{
    char nome[30];
    char cor[10];
    int tropas;
};

void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{
    struct Territorio mundo[MAX_TERRITORIO];
    int totalTerrirorio = 0;
    int opcao = 1;

    printf("================================================================\n\n");
    printf(" Vamos cadastrar os 5 territorios iniciais do nosso mundo\n\n");

    for (int i = 0; i < MAX_TERRITORIO; i++)
    {
        printf(" --- Cadastrando territorio %d ---\n\n", i + 1);
        printf("Nome do territorio: ");
        fgets(mundo[i].nome, 30, stdin);
        mundo[i].nome[strcspn(mundo[i].nome, "\n")] = '\0';

        printf("Cor: ");
        fgets(mundo[i].cor, 10, stdin);
        mundo[i].cor[strcspn(mundo[i].cor, "\n")] = '\0';

        printf("quantidade de tropas: ");
        scanf("%d", &mundo[i].tropas);
        limparBufferEntrada();
        printf("\n");
    }

    printf("===================================\n");
    printf("   MAPA DO MUNDO - ESTADO ATUAL   \n");
    printf("===================================\n\n");

    for (int i = 0; i < MAX_TERRITORIO; i++)
    {
        printf("TERRITORIO %d:\n", i + 1);
        printf("- Nome: %s\n", mundo[i].nome);
        printf("- Dominado por: Exercito %s\n", mundo[i].cor);
        printf("- Tropas: %d\n\n", mundo[i].tropas);
    }
}