/**
 * 백준 4963번 - 섬의 개수
 * 
 * */
#include <bits/stdc++.h>
using namespace std;

const int MAX = 50;
int matrix[MAX][MAX];
bool visited[MAX][MAX];

vector<pair<int, int>> dir = {{1, 0}, {1, 1}, {1, -1}, {-1, 0}, {-1, 1}, {-1, -1}, {0, 1}, {0, -1}};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while (true) {
        int n, m;
        cin >> m >> n;

        if (m == 0 && n == 0)
            break;
        
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                cin >> matrix[i][j];
        
        memset(visited, false, sizeof(visited));
        queue<pair<int, int>> q;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] || matrix[i][j] == 0) continue;
                ret++;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int k = 0; k < 8; k++) {
                        int next_y = y + dir[k].first;
                        int next_x = x + dir[k].second;

                        if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m || visited[next_y][next_x] || matrix[next_y][next_x] == 0) continue;

                        visited[next_y][next_x] = true;
                        q.push({next_y, next_x});
                    }
                }
            }
        }
        cout << ret << "\n";
    }

    return 0;
}