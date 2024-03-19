#include <stdio.h>

// Função para contar o número de maneiras de comer pedaços de sanduíche com soma D
int contarManeiras(int N, int D, int comprimentos[]) {
    int maneiras = 0;

    // Contagem das sequências contínuas
    for (int i = 0; i < N; i++) {
        int soma = 0;
        for (int j = i; j < N; j++) {
            soma += comprimentos[j];
            if (soma == D)
                maneiras++;
            else if (soma > D)
                break;
        }
    }

    // Contagem das sequências das extremidades
    for (int i = 0; i < N - 1; i++) {
        int soma = 0;
        for (int j = i; j < N; j++) {
            soma += comprimentos[j];
            if (soma == D)
                maneiras++;
            else if (soma > D)
                break;
        }
    }

    return maneiras;
}

int main() {
    int N, D;
    scanf("%d %d", &N, &D);

    int comprimentos[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &comprimentos[i]);
    }

    int resultado = contarManeiras(N, D, comprimentos);
    printf("%d\n", resultado);

    return 0;
}