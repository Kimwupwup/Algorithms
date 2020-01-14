/**
 * Educational Codeforces Round 80
 * C. 
 * 
 * */

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1001;
const int MAXM = 11;

long long dp[MAXN][MAXM];
int n, m;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    dp[1][1] = 1;
    for (int i = 2; i < MAXN; i++) {
        dp[i][1] = dp[i - 1][1] + i;
    }
    cin >> n >> m;
    long long ret = 0;
    for (int i = 2; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < j; k++) {
                dp[j][i] = (dp[j][i] + dp[j - k][i - 1] * (k + 1)) % (1000000000 + 7);
            }            
        }
    }

    cout << dp[n][m] << "\n";
    return 0;
}