/**
 * 백준 11722번 - 가장 긴 감소하는 부분 수열
 *
 * TODO:
 * DP, LIS
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;
int matrix[MAX];
int dp[MAX];
int n;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> matrix[i];

    reverse(matrix, matrix + n);

    int idx = 0;
    dp[0] = matrix[0];
    for (int i = 1; i < n; i++) {
        if (dp[idx] < matrix[i]) {
            dp[++idx] = matrix[i];
        } else {
            int idx2 = lower_bound(dp, dp + idx, matrix[i]) - dp;
            dp[idx2] = matrix[i];
        }
    }
    cout << idx + 1 << "\n";
    return 0;
}
