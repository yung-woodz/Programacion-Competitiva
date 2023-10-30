#include <bits/stdc++.h>
using namespace std;

using namespace std;

const long long MOD = 1000000009;

long long calculateSequenceValue(long long h0, long long a, long long b, long long q, int i) {
    return (a * h0 + b) % q;
}

long long calculateDistinctWays(int n, long long t, vector<long long>& allowableValues) {
    unordered_map<long long, long long> dp;
    dp[0] = 1;
    
    for (int i = 0; i < n; i++) {
        unordered_map<long long, long long> new_dp;
        for (auto& entry : dp) {
            long long current = entry.first;
            long long ways = entry.second;
            
            for (long long val : allowableValues) {
                long long next = (current * 10 + val) % (long long)pow(10, n);
                new_dp[next] = (new_dp[next] + ways) % MOD;
            }
        }
        dp = new_dp;
    }
    
    return dp[t];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c;
    cin >> c;
    
    for (int i = 0; i < c; i++) {
        int n;
        long long t, h0, a, b, q;
        cin >> n >> t >> h0 >> a >> b >> q;
        
        vector<long long> allowableValues;
        long long hi = h0;
        do {
            allowableValues.push_back(hi % 10);
            hi = calculateSequenceValue(hi, a, b, q, i);
        } while (hi != h0);
        
        reverse(allowableValues.begin(), allowableValues.end());
        
        long long distinctWays = calculateDistinctWays(n, t, allowableValues);
        if (distinctWays == 0) {
            cout << -1 << endl;
        } else {
            cout << n << " " << distinctWays << endl;
        }
    }
    
    return 0;
}
