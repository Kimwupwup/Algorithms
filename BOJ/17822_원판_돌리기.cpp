/**
 * 백준 17822번 - 원판 돌리기
 * 
 * TODO:
 * 시뮬레이션, 구현, deque, BFS
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 51;
const int INF = 987654321;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, t;
deque<int> matrix[MAX];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            matrix[i].push_back(temp);
        }
    }

    // t 회 회전
    for (int i = 0; i < t; i++) {
        int x, d, k;
        cin >> x >> d >> k;

        // 판 회전
        for (int j = x; j <= n; j += x) {
            if (j == 1) {
                for (int l = 0; l < k; l++) {
                    if (d == 0) {
                        int temp = matrix[j].back();
                        matrix[j].pop_back();
                        matrix[j].push_front(temp);
                    }
                    else {
                        int temp = matrix[j].front();
                        matrix[j].pop_front();
                        matrix[j].push_back(temp);
                    }
                }
                break;
            }
            else {
                for (int l = 0; l < k; l++) {
                    if (d == 0) {
                        int temp = matrix[j].back();
                        matrix[j].pop_back();
                        matrix[j].push_front(temp);
                    }
                    else {
                        int temp = matrix[j].front();
                        matrix[j].pop_front();
                        matrix[j].push_back(temp);
                    }
                }
            }
        }

        // 인접 확인
        int cnt = 0;
        bool visited[n + 1][m];
        memset(visited, false, sizeof(visited));

        queue<pair<int, pair<int, int>>> q;
        for (int j = 1; j <= n; j++) {
            for (int l = 0; l < m; l++) {
                if (visited[j][l] || matrix[j][l] == INF) continue;
                vector<pair<int, int>> temp;
                temp.push_back({j, l});
                q.push({matrix[j][l], {j, l}});
                visited[j][l] = true;

                // 동일 숫자 찾기(인접)
                while (!q.empty()) {
                    int cur = q.front().first;
                    int y = q.front().second.first;
                    int x = q.front().second.second;
                    q.pop();

                    for (int o = 0; o < 4; o++) {
                        int next_y = y + dir[o].first;
                        int next_x = x + dir[o].second;

                        if (next_x == -1) next_x = m - 1;
                        else if (next_x == m) next_x = 0;

                        if (next_y <= 0 || next_y > n || next_x < 0 || next_x >= m || visited[next_y][next_x] || matrix[next_y][next_x] == INF || cur != matrix[next_y][next_x])
                            continue;
                        
                        q.push({cur, {next_y, next_x}});
                        visited[next_y][next_x] = true;
                        temp.push_back({next_y, next_x});
                    }
                }

                // 숫자 삭제
                if (temp.size() > 1) {
                    cnt++;
                    for (int o = 0; o < temp.size(); o++) {
                        int y = temp[o].first;
                        int x = temp[o].second;
                        matrix[y][x] = INF;
                    }
                }
            }
        }
        
        // 인접하고 같은 숫자가 없었을 경우
        if (cnt == 0) {
            int sum = 0;
            int div = 0;
            for (int j = 1; j <= n; j++) {
                for (int l = 0; l < m; l++) {
                    if (matrix[j][l] != INF) {
                        sum += matrix[j][l];
                        div++;
                    } 
                }
            }
            double pivot = double(sum) / div;

            for (int j = 1; j <= n; j++) {
                for (int l = 0; l < m; l++) {
                    if (matrix[j][l] != INF) {
                        if (pivot < matrix[j][l]) matrix[j][l]--;
                        else if (pivot > matrix[j][l]) matrix[j][l]++;
                    } 
                }
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != INF)
                sum += matrix[i][j];
        }
    }
    cout << sum << "\n";
    return 0;
}