#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

int main() {
    int n;
    std::cout << "Ingresa el valor de n: ";
    std::cin >> n;

    std::vector<int> elementos(n);
    std::iota(elementos.begin(), elementos.end(), 1);

    int total_permutaciones = std::tgamma(n + 1); // Calcula n!

    std::cout << "Total de permutaciones: " << total_permutaciones << std::endl;

    std::vector<std::vector<int>> vector_permutaciones;
    vector_permutaciones.reserve(total_permutaciones);

    do {
        vector_permutaciones.push_back(elementos);
    } while (std::next_permutation(elementos.begin(), elementos.end()));

    std::cout << "Tamanio del vector de permutaciones: " << vector_permutaciones.size() << std::endl;

    // Imprime todas las permutaciones
    for (const auto& permutacion : vector_permutaciones) {
        for (const auto& elemento : permutacion) {
            std::cout << elemento << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
