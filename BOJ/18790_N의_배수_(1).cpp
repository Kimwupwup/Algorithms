/**
 * 백준 18790번 - N의 배수 (1)
 * 
 * TODO:
 * DP
 * */
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

const int MAX = 1000;
int matrix[MAX];
bool dp[MAX][MAX / 2][MAX / 2];
int n, m;


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    m = (2 * n) - 1;

    for (int i = 1; i <= m; i++) {
        cin >> matrix[i];
    }

    dp[0][0][0] = true;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (dp[i][j][k]) {
                    dp[i + 1][j][k] = true;
                    dp[i][j + 1][(k + matrix[i + 1]) % n] = true;
                }
            }
        }
    }

    if (dp[m][n][0] == false) {
        cout << -1 << "\n";
        return 0;
    }

    int j = n;
    int k = 0;
    vector<int> v;
    for (int i = m; i > 0; i--) {
        if (dp[i][j][k] && dp[i - 1][j - 1][abs(k - matrix[i]) % n]) {
            j--;
            k = abs(k - matrix[i]) % n;
            v.push_back(matrix[i]);
        }
    }
    for (auto a : v)
        cout << a << " ";
    cout << "\n";
    return 0;
}
