#include <stdio.h>
#include <stdlib.h>

#define TAB_SIZE 10
#define HAB_SIZE 5

// Inicializa o tabuleiro com água (~)
void inicializarTabuleiro(int tab[TAB_SIZE][TAB_SIZE]) {
    for (int i = 0; i < TAB_SIZE; i++)
        for (int j = 0; j < TAB_SIZE; j++)
            tab[i][j] = 0;
}

// Posiciona navio no tabuleiro, retorna 1 se sucesso, 0 se falha
int posicionarNavio(int tab[TAB_SIZE][TAB_SIZE], int linha, int coluna, char tipo, int tamanho) {
    if (tipo == 'H') {
        if (coluna + tamanho > TAB_SIZE) return 0;
        for (int c = coluna; c < coluna + tamanho; c++)
            if (tab[linha][c] == 3) return 0;
        for (int c = coluna; c < coluna + tamanho; c++)
            tab[linha][c] = 3;
    } else if (tipo == 'V') {
        if (linha + tamanho > TAB_SIZE) return 0;
        for (int l = linha; l < linha + tamanho; l++)
            if (tab[l][coluna] == 3) return 0;
        for (int l = linha; l < linha + tamanho; l++)
            tab[l][coluna] = 3;
    } else if (tipo == 'D') { // diagonal crescente
        if (linha + tamanho > TAB_SIZE || coluna + tamanho > TAB_SIZE) return 0;
        for (int k = 0; k < tamanho; k++)
            if (tab[linha + k][coluna + k] == 3) return 0;
        for (int k = 0; k < tamanho; k++)
            tab[linha + k][coluna + k] = 3;
    } else if (tipo == 'E') { // diagonal decrescente
        if (linha + tamanho > TAB_SIZE || coluna - tamanho + 1 < 0) return 0;
        for (int k = 0; k < tamanho; k++)
            if (tab[linha + k][coluna - k] == 3) return 0;
        for (int k = 0; k < tamanho; k++)
            tab[linha + k][coluna - k] = 3;
    } else
        return 0;
    return 1;
}

// Cria habilidade cone
void criarHabilidadeCone(int hab[HAB_SIZE][HAB_SIZE]) {
    int centro = HAB_SIZE / 2;
    for (int i = 0; i < HAB_SIZE; i++)
        for (int j = 0; j < HAB_SIZE; j++)
            hab[i][j] = (j >= centro - i && j <= centro + i) ? 1 : 0;
}

// Cria habilidade cruz
void criarHabilidadeCruz(int hab[HAB_SIZE][HAB_SIZE]) {
    int centro = HAB_SIZE / 2;
    for (int i = 0; i < HAB_SIZE; i++)
        for (int j = 0; j < HAB_SIZE; j++)
            hab[i][j] = (i == centro || j == centro) ? 1 : 0;
}

// Cria habilidade octaedro
void criarHabilidadeOctaedro(int hab[HAB_SIZE][HAB_SIZE]) {
    int centro = HAB_SIZE / 2;
    for (int i = 0; i < HAB_SIZE; i++)
        for (int j = 0; j < HAB_SIZE; j++) {
            int dist = abs(i - centro) + abs(j - centro);
            hab[i][j] = (dist <= 2) ? 1 : 0;
        }
}

// Sobrepõe habilidade no tabuleiro, marcando áreas com 5
void sobreporHabilidade(int tab[TAB_SIZE][TAB_SIZE], int hab[HAB_SIZE][HAB_SIZE], int origemLinha, int origemColuna) {
    int meio = HAB_SIZE / 2;
    for (int i = 0; i < HAB_SIZE; i++) {
        for (int j = 0; j < HAB_SIZE; j++) {
            if (hab[i][j] == 1) {
                int linhaTab = origemLinha + (i - meio);
                int colTab = origemColuna + (j - meio);
                if (linhaTab >= 0 && linhaTab < TAB_SIZE && colTab >= 0 && colTab < TAB_SIZE) {
                    if (tab[linhaTab][colTab] == 0) {
                        tab[linhaTab][colTab] = 5;
                    }
                }
            }
        }
    }
}

// Função para converter valor em símbolo para exibição
char simboloTabuleiro(int val) {
    switch(val) {
        case 0: return '~';   // água
        case 3: return 'N';   // navio
        case 5: return '*';   // área de habilidade
        default: return '?';  // inesperado
    }
}

// Imprime o tabuleiro com cabeçalho e legenda
void imprimirTabuleiro(int tab[TAB_SIZE][TAB_SIZE]) {
    char letras[] = "ABCDEFGHIJ";

    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");

    printf("   ");
    for (int c = 0; c < TAB_SIZE; c++)
        printf(" %c ", letras[c]);
    printf("\n");

    for (int l = 0; l < TAB_SIZE; l++) {
        printf("%2d ", l);
        for (int c = 0; c < TAB_SIZE; c++) {
            printf(" %c ", simboloTabuleiro(tab[l][c]));
        }
        printf("\n");
    }

    printf("\nLegenda: ~ Água | N Navio | * Área de habilidade\n");
}

int main() {
    int tabuleiro[TAB_SIZE][TAB_SIZE];
    int habCone[HAB_SIZE][HAB_SIZE], habCruz[HAB_SIZE][HAB_SIZE], habOctaedro[HAB_SIZE][HAB_SIZE];

    inicializarTabuleiro(tabuleiro);

    // Posiciona navios (exemplos)
    posicionarNavio(tabuleiro, 1, 1, 'H', 3);
    posicionarNavio(tabuleiro, 3, 6, 'V', 3);
    posicionarNavio(tabuleiro, 5, 2, 'D', 3);
    posicionarNavio(tabuleiro, 7, 7, 'E', 3);

    criarHabilidadeCone(habCone);
    criarHabilidadeCruz(habCruz);
    criarHabilidadeOctaedro(habOctaedro);

    // Define posições origens das habilidades
    sobreporHabilidade(tabuleiro, habCone, 2, 3);
    sobreporHabilidade(tabuleiro, habCruz, 6, 5);
    sobreporHabilidade(tabuleiro, habOctaedro, 8, 1);

    imprimirTabuleiro(tabuleiro);

    return 0;
}
