#include <stdio.h>
#include <stdbool.h>

// Função para verificar se o código está com as chaves balanceadas
bool chaves_balanceadas(char codigo[][101], int N) {
    int contador_chaves = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; codigo[i][j] != '\0'; j++) {
            if (codigo[i][j] == '{') {
                contador_chaves++;
            } else if (codigo[i][j] == '}') {
                contador_chaves--;
            }

            if (contador_chaves < 0) {
                return false; // Mais chaves fechadas do que abertas
            }
        }
    }

    return contador_chaves == 0; // Verifica se todas as chaves foram fechadas
}

int main() {
    int N;
    scanf("%d", &N);

    char codigo[N][101]; // Matriz para armazenar o código
    getchar(); // Consumir a quebra de linha após o scanf

    // Ler as linhas do código
    for (int i = 0; i < N; i++) {
        fgets(codigo[i], 101, stdin);
    }

    // Verificar se as chaves estão balanceadas e imprimir o resultado
    if (chaves_balanceadas(codigo, N)) {
        printf("S\n");
    } else {
        printf("N\n");
    }

    return 0;
}