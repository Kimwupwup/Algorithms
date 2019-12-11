/**
 * SW Expert Academy
 * 1767번 - 프로세서 연결하기
 * 
 * DFS 완전탐색
 * 그리기, 지우기
 * 사용된 코어가 최대인지 확인해야 하며, 사용된 길이가 최소인지 확인해야 한다.
 * 사용된 코어가 최대인지 확인한다는 것은 사용되지 않는 코어도 있을 수 있다는 것이다.
 * */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pair<int, int>> v;

const int MAX = 12;
int matrix[MAX][MAX];
int dp[MAX][MAX];

int t, n;
int mini = 987654321;
int maxi = -1;

void draw_line(int y, int x, int dir_idx, int type) {
    int next_y = y + dir[dir_idx].first;
    int next_x = x + dir[dir_idx].second;

    while (true) {
        if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= n) break;
        
        matrix[next_y][next_x] = type;

        next_y += dir[dir_idx].first;
        next_x += dir[dir_idx].second;
    }
}

int calculate_length() {
    int ret = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == 2)
                ret++;
    return ret;
}

bool check(int y, int x, int dir_idx) {
    int next_y = y + dir[dir_idx].first;
    int next_x = x + dir[dir_idx].second;

    while (true) {
        if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= n) break;
        if (matrix[next_y][next_x] >= 1) return false;

        next_y += dir[dir_idx].first;
        next_x += dir[dir_idx].second;
    }
    return true;
}

void DFS(int idx, int cnt) {
    if (idx == v.size()) {
        int num = calculate_length();
        if (maxi < cnt) {
            maxi = cnt;
            mini = num;
        }
        else if (maxi == cnt) {
            mini = min(mini, num);
        }
        return;
    }

    int y = v[idx].first;
    int x = v[idx].second;
    
    for (int i = 0; i < 4; i++) {
        if (check(y, x, i)) {
            draw_line(y, x, i, 2);
            DFS(idx + 1, cnt + 1);
            draw_line(y, x, i, 0);
        }
    }
    DFS(idx + 1, cnt);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    int temp = t;
    while (t--) {
        memset(matrix, false, sizeof(matrix));
        v.clear();
        mini = 987654321;
        maxi = -1;
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
                if (matrix[i][j] == 1) {
                    if (i == 0 || i == n - 1 || j == 0 || j == n - 1) continue;
                    v.push_back({i, j});
                }
            }
        }
        DFS(0, 0);
        cout << "#" << temp - t << " " << mini << "\n";
    }
    return 0;
}