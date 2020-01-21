/**
 * 백준 15649번 - N과 M (1)
 * 
 * TODO:
 * 백트랙킹
 * */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 8;

int n, m;
int mask = 0;
vector<int> v;

void solve(int cnt) {
    if (cnt == m) {
        for (int a : v) 
            cout << a << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (mask & (1 << i)) 
            continue;
        v.push_back(i);
        mask = mask + (1 << i);
        solve(cnt + 1);
        v.pop_back();
        mask = mask - (1 << i);

    }
    return;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    solve(0);

    return 0;
}