/**
 * Educational Codeforces Round 80
 * D. 
 * 
 * */

#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 300005, MAX_M = 10;
int matrix[MAX_N][MAX_M];
int dp[1 << MAX_M];
int dpid[1 << MAX_M];
int n, m;
pair<int, pair<int, int>> ret;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) cin >> matrix[i][j];
        for (int mask = 0; mask < (1 << m); mask++) {
            int mini = INT_MAX;
            for (int k = 0; k < m; k++) {
                if (mask & (1 << k)) mini = min(mini, matrix[i][k]);
            }

            if (dp[mask] < mini && mini != INT_MAX) {
                dp[mask] = mini;
                dpid[mask] = i;
            }

            if (ret.first <= mini && mask + 1 == (1 << m))
                ret = {mini, {i, i}};
            
            int x = ((1 << m) - 1) ^ mask;
            if (dp[x] == -1 || dp[mask] == -1) continue;

            int u = min(dp[x], dp[mask]);
            if (ret.first < u) {
                ret = {u, {i, dpid[x]}};
            }
        }
    }
    cout << ret.second.first << " " << ret.second.second << "\n";
    return 0;
}