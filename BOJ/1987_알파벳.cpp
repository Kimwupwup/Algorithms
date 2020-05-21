/**
 * 백준 1987번 - 알파벳
 * 
 * */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 21;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int matrix[MAX][MAX];
int n, m, ret = 1;

void DFS(int y, int x, int mask, int cnt) {
    int cur = matrix[y][x];
    mask |= (1 << cur);

    for (int i = 0; i < 4; i++) {
        int next_y = y + dir[i].first;
        int next_x = x + dir[i].second;

        if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m) continue;

        int next = matrix[next_y][next_x];
        if (mask & (1 << next)) continue;

        ret = max(ret, cnt + 1);
        DFS(next_y, next_x, mask, cnt + 1);
    }
    mask &= (0 << cur);

    return;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char temp;
            cin >> temp;
            matrix[i][j] = temp - 'A';
        }
    }

    DFS(0, 0, 0, 1);
    cout << ret << "\n";

    return 0;
}