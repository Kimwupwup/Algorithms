#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 0x7f;
const int MAX = 101;
const vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

char matrix[MAX][MAX];
int cost[MAX][MAX];

int n, m;
int ret;
pair<int, int> point[2] = {{-1, -1}, {-1, -1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'C') {
                if (point[0].first == -1) {
                    point[0].first = i;
                    point[0].second = j;
                }
                else {
                    point[1].first = i;
                    point[1].second = j;
                }
            }
        }
    }

    memset(cost, INF, sizeof(cost));
    queue<pair<pair<int, int>, pair<int, int>>> q;
    cost[point[0].first][point[0].second] = 0;
    for (int d = 0; d < 4; d++) {
        int y = point[0].first + dir[d].first;
        int x = point[0].second + dir[d].second;

        if (y < 0 || y >= n || x < 0 || x >= m || matrix[y][x] == '*') continue;

        q.push({{y, x}, {d, 0}});
        cost[y][x] = 0;
    }
   
    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cur_dir = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int next_y = y + dir[d].first;
            int next_x = x + dir[d].second;
            int next_cnt;

            if (cur_dir == d) next_cnt = cnt;
            else next_cnt = cnt + 1;

            if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m || matrix[next_y][next_x] == '*') continue;

            if (cost[next_y][next_x] >= next_cnt) {
                cost[next_y][next_x] = next_cnt;
                q.push({{next_y, next_x}, {d, next_cnt}});
            }
        }
    }
    cout << cost[point[1].first][point[1].second];

    return 0;
}