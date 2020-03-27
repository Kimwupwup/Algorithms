/**
 * 백준 18809번 - Gaaaaaaaaaarden
 * 
 * TODO:
 * BFS
 * */
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX = 50;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<pair<int, int>> possible;
vector<int> v;

int matrix[MAX][MAX];
int n, m, r, g;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> r >> g;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 2) 
                possible.push_back({i, j});
        }
    }

    for (int i = 0; i < possible.size() - r - g; i++)
        v.push_back(0);
    for (int i = 0; i < r; i++)
        v.push_back(3);
    for (int i = 0; i < g; i++) 
        v.push_back(4);

    int ret = 0;

    // 배양액을 뿌릴 곳에 대해서 모든 경우를 실행한다.
    do {
        int temp[MAX][MAX];
        queue<pair<pair<int, int>, int>> q;

        // 배열 복사
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0)
                    temp[i][j] = matrix[i][j];
                else
                    temp[i][j] = -1;
            }

        // 배양액을 뿌릴 곳 표시
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != 0) {
                q.push({{possible[i].first, possible[i].second}, v[i] * 10000});
                temp[possible[i].first][possible[i].second] = 0;
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int y = q.front().first.first;
                int x = q.front().first.second;
                int color = q.front().second;
                q.pop();

                // 현재 자리가 꽃이 핀 자리라면 무시한다.
                if (temp[y][x] >= 50000) continue;

                for (int j = 0; j < 4; j++) {
                    int next_y = y + dir[j].first;
                    int next_x = x + dir[j].second;
                    int next_color = color + 1;
                    // 배열 이탈
                    if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m) continue;

                    // 호수, 똑같은 색의 배양액, 꽃의 경우 무시한다.
                    if (temp[next_y][next_x] == 0 || temp[next_y][next_x] >= 50000) continue;
                    
                    if (abs(next_color - temp[next_y][next_x]) == 10000) {
                        temp[next_y][next_x] = 100000;
                        cnt++;
                    } 

                    // 서로 다른 배양액일 경우, cnt 를 늘리고 temp 에 표시한다. (queue 에는 추가하지 않는다.)
                    else if (temp[next_y][next_x] == -1) {
                        temp[next_y][next_x] = next_color;
                        q.push({{next_y, next_x}, next_color});
                    }
                }
            }
        }
        ret = max(ret, cnt);
    } while (next_permutation(v.begin(), v.end()));
    cout << ret << "\n";
    return 0;
}