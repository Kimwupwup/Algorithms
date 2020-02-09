#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> v;
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        bool good = false;
        int sum = 0;

        for (int a : v)
            sum += a;
        if (sum % 2 == 1)
            good = true;
        int temp = sum;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if ((sum + v[i] - v[j]) % 2 == 1)
                    good = true;
            }
        if (good)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    
    return 0;
}