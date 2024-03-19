import java.util.Scanner;

public class LampadasDoHotel {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Lendo os estados iniciais e finais das lâmpadas
        int IA = scanner.nextInt();
        int IB = scanner.nextInt();
        int FA = scanner.nextInt();
        int FB = scanner.nextInt();
        
        // Contando o número mínimo de vezes que os interruptores devem ser apertados
        int switchesPressed = countSwitchesPressed(IA, IB, FA, FB);
        
        // Imprimindo o resultado
        System.out.println(switchesPressed);
        
        scanner.close();
    }
    
    public static int countSwitchesPressed(int IA, int IB, int FA, int FB) {
        // Verificando se as lâmpadas já estão nos estados desejados
        if (IA == FA && IB == FB) {
            return 0;
        }
        
        // Verificando se é necessário apenas apertar um dos interruptores
        if (IA != FA && IB != FB) {
            return 2;
        }
        
        // Se apenas uma lâmpada precisa mudar de estado, retornamos 1
        return 1;
    }
}