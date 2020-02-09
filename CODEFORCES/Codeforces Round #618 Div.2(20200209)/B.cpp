/**
 * http://codeforces.com/contest/1300/problem/B
 * Codeforces Round #618 Div.2 (20200209)
 * B. Assigning to Classes
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
        v.resize(2 * n);

        for (int i = 0; i < v.size(); i++) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        cout << v[v.size() / 2] - v[v.size() / 2 - 1] << "\n";
    }
    return 0;
}