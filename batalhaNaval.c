#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para verificar se a posição está livre
int posicaoLivre(int tabuleiro[TAM][TAM], int linha, int coluna) {
    return tabuleiro[linha][coluna] == 0;
}

// Função para posicionar navio na horizontal
void posicionarHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (posicaoLivre(tabuleiro, linha, coluna + i)) {
            tabuleiro[linha][coluna + i] = 3;
        }
    }
}

// Função para posicionar navio na vertical
void posicionarVertical(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (posicaoLivre(tabuleiro, linha + i, coluna)) {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}

// Função para posicionar navio na diagonal principal
void posicionarDiagonalPrincipal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (posicaoLivre(tabuleiro, linha + i, coluna + i)) {
            tabuleiro[linha + i][coluna + i] = 3;
        }
    }
}

// Função para posicionar navio na diagonal secundária
void posicionarDiagonalSecundaria(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (posicaoLivre(tabuleiro, linha + i, coluna - i)) {
            tabuleiro[linha + i][coluna - i] = 3;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro Batalha Naval:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Posiciona 2 navios na horizontal/vertical
    posicionarHorizontal(tabuleiro, 1, 2);  // Linha 1, Coluna 2
    posicionarVertical(tabuleiro, 5, 5);    // Linha 5, Coluna 5

    // Posiciona 2 navios na diagonal
    posicionarDiagonalPrincipal(tabuleiro, 0, 0);  // Diagonal principal
    posicionarDiagonalSecundaria(tabuleiro, 2, 9); // Diagonal secundária

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
