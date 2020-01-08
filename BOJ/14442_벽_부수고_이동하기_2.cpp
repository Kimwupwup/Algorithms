/**
 * 백준 14442번 - 벽 부수고 이동하기 2
 * 
 * TODO:
 * BFS
 * */

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
const int MAX_K = 10;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, k;
char matrix[MAX][MAX];
bool visited[MAX][MAX][MAX_K];

int BFS(int y, int x) {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{y, x}, {1, 0}});
    visited[y][x][0] = true;

    while (!q.empty()) {
        int cur_y = q.front().first.first;
        int cur_x = q.front().first.second;
        int cnt = q.front().second.first;
        int broken = q.front().second.second;
        q.pop();

        if (cur_y == n - 1 && cur_x == m - 1)
            return cnt;
        
        for (int i = 0; i < 4; i++) {
            int next_y = cur_y + dir[i].first;
            int next_x = cur_x + dir[i].second;
            if (next_y >= 0 && next_y < n && next_x >= 0 && next_x < m) {
                if (matrix[next_y][next_x] == '1' && broken < k && !visited[next_y][next_x][broken + 1]) {
                    visited[next_y][next_x][broken + 1] = true;
                    q.push({{next_y, next_x}, {cnt + 1, broken + 1}});
                }
                else if (matrix[next_y][next_x] == '0' && !visited[next_y][next_x][broken]) {
                    visited[next_y][next_x][broken] = true;
                    q.push({{next_y, next_x}, {cnt + 1, broken}});
                }
            }
        }        
    }
    return -1;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << BFS(0, 0) << "\n";
    return 0;
}