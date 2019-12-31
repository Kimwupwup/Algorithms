/**
 * 백준 14890번 - 경사로
 * 
 * TODO:
 * greedy, stack
 * */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;
int n, l;
int matrix[MAX][MAX];
int visited[MAX][MAX];
int ret = 0;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> l;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
        bool good = true;
        for (int j = 1; j < n; j++) {
            if (matrix[i][j - 1] == matrix[i][j] + 1) {
                if (j + l - 1 > n - 1) {
                    good = false;
                    break;
                }
                for (int k = j; k <= min(j + l - 1, n - 1); k++) {
                    if (matrix[i][j] != matrix[i][k])
                        good = false;
                }
                if (!good)
                    break;
                j = j + l - 1;
                visited[i][j] = 1;
            } else if (matrix[i][j - 1] + 1 == matrix[i][j]) {
                if (j - l < 0) {
                    good = false;
                    break;
                }                    
                for (int k = j - 1; k >= max(j - l, 0); k--) {
                    if (matrix[i][j - 1] != matrix[i][k] || visited[i][k] == 1)
                        good = false;
                }
                if (!good)
                    break;
            } else if (abs(matrix[i][j - 1] - matrix[i][j]) > 1) {
                good = false;
                break;
            }
        }
        if (good) {
            ret++;
        }
    }

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
        bool good = true;
        for (int j = 1; j < n; j++) {
            if (matrix[j - 1][i] == matrix[j][i] + 1) {
                if (j + l - 1 > n - 1) {
                    good = false;
                    break;
                }
                for (int k = j; k <= min(j + l - 1, n - 1); k++) {
                    if (matrix[j][i] != matrix[k][i])
                        good = false;
                }
                if (!good)
                    break;
                j = j + l - 1;
                visited[j][i] = 1;
            } else if (matrix[j - 1][i] + 1 == matrix[j][i]) {
                if (j - l < 0) {
                    good = false;
                    break;
                }                    
                for (int k = j - 1; k >= max(j - l, 0); k--) {
                    if (matrix[j - 1][i] != matrix[k][i] || visited[k][i] == 1)
                        good = false;
                }
                if (!good)
                    break;
            } else if (abs(matrix[j - 1][i] - matrix[j][i]) > 1) {
                good = false;
                break;
            }
        }
        if (good) {
            ret++;
        }
    }

    cout << ret << "\n";
    return 0;
}