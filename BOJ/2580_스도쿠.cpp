/**
 * 백준 2580번 - 스도쿠
 * 
 * TODO:
 * 백트래킹
 * */
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 9;
int matrix[MAX][MAX];
bool col[MAX][MAX + 1];
bool row[MAX][MAX + 1];
bool box[MAX / 3][MAX / 3][MAX + 1];
vector<pair<int, int>> v;

void solve(int idx) {
    if (idx == v.size()) {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }

    int y = v[idx].first;
    int x = v[idx].second;
    int by = y / 3;
    int bx = x / 3;

    for (int i = 1; i <= MAX; i++) {
        if (col[y][i] || row[x][i] || box[by][bx][i])
            continue;
        
        col[y][i] = true;
        row[x][i] = true;
        box[by][bx][i] = true;
        matrix[y][x] = i;
        solve(idx + 1);
        col[y][i] = false;
        row[x][i] = false;
        box[by][bx][i] = false;
        matrix[y][x] = 0;
    }
    return;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j]) {
                col[i][matrix[i][j]] = true;
                row[j][matrix[i][j]] = true;
                box[i / 3][j / 3][matrix[i][j]] = true;
            }
            else {
                v.push_back({i, j});
            }
        }
    }

    solve(0);
    return 0;
}