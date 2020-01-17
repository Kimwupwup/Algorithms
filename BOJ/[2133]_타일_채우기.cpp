/**
 * 백준 2133번 - 타일 채우기
 * 
 * TODO:
 * DP
 * 3xn 칸 채우기 이므로 예외처리가 필요하다.
 * 특이 케이스가 존재한다.
 * n이 2 이후부터 특이 케이스가 2개씩 존재한다.(2쌍)
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 31;
int n;
int dp[MAX];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= n; i += 2) {
        for (int j = 2; j <= i; j += 2) {
            int p = 2;
            if (j == 2) p = 3;
            dp[i] += dp[i - j] * p;
        }
    }
    
    cout << dp[n] << "\n";

    return 0;
}