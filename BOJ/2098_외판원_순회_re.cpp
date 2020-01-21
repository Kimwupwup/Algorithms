/**
 * 백준 2098번 - 외판원 순회
 * 문제 다시 풀어보기
 * 
 * TODO:
 * 마을을 방문했었는지 확인하여야 한다.
 * 최소 비용이여야 한다.
 * 
 * FIXME:
 * 마을을 방문했었는지 확인하기 위해서 비트마스트를 사용한다.
 * DP 알고리즘을 사용하며,
 * dp[i][j] : i는 현재 마을이며, j는 지금까지 방문했던 마을들이다.
 * dp[i][j]는 지금까지의 비용이다.
 * */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX = 16;
int n;
int matrix[MAX][MAX];
int dp[MAX][1 << MAX];

int solve(int idx, int mask) {
    if (mask == (1 << n) - 1) {
        if (matrix[idx][0] != 0) {
            return matrix[idx][0];
        }
        return INF;
    }

    int &ret = dp[idx][mask];
    if (ret != -1)
        return ret;
    
    ret = INF;
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i) || matrix[idx][i] == 0)
            continue;
        int next = matrix[idx][i] + solve(i, mask | (1 << i));
        ret = min(next, ret);
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
    cout << solve(0, (1 << 0)) << "\n";
}