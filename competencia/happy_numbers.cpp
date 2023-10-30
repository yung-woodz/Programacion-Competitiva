#include <bits/stdc++.h>
using namespace std;

const double MAX = 1e+16;

int separarDigitos(int n) {
    set<int> visited;
    int cont = 0;
    while (n != 1 && visited.find(n) == visited.end()) {
        visited.insert(n);
        int suma = 0;
        while (n > 0) {
            int digito = n % 10;
            suma += digito * digito;
            n /= 10;
        }
        n = suma;
        cont++;
    }
    return (n == 1) ? cont : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, result, cont = 0;

    do {
        cin >> a >> b;
    } while (!(1 <= a && a <= b && b <= MAX));

    for (int i = a; i <= b; i++) {
        result = separarDigitos(i);
        if (result != -1) {
            cont++;
        }
    }

    cout << cont;
}
