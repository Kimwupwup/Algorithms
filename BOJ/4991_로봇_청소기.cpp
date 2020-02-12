/**
 * 백준 4991번 - 로봇 청소기
 * 
 * TODO:
 * BFS, 비트마스크
 * 청소할 곳을 입력할 때, 카운트를 통해 matrix에 청소할 곳의 번호를 매긴다.
 * visited는 3차원으로 [height][width][mask] mask 는 지금까지 청소한 곳의 번호를 말한다.
 * queue 에는 위 3 개의 값을 넣어준다.
 * 다음 칸이 청소할 곳이면 mask 에 추가하고 visited 를 업데이트하며, 아닐 경우는 mask 를
 * 그대로 하여 visited 를 업데이트한다.
 * 끝나는 조건: (지금까지 청소한 곳 == (1 << 청소할 곳의 개수) - 1)
 * 
 * 다른 방법: next_permutation() 으로 청소할 곳을 전부 나열하고
 * BFS 로 다음으로 가는 최단거리를 계속 찾으면서 푸는 방식이 있다고 한다.
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 21;
const int MAX_T = 11;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int matrix[MAX][MAX];
int visited[MAX][MAX][1 << MAX_T];

int n, m;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while (true) {
        memset(matrix, 0, sizeof(matrix));
        memset(visited, 0, sizeof(visited));
        
        int t = 0;
        queue<pair<int, pair<int, int>>> q;

        cin >> m >> n;
        if (m == 0 && n == 0)
            break;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char temp;
                cin >> temp;
                if (temp == '*') {
                    t++;
                    matrix[i][j] = t;
                } else if (temp == 'o') {
                    q.push({0, {i, j}});
                } else if (temp == 'x') {
                    matrix[i][j] = -1;
                }
            }
        }

        bool good = false;
        while (!q.empty()) {
            int y = q.front().second.first;
            int x = q.front().second.second;
            int clear = q.front().first;
            q.pop();

            if (clear == (1 << t) - 1) {
                cout << visited[y][x][clear] << "\n";
                good = true;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int ny = y + dir[i].first;
                int nx = x + dir[i].second;
                int nc = clear | (1 << (matrix[ny][nx] - 1));

                if (ny < 0 || ny >= n || nx < 0 || nx >= m || matrix[ny][nx] == -1) continue;

                if (matrix[ny][nx] > 0) {
                    if (!visited[ny][nx][nc]) {
                        q.push({nc, {ny, nx}});
                        visited[ny][nx][nc] = visited[y][x][clear] + 1;
                    }
                } else if (matrix[ny][nx] == 0) {
                    if (!visited[ny][nx][clear]) {
                        q.push({clear, {ny, nx}});
                        visited[ny][nx][clear] = visited[y][x][clear] + 1;
                    }
                }
            }
        }
        if (!good)
            cout << -1 << "\n";
    }

    return 0;
}