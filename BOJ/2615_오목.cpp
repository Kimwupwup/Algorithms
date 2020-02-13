/**
 * 백준 2615번 - 오목
 * 
 * TODO:
 * 완전탐색, DFS
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 25;
vector<pair<int, int>> dir = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}};
int matrix[MAX][MAX];

bool solve(int y, int x, int d) {
    int who = matrix[y][x];
    if (matrix[y - dir[d].first][x -dir[d].second] == who) return false;
    for (int i = 0; i < 5; i++) {
        if (matrix[y][x] != who || y < 0 || y >= 19 || x < 0 || x >= 19) return false;
        y += dir[d].first;
        x += dir[d].second;
    }
    return matrix[y][x] != who;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (matrix[i][j]) {
                for (int k = 0; k < 4; k++) {
                    if (solve(i, j, k)) {
                        cout << matrix[i][j] << "\n" << i + 1 << " " << j + 1 << "\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << 0 << "\n";
    return 0;
}