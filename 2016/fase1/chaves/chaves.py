def verifica_chaves_balanceadas(codigo):
    pilha = []
    for char in codigo:
        if char == '{':
            pilha.append(char)
        elif char == '}':
            if not pilha:
                return False
            pilha.pop()
    return len(pilha) == 0

def codigo_com_chaves_balanceadas():
    N = int(input())
    codigo = ""
    for _ in range(N):
        linha = input().strip()
        codigo += linha
    if verifica_chaves_balanceadas(codigo):
        print("S")
    else:
        print("N")

if __name__ == "__main__":
    codigo_com_chaves_balanceadas()