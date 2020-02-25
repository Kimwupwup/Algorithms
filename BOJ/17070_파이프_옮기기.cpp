/**
 * 백준 17070번 - 파이프 옮기기 1
 * 
 * TODO:
 * BFS or DP
 * */
#include <bits/stdc++.h>

using namespace std;

/* DP */
const int MAX = 16;

int matrix[MAX][MAX];
int dp[MAX][MAX][3];
int n;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    
    dp[0][1][0] = 1;
    dp[0][1][1] = 0;
    dp[0][1][2] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < n - 1 && matrix[i][j + 1] == 0) {
                dp[i][j + 1][0] += dp[i][j][0] + dp[i][j][2];
            }
            if (i < n - 1 && matrix[i + 1][j] == 0) {
                dp[i + 1][j][1] += dp[i][j][1] + dp[i][j][2];
            }
            if (i < n - 1 && j < n - 1) {
                if (matrix[i + 1][j] == 0 && matrix[i][j + 1] == 0 && matrix[i + 1][j + 1] == 0) {
                    dp[i + 1][j + 1][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
                }
            }
        }
    }

    cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2] << "\n";

    return 0;
}

/* BFS */

// const int MAX = 16;
// vector<pair<int, int>> dir = {{0, 1}, {1, 1}, {1, 0}};

// int matrix[MAX][MAX];
// int n;

// int main() {
//     cin.tie(nullptr);
//     ios::sync_with_stdio(false);

//     cin >> n;
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             cin >> matrix[i][j];
    
//     queue<pair<int, pair<int, int>>> q;
//     q.push({0, {0, 1}});
//     int ret = 0;
//     while (!q.empty()) {
//         int type = q.front().first;
//         int y = q.front().second.first;
//         int x = q.front().second.second;
//         q.pop();

//         if (y == n - 1 && x == n - 1) {
//             ret++;
//             continue;
//         }

//         // 0: 0 ~ 1, 1: 0 ~ 2, 2: 1 ~ 2
//         for (int i = max(type - 1, 0); i <= min(type + 1, 2); i++) {
//             int next_y = y + dir[i].first;
//             int next_x = x + dir[i].second;

//             if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= n || matrix[next_y][next_x] == 1) continue;
//             if (i == 1 && (matrix[next_y - 1][next_x] == 1 || matrix[next_y][next_x - 1])) continue;
//             q.push({i, {next_y, next_x}});
//         }
//     }
//     cout << ret << "\n";
//     return 0;
// }