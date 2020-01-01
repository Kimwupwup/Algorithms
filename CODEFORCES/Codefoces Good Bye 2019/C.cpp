/**
 * https://codeforces.com/contest/1270/problem/C
 * Codeforces Good Bye 2019 (2019-12-31)
 * C. Make Good
 * */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        vector<int> v;
        int n;
        cin >> n;
        v.resize(n);

        long long left = 0;
        long long right = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            left += v[i];
            right ^= v[i];
        }
        
    }
    return 0;
}