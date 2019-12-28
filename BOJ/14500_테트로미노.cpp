/**
 * 백준 14500번 - 테트로미노
 * 
 * TODO:
 * 브루트포스
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 500;
int matrix[MAX][MAX];
bool visited[MAX][MAX];

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n, m;

int DFS(int y, int x, int cnt) {
    int ret = 0;

    if (cnt == 4) {
        return matrix[y][x];
    }

    for (int i = 0; i < 4; i++) {
        int next_y = y + dir[i].first;
        int next_x = x + dir[i].second;

        if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m || visited[next_y][next_x])
            continue;
        visited[next_y][next_x] = true;
        ret = max(ret, matrix[y][x] + DFS(next_y, next_x, cnt + 1));
        visited[next_y][next_x] = false;
    }
    return ret;
}

int finger(int y, int x) {
    int ret = 0;
    if (y >= 1 && x >= 1 && x < m - 1)
        ret = max(ret, matrix[y][x - 1] + matrix[y][x] + matrix[y][x + 1] + matrix[y - 1][x]);
    if (y >= 1 && y < n - 1 && x < m - 1)
        ret = max(ret, matrix[y - 1][x] + matrix[y][x] + matrix[y + 1][x] + matrix[y][x + 1]);
    if (y >= 0 && y < n - 1 && x < m - 1 && x >= 1)
        ret = max(ret, matrix[y][x - 1] + matrix[y][x] + matrix[y][x + 1] + matrix[y + 1][x]);
    if (y >= 1 && y < n - 1 && x >= 1)
        ret = max(ret, matrix[y - 1][x] + matrix[y][x] + matrix[y + 1][x] + matrix[y][x - 1]);
    return ret;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = true;
            ret = max(ret, DFS(i, j, 1));            
            ret = max(ret, finger(i, j));
            visited[i][j] = false;
        }
    }
    cout << ret << "\n";
    return 0;
}