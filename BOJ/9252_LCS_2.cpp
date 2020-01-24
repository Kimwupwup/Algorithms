/**
 * 백준 9252번 - LCS 2
 * 
 * TODO:
 * DP
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;
string str_a, str_b;
string dp[MAX][MAX];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> str_a >> str_b;
    for (int i = 1; i <= str_a.size(); i++) {
        for (int j = 1; j <= str_b.size(); j++) {
            if (str_a[i - 1] == str_b[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1] + str_a[i - 1];
            else {
                if (dp[i - 1][j].size() > dp[i][j - 1].size())
                    dp[i][j] = dp[i - 1][j];
                else 
                    dp[i][j] = dp[i][j - 1];
            }                
        }
    }
    cout << dp[str_a.size()][str_b.size()].size() << "\n" << dp[str_a.size()][str_b.size()] << "\n";
    return 0;
}