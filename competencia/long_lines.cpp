#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h0, a, c, q;
    cin >> n >> h0 >> a >> c >> q;

    if (n < 1 || n > 1e7 || h0 < 1 || h0 >= q || a < 1 || a >= q || c < 1 || c >= q) {
        cerr << "Las entradas no cumplen con las restricciones." << endl;
        return 1;
    }

    vector<int> heights(n);

    heights[0] = h0;

    for (int i = 1; i < n; i++) {
        heights[i] = (a * heights[i - 1] + c) % q;
    }

    int notable_count = 0;
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[i] >= heights[st.top()]) {
            st.pop();
        }
        if (!st.empty()) {
            notable_count++;
        }
        st.push(i);
    }

    cout << notable_count << endl;

    return 0;
}
