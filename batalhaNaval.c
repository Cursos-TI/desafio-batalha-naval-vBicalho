#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// ================================
// Função principal
// ================================
#define T 10   // tamanho do tabuleiro
#define H 5    // tamanho das matrizes de habilidade

// Função auxiliar para evitar numero negativo
int valor_absoluto(int x) {
    if (x < 0)
        return -x;
    else
        return x;
}

int main() {
    int tabuleiro[T][T] = {0};

    // --- Posicionando navios (valor 3) ---
    // Navio horizontal
    int linhaH = 2, colunaH = 1;
    for (int j = 0; j < 3; j++) {
        tabuleiro[linhaH][colunaH + j] = 3;
    }

    // Navio vertical
    int linhaV = 4, colunaV = 6;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // --- Criando matrizes de habilidades ---
    int cone[H][H] = {0};
    int cruz[H][H] = {0};
    int octaedro[H][H] = {0};

    // Cone (aponta para baixo)
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (j >= H/2 - i && j <= H/2 + i)
                cone[i][j] = 1;
        }
    }

    // Cruz (centro e linhas/colunas centrais)
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (i == H/2 || j == H/2)
                cruz[i][j] = 1;
        }
    }

    // Octaedro (losango)
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            int di = i - H/2;
            int dj = j - H/2;
            if (di < 0) di = -di;   
            if (dj < 0) dj = -dj;
            if (di + dj <= H/2)
                octaedro[i][j] = 1;
        }
    }

    // --- Aplicando habilidades no tabuleiro ---
    int origem_cone_l = 1, origem_cone_c = 1;
    int origem_cruz_l = 5, origem_cruz_c = 4;
    int origem_octa_l = 7, origem_octa_c = 7;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {

            // Cone
            if (cone[i][j] == 1) {
                int linha = origem_cone_l + i - H/2;
                int coluna = origem_cone_c + j - H/2;
                if (linha >= 0 && linha < T && coluna >= 0 && coluna < T && tabuleiro[linha][coluna] == 0)
                    tabuleiro[linha][coluna] = 5;
            }

            // Cruz
            if (cruz[i][j] == 1) {
                int linha = origem_cruz_l + i - H/2;
                int coluna = origem_cruz_c + j - H/2;
                if (linha >= 0 && linha < T && coluna >= 0 && coluna < T && tabuleiro[linha][coluna] == 0)
                    tabuleiro[linha][coluna] = 5;
            }

            // Octaedro
            if (octaedro[i][j] == 1) {
                int linha = origem_octa_l + i - H/2;
                int coluna = origem_octa_c + j - H/2;
                if (linha >= 0 && linha < T && coluna >= 0 && coluna < T && tabuleiro[linha][coluna] == 0)
                    tabuleiro[linha][coluna] = 5;
            }
        }
    }

    // --- Exibindo o tabuleiro ---
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}