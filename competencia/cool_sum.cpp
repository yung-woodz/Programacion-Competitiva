#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Ingresa el valor de n: ";
    cin >> n;

    vector<int> elementos(n);
    iota(elementos.begin(), elementos.end(), 1);

    long long total_permutaciones = 1; // Inicializa con 1 (n! = 1 si n = 0)
    for (int i = 1; i <= n; ++i) {
        total_permutaciones *= i;
    }

    cout << "Total de permutaciones: " << total_permutaciones << endl;

    vector<vector<int>> vector_permutaciones;
    vector_permutaciones.reserve(total_permutaciones);

    do {
        vector_permutaciones.push_back(elementos);
    } while (next_permutation(elementos.begin(), elementos.end()));

    cout << "Tamanio del vector de permutaciones: " << vector_permutaciones.size() << endl;

    // Imprime todas las permutaciones
    for (const auto& permutacion : vector_permutaciones) {
        for (const auto& elemento : permutacion) {
            cout << elemento << ' ';
        }
        cout << endl;
    }

    return 0;
}
