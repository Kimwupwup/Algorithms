/**
 * 백준 15684번 - 사다리 조작
 * 
 * */

#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;

int n, m, h;
int ret;
bool flag;
bool visited[MAX][11];

void DFS(int y, int cnt) {
    if (flag)
        return;
    if (ret == cnt) {
        bool possible = true;
        for (int i = 1; i <= n; i++) {
            int row = i;
            for (int j = 0; j < h; j++) {
                if (visited[j][row])
                    row++;
                else if (visited[j][row - 1])
                    row--;
            }
            if (i != row) {
                possible = false;
                break;
            }
        }
        if (possible)
            flag = true;
        return;
    }

    for (int i = y; i < h; i++) {
        for (int j = 1; j < n; j++) {
            if (!visited[i][j - 1] && !visited[i][j] && !visited[i][j + 1]) {
                visited[i][j] = true;
                DFS(i, cnt + 1);
                visited[i][j] = false;
            }
        }
    }
    return;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        visited[a - 1][b] = true;
    }
    for (int i = 0; i <= 3; i++) {
        ret = i;
        DFS(0, 0);
        if (flag) {
            cout << ret << endl;
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}