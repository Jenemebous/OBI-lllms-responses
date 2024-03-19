import java.util.Scanner;

public class Chuva {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Lendo o número de seções da piscina
        int N = scanner.nextInt();
        int[] alturas = new int[N];

        // Lendo as alturas das seções
        for (int i = 0; i < N; i++) {
            alturas[i] = scanner.nextInt();
        }

        // Contador para o número de seções cobertas com água
        int secoesCobertas = 0;

        // Encontrando a altura máxima da piscina
        int alturaMaxima = 0;
        for (int i = 0; i < N; i++) {
            alturaMaxima = Math.max(alturaMaxima, alturas[i]);
        }

        // Contando o número de seções cobertas com água
        for (int i = 0; i < N; i++) {
            if (alturas[i] >= alturaMaxima) {
                secoesCobertas++;
            }
        }

        // Imprimindo o resultado
        System.out.println(secoesCobertas);

        scanner.close();
    }
}