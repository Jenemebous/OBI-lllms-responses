function minInterruptores(IA, IB, FA, FB) {
    // Verifica se as lâmpadas já estão nos estados desejados
    if (IA === FA && IB === FB) {
        return 0; // Nenhum interruptor precisa ser apertado
    }
    
    // Verifica se as lâmpadas podem ser colocadas nos estados desejados com apenas um interruptor
    if (IA !== FA && IB !== FB) {
        return 1; // Apenas um interruptor precisa ser apertado para cada lâmpada
    }
    
    // Se uma lâmpada está no estado desejado e a outra não, ou vice-versa,
    // então ambas lâmpadas precisam ser ajustadas
    return 2; // Ambos interruptores precisam ser apertados
}

// Exemplo de uso
const IA = 0; // Estado inicial da lâmpada A
const IB = 1; // Estado inicial da lâmpada B
const FA = 1; // Estado final desejado da lâmpada A
const FB = 0; // Estado final desejado da lâmpada B

const resultado = minInterruptores(IA, IB, FA, FB);
console.log(resultado); // Saída: 2 (ambos interruptores precisam ser apertados)