/**
 * 백준 17472번 - 다리 만들기 2
 * 
 * TODO:
 * 브루트 포스, BFS, 최소 스패닝 트리, 크루스칼
 * */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 10;
const int INF = 987654321;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int parent[7];
int cost[7][7];
int matrix[MAX][MAX];
int n, m;
vector<pair<int, pair<int, int>>> v;

int partition() {
    queue<pair<int, int>> q;
    bool visited[MAX][MAX];
    memset(visited, false, sizeof(visited));

    int idx = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    matrix[y][x] = idx;

                    for (int d = 0; d < 4; d++) {
                        int next_y = y + dir[d].first;
                        int next_x = x + dir[d].second;

                        if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m || visited[next_y][next_x] || matrix[next_y][next_x] == 0)
                            continue;
                        
                        q.push({next_y, next_x});
                        visited[next_y][next_x] = true;
                    }
                }
                idx++;
            }
        }
    }
    return idx;
}

void cal_cost(int idx) {
    for (int i = 1; i < idx; i++) {
        for (int j = 1; j < idx; j++) {
            cost[i][j] = INF;
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            for (int d = 0; d < 4; d++) {
                int next_y = y;
                int next_x = x;
                int len = 0;
                int target = -1;

                while (true) {
                    next_y = next_y + dir[d].first;
                    next_x = next_x + dir[d].second;

                    if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m)
                        break;

                    if (matrix[next_y][next_x] != 0) {
                        target = matrix[next_y][next_x];
                        break;
                    }
                    len++;
                }

                if (len >= 2 && target != -1 && target != matrix[y][x]) {
                    cost[matrix[y][x]][target] = min(cost[matrix[y][x]][target], len);
                    cost[target][matrix[y][x]] = cost[matrix[y][x]][target];
                }
            }
        }
    }

    for (int i = 1; i < idx; i++) {
        for (int j = i; j < idx; j++) {
            if (i == j || cost[i][j] == INF) continue;
            v.push_back({cost[i][j], {i, j}});
        }
    }
    sort(v.begin(), v.end());
    return;
}

int union_find(int idx) {
    if (idx == parent[idx]) return idx;
    return parent[idx] = union_find(parent[idx]);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    // 영역 분리(영역 인덱싱)
    int idx = partition();

    // 거리 계산
    cal_cost(idx);

    // 최소 스패닝 트리 (크루스칼)
    for (int i = 1; i < idx; i++)
        parent[i] = i;
    
    int ret = 0;
    for (int i = 0; i < v.size(); i++) {
        int parent_a = union_find(v[i].second.first);
        int parent_b = union_find(v[i].second.second);

        if (parent_a == parent_b) continue;

        parent[parent_b] = parent_a;
        ret += v[i].first;
    }

    // 독립된 영역이 있는지 확인하고
    // 있다면 -1 출력
    int temp = union_find(1);
    for (int i = 2; i < idx; i++) {
        if (temp != union_find(i)) {
            ret = -1;
            break;
        }
    }

    cout << ret << "\n";

    return 0;
}