/**
 * 백준 1600번 - 말이 되고픈 원숭이
 * 
 * */
#include <bits/stdc++.h>
using namespace std;

const int MAX = 200;
const int INF = 987654321;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {2, 1}, {2, -1}, {1, -2}, {1, 2}, {-1, -2}, {-1, 2}, {-2, -1}, {-2, 1}};
int k;
int n, m;
int matrix[MAX][MAX];
bool visited[MAX][MAX][30 + 2];
queue<pair<pair<int, int>, int>> q;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> k;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    visited[0][0][0] = true;
    q.push(make_pair(make_pair(0, 0), k));
    
    int cnt = 0;
    bool good = false;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int y = q.front().first.first;
            int x = q.front().first.second;
            int cur = q.front().second;
            q.pop();
            if (y == n - 1 && x == m - 1) {
                good = true;
                break;
            }

            for (int j = 0; j < dir.size(); j++) {
                int next_y = y + dir[j].first;
                int next_x = x + dir[j].second;
                int next_cur = cur;
                if (j > 3 && next_cur == 0)
                    break;
                if (j > 3)
                    next_cur--;

                if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m || visited[next_y][next_x][next_cur] || matrix[next_y][next_x])
                    continue;

                visited[next_y][next_x][next_cur] = true;
                q.push(make_pair(make_pair(next_y, next_x), next_cur));
            }
        }
        if (good)
            break;
        cnt++;
    }
    if (good)
        cout << cnt << "\n";
    else 
        cout << -1 << "\n";
    return 0;
}