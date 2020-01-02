/**
 * 백준 9935번 - 문자열 폭발
 * 
 * */

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

string str;
string p;
char ret[MAX];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> str;
    cin >> p;
    
    int idx = 0;
    for (int i = 0; i < str.size(); i++) {
        ret[idx++] = str[i];

        if (ret[idx - 1] == p[p.size() - 1] && idx - p.size() >= 0) {
            bool good = true;
            for (int j = 0; j < p.size(); j++) {
                if (ret[idx - j - 1] != p[p.size() - j - 1]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                idx -= p.size();
            }
        }
    }
    if (idx <= 0) {
        cout << "FRULA\n";
    }
    else {
        for (int i = 0; i < idx; i++) {
            cout << ret[i];
        }
        cout << "\n";
    }
    return 0;
}