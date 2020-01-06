/**
 * 백준 2225번 - 합분해
 * 
 * */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 201;
int dp[MAX][MAX];
int n, k;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        dp[i][1] = 1;
    }
    
    for (int i = 2; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            for (int l = 0; l <= j; l++) {
                dp[j][i] = (dp[j][i] + dp[l][i - 1]) % 1000000000;
            }
        }
    }
    cout << dp[n][k] << "\n";
    return 0;
}