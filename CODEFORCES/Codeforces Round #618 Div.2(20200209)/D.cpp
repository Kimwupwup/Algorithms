/**
 * http://codeforces.com/contest/1300/problem/C
 * Codeforces Round #618 Div.2 (20200209)
 * C. Anu Has a Function
 * */
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<pair<int, int>> v;
    v.resize(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }

    if (n % 2) {
        cout << "NO" << "\n";
        return 0;
    }

    int mid = n / 2;

    for (int i = 0; i < mid; i++) {
        int a = abs(v[(i + 1) % 8].second - v[i].second) / abs(v[(i + 1) % 8].first - v[i].first);
        int b = abs(v[(i + 2) % 8].second - v[i + 1].second) / abs(v[(i + 2) % 8].first - v[i + 1].first);

        int c = abs(v[mid + i + 1].second - v[mid + i].second) / abs(v[mid + i + 1].first - v[mid + i].first);
        int d = abs(v[mid + i + 2].second - v[mid + i + 1].second) / abs(v[mid + i + 2].first - v[mid + i + 1].first);

        cout << a << " " << b << " " << c << " " << d << "\n";
    }

    return 0;
}