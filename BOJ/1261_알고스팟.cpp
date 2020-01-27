/**
 * 백준 1261번 - 알고스팟
 * 
 * TODO:
 * BFS
 * */
#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
const int MAX = 100;
char matrix[MAX][MAX];
int dp[MAX][MAX];
int n, m;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void BFS() {
    dp[0][0] = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    q.push({0, {0, 0}});

    while (!q.empty()) {
        int y = q.top().second.first;
        int x = q.top().second.second;
        int cost = q.top().first;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_y = dir[i].first + y;
            int next_x = dir[i].second + x;
            int next_cost = cost + (matrix[next_y][next_x] == '1' ? 1 : 0);

            if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m || dp[next_y][next_x] <= next_cost) 
                continue;
            dp[next_y][next_x] = next_cost;
            q.push({next_cost, {next_y, next_x}});
        }
    } 
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            dp[i][j] = INF;
        }
    }

    BFS();
    cout << dp[n - 1][m - 1] << "\n";
    return 0;
}