/**
 * http://codeforces.com/contest/1270/problem/A
 * Codeforces Good Bye 2019 (2019-12-31)
 * A. Card Game
 * */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n, a, b;
        vector<int> aa;
        vector<int> bb;
        cin >> n >> a >> b;
        aa.resize(a);
        bb.resize(b);
        for (int i = 0; i < a; i++)
            cin >> aa[i];
        for (int i = 0; i < b; i++)
            cin >> bb[i];
        
        sort(aa.begin(), aa.end(), greater<int>());
        sort(bb.begin(), bb.end(), greater<int>());

        if (aa[0] < bb[0])
            cout << "NO" << endl;
        else 
            cout << "YES" << endl;
    }
    return 0;
}