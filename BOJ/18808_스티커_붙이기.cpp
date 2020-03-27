/**
 * 백준 18808번 - 스티커 붙이기
 * 
 * TODO:
 * 구현
 * */
#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 40;

int matrix[MAX][MAX];
int sticker[10][10];
int N, M, K, R, C, ret;
int idx = 1;

bool box_check(int i, int j) {
    for (int a = 0; a < R; a++) {
        for (int b = 0; b < C; b++) {
            if (i + a >= N || j + b >= M || (matrix[i + a][j + b] && sticker[a][b]))
                return false;
        }
    }
    return true;
}

void box_draw(int i, int j) {
    for (int a = 0; a < R; a++) {
        for (int b = 0; b < C; b++) {
            if (sticker[a][b])
                matrix[i + a][j + b] = idx;
        }
    }
    idx++;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M >> K;
    while (K--) {
        int cnt = 0;
        memset(sticker, 0, sizeof(sticker));
        cin >> R >> C;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> sticker[i][j];
                if (sticker[i][j]) cnt++;
            }
        }

        for (int k = 0; k < 4; k++) {
            bool flag = false;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (box_check(i, j)) {
                        box_draw(i, j);
                        ret += cnt;
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }

            if (flag) break;
            else {
                int temp[10][10];
                for (int i = 0; i < R; i++) {
                    for (int j = 0; j < C; j++) {
                        temp[j][R - i - 1] = sticker[i][j];
                    }
                }

                int tmp = R;
                R = C;
                C = tmp;

                for (int i = 0; i < R; i++) {
                    for (int j = 0; j < C; j++) {
                        sticker[i][j] = temp[i][j];
                    }
                }                
            }
        }
    }
    
    cout << ret << "\n";

    return 0;
}