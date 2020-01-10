/**
 * 백준 1620번 - 나는야 포켓몬 마스터 이다솜
 * 
 * */
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int n, m;
unordered_map<string, int> poket;
unordered_map<int, string> poket_reverse;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        poket.insert({temp, i});
        poket_reverse.insert({i, temp});
    }
    for (int i = 0; i < m; i++) {
        string temp;
        cin >> temp;
        if (temp[0] >= '0' && temp[0] <= '9') {
            cout << poket_reverse[stoi(temp) - 1] << "\n";
        }
        else {
            cout << (poket[temp] + 1) << "\n";
        }
    }

    return 0;
}