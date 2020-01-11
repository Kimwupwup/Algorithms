/**
 * 백준 1034번 - 램프
 * 
 * TODO:
 * 
 * */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 51;
char matrix[MAX][MAX];
int n ,m, k;
int dp[MAX];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    cin >> k;
    vector<long long> v;
    for (int i = 0; i < n; i++) {
        long long value = 0;
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            value += (matrix[i][j] == '1') ? pow(2, j) : 0;
            cnt += matrix[i][j] == '0' ? 1 : 0;
        }
        if (cnt > k || (k - cnt) % 2 != 0)
            continue;
        v.push_back(value);
    }

    sort(v.begin(), v.end());
    if (v.empty()) {
        cout << 0 << "\n";
        return 0;
    }

    dp[0] = 1;
    int ret = 1;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == v[i - 1]) {
            dp[i] = dp[i - 1] + 1;
            ret = max(ret, dp[i]);
        }
        else {
            dp[i] = 1;
        }
    }
    cout << ret << "\n";
    return 0;
}
