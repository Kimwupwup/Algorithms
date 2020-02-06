#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    
    while (t--) {
        int m, n, k;
        cin >> m >> n >> k;
        vector<pair<int, int>> v;
        vector<int> ret;

        v.resize(n);
        for (int i = 0; i < n; i++) {
            int pos, dir;
            cin >> pos >> dir;
            v[i] = {pos, dir};
        }
        
        for (int i = 0; i < n; i++) {
            if (v[i].second == 1) {
                ret.push_back(m - v[i].first);
            }
        }

        sort(v.begin(), v.end());
        sort(ret.begin(), ret.end());
        cout << ret[k - 1] << " " << v[n - k].first << "\n";

    }

    return 0;
}