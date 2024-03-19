def count_sandwich_ways(N, D, sandwich):
    total_ways = 0
    
    # Contando as maneiras de pegar uma sequência contínua de pedaços
    prefix_sum = [0] * (N + 1)
    for i in range(1, N + 1):
        prefix_sum[i] = prefix_sum[i - 1] + sandwich[i - 1]
    for i in range(1, N + 1):
        for j in range(i, N + 1):
            if prefix_sum[j] - prefix_sum[i - 1] == D:
                total_ways += 1
    
    # Contando as maneiras de pegar pedaços das extremidades
    suffix_sum = [0] * (N + 1)
    for i in range(N, 0, -1):
        suffix_sum[i] = suffix_sum[i + 1] + sandwich[i - 1]
    for i in range(1, N):
        for j in range(i + 1, N + 1):
            if prefix_sum[i - 1] + suffix_sum[j] == D:
                total_ways += 1
    
    return total_ways

# Entrada de dados
N, D = map(int, input().split())
sandwich = list(map(int, input().split()))

# Chamada da função e saída
print(count_sandwich_ways(N, D, sandwich))