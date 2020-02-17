/**
 * 백준 1244번 - 스위치 켜고 끄기
 * 
 * */
#include <bits/stdc++.h>

using namespace std;
const int MAX = 101;
bool matrix[MAX];
int n, m;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> matrix[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            for (int j = b; j <= n; j += b) {
                matrix[j] = !matrix[j];
            }
        }
        else {
            int idx = 0;
            while (true) {
                if (b + idx > n || b - idx <= 0) break;
                if (matrix[b + idx] == matrix[b - idx]) {
                    if (idx == 0) matrix[b] = !matrix[b];
                    else {
                        matrix[b + idx] = !matrix[b + idx];
                        matrix[b - idx] = !matrix[b - idx];
                    }
                    idx++;
                }
                else 
                    break;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << matrix[i] << " ";
        if (i % 20 == 0) cout << "\n";
    }

    return 0;
}