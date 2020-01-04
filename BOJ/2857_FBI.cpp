/**
 * 백준 2857번 - FBI
 * 
 * */
#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;

vector<int> v;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    forn(i, 5) {
        string temp;
        cin >> temp;
        forn(j, temp.size()) {
            if (temp[j] == 'I' && j > 1)
                if (temp[j - 1] == 'B' && temp[j - 2] == 'F') {
                    v.push_back(i + 1);
                    break;
                }
        }
    }
    if (v.empty()) {
        cout << "HE GOT AWAY!\n";
        return 0;
    }
    for (int a : v)
        cout << a << " ";
    cout << "\n";

    return 0;
}