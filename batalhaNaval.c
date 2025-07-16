#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define OCUPADO 3

// Função auxiliar para verificar se a posição está livre
int posicaoLivre(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    return tabuleiro[linha][coluna] == 0;
}

int main() {
    // Inicializa o tabuleiro com água
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // Posicionamento horizontal
    int linhaH = 0, colunaH = 1;
    for (int i = 0; i < NAVIO; i++) {
        if (colunaH + NAVIO > TAMANHO || !posicaoLivre(tabuleiro, linhaH, colunaH + i)) {
            printf("Erro: navio horizontal fora dos limites ou sobreposição.\n");
            return 1;
        }
        tabuleiro[linhaH][colunaH + i] = OCUPADO;
    }

    // Posicionamento vertical
    int linhaV = 3, colunaV = 5;
    for (int i = 0; i < NAVIO; i++) {
        if (linhaV + NAVIO > TAMANHO || !posicaoLivre(tabuleiro, linhaV + i, colunaV)) {
            printf("Erro: navio vertical fora dos limites ou sobreposição.\n");
            return 1;
        }
        tabuleiro[linhaV + i][colunaV] = OCUPADO;
    }

    // Posicionamento diagonal ascendente (↘)
    int linhaD1 = 1, colunaD1 = 1;
    for (int i = 0; i < NAVIO; i++) {
        if (linhaD1 + NAVIO > TAMANHO || colunaD1 + NAVIO > TAMANHO ||
            !posicaoLivre(tabuleiro, linhaD1 + i, colunaD1 + i)) {
            printf("Erro: navio diagonal ↘ fora dos limites ou sobreposição.\n");
            return 1;
        }
        tabuleiro[linhaD1 + i][colunaD1 + i] = OCUPADO;
    }

    // Posicionamento diagonal descendente (↙)
    int linhaD2 = 2, colunaD2 = 8;
    for (int i = 0; i < NAVIO; i++) {
        if (linhaD2 + NAVIO > TAMANHO || colunaD2 - i < 0 ||
            !posicaoLivre(tabuleiro, linhaD2 + i, colunaD2 - i)) {
            printf("Erro: navio diagonal ↙ fora dos limites ou sobreposição.\n");
            return 1;
        }
        tabuleiro[linhaD2 + i][colunaD2 - i] = OCUPADO;
    }

    // Exibição do tabuleiro
    printf("Tabuleiro de Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}