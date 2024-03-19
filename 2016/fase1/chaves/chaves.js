function verificaChavesBalanceadas(N, linhas) {
    // Função para verificar se uma string tem as chaves balanceadas
    function chavesBalanceadas(str) {
        let count = 0;
        for (let char of str) {
            if (char === '{') {
                count++;
            } else if (char === '}') {
                if (count === 0) {
                    return false;
                }
                count--;
            }
        }
        return count === 0;
    }

    // Verifica cada linha do código
    for (let i = 0; i < N; i++) {
        if (!chavesBalanceadas(linhas[i])) {
            return 'N';
        }
    }
    return 'S';
}

// Entrada de exemplo
const N = 4;
const linhas = [
    '{Bom Correto}',
    'Correto',
    'Bom{Correto}',
    'Bom Correto}'
];

// Chamada da função e exibição do resultado
console.log(verificaChavesBalanceadas(N, linhas));