#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int i, j;

    // Inicializa tabuleiro com 0 (água)
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    if (colunaHorizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal não cabe no tabuleiro.\n");
        return 1;
    }
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
    }

    int navioVertical[TAMANHO_NAVIO] = {3, 3, 3};
    int linhaVertical = 5;
    int colunaVertical = 6;

    if (linhaVertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical não cabe no tabuleiro.\n");
        return 1;
    }
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaVertical + i][colunaVertical] != 0) {
            printf("Erro: Navio vertical sobrepõe outro navio.\n");
            return 1;
        }
    }
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
    }

    // Imprime título centralizado (aproximadamente)
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");

    // Imprime letras das colunas no topo
    printf("  "); // Espaço para alinhar com números das linhas
    for (j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf(" %c", 'A' + j); // Letras de A a J
    }
    printf("\n");

    // Imprime o tabuleiro com números nas linhas
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Número da linha
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
