#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
#define MAX_M 100

int N, M;
int toca[MAX_N][MAX_M];
int visited[MAX_N][MAX_M];

// Função para verificar se uma posição está dentro dos limites da toca
int dentroDaToca(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

// Função recursiva para encontrar o caminho até a saída
int encontrarSaida(int x, int y) {
    // Verifica se está fora da toca ou se já visitou essa posição
    if (!dentroDaToca(x, y) || toca[x][y] == 0 || visited[x][y])
        return 0;

    // Marca a posição como visitada
    visited[x][y] = 1;

    // Se encontrar a saída, retorna 1
    if (toca[x][y] == 3)
        return 1;

    // Tenta encontrar a saída em todas as direções
    int encontrouSaida = encontrarSaida(x + 1, y) || encontrarSaida(x - 1, y) ||
                         encontrarSaida(x, y + 1) || encontrarSaida(x, y - 1);

    // Se encontrou a saída em alguma direção, retorna 1 + o número de passos
    if (encontrouSaida)
        return 1 + encontrouSaida;

    // Se não encontrou em nenhuma direção, marca como não visitado e retorna 0
    visited[x][y] = 0;
    return 0;
}

int main() {
    // Lê o tamanho da toca
    scanf("%d %d", &N, &M);

    // Lê a configuração da toca
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &toca[i][j]);
            // Inicializa o array de visitados
            visited[i][j] = 0;
        }
    }

    int startX, startY;

    // Encontra a posição inicial de Emília
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (toca[i][j] == 2) {
                startX = i;
                startY = j;
                break;
            }
        }
    }

    // Encontra a saída e imprime o número de passos
    printf("%d\n", encontrarSaida(startX, startY));

    return 0;
}