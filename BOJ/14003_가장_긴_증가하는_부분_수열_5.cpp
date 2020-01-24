/**
 * 백준 14003번 - 가장 긴 증가하는 부분 수열 5
 * 
 * TODO:
 * DP
 * */
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;
int dp[MAX];
int matrix[MAX];
vector<pair<int, int>> temp;
vector<int> ret;
int n;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> matrix[i];
    
    dp[0] = matrix[0];
    int idx = 0;
    temp.push_back({0, matrix[0]});

    for (int i = 1; i < n; i++) {
        if (dp[idx] < matrix[i]) {
            dp[++idx] = matrix[i];
            temp.push_back({idx, matrix[i]});
        }
        else {
            int idx2 = lower_bound(dp, dp + idx, matrix[i]) - dp;
            dp[idx2] = matrix[i];
            temp.push_back({idx2, matrix[i]});
        }
    }

    cout << idx + 1 << "\n";
    for (int i = n - 1; i >= 0; i--) {
        if (temp[i].first == idx) {
            ret.push_back(temp[i].second);
            idx--;
        }
    }
    for (int i = ret.size() - 1; i >= 0; i--) {
        cout << ret[i] << " ";
    }

    return 0;
}