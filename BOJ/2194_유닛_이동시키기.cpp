/**
 * 백준 2194번 - 유닛 이동시키기
 * 
 * */
#include <bits/stdc++.h>
using namespace std;

const int MAX = 501;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, a, b, k;
int matrix[MAX][MAX];
bool visited[MAX][MAX];

bool full_chk(int y, int x, int idx) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            int next_y = y + i + dir[idx].first;
            int next_x = x + j + dir[idx].second;

            if (next_y <= 0 || next_y > n || next_x <= 0 || next_x > m || matrix[next_y][next_x] == 1) 
                return false;
        }
    }
    return true;
}

int BFS(pair<int, int> start) {
    queue<pair<pair<int, int>, int>> q;
    q.push({start, 0});
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        // for (int i = 0; i < a; i++)
        //     for (int j = 0; j < b; j++)
                if (matrix[y][x] == 2)
                    return cnt;
        
        for (int i = 0; i < 4; i++) {
            int next_y = y + dir[i].first;
            int next_x = x + dir[i].second;
            if (!visited[next_y][next_x]) {
                if (full_chk(y, x, i)) {
                    visited[next_y][next_x] = true;
                    q.push({{next_y,next_x}, cnt + 1});
                }
            }
        }
    }
    return -1;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    pair<int, int> start;
    pair<int, int> target;

    cin >> n >> m >> a >> b >> k;
    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        matrix[y][x] = 1;
    }
    int y, x;
    cin >> y >> x;
    start = {y, x};
    cin >> y >> x;
    target = {y, x};
    matrix[y][x] = 2;

    cout << BFS(start) << "\n";

    return 0;
}