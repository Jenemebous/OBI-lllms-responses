#include <stdio.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int IA, IB, FA, FB;
    scanf("%d %d %d %d", &IA, &IB, &FA, &FB);

    // Contagem de operações para cada possível estado final
    int operations[2][2] = {{0, 0}, {0, 0}};

    // Possíveis combinações de operações para cada estado final
    operations[FA][FB] = 0; // Se os estados finais já estiverem alcançados

    if (FA != IA) {
        // Se o estado final da lâmpada A não for alcançado
        operations[FA][FB]++;
        operations[!FA][FB]++;
    }

    if (FB != IB) {
        // Se o estado final da lâmpada B não for alcançado
        operations[FA][FB]++;
        operations[FA][!FB]++;
    }

    // Encontrando o mínimo de operações necessárias
    int minOperations = min(operations[1][1], min(operations[1][0], min(operations[0][1], operations[0][0])));
    printf("%d\n", minOperations);

    return 0;
}