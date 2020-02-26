/**
 * 백준 10971번 - 외판원 순회 2
 * 
 * TODO:
 * 비트마스크, DP
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 10;
const int INF = 987654321;

int matrix[MAX][MAX];
int dp[MAX][1 << MAX];
int n;

int solve(int cur, int mask) {
    if (mask == (1 << n) - 1) {
        if (matrix[cur][0] != 0) {
            return matrix[cur][0];
        }
        return INF;
    }

    int &ret = dp[cur][mask];
    if (ret != -1)
        return ret;
    
    ret = INF;

    for (int i = 1; i < n; i++) {
        if (mask & (1 << i) || matrix[cur][i] == 0) continue;
        ret = min(ret, matrix[cur][i] + solve(i, mask | (1 << i)));
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 1);
    return 0;
}