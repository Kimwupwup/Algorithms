/**
 * 백준 14002번 - 가장 긴 증가하는 부분 수열 4
 * 
 * TODO:
 * DP, lower_bound
 * */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1e3 + 1;
int dp[MAX];
int matrix[MAX];
pair<int, int> ret[MAX];
int n;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }

    int idx = 0;
    dp[0] = matrix[0];
    ret[0] = {0, matrix[0]};
    
    for (int i = 1; i < n; i++) {
        if (dp[idx] < matrix[i]) {
            dp[++idx] = matrix[i];
            ret[i] = {idx, matrix[i]};
        }
        else {
            int idx2 = lower_bound(dp, dp + idx, matrix[i]) - dp;
            dp[idx2] = matrix[i];
            ret[i] = {idx2, matrix[i]};
        } 
    }
    cout << idx + 1 << "\n";
    
    vector<int> v;
    for (int i = n - 1; i >= 0; i--) {
        if (ret[i].first == idx) {
            v.push_back(ret[i].second);
            idx--;
        }
    }
    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i] << " ";
    cout << "\n";
    return 0;
}