/**
 * 백준 3085번 - 사탕 게임
 * 
 * TODO:
 * 브루트 포스, BFS
 * */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 50;
const vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int N;
char matrix[MAX][MAX];

void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

int BFS(int y, int x, int type) {
    bool visited[MAX][MAX];
    queue<pair<int, int>> q;
    int ret = 1;

    memset(visited, false, sizeof(visited));
    q.push({y, x});
    visited[y][x] = true;

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = type; i <= type + 1; i++) {
            int ny = cy + dir[i].first;
            int nx = cx + dir[i].second;

            if (ny < 0 || ny >= N || nx < 0 || nx >= N || matrix[ny][nx] != matrix[cy][cx] || visited[ny][nx]) continue;

            visited[ny][nx] = true;
            q.push({ny, nx});
            ret++; 
        }
    }
   
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int ret = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int d = 0; d < 4; d++) {
                int cy = i;
                int cx = j;
                int ny = i + dir[d].first;
                int nx = j + dir[d].second;

                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

                swap(matrix[cy][cx], matrix[ny][nx]);
                ret = max(ret, BFS(cy, cx, 0));
                ret = max(ret, BFS(cy, cx, 2));
                swap(matrix[cy][cx], matrix[ny][nx]);
            }
        }
    }
    cout << ret << "\n";
    return 0;
}