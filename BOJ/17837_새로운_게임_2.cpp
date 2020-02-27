/**
 * 백준 17837번 - 새로운 게임 2
 * 
 * TODO:
 * 구현, 시뮬레이션
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 12;
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
pair<pair<int, int>, int> m[MAX];
vector<int> v[MAX][MAX];
int matrix[MAX][MAX];
int n, k;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        int y, x, d;
        cin >> y >> x >> d;
        y--;
        x--;
        d--;
        m[i] = {{y, x}, d};
        v[y][x].push_back(i);
    }

    int ret = 1;
    while (true) {
        for (int i = 0; i < k; i++) {
            int y = m[i].first.first;
            int x = m[i].first.second;
            int d = m[i].second;

            int next_y = y + dir[d].first;
            int next_x = x + dir[d].second;

            if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= n || matrix[next_y][next_x] == 2) {
                if (d == 0) d = 1;
                else if (d == 1) d = 0;
                else if (d == 2) d = 3;
                else if (d == 3) d = 2;

                next_y = y + dir[d].first;
                next_x = x + dir[d].second;
                m[i].second = d;
            }

            // 다음 칸이 빨강, 파랑
            if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= n || matrix[next_y][next_x] == 2) {
                continue;
            }

            if (matrix[next_y][next_x] == 0) {
                int idx = -1;
                for (int j = 0; j < v[y][x].size(); j++) {
                    int temp = v[y][x][j];
                    if (temp == i)
                        idx = j;
                    
                    if (idx == -1) continue;

                    m[temp].first.first = next_y;
                    m[temp].first.second = next_x;
                    v[next_y][next_x].push_back(temp);
                    if (v[next_y][next_x].size() >= 4) {
                        cout << ret << "\n";
                        return 0;
                    }
                }

                int size = v[y][x].size();
                for (int j = idx; j < size; j++) {
                    v[y][x].pop_back();
                }
            }
            if (matrix[next_y][next_x] == 1) {
                int idx = -1;
                for (int j = v[y][x].size() - 1; j >= 0; j--) {
                    int temp = v[y][x][j];
                    if (temp == i) {
                        idx = j;
                        break;
                    }
                }

                for (int j = v[y][x].size() - 1; j >= idx; j--) {
                    int temp = v[y][x][j];
                    m[temp].first.first = next_y;
                    m[temp].first.second = next_x;
                    v[next_y][next_x].push_back(temp);
                    if (v[next_y][next_x].size() >= 4) {
                        cout << ret << "\n";
                        return 0;
                    }
                }

                int size = v[y][x].size();
                for (int j = idx; j < size; j++) {
                    v[y][x].pop_back();
                }
            }
        }
        
        ret++;
        if (ret > 1000) {
            cout << -1 << "\n";
            return 0;
        }
    }
    return 0;
}
