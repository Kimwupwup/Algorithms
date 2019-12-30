/**
 * 백준 14503번 - 로봇청소기
 * 
 * */

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (int)n; i++)

using namespace std;

const int MAX = 50;
vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int n, m;
int originY, originX, originDir;
int matrix[MAX][MAX];

int ret = 0;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    cin >> originY >> originX >> originDir;
    forn (i, n)
        forn (j, m)
            cin >> matrix[i][j];

    int y = originY;
    int x = originX;
    int cur = originDir;
    int cnt = 0;
    while (true) {
        if (matrix[y][x] == 0) {
            matrix[y][x] = 2;
            ret++;
        }            
        
        cnt = 0;
        while (cnt < 4) {
            cnt++;
            cur--;
            if (cur < 0)
                cur = 3;
            int nextY = y + dir[cur].first;
            int nextX = x + dir[cur].second;
            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m || matrix[nextY][nextX] != 0)
                continue;

            y = nextY;
            x = nextX;
            break;
        }

        if (matrix[y][x]) {
            y = y + dir[(cur - 2 < 0) ? cur + 2 : cur - 2].first;
            x = x + dir[(cur - 2 < 0) ? cur + 2 : cur - 2].second;
            
            if (matrix[y][x] == 1)
                break;
        }
    }
    cout << ret << "\n";
    return 0;
}