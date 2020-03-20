/**
 * 백준 1976번 - 여행 가자
 * 
 * TODO:
 * 플로이드 와샬
 * */
#include <iostream>

using namespace std;

const int MAX = 200;
int matrix[MAX][MAX];
int ans[1000];
int n, m;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> ans[i];
        ans[i]--;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) matrix[i][j] = 1;
                if (matrix[i][k] == 0 || matrix[k][j] == 0) continue;
                matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }

    int u = ans[0];
    for (int i = 1; i < m; i++) {
        int v = ans[i];
        if (matrix[u][v] == 0) {
            cout << "NO\n";
            return 0;
        }
        u = v;
    }
    cout << "YES\n";
    return 0;
}