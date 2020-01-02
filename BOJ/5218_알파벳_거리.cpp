/**
 * 백준 5218번 - 알파벳 거리
 * 
 * */

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        string a, b;
        cin >> a >> b;
        cout << "Distances: ";
        for (int i = 0; i < a.size(); i++) {            
            cout << ((a[i] > b[i]) ? (b[i] + 26 - a[i]) : (b[i] - a[i]));
            cout << " ";
        }
        cout << "\n";
    }
    return 0;
}