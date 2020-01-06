/**
 * 백준 9372번 - 상근이의 여행
 * 
 * */
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;

int T, n, m;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
        }
        cout << n - 1 << "\n";

    }

    return 0;
}