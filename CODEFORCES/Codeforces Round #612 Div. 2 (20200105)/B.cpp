/**
 * http://codeforces.com/contest/1287/problem/B
 * Codeforces Round #612 Div. 2 (20200105)
 * B. Hyperset
 * */
#include <bits/stdc++.h>
using namespace std;

vector<string> v;
set<string> s;
int n, m;

char make_string(char a, char b) {
    if (a < b) {
        char temp = a;
        a = b;
        b = temp;
    }
    if (a == 'S' && b == 'S') 
        return 'S';
    if (a == 'S' && b == 'E')
        return 'T';
    if (a == 'T' && b == 'S')
        return 'E';
    if (a == 'T' && b == 'E')
        return 'S';
    if (a == 'T' && b == 'T')
        return 'T';
    if (a == 'E' && b == 'E')
        return 'E';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        v.push_back(str);
        s.insert(str);
    }
    int ret = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            string temp = "";
            for (int k = 0; k < m; k++) {
                temp.push_back(make_string(v[i][k], v[j][k]));
            }
            if (s.find(temp) != s.end()) {
                ret++;
            }
        }
    }

    cout << (ret / 3) << "\n";
    return 0;
}