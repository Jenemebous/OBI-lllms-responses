import java.util.Scanner;
import java.util.Stack;

public class BalanceamentoChaves {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.nextLine(); // Consumir a quebra de linha após o número de linhas
        
        boolean balanceado = true;
        
        for (int i = 0; i < N; i++) {
            String linha = scanner.nextLine().trim();
            if (!chavesBalanceadas(linha)) {
                balanceado = false;
                break;
            }
        }
        
        System.out.println(balanceado ? "S" : "N");
    }
    
    public static boolean chavesBalanceadas(String linha) {
        Stack<Character> pilha = new Stack<>();
        
        for (char c : linha.toCharArray()) {
            if (c == '\\') {
                if (!pilha.isEmpty() && pilha.peek() == '\\') {
                    pilha.pop(); // remove a barra anterior (já que ela está escapada)
                } else {
                    pilha.push(c);
                }
            } else if (c == '"') {
                if (!pilha.isEmpty() && pilha.peek() == '"') {
                    pilha.pop(); // fecha as aspas
                } else {
                    pilha.push(c); // abre aspas
                }
            } else if (c == '{') {
                pilha.push(c);
            } else if (c == '}') {
                if (pilha.isEmpty() || pilha.peek() != '{') {
                    return false; // chave fechada sem estar aberta
                }
                pilha.pop();
            }
        }
        
        return pilha.isEmpty();
    }
}