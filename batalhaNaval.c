#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// ================================
// Função principal
// ================================
int main() {
    int tabuleiro[10][10]; // matriz 10x10
    int i, j;

    // ----------------------------
    // Inicializar o tabuleiro com 0 (água)
    // ----------------------------
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ----------------------------
    // Definir os 3s (vetores unidimensionais)
    // ----------------------------
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3]   = {3, 3, 3};

    // ----------------------------
    // Definir coordenadas iniciais dos 3s
    // ----------------------------
    int linha_horizontal = 2;  // linha de início do 3 horizontal
    int coluna_horizontal = 4; // coluna inicial do 3 horizontal

    int linha_vertical = 5;    // linha inicial do 3 vertical
    int coluna_vertical = 7;   // coluna de início do 3 vertical

    // ----------------------------
    // Validaf se os 3s cabem dentro do tabuleiro
    // ----------------------------
    if (coluna_horizontal + 3 <= 10 &&
        linha_vertical + 3 <= 10) {

        // ----------------------------
        // Posicionar o 3 horizontal
        // ----------------------------
        for (i = 0; i < 3; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
        }

        // ----------------------------
        //  Posicionar o 3 vertical
        //    (somente se não sobrepor o outro)
        // ----------------------------
        int sobrepoe = 0;
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] == 3) {
                sobrepoe = 1;
                break;
            }
        }

        if (!sobrepoe) {
            for (i = 0; i < 3; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
            }
        } else {
            printf("Erro: os 3s se sobrepõem!\n");
        }

    } else {
        printf("Erro: coordenadas inválidas (3 fora do tabuleiro).\n");
    }

    // ----------------------------
    // Exibir o tabuleiro completo
    // ----------------------------
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}