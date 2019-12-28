/**
 * Educational Codeforces Round 78
 * C. Berry Jam
 * 
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <map>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> v;

    int T;
    cin >> T;
    while (T--) {
        int a = 0, b = 0;
        int n;
        v.clear();
        cin >> n;
        v.resize(2 * n);

        for (int i = 0; i < 2 * n; i++) {
            cin >> v[i];
        }


        int cur = 0;
        map<int, int> m;

        m[0] = 0;
        cur = 0;
        for (int i = n; i < 2 * n; i++) {
            if (v[i] == 1)
                cur++;
            else 
                cur--;
            if (!m.count(cur)) {
                m[cur] = i - (n - 1);
            }
        }

        int ans = 2 * n;
        int cal = count(v.begin(), v.end(), 1) - count(v.begin(), v.end(), 2);

        cur = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (v[i] == 1)
                cur++;
            else 
                cur--;
            if (m.count(cal - cur)) {
                ans = min(ans, n - i + m[cal - cur]);
            }
        }

        if (m.count(cal)) {
            ans = min(ans, m[cal]);
        }
        cout << ans << "\n";
    }
    return 0;
}