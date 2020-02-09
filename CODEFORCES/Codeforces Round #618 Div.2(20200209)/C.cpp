/**
 * http://codeforces.com/contest/1300/problem/C
 * Codeforces Round #618 Div.2 (20200209)
 * C. Anu Has a Function
 * */
#include <bits/stdc++.h>

using namespace std;

unordered_map<int, bool> um;
vector<int> v;
int maxi = 0;
void solve() {
    if (um.size() == v.size()) {
        for (unordered_map<int, bool>::iterator iter = um.begin(); iter != um.end(); iter++) {
            cout << iter->first << " ";
        }
        exit(0);
    }

    for (int i = 0; i < v.size(); i++) {
        if (um.find(v[i]) == um.end()) continue;
        um.insert({v[i], true});
        solve();        
        um.erase(um.find(v[i]));
    }
    return;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;    
    
    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<int>());
    int start = v[0];


    return 0;
}