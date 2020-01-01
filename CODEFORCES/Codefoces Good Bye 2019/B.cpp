/**
 * http://codeforces.com/contest/1270/problem/B
 * Codeforces Good Bye 2019 (2019-12-31)
 * B. Intersting Subarray
 * */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        bool flag = false;
        int n;
        vector<int> v;
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        for (int i = 0; i < n - 1; i++) {
            if (abs(v[i + 1] - v[i]) > 1) {
                cout << "YES\n";
                cout << i + 1 << " " << i + 2 << "\n";
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "NO\n";
    }
    return 0;
}