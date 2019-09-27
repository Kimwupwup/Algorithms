#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <memory.h>

using namespace std;

int n;
bool visited[101][101];
char matrix[101][101];
queue<pair<int, int>> q;
vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int BFS(char c, int y, int x) {
    q.push({y, x});
    visited[y][x] = true;

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextY = cy + dir[i].first;
            int nextX = cx + dir[i].second;

            if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n && !visited[nextY][nextX] && matrix[nextY][nextX] == c) {
                visited[nextY][nextX] = true;
                q.push({nextY, nextX});
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                answer++;
                BFS(matrix[i][j], i, j);
            }
        }
    }
    cout << answer << " ";
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 'G') matrix[i][j] = 'R';
        }
    }

    answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                answer++;
                BFS(matrix[i][j], i, j);
            }
        }
    }
    cout << answer << endl;
    return 0;
}
