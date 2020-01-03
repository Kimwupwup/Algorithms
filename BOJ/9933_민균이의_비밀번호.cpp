/**
 * 백준 9933번 - 민균이의 비밀번호
 * 
 * */
#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < (int)n; i++)

using namespace std;

vector<string> v;
int n;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    forn(i, n) {
        string temp;
        cin >> temp;
        v.push_back(temp);
    }

    forn(i, v.size()) {
        for (int j = i; j < v.size(); j++) {
            bool good = true;
            if (v[i].size() != v[j].size())
                continue;
            for (int k = 0; k < v[i].size(); k++) {
                if (v[i][k] != v[j][v[j].size() - k - 1]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                cout << v[i].size() << " " << v[i][v[i].size() / 2] << "\n";
                return 0;
            }
        }
    }
    return 0;
}