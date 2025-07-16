#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5
#define VALOR_AGUA 0
#define VALOR_NAVIO 3
#define VALOR_HABILIDADE 5

// Verifica se uma coordenada está dentro dos limites do tabuleiro
int dentroDosLimites(int linha, int coluna) {
    return linha >= 0 && linha < TAMANHO_TABULEIRO &&
           coluna >= 0 && coluna < TAMANHO_TABULEIRO;
}

// Aplica uma matriz de habilidade sobre o tabuleiro,
// centralizando-a na coordenada (linhaOrigem, colunaOrigem)
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                       int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                       int linhaOrigem, int colunaOrigem) {
    int centro = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTabuleiro = linhaOrigem + i - centro;
            int colunaTabuleiro = colunaOrigem + j - centro;

            if (dentroDosLimites(linhaTabuleiro, colunaTabuleiro) &&
                habilidade[i][j] == 1 &&
                tabuleiro[linhaTabuleiro][colunaTabuleiro] == VALOR_AGUA) {

                tabuleiro[linhaTabuleiro][colunaTabuleiro] = VALOR_HABILIDADE;
            }
        }
    }
}

int main() {
    // Declara o tabuleiro e inicializa com água
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posiciona dois navios comuns (horizontal e vertical)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[0][2 + i] = VALOR_NAVIO;          // Horizontal
        tabuleiro[3 + i][5] = VALOR_NAVIO;          // Vertical
    }

    // Posiciona dois navios diagonais (↘ e ↙)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[1 + i][1 + i] = VALOR_NAVIO;      // Diagonal ↘
        tabuleiro[2 + i][8 - i] = VALOR_NAVIO;      // Diagonal ↙
    }

    // Criação dinâmica da matriz de habilidade em forma de Cone (triângulo invertido)
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i >= abs(j - TAMANHO_HABILIDADE / 2))
                cone[i][j] = 1;
        }
    }

    // Criação da matriz de habilidade em forma de Cruz
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        cruz[TAMANHO_HABILIDADE / 2][i] = 1;
        cruz[i][TAMANHO_HABILIDADE / 2] = 1;
    }

    // Criação da matriz de habilidade em forma de Octaedro (losango)
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - TAMANHO_HABILIDADE / 2) + abs(j - TAMANHO_HABILIDADE / 2) <= 2)
                octaedro[i][j] = 1;
        }
    }

    // Aplicação das habilidades no tabuleiro com pontos de origem definidos
    aplicarHabilidade(tabuleiro, cone, 6, 2);       // Cone centralizado em (6,2)
    aplicarHabilidade(tabuleiro, cruz, 2, 2);       // Cruz centralizada em (2,2)
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);   // Octaedro centralizado em (7,7)

    // Exibe o tabuleiro completo
    printf("Tabuleiro de Batalha Naval com Habilidades Especiais:\n\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}