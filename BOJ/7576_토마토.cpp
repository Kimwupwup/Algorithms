#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int matrix[1000][1000];
int main() {
    int n, m, cnt = 0, rcnt = 0;
    
    queue<pair<int, int>> q;
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    cin >> m >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) {
                q.push({i, j});
                rcnt++;
            }
            else if (matrix[i][j] == -1) cnt++;
        }

    if (rcnt == (n * m) - cnt) {
        cout << 0 << endl;
        return 0;
    }

    int answer = 0;
    while (!q.empty()) {
        int size = q.size();
        answer++;
        for (int i = 0; i < size; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int j = 0; j < 4; j++) {
                int next_y = y + dir[j].first;
                int next_x = x + dir[j].second;

                if (next_y >= 0 && next_y < n && next_x >= 0 && next_x < m && matrix[next_y][next_x] == 0) {
                    q.push({next_y, next_x});
                    matrix[next_y][next_x] = 1;
                    rcnt++;
                }
            }
        }
    }
    if (rcnt == (n * m) - cnt) {
        cout << answer - 1 << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}