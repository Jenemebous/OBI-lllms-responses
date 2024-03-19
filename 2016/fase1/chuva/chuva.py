def secoes_cobertas_por_agua(N, alturas):
    cobertas_por_agua = 0
    max_altura = 0
    
    for altura in alturas:
        if altura > max_altura:
            max_altura = altura
            cobertas_por_agua += 1
    
    return cobertas_por_agua

# Leitura da entrada
N = int(input())
alturas = [int(input()) for _ in range(N)]

# Chamada da função e impressão do resultado
print(secoes_cobertas_por_agua(N, alturas))