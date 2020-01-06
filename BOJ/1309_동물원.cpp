/**
 * 백준 1309번 - 동물원
 * 
 * */
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
const int MOD = 9901;
int n;
int dp[MAX][3];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }
    cout << (dp[n][0] + dp[n][1] + dp[n][2]) << "\n";
    return 0;
}