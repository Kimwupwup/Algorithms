/**
 * 백준 1509번 - 펠린드롬 분할
 * 
 * TODO:
 * DP
 * */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 2501;
const int INF = 987654321;

int dp[MAX][MAX];
int min_ret[MAX];
string str;
char s[MAX];

int palindrome(int start, int end) {
    if (start >= end) {
        return 1;
    }

    int &ret = dp[start][end];
    if (ret != -1)
        return ret;
    
    if (s[start] != s[end])
        return 0;
    return ret = palindrome(start + 1, end - 1);
}

int solve() {
    min_ret[0] = 0;
    for (int i = 1; i <= str.size(); i++) {
        min_ret[i] = INF;
        for (int j = 1; j <= i; j++) {
            if (palindrome(j, i))
                min_ret[i] = min(min_ret[i], min_ret[j - 1] + 1);
        }
    }
    return min_ret[str.size()];
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> str;
    for (int i = 0; i < str.size(); i++) 
        s[i + 1] = str[i];
    
    memset(dp, -1, sizeof(dp));

    cout << solve() << "\n";

    return 0;
}