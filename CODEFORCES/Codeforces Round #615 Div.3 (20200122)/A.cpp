/**
 * http://codeforces.com/contest/1294/problem/A
 * Codeforces Round #615 Div.3 (20200122)
 * A. Collecting Coins
 * */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        vector<int> v(3);
        int n;
        for (int i = 0; i < 3; i++)
            cin >> v[i];
        cin >> n;
        sort(v.begin(), v.end(), greater<int>());

        int dist1 = abs(v[0] - v[1]);
        int dist2 = abs(v[0] - v[2]);

        n -= (dist1 + dist2);
        if (n < 0) {
            cout << "NO\n";
            continue;
        }
        if (n % 3 == 0) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }

    return 0;
}