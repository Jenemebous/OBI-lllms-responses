#include <stdio.h>

int main() {
    // Declaração de variáveis
    int N, i, cont = 0;

    // Leitura do número de seções da piscina
    scanf("%d", &N);

    // Declaração e leitura das alturas das seções da piscina
    int alturas[N];
    for(i = 0; i < N; i++) {
        scanf("%d", &alturas[i]);
    }

    // Verificação das seções cobertas por água
    for(i = 0; i < N; i++) {
        // Se a altura da seção for maior ou igual a 1, está coberta por água
        if(alturas[i] >= 1) {
            cont++;
        }
    }

    // Impressão do número de seções cobertas por água
    printf("%d\n", cont);

    return 0;
}