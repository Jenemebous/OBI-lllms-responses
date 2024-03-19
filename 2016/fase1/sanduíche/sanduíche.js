function contarFormasDeComerSanduiche(N, D, comprimentos) {
    let formas1 = 0;
    let formas2 = 0;

    // Contagem de formas com sequência contínua de pedaços
    let soma = 0;
    for (let i = 0; i < N; i++) {
        soma += comprimentos[i];
        if (soma === D) {
            formas1++;
        }
        if (soma > D) {
            break;
        }
    }

    // Contagem de formas com pedaços das extremidades
    let esquerda = 0;
    let direita = 0;
    soma = 0;
    for (let i = 0; i < N - 1; i++) {
        soma += comprimentos[i];
        while (soma > D && esquerda < i) {
            soma -= comprimentos[esquerda];
            esquerda++;
        }
        if (soma === D) {
            formas2 += i - esquerda + 1;
        }
    }

    return formas1 + formas2;
}

// Entrada
const entrada = "5 8\n1 2 3 2 1\n";
const linhas = entrada.trim().split("\n");
const [N, D] = linhas[0].split(" ").map(Number);
const comprimentos = linhas[1].split(" ").map(Number);

// Saída
console.log(contarFormasDeComerSanduiche(N, D, comprimentos));