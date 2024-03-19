def min_interruptores(IA, IB, FA, FB):
    # Verificar se os estados iniciais e finais das lâmpadas são os mesmos
    if IA == FA and IB == FB:
        return 0
    
    # Verificar se é necessário inverter o estado de uma das lâmpadas com C1
    if IA != FA and IB != FB:
        return 1
    
    # Se apenas uma lâmpada precisa ser invertida com C1
    if IA != FA or IB != FB:
        return 1
    
    # Se apenas uma lâmpada precisa ser invertida com C2
    return 2

# Lendo os estados iniciais e finais das lâmpadas
IA, IB, FA, FB = map(int, input().split())

# Chamando a função e imprimindo o resultado
print(min_interruptores(IA, IB, FA, FB))