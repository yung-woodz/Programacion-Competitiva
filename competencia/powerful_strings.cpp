#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;

    vector<string> strings(M);
    for (int i = 0; i < M; ++i) {
        cin >> strings[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(1 << M, 0));
    dp[0][0] = 1;

    for (int len = 1; len <= N; ++len) {
        for (int mask = 0; mask < (1 << M); ++mask) {
            for (int i = 0; i < M; ++i) {
                if ((mask & (1 << i)) == 0) {
                    int cnt = 0;
                    for (char c : strings[i]) {
                        cnt += ((mask & (1 << (c - 'a'))) != 0);
                    }
                    dp[len][mask | (1 << i)] = (dp[len][mask | (1 << i)] + 1LL * dp[len - 1][mask] * (1 << cnt)) % MOD;
                }
            }
        }
    }

    int totalPower = 0;
    for (int mask = 1; mask < (1 << M); ++mask) {
        totalPower = (totalPower + dp[N][mask]) % MOD;
    }

    cout << totalPower << endl;

    return 0;
}
