function secoesCobertasPorAgua(N, alturas) {
    let secoesCobertas = 0;
    let maxAltura = 0;

    // Encontrar a altura máxima
    for (let i = 0; i < N; i++) {
        maxAltura = Math.max(maxAltura, alturas[i]);
    }

    // Contar seções cobertas por água
    for (let i = 0; i < N; i++) {
        if (alturas[i] >= maxAltura) {
            secoesCobertas++;
        }
    }

    return secoesCobertas;
}

// Entrada de exemplo
const N = 6;
const alturas = [2, 5, 3, 2, 6, 3];

// Chamada da função e exibição do resultado
const resultado = secoesCobertasPorAgua(N, alturas);
console.log(resultado); // Saída: 2