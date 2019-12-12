/**
 * ALGOSPOT - 게임판 덮기
 * 
 * 재귀적 호출로 해결 생각
 * */
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int MAX = 20;

vector<vector<pair<int, int>>> dir = 
    {{{0,0},{1,0},{0,1}},{{0,0},{0,1},{1,1}},
{{0,0},{1,0},{1,1}},{{0,0},{1,0},{1,-1}}};
int T;
int n, m;
char matrix[MAX][MAX];
vector<pair<int, int>> v;
int ret = 0;

bool check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '.')
                return false;
        }
    }
    return true;
}

bool can(int y, int x, int dir_idx) {
    for (int i = 0; i < 3; i++) {
        int next_y = y + dir[dir_idx][i].first;
        int next_x = x + dir[dir_idx][i].second;

        if (matrix[next_y][next_x] != '.')
            return false;
    }
    return true;
}

void draw (int y, int x, int dir_idx, char type) {
    for (int i = 0; i < 3; i++) {
        int next_y = y + dir[dir_idx][i].first;
        int next_x = x + dir[dir_idx][i].second;
        if (type == '#')
            matrix[next_y][next_x] = type + 1;
        else
            matrix[next_y][next_x] = type;
    }

}

void DFS(int idx) {
    if (idx == v.size()) {
        if (check()) {
            ret++;
        }
        return;
    }
    
    int y = v[idx].first;
    int x = v[idx].second;    
    if (matrix[y][x] == '$' || matrix[y][x] == '#') {
        DFS(idx + 1);
    }
    for (int i = 0; i < 4; i++) {
        if (can(y, x, i)) {
            draw(y, x, i, '#');
            DFS(idx + 1);
            draw(y, x, i, '.');
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        memset(matrix, ' ', sizeof(matrix));
        ret = 0;
        v.clear();
        cin >> n >> m;
        for (int i = 0 ; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
                if (matrix[i][j] == '.')
                    v.push_back({i, j});
            }
        }
        DFS(0);
        cout << ret << endl;
    }

    return 0;
}