/**
 * 백준 1915번 - 가장 큰 정사각형
 * 
 * TODO:
 * 비트마스크
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;
string matrix[MAX];
int dp[MAX][MAX];
int n, m;

int solve() {
    int leng = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = matrix[i][j] - '0';
            else if (matrix[i][j] == '1') 
                dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
            leng = max(leng, dp[i][j]);
        }
    }
    return leng * leng;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }

    cout << solve() << "\n";
    return 0;
}