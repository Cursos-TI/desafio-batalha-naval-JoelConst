#include <stdio.h>

#define TAM 10
#define TAM_HAB 5

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio horizontal ou vertical
void posicionarNavioHV(int tabuleiro[TAM][TAM], int x, int y, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 'H') {
            if (y + i < TAM) {
                tabuleiro[x][y + i] = 3;
            }
        } else if (direcao == 'V') {
            if (x + i < TAM) {
                tabuleiro[x + i][y] = 3;
            }
        }
    }
}

// Função para posicionar um navio na diagonal
void posicionarNavioDiagonal(int tabuleiro[TAM][TAM], int x, int y, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 'D') { // Diagonal principal
            if (x + i < TAM && y + i < TAM) {
                tabuleiro[x + i][y + i] = 3;
            }
        } else if (direcao == 'S') { // Diagonal secundária
            if (x + i < TAM && y - i >= 0) {
                tabuleiro[x + i][y - i] = 3;
            }
        }
    }
}

// Função para criar matriz de habilidade Cone
void criarHabilidadeCone(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar matriz de habilidade Cruz
void criarHabilidadeCruz(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar matriz de habilidade Octaedro
void criarHabilidadeOctaedro(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para aplicar habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int x, int y) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int posX = x - TAM_HAB / 2 + i;
            int posY = y - TAM_HAB / 2 + j;
            if (posX >= 0 && posX < TAM && posY >= 0 && posY < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[posX][posY] == 0) {
                    tabuleiro[posX][posY] = 5;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int habilidadeCone[TAM_HAB][TAM_HAB];
    int habilidadeCruz[TAM_HAB][TAM_HAB];
    int habilidadeOctaedro[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);

    // Posicionar navios
    posicionarNavioHV(tabuleiro, 1, 1, 3, 'H');  // Horizontal
    posicionarNavioHV(tabuleiro, 4, 2, 3, 'V');  // Vertical
    posicionarNavioDiagonal(tabuleiro, 0, 0, 3, 'D');  // Diagonal principal
    posicionarNavioDiagonal(tabuleiro, 6, 9, 3, 'S');  // Diagonal secundária

    // Criar habilidades
    criarHabilidadeCone(habilidadeCone);
    criarHabilidadeCruz(habilidadeCruz);
    criarHabilidadeOctaedro(habilidadeOctaedro);

    // Aplicar habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, habilidadeCone, 2, 5);
    aplicarHabilidade(tabuleiro, habilidadeCruz, 7, 3);
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, 5, 7);

    exibirTabuleiro(tabuleiro);

    return 0;
}
