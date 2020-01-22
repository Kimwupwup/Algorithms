/**
 * http://codeforces.com/contest/1294/problem/B
 * Codeforces Round #615 Div.3 (20200122)
 * B. Collecting Packages
 * */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        vector<pair<int, int>> v;
        vector<char> ret;
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
        }

        sort(v.begin(), v.end());

        int cur_x = 0;
        int cur_y = 0;
        bool good = true;
        for (int i = 0; i < n; i++) {
            if (v[i].first < cur_x || v[i].second < cur_y) {
                good = false;
                break;
            } else {
                for (int j = 0; j < v[i].first - cur_x; j++) {
                    ret.push_back('R');
                }
                for (int j = 0; j < v[i].second - cur_y; j++) {
                    ret.push_back('U');
                }
                cur_x = v[i].first;
                cur_y = v[i].second;
            }
            if (!good) {
                break;
            }
        }
        if (good) {
            cout << "YES\n";
            for (char a : ret)
                cout << a;
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}