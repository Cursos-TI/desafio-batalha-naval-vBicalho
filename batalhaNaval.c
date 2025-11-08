#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// ================================
// Função principal
// ================================
#define TAM 10   // tamanho fixo do tabuleiro
#define NAVIO 3  // valor que representa uma parte de navio
#define AGUA 0   // valor que representa água
#define TAMANHO_NAVIO 3  // cada navio ocupa 3 posições

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // 🔹 1. Inicializa todo o tabuleiro com 0 (água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 🔹 2. Definição das coordenadas iniciais dos navios
    // Dois navios horizontais/verticais e dois diagonais

    // Navio 1 (horizontal) — começa na linha 0, coluna 1
    int linha1 = 0, coluna1 = 1;
    for (j = coluna1; j < coluna1 + TAMANHO_NAVIO; j++) {
        tabuleiro[linha1][j] = NAVIO;
    }

    // Navio 2 (vertical) — começa na linha 4, coluna 5
    int linha2 = 4, coluna2 = 5;
    for (i = linha2; i < linha2 + TAMANHO_NAVIO; i++) {
        tabuleiro[i][coluna2] = NAVIO;
    }

    // Navio 3 (diagonal principal) — tabuleiro[i][i]
    // começa em (2,2)
    int linha3 = 2, coluna3 = 2;
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha3 + i][coluna3 + i] = NAVIO;
    }

    // Navio 4 (diagonal secundária) — tabuleiro[i][9 - i]
    // começa em (6,6) e vai para cima e à direita
    int linha4 = 6, coluna4 = 6;
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha4 - i][coluna4 + i] = NAVIO;
    }

    // 🔹 3. Exibe o tabuleiro completo
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}