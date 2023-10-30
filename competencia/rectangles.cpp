#include <iostream>
#include <vector>

using namespace std;

bool is_prime(long long n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    long long p, q;
    cout << "Ingrese el valor de p: ";
    cin >> p;
    cout << "Ingrese el valor de q: ";
    cin >> q;

    long long maxBlocks = 0;

    if (p <= 2 && q >= 2) {
        maxBlocks += 2;
    }
    
    for (long long n = max(p, 3); n <= q; n++) {
        if (is_prime(n)) {
            maxBlocks += n;
        }
    }

    if (maxBlocks == 0) {
        cout << "No valid blocks found." << endl;
    } else {
        cout << maxBlocks << endl;
    }

    return 0;
}
