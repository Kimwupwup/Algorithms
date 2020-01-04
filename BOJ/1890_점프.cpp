/**
 * 백준 1890번 - 점프
 * 
 * */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;
int n;
int matrix[MAX][MAX];
long long dp[MAX][MAX];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            cin >> matrix[i][j];
    
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < i; k++) {
                if (dp[k][j] == 0) continue;
                else {
                    if (i - k == matrix[k][j])
                        dp[i][j] += dp[k][j];
                }
            }
            for (int k = 0; k < j; k++) {
                if (dp[i][k] == 0) continue;
                else {
                    if (j - k == matrix[i][k])
                        dp[i][j] += dp[i][k];
                }
            }
        }
    }
    cout << dp[n][n] << "\n";
    return 0;
}