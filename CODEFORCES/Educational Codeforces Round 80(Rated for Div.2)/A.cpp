/**
 * Educational Codeforces Round 80
 * A. Deadline
 * 
 * */

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        double n, d, ret;
        cin >> n >> d;
        for (int i = 0; i <= n; i++) {
            ret = i + ceil(d / (i + 1));
            if (n == ret) {
                cout << "YES\n";
                break;
            }
        }
        if (n != ret)
            cout << "NO\n";
    }

    return 0;
}