/**
 * 백준 16234번 - 인구 이동
 * 
 * TODO:
 * DFS, BFS, 탐색
 * */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 51;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int matrix[MAX][MAX];
bool visited[MAX][MAX];
int n, l, r;
int sum, cnt;
vector<pair<int, int>> v;

void DFS(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dir[i].first;
        int nx = x + dir[i].second;

        if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;

        int dist = abs(matrix[y][x] - matrix[ny][nx]);
        
        if (dist < l || dist > r) continue;

        visited[ny][nx] = true;
        v.push_back({ny, nx});
        sum += matrix[ny][nx];
        cnt++;
        DFS(ny, nx);
    }
    return;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    
    int ret = 0;
    while (true) {
        memset(visited, false, sizeof(visited));

        bool good = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j]) continue;

                visited[i][j] = true;
                sum = matrix[i][j];
                cnt = 1;

                v.clear();
                v.push_back({i, j});
                DFS(i, j);

                if (cnt >= 2) {
                    good = true;
                    for (pair<int, int> p : v)
                        matrix[p.first][p.second] = (sum / cnt);
                }
            }
        }
        if (good == false) {
            break;
        }
        else {
            ret++;
        }
    }
    cout << ret << "\n";

    return 0;
}