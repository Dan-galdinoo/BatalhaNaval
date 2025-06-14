#include <stdio.h>

#define TAMANHO_TABULEIRO 10   // Dimensão fixa do tabuleiro (10x10)
#define TAMANHO_NAVIO 3       // Tamanho fixo de cada navio (3 posições)

// Função que verifica se a posição [linha][coluna] está livre (contém 0)
int estaLivre(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    return (tabuleiro[linha][coluna] == 0);
}

// Função para posicionar navio horizontal ou vertical
// orientacao: 'H' para horizontal, 'V' para vertical
// Retorna 1 se posicionado com sucesso, 0 caso contrário
int posicionarNavioHV(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                      int linha, int coluna, char orientacao) {
    int i;

    // Verifica se navio cabe dentro do tabuleiro
    if (orientacao == 'H') {
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;

        // Verifica se não há sobreposição com outro navio
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            if (!estaLivre(tabuleiro, linha, coluna + i))
                return 0;
        }

        // Posiciona o navio na horizontal
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = 3;
        }
    } 
    else if (orientacao == 'V') {
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;

        // Verifica sobreposição
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            if (!estaLivre(tabuleiro, linha + i, coluna))
                return 0;
        }

        // Posiciona o navio na vertical
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = 3;
        }
    } 
    else {
        return 0; // Orientação inválida
    }

    return 1;
}

// Função para posicionar navio diagonal descendente (linha e coluna aumentam)
// Exemplo de posições: (linha,col), (linha+1,col+1), (linha+2,col+2)
int posicionarNavioDiagonalDesc(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                               int linha, int coluna) {
    int i;

    // Verifica se cabe no tabuleiro
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
        return 0;

    // Verifica sobreposição
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        if (!estaLivre(tabuleiro, linha + i, coluna + i))
            return 0;
    }

    // Posiciona o navio diagonal descendente
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = 3;
    }

    return 1;
}

// Função para posicionar navio diagonal ascendente (linha diminui, coluna aumenta)
// Exemplo de posições: (linha,col), (linha-1,col+1), (linha-2,col+2)
int posicionarNavioDiagonalAsc(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                              int linha, int coluna) {
    int i;

    // Verifica se cabe no tabuleiro
    if (linha - (TAMANHO_NAVIO - 1) < 0 || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
        return 0;

    // Verifica sobreposição
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        if (!estaLivre(tabuleiro, linha - i, coluna + i))
            return 0;
    }

    // Posiciona o navio diagonal ascendente
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha - i][coluna + i] = 3;
    }

    return 1;
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int i, j;

    // Inicializa todas as posições do tabuleiro com 0 (água)
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona navios horizontais/verticais
    if (!posicionarNavioHV(tabuleiro, 1, 1, 'H')) {
        printf("Erro ao posicionar navio horizontal 1.\n");
        return 1;
    }
    if (!posicionarNavioHV(tabuleiro, 4, 5, 'V')) {
        printf("Erro ao posicionar navio vertical 2.\n");
        return 1;
    }

    // Posiciona navios diagonais
    if (!posicionarNavioDiagonalDesc(tabuleiro, 6, 2)) {
        printf("Erro ao posicionar navio diagonal descendente 3.\n");
        return 1;
    }
    if (!posicionarNavioDiagonalAsc(tabuleiro, 8, 6)) {
        printf("Erro ao posicionar navio diagonal ascendente 4.\n");
        return 1;
    }

    // Imprime título do tabuleiro
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");

    // Imprime letras nas colunas para facilitar visualização (A-J)
    printf("  ");
    for (j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf(" %c", 'A' + j);
    }
    printf("\n");

    // Imprime linhas do tabuleiro com números (0-9)
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Número da linha
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
