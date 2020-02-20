/**
 * 백준 17144번 - 미세먼지 안녕!
 * 
 * TODO:
 * 구현, 시뮬레이션
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 51;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<pair<int, int>> w[2] = {{{0, 1}, {-1, 0}, {0, -1}, {1, 0}}, {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};

int matrix[MAX][MAX];
int n, m, t;
vector<pair<int, int>> air;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == -1)
                air.push_back({i, j});
        }
    }

    while (t--) {

        // 미세먼지 확산(동시에 방생하므로 따로 저장 후, 적용)
        int copy[MAX][MAX];
        memset(copy, 0, sizeof(copy));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] != -1 || matrix[i][j] != 0) {
                    int cnt = 0;
                    for (int d = 0; d < 4; d++) {
                        int y = i + dir[d].first;
                        int x = j + dir[d].second;

                        if (y < 0 || y >= n || x < 0 || x >= m || matrix[y][x] == -1)
                            continue;
                        
                        cnt++;
                        copy[y][x] += matrix[i][j] / 5;
                    }
                    copy[i][j] += matrix[i][j] - (matrix[i][j] / 5) * cnt;
                }
            }
        }
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (matrix[i][j] != -1)
                    matrix[i][j] = copy[i][j];

        // 공기청정기 작동(동시에 방생하므로 따로 저장 후, 적용)
        memset(copy, 0, sizeof(copy));
        for (int k = 0; k < 2; k++) {
            int y = air[k].first;
            int x = air[k].second;
            int idx = 0;

            y += w[k][0].first;
            x += w[k][0].second;

            while (!(y == air[k].first && x == air[k].second)) {
                int next_y = y + w[k][idx].first;
                int next_x = x + w[k][idx].second;

                int lim;
                if (k == 0)
                    lim = air[0].first + 1;
                else 
                    lim = n;

                if (next_y < 0 || next_y >= lim || next_x < 0 || next_x >= m) {
                    idx++;
                    continue;
                }                    
                
                copy[next_y][next_x] = matrix[y][x];
                y = next_y;
                x = next_x;
            }
        }
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == -1)
                    continue;
                else if (i == 0 || i == n - 1 || j == 0 || j == m - 1 || i == air[0].first || i == air[1].first)
                    matrix[i][j] = copy[i][j];
                
                    
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != -1)
                ret += matrix[i][j];
        }
    }
    cout << ret << "\n";
    return 0;
}