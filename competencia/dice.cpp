#include <iostream>
#include <vector>
using namespace std;

const int MAX_K = 23;

vector<vector<int>> dp(MAX_K + 1, vector<int>(MAX_K * 6 + 1, 0));

int main() {
    int n, k;
    cin >> n >> k;

    // Inicializar el caso base
    for (int i = 1; i <= 6; i++) {
        dp[1][i] = 1;
    }

    // Calcular las probabilidades para cada cantidad de dados lanzados
    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int x = 1; x <= 6; x++) {
                if (j - x >= 0) {
                    dp[i][j] += dp[i - 1][j - x];
                }
            }
        }
    }

    int numerator = dp[k][n];
    int denominator = 6 * 6 * 6 * 6 * 6 * 6; // 6^k

    cout << numerator << "/" << denominator << endl;

    return 0;
}
