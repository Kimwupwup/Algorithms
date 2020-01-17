/**
 * 백준 1025번 - 제곱수 찾기
 * 
 * 일정한 규칙으로 숫자를 연결하였을 때, 그 수의 제곱수가 가장 큰 것을 찾아라.
 * 다해보는 방법을 사용해야 한다.
 * TODO:
 * 브루트 포스
 * */
#include <bits/stdc++.h>
using namespace std;

const int MAX = 9;
int matrix[MAX][MAX];
int n, m;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = matrix[i][j];
            
            // 범위 안에 듥어가는 지 조건부
            // dx, dy의 루프를 돌아서 이동의 경우를 다 생각해본다.
            /*
                for (int dx = -a; dx <= a; dx++) {
                    for (int dy = -b; dy <= b; dy++) {
                        if (i + dx > ... || i + dx < ...) {
                            if (j + dy > ... || j + dy < ...) {
                                sum = sum * 10 + matrix[i + dx][i + dy];
                            }
                        }
                    }
                }
            */
        }
    }

    return 0;
}