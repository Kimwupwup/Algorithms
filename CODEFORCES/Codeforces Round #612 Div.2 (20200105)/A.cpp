/**
 * http://codeforces.com/contest/1287/problem/0
 * Codeforces Round #612 Div. 2 (20200105)
 * A. Angry Students
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
        vector<char> v;
        queue<int> angrys;

        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] == 'A')
                angrys.push(i);
        }
        int cnt = 0;
        while (!angrys.empty()) {
            int size = angrys.size();
            for (int i = 0; i < size; i++) {
                int cur = angrys.front();
                angrys.pop();

                if (v[cur + 1] == 'P' && cur + 1 < n) {
                    angrys.push(cur + 1);
                    v[cur + 1] = 'A';
                }
            }            
            cnt++;
        }
        if (cnt == 0)
            cout << 0 << "\n";
        else 
            cout << cnt - 1<< "\n";
    }

    return 0;
}