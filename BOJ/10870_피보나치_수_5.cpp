/**
 * 백준 10870번 - 피보나치 수 5
 * 
 * TODO:
 * DP
 * */
#include <iostream>
using namespace std;

const int MAX = 21;
int dp[MAX];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    dp[0] = 0;
    dp[1] = 1;

    cin >> n;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << "\n";
}