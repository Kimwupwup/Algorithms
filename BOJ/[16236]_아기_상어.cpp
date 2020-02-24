/**
 * 백준 16236번 - 아기 상어
 * 
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 20;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int matrix[MAX][MAX];
int visited[MAX][MAX];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    pair<int, int> start;

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 9) {
                start = {i, j};
                matrix[i][j] = 0;
            }
        }
    }

    queue<pair<int, pair<int, int>>> q;
    q.push({2, {start}});

    int ret = 0;
    int eat = 0;

    while (!q.empty()) {
        int y = q.front().second.first;
        int x = q.front().second.second;
        int size = q.front().first;
        q.pop();

        memset(visited, false, sizeof(visited));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> temp;
        temp.push({0, {y, x}});
        visited[y][x] = true;

        while (!temp.empty()) {
            int iter = temp.size();

            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
            
            for (int i = 0; i < iter; i++) {
                int cur_y = temp.top().second.first;
                int cur_x = temp.top().second.second;
                int cur_time = temp.top().first;
                temp.pop();

                for (int j = 0; j < 4; j++) {
                    int next_y = cur_y + dir[j].first;
                    int next_x = cur_x + dir[j].second;

                    if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= n || visited[next_y][next_x]) continue;
                    if (size >= matrix[next_y][next_x]) {
                        temp.push({cur_time + 1, {next_y, next_x}});
                        visited[next_y][next_x] = true;

                        if (matrix[next_y][next_x] >= 1 && matrix[next_y][next_x] < size) 
                            pq.push({cur_time + 1, {next_y, next_x}});
                    }
                }
            }

            if (!pq.empty()) {
                eat++;

                if (eat == size) {
                    q.push({size + 1, {pq.top().second}});
                    eat = 0;
                }
                else 
                    q.push({size, {pq.top().second}});

                matrix[pq.top().second.first][pq.top().second.second] = 0;
                ret += pq.top().first;
                break;
            }
        }
    }
    cout << ret << "\n";
    return 0;
}