/**
 * 백준 4991번 - 로봇 청소기
 * 
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 21;
vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int matrix[MAX][MAX];
int visited[MAX][MAX][1 << 11];
int n, m;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while (true) {
        memset(matrix, 0, sizeof(matrix));
        memset(visited, 0, sizeof(visited));

        cin >> m >> n;
        if (m == 0 && n == 0)
            return 0;
        int trash = 0;
        queue<pair<int, pair<int, int>>> q;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char temp;
                cin >> temp;
                if (temp == '*') {
                    trash++;
                    matrix[i][j] = trash;
                }
                if (temp == 'o')
                    q.push({0, {i, j}});
                if (temp == 'x')
                    matrix[i][j] = -1;
            }
        }

        bool good = false;
        while (!q.empty()) {
            int y = q.front().second.first;
            int x = q.front().second.second;
            int clear = q.front().first;
            q.pop();

            if (clear == (1 << trash) - 1) {
                good = true;
                cout << visited[y][x][clear] << "\n";
                break;
            }

            for (int i = 0; i < 4; i++) {
                int next_y = y + dir[i].first;
                int next_x = x + dir[i].second;

                if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m || matrix[next_y][next_x] == -1)
                    continue;
                
                if (!visited[next_y][next_x][clear | (1 << (matrix[next_y][next_x] - 1))] && matrix[next_y][next_x] > 0) {
                    q.push({clear | (1 << (matrix[next_y][next_x] - 1)), {next_y, next_x}});
                    visited[next_y][next_x][clear | (1 << (matrix[next_y][next_x] - 1))] = visited[y][x][clear] + 1;
                }
                if (!visited[next_y][next_x][clear] && matrix[next_y][next_x] == 0) {
                    q.push({clear, {next_y, next_x}});
                    visited[next_y][next_x][clear] = visited[y][x][clear] + 1;
                }
            }
        }
        if (!good)
            cout << -1 << "\n";
    }

    return 0;
}