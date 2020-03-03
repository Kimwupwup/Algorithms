/**
 * 백준 17136번 - 생종이 붙이기
 * 
 * TODO:
 * DFS, 브루트 포스
 * */
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 10;
const int INF = 987654321;

int matrix[MAX][MAX];
int maxi[6];
int ret, cnt;

void DFS(int y, int x) {
    if (x == MAX) {
        DFS(y + 1, 0);
        return;
    }

    if (y == MAX) {
        ret = min(ret, cnt);
        return;
    }

    if (matrix[y][x] == 0) {
        DFS(y, x + 1);
        return;
    }

    for (int k = 5; k > 0; k--) {
        if (maxi[k] >= 5 || y + k > MAX || x + k > MAX) {
            continue;
        }

        bool good = true;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (matrix[y + i][x + j] == 0) {
                    good = false;
                    break;
                }
            }
            if (good == false) {
                break;
            }
        }
        if (good == false) {
            continue;
        }

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                matrix[y + i][x + j] = 0;
            }
        }

        maxi[k]++;
        cnt++;

        DFS(y, x + 1);

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                matrix[y + i][x + j] = 1;
            }
        }

        maxi[k]--;
        cnt--;
    }
    return;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> matrix[i][j];
        }
    }
    ret = INF;
    DFS(0, 0);

    if (ret == INF) 
        cout << -1 << "\n";
    else 
        cout << ret << "\n";
    return 0;
}