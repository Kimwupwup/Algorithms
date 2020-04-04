/**
 * 
 * Codeforces Round #631 Div.2 (20200303)
 * B. 
 * */
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n + 1), dp(n + 1), inv_dp(n + 1);
        
        for (int i = 1; i <= n; i++) 
            cin >> v[i];
        
        long long chk = 0;
        long long sum = 0, inv_sum = 0;
        map<int, int> m;
        for (int i = 1; i < n; i++) {
            chk += i;
            sum += v[i];
            if (m.count(v[i]) != 0) break;
            m[v[i]] = 1;
            if (chk == sum) dp[i] = 1;
        }

        m.clear();

        chk = 0;
        for (int i = 1; i < n; i++) {
            chk += i;
            inv_sum += v[n - i + 1];
            if (m.count(v[n - i + 1]) != 0) break;
            m[v[n - i + 1]] = 1;
            if (chk == inv_sum) inv_dp[i] = 1;
        }

        vector<pair<int, int>> ret;
        for (int i = 1; i < n; i++) {
            if (dp[i] == 1 && inv_dp[n - i]) ret.push_back({i, n - i});
        }
        cout << ret.size() << "\n";
        for (auto temp : ret)
            cout << temp.first << " " << temp.second << "\n";
    }

    return 0;
}