/**
 * 백준 7785번 - 회사에 있는 사람
 * 
 * */
#include <bits/stdc++.h>
using namespace std;

map<string, bool, greater<string>> m;
int n;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string who, what;
        cin >> who >> what;
        if (what == "enter") {
            m[who] = true;
        } else {
            m[who] = false;
        }
    }

    map<string, bool>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second == true)
            cout << iter->first << "\n";
    }

    return 0;
}