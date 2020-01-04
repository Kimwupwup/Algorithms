/**
 * 백준 5427번 - 불
 * 
 * */

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int MAX = 1000;
int T, n, m;
char matrix[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int>> q;
queue<pair<int, int>> fire_route;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        while (!q.empty())
            q.pop();
        while (!fire_route.empty())
            fire_route.pop();
        memset(visited, false, sizeof(visited));
        memset(matrix, ' ', sizeof(matrix));

        cin >> m >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
                if (matrix[i][j] == '@') {
                    q.push(make_pair(i, j));
                    visited[i][j] = true;
                }                    
                else if (matrix[i][j] == '*') {
                    fire_route.push(make_pair(i, j));
                }                    
            }
        }

        int cnt = 0;
        bool good = false;
        while (!q.empty()) {
            int size = fire_route.size();
            for (int j = 0; j < size; j++) {
                int y = fire_route.front().first;
                int x = fire_route.front().second;
                fire_route.pop();

                for (int i = 0; i < 4; i++) {
                    int next_y = y + dir[i].first;
                    int next_x = x + dir[i].second;

                    if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m || matrix[next_y][next_x] == '#' || matrix[next_y][next_x] == '*')
                        continue;
                    fire_route.push(make_pair(next_y, next_x));
                    matrix[next_y][next_x] = '*';
                }   
            }

            size = q.size();
            for (int j = 0; j < size; j++) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int next_y = y + dir[i].first;
                    int next_x = x + dir[i].second;
                    if (next_y == -1 || next_y == n || next_x == -1 || next_x == m) {
                        good = true;
                        break;
                    }
                    if (next_y < -1 || next_y > n || next_x < -1 || next_x > m || matrix[next_y][next_x] == '#' || matrix[next_y][next_x] == '*' || visited[next_y][next_x])
                        continue;
                    q.push(make_pair(next_y, next_x));
                    visited[next_y][next_x] = true;
                }   
                if (good)
                    break;
            }
            if (good)
                break;
            cnt++;
        }

        if (good)
            cout << cnt + 1 << "\n";
        else 
            cout << "IMPOSSIBLE\n"; 
    }

    return 0;
}