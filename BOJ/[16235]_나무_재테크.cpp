/**
 * 백준 16235번 - 나무 재테크
 * 
 * TODO:
 * 구현
 * */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 10;

vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int matrix[MAX][MAX];
int S2D2[MAX][MAX];
vector<int> v[MAX][MAX];
int n, m, k;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;

    // 땅 정보
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> S2D2[i][j];
            matrix[i][j] = 5;
        }
    }

    // 나무 정보
    for (int i = 0; i < m; i++) {
        int y, x, age;
        cin >> y >> x >> age;
        v[y - 1][x - 1].push_back(age);
    }

    // k 년 반복
    while (k--) {

        // 봄, 여름 처리(사망 확인, 양분 추가)
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (!v[y][x].empty()) {

                    // 살아남은 나무
                    vector<int> temp;

                    // 죽은 나무 -> 양분
                    int dead = 0;

                    // 가장 어린 나무부터 처리
                    sort(v[y][x].begin(), v[y][x].end());

                    for (int i = 0; i < v[y][x].size(); i++) {
                        int age = v[y][x][i];

                        if (matrix[y][x] >= age) {
                            matrix[y][x] -= age;
                            temp.push_back(age + 1);
                        }
                        else 
                            dead += age / 2;
                    }

                    v[y][x].clear();
                    for (int i = 0; i < temp.size(); i++) 
                        v[y][x].push_back(temp[i]);
                    matrix[y][x] += dead;
                }
            }
        }

        // 가을 처리(번식)
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (!v[y][x].empty()) {
                    for (int i = 0; i < v[y][x].size(); i++) {
                        if (v[y][x][i] % 5 != 0)
                            continue;
                        for (int d = 0; d < 8; d++) {
                            int next_y = y + dir[d].first;
                            int next_x = x + dir[d].second;

                            if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= n)
                                continue;
                            v[next_y][next_x].push_back(1);
                        }
                    }
                }
            }
        }

        // 겨울 처리(S2D2 양분 추가)
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                matrix[y][x] += S2D2[y][x];
            }
        }
    }

    // 살아있는 나무 개수 합
    int ret = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            ret += v[y][x].size();
        }
    }
    cout << ret << "\n";
    return 0;
}