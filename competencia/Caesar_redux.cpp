#include <bits/stdc++.h>
using namespace std;

string caesarCipher(const string& text, int shift) {
    string result = text;
    transform(result.begin(), result.end(), result.begin(), [shift](char c) {
        if (c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' + shift) % 26;
        } else if (c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' + shift) % 26;
        }
        return c;
    });
    return result;
}

void processCase(int n) {
    if (n == 0) {
        return;
    }

    int shift;
    cin >> shift;
    cin.ignore();

    string message;
    getline(cin, message);

    string result = (message.find("the") != string::npos) ? caesarCipher(message, 26 - shift) : caesarCipher(message, shift);

    cout << result << "\n";

    processCase(n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();

    processCase(n);

    return 0;
}