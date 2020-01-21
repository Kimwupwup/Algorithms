/**
 * 백준 15651번 - N과 M (3)
 * 
 * TODO:
 * 백트래킹
 * */
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 7;
int n, m;
vector<int> v;

void solve(int cnt) {
    if (cnt == m) {
        for (int a : v) 
            cout << a << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        v.push_back(i);
        solve(cnt + 1);
        v.pop_back();
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