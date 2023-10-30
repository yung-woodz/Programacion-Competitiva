#include <bits/stdc++.h>
using namespace std;


int calculateR(int A, int B, int C) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int v0 = A;
    int v1 = B;
    int v2 = C;

    int v5 = A + B;

    int v6 = 1;
    int v7 = 0 - B;
    int v8 = A;
    int v9 = A + B;
    int v10 = 0;
    int v11 = 0;
    int v12 = 1;

    while (true) {
        v11 += v1;
        v10 += v0;
        int v13 = v10;
        int v14 = 0;
        int v15 = 0;

        while (true) {
            int v16 = v13 + v13;
            if (v16 <= v1) {
                break;
            }
            v13 -= v1;
            v14 += 1;
            v15 += v1;
        }

        if (v13 <= 0) {
            v13 = 0;
        }

        int v17 = 0;
        int v18 = 1;

        while (true) {
            v17 += v13;
            v18 += 1;
            if (v18 <= v6) {
                continue;
            }
            v18 = 1;

            while (true) {
                v17 -= v9;
                v18 += 1;
                if (v18 <= v12) {
                    break;
                }
            }

            if (v17 >= 0) {
                v5 = v14;
                v6 = v12;
                v7 = v15;
                v8 = v10;
                v9 = v13;
            }
        }

        v12 += 1;

        if (v12 > v2) {
            break;
        }
    }

    std::cout << v6 << std::endl;

    return 0;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int A, B, C;
        cin >> A >> B >> C;
        int R = calculateR(A, B, C);
        cout << R << endl;
    }

    return 0;
}
