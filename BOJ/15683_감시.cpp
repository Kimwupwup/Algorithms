/**
 * 백준 15683번 - 감시
 * 
 * TODO:
 * 브루트포스, 구현
 * */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 8;
const int INF = 987654321;

vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int n, m;
int matrix[MAX][MAX], cp_matrix[MAX][MAX];
bool visited[MAX][MAX][4];
vector<pair<int, int>> cameras;
vector<int> angles;
int ret = INF;

void copy() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cp_matrix[i][j] = matrix[i][j];
}

int counting() {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (cp_matrix[i][j] == 0)
                cnt++;
    
    return cnt;
}

void DFS(int idx) {
    if (idx == cameras.size()) {
        for (int i = 0; i < cameras.size(); i++) {
            int y = cameras[i].first;
            int x = cameras[i].second;

            for (int j = 0; j < 4; j++) {
                if (visited[y][x][j]) {
                    int next_y = y + dir[(angles[i] + j) % 4].first;
                    int next_x = x + dir[(angles[i] + j) % 4].second;
                    while (true) {
                        if (cp_matrix[next_y][next_x] == 6) {
                            break;
                        }
                        if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m) {
                            break;
                        }
                        if (cp_matrix[next_y][next_x] == 0)
                            cp_matrix[next_y][next_x] = -1;
                        
                        next_y += dir[(angles[i] + j) % 4].first;
                        next_x += dir[(angles[i] + j) % 4].second;
                    }
                }
            }
        }
        ret = min(ret, counting());
        copy();
        return;
    }

    for (int i = 0; i < 4; i++) {
        angles.push_back(i);
        DFS(idx + 1);
        angles.pop_back();
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];

            if (matrix[i][j] >= 1 && matrix[i][j] <= 5) {
                cameras.push_back(make_pair(i, j));
                switch(matrix[i][j]) {
                    case 1:
                        visited[i][j][0] = true;
                        break;
                    case 2:
                        visited[i][j][0] = true;
                        visited[i][j][2] = true;
                        break;
                    case 3:
                        visited[i][j][0] = true;
                        visited[i][j][1] = true;
                        break;
                    case 4:
                        visited[i][j][0] = true;
                        visited[i][j][1] = true;
                        visited[i][j][2] = true;
                        break;
                    case 5:
                        visited[i][j][0] = true;
                        visited[i][j][1] = true;
                        visited[i][j][2] = true;
                        visited[i][j][3] = true;
                        break;
                }
            }
        }
    }
        
    ret = INF;
    copy();
    DFS(0);
    cout << ret << "\n";

    return 0;
}