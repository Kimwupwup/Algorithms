/**
 * http://codeforces.com/contest/1300/problem/0
 * Codeforces Round #618 Div.2 (20200209)
 * A. Non-zero
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
        vector<int> v;
        v.resize(n);

        int sum = 0;
        vector<int> zeroo;

        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] == 0)
                zeroo.push_back(i);
        }
        
        int cnt = 0;
        for (int idx : zeroo) {
            v[idx]++;
            cnt++;
        }

        for (int a : v)
            sum += a;
        if (sum == 0)
            cnt++;
        
        cout << cnt << "\n";
    }

    return 0;
}