/**
 * 백준 17143번 - 낚시왕
 * 
 * TODO:
 * 시뮬레이션, 구현, 자료구조
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;

pair<int, pair<int ,int>> matrix[MAX][MAX];
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int n, m, k;
int ret = 0;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++)
            matrix[i][j].first = -1;

    for (int i = 0; i < k; i++) {
        int y, x, s, d, z;
        cin >> y >> x >> s >> d >> z;

        matrix[y][x] = {z, {s, d - 1}};
    }

    int cur = 0;

    for (int c = 0; c < m; c++) {
        
        // 낚시왕 오른쪽으로 한 칸 이동
        cur++;

        // 가장 가까운 상어 사냥
        for (int i = 1; i <= n; i++) {
            if (matrix[i][cur].first != -1) {
                ret += matrix[i][cur].first;
                matrix[i][cur].first = -1;
                break;
            }
        }

        // 상어 이동
        queue<pair<pair<int, int>, pair<int, pair<int, int>>>> q;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (matrix[i][j].first != -1) {
                    q.push({{i, j}, {matrix[i][j]}});
                    matrix[i][j].first = -1;
                }
            }
        }

        while (!q.empty()) {
            int y = q.front().first.first;
            int x = q.front().first.second;
            int z = q.front().second.first;
            int s = q.front().second.second.first;
            int d = q.front().second.second.second;
            q.pop();

            for (int i = 0; i < s; i++) {
                if (d == 0 || d == 1) {
                    int next = y + dir[d].first;
                    if (next <= 0 || next > n)
                        d = 1 - d;
                    y += dir[d].first;
                }
                else {
                    int next = x + dir[d].second;
                    if (next <= 0 || next > m) 
                        d = 5 - d;
                    x += dir[d].second;
                }
            }

            if (matrix[y][x].first != -1) {
                if (matrix[y][x].first < z) {
                    matrix[y][x] = {z, {s, d}};
                }
            }
            else matrix[y][x] = {z, {s, d}};
        }
    }
    cout << ret << "\n";
    return 0;
}