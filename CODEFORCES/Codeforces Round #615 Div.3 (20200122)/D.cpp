/**
 * http://codeforces.com/contest/1294/problem/C
 * Codeforces Round #615 Div.3 (20200122)
 * C. Product of Three Numbers
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
        cin >> n;
        if (n < 24) {
            cout << "NO\n";
            continue;
        }

        int cnt = 2;
        set<int> s;

        while (cnt--) {
            for (int i = 2; i <= int(sqrt(n)); i++) {
                if (n % i == 0) {
                    if (s.find(i) == s.end()) {
                        s.insert(i);
                        n /= i;
                        break;
                    }
                }
            }
        }
        s.insert(n);
        if (s.size() == 3) {
            cout << "YES\n";
            for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
                cout << *iter << " ";
            cout << "\n";
        }
            
        else 
            cout << "NO\n";
    }

    return 0;
}