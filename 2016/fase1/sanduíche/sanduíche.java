import java.util.Scanner;

public class Sanduiche {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Lendo a entrada
        int N = scanner.nextInt(); // Número de pedaços
        int D = scanner.nextInt(); // Comprimento total do sanduíche
        int[] comprimentos = new int[N]; // Array para armazenar os comprimentos dos pedaços

        for (int i = 0; i < N; i++) {
            comprimentos[i] = scanner.nextInt();
        }

        // Contagem de maneiras de comer pedaços de sanduíche com soma D
        int totalWays = 0;

        // Caso 1: Sequência contínua de pedaços
        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = i; j < N; j++) {
                sum += comprimentos[j];
                if (sum == D) {
                    totalWays++;
                } else if (sum > D) {
                    break; // Se a soma exceder D, interrompa o loop interno
                }
            }
        }

        // Caso 2: Pedaços das extremidades
        for (int i = 0; i < N - 1; i++) {
            int sum = 0;
            for (int j = i + 1; j < N; j++) {
                sum += comprimentos[j];
                if (sum == D) {
                    totalWays++;
                } else if (sum > D) {
                    break; // Se a soma exceder D, interrompa o loop interno
                }
            }
        }

        System.out.println(totalWays);
    }
}