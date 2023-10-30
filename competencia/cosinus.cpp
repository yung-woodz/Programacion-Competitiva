#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a; // Ángulo "a" en grados
    int t;
    cin >> t;
    cin >> a;
    
    for(int i=0;i<t;i++)
    {
        double minCos = 1.0; // Inicializa el valor mínimo del coseno a 1
        int n = 1; // Inicializa "n" a 1

        // Itera para encontrar el valor de "n" que minimiza el coseno
        for (int i = 1; i <= 180; i++) {
            double cosValue = abs(cos(i * a * M_PI / 180.0));

            if (cosValue < minCos) {
                minCos = cosValue;
                n = i;
            }
        }

        cout << n << endl; // Imprime el valor de "n" mínimo
        return 0;
    }
    
}