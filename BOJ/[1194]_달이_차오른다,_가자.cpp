/**
 * 백준 1194번 - 달이 차오른다, 가자.
 * 
 * */

#include <bits/stdc++.h>
using namespace std;

const int MAX = 50;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
char matrix[MAX][MAX];
bool visited[1 << 6][MAX][MAX];

int BFS(int y, int x) {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(y, x), make_pair(0, 0)));
    visited[0][y][x] = true;

    while (!q.empty()) {
        int cur_y = q.front().first.first;
        int cur_x = q.front().first.second;
        int cnt = q.front().second.first;
        int key = q.front().second.second;
        q.pop();

        if (matrix[cur_y][cur_x] == '1')
            return cnt;

        for (int i = 0; i < 4; i++) {
            int next_y = cur_y + dir[i].first;
            int next_x = cur_x + dir[i].second;
            char value = matrix[next_y][next_x];

            if (next_y >= 0 && next_y < n && next_x >= 0 && next_x < m && value != '#' && !visited[key][next_y][next_x]) {
                if (value == '.' || value == '0' || value == '1') {
                    visited[key][next_y][next_x] = true;
                    q.push(make_pair(make_pair(next_y, next_x), make_pair(cnt + 1, key)));
                }
                else if (value >= 'a' && value <= 'f') {
                    int new_key = key | 1 << (value - 'a');
                    if (!visited[new_key][next_y][next_x]) {
                        visited[key][next_y][next_x] = true;
                        visited[new_key][next_y][next_x] = true;
                        q.push(make_pair(make_pair(next_y, next_x), make_pair(cnt + 1, new_key)));
                    }
                }
                else if (value >= 'A' && value <= 'F') {
                    if (key & 1 << (value - 'A')) {
                        visited[key][next_y][next_x] = true;
                        q.push(make_pair(make_pair(next_y, next_x), make_pair(cnt + 1, key)));
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    pair<int, int> start;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == '0')
                start = make_pair(i, j);
        }
    }
    cout << BFS(start.first, start.second) << "\n";
    return 0;
}