#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    do {
        cin >> n;
    } while (!(1 <= n && n <= 20));

    cin.ignore(); // Limpia el salto de línea

    const string letters = "ABCDEFG"; // Letras mayúsculas

    while (n--) {
        string mensaje;
        getline(cin, mensaje);

        if (mensaje.size() > 50000) {
            cerr << "Mensaje demasiado largo. Ignorando." << endl;
            continue; // Ignora mensajes demasiado largos
        }

        vector<int> letterCount(26, 0); // Inicializa un contador para cada letra del alfabeto

        for (char letra : mensaje) {
            char letraMayuscula = toupper(letra);
            if (letters.find(letraMayuscula) != string::npos) {
                letterCount[letraMayuscula - 'A']++;
            }
        }

        int maxCount = 0;
        char mostCommonLetter = ' ';

        for (int i = 0; i < 26; i++) {
            if (letterCount[i] > maxCount) {
                maxCount = letterCount[i];
                mostCommonLetter = static_cast<char>('A' + i);
            }
        }

        cout << mostCommonLetter << endl;
    }

    return 0;
}
