#include <iostream>

using namespace std;

int main() {
    int IA, IB, FA, FB;
    cin >> IA >> IB >> FA >> FB;

    // Contagem dos interruptores a serem pressionados
    int switches_pressed = 0;

    // Verificando se a lâmpada A precisa ser trocada
    if (IA != FA) {
        switches_pressed++;
    }

    // Verificando se a lâmpada B precisa ser trocada
    if (IB != FB) {
        switches_pressed++;
    }

    cout << switches_pressed << endl;

    return 0;
}