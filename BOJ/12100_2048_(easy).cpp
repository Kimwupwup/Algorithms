/**
 * 백준 12100번 - 2048(easy)
 * 
 * 최대 5번 움직여서 나올 수 있는 가장 큰 숫자는?
 * TODO:
 * DFS, 부르트포스
 * 구현 문제 였다.
 * */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 20;
int n;
int ret = 0;

vector<vector<int>> move(int type, vector<vector<int>> origin) {
    queue<int> q;

    if (type == 0) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (origin[y][x])
                    q.push(origin[y][x]);
                origin[y][x] = 0;
            }
            
            int idx = 0;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                if (origin[y][idx] == 0) {
                    origin[y][idx] = cur;
                } else if (origin[y][idx] == cur) {
                    origin[y][idx] *= 2;
                    idx++;
                } else {
                    idx++;
                    origin[y][idx] = cur;
                }
            }
        }
    } else if (type == 1) {
        for (int y = 0; y < n; y++) {
            for (int x = n - 1; x >= 0; x--) {
                if (origin[y][x])
                    q.push(origin[y][x]);
                origin[y][x] = 0;
            }
            
            int idx = n - 1;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                if (origin[y][idx] == 0) {
                    origin[y][idx] = cur;
                } else if (origin[y][idx] == cur) {
                    origin[y][idx] *= 2;
                    idx--;
                } else {
                    idx--;
                    origin[y][idx] = cur;
                }
            }
        }
    } else if (type == 2) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (origin[y][x])
                    q.push(origin[y][x]);
                origin[y][x] = 0;
            }
            
            int idx = 0;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                if (origin[idx][x] == 0) {
                    origin[idx][x] = cur;
                } else if (origin[idx][x] == cur) {
                    origin[idx][x] *= 2;
                    idx++;
                } else {
                    idx++;
                    origin[idx][x] = cur;
                }
            }
        }
    } else if (type == 3) {
        for (int x = 0; x < n; x++) {
            for (int y = n - 1; y >= 0; y--) {
                if (origin[y][x])
                    q.push(origin[y][x]);
                origin[y][x] = 0;
            }
            
            int idx = n - 1;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                if (origin[idx][x] == 0) {
                    origin[idx][x] = cur;
                } else if (origin[idx][x] == cur) {
                    origin[idx][x] *= 2;
                    idx--;
                } else {
                    idx--;
                    origin[idx][x] = cur;
                }
            }
        }
    }
    return origin;
}

void DFS(int cnt, vector<vector<int>> matrix) {
    if (cnt == 5) {
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                if (ret < matrix[i][j])
                    ret = matrix[i][j];
        
        return;
    }

    for (int i = 0; i < 4; i++) {
        DFS(cnt + 1, move(i, matrix));
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    vector<vector<int>> v;
    vector<int> temp;
    temp.resize(n);
    v.resize(n, temp);

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    
    DFS(0, v);
    cout << ret << "\n";
    return 0;
}