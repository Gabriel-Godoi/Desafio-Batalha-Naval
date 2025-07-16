#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

int main() {
    // Tabuleiro 10x10 inicializado com água (0)
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // Coordenadas iniciais dos navios
    int linhaVertical = 1, colunaVertical = 4;
    int linhaHorizontal = 6, colunaHorizontal = 2;

    // Verificação se os navios cabem no tabuleiro
    if (linhaVertical + NAVIO > TAMANHO || colunaHorizontal + NAVIO > TAMANHO) {
        printf("Erro: navio fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Verificação de sobreposição (simples)
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linhaVertical + i][colunaVertical] == NAVIO ||
            tabuleiro[linhaHorizontal][colunaHorizontal + i] == NAVIO) {
            printf("Erro: sobreposição de navios.\n");
            return 1;
        }
    }

    // Posiciona o navio vertical
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = NAVIO;
    }

    // Posiciona o navio horizontal
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = NAVIO;
    }

    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}