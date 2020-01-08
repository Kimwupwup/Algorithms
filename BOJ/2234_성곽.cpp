/**
 * 백준 2234번 - 성곽
 * 
 * TODO:
 * BFS, 입력 처리
 * */
#include <bits/stdc++.h>
using namespace std;

const int MAX = 50;
int n, m;
int matrix[MAX][MAX];
int visited[MAX][MAX];
vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
vector<int> ret;

void BFS(int y, int x, int num) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = num;
    int cnt = 1;

    while (!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        int value = matrix[cur_y][cur_x];
        q.pop();

        for (int i = 3; i >= 0; i--) {
            if (value - pow(2, i) >= 0) {
                value -= pow(2, i);
                continue;
            }

            int next_y = cur_y + dir[i].first;
            int next_x = cur_x + dir[i].second;

            if (next_y >= 0 && next_y < n && next_x >= 0 && next_x < m && !visited[next_y][next_x]) {
                visited[next_y][next_x] = num;
                q.push({next_y, next_x});
                cnt++;
            }
        }
    }
    ret.push_back(cnt);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                BFS(i, j, num);
                num++;
            }
        }
    }

    int maxi = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int y = i + dir[k].first;
                int x = j + dir[k].second;
                if (y < 0 || y >= n || x < 0 || x >= m)
                    continue;
                if (visited[i][j] != visited[y][x]) {
                    maxi = max(maxi, ret[visited[i][j] - 1] + ret[visited[y][x] - 1]);
                }
            }
        }
    }

    sort(ret.begin(), ret.end(), greater<int>());
    cout << ret.size() << "\n" << ret[0] << "\n";
    cout << maxi << "\n";
    return 0;
}