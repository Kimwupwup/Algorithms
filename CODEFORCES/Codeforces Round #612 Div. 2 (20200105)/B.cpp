/**
 * http://codeforces.com/contest/1287/problem/B
 * Codeforces Round #612 Div. 2 (20200105)
 * B. Hyperset
 * */
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> v;
vector<int> sset(3);

bool chk(int a, int b, int c) {
    bool good = true;
    for (int i = 0; i < k; i++) {
        if (v[a][i] == v[b][i] && v[a][i] == v[c][i] && v[b][i] == v[c][i]) {
            good = true;
        } else if (v[a][i] != v[b][i] && v[a][i] != v[c][i] && v[b][0] != v[c][0]) {
            good = true;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(), v.end());
    int ret = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int l = j + 1; l < n; l++) {
                if (v[i][0] == v[j][0] && v[j][0] != v[l][0])
                    break;
                if (v[i][0] == v[j][0] && v[i][0] == v[l][0] && v[j][0] == v[l][0]) {
                    if (chk(i, j, l))
                        ret++;
                } else if (v[i][0] != v[j][0] && v[i][0] != v[l][0] && v[j][0] != v[l][0]) {
                    if (chk(i, j, l))
                        ret++;
                }
            }
        }
    }
    
    cout << ret << "\n";
    return 0;
}