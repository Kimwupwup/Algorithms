/**
 * 백준 1074번 - Z
 * 
 * */
#include <iostream>
#include <cmath>

using namespace std;

int n, r, c, cnt;

void solve(int size, int y, int x) {
    if (size == 2) {
        if (y == r && x == c) {
            cout << cnt << "\n";
            return;
        }
        cnt++;
        if (y == r && x + 1 == c) {
            cout << cnt << "\n";
            return;
        }
        cnt++;
        if (y + 1 == r && x == c) {
            cout << cnt << "\n";
        }
        cnt++;
        if (y + 1 == r && x + 1 == c) {
            cout << cnt << "\n";
            return;
        }
        cnt++;
        return;
    }

    solve(size / 2, y, x);
    solve(size / 2, y, x + size / 2);
    solve(size / 2, y + size / 2, x);
    solve(size / 2, y + size / 2, x + size / 2);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> r >> c;
    solve(1 << n, 0, 0);
    
    return 0;
}