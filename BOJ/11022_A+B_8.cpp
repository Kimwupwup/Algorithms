/**
 * 백준 11022번 - A + B - 8
 * 
 * */
#include <iostream>

using namespace std;

int n, a, b;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << "Case #" << (i + 1) << ": " << a << " + " << b << " = " << (a + b) << "\n";
    }

    return 0;
}