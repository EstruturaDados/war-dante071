// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Constantes globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
#define TAM_MAX_TEXTO 50
#define QTD_TERRITORIOS 5

// --- Estrutura de dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
typedef struct {
    char nome[TAM_MAX_TEXTO];   // Nome do território
    char cor[TAM_MAX_TEXTO];    // Cor do exército associado
    int tropas;                 // Quantidade de tropas
} Territorio;

// --- Função auxiliar ---
// Limpa o buffer de entrada para evitar problemas com fgets e scanf.
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Função principal ---
// Responsável por cadastrar e exibir os territórios
int main() {
    Territorio lista[QTD_TERRITORIOS];

    printf("=========================================\n");
    printf("      SISTEMA DE CADASTRO DE TERRITÓRIOS\n");
    printf("=========================================\n\n");

    // --- Entrada de dados ---
    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf(">>> Cadastro do território %d <<<\n", i + 1);

        printf("Informe o nome do território: ");
        fgets(lista[i].nome, TAM_MAX_TEXTO, stdin);

        printf("Informe a cor do exército: ");
        fgets(lista[i].cor, TAM_MAX_TEXTO, stdin);

        printf("Informe o número de tropas: ");
        scanf("%d", &lista[i].tropas);
        limparBuffer();  // evita conflito entre scanf e fgets

        printf("\n");
    }

    // --- Exibição dos territórios cadastrados ---
    printf("\n===== RELATÓRIO DE TERRITÓRIOS =====\n\n");

    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("Território %d:\n", i + 1);
        printf("  • Nome: %s", lista[i].nome);
        printf("  • Cor do exército: %s", lista[i].cor);
        printf("  • Tropas: %d\n", lista[i].tropas);
        printf("-----------------------------------------\n");
    }

    printf("\nCadastro finalizado com sucesso!\n");
    return 0;
}
