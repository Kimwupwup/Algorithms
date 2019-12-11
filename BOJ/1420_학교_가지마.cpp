/**
 * 백준 1420번 - 학교 가지마
 * 
 * n * m 행렬
 * 상하좌우 이동 가능
 * 이동할 때마다 갈 수 있는 곳을 막고, 그 갯수를 센다.
 * 그 갯수가 최소인 경우를 저장한다.
 * */

#include <iostream>
#include <queue>

using namespace std;

int dir_y[4] = {0, 0, 1, -1};
int dir_x[4] = {1, -1, 0, 0};

const int MAX = 101;
int n, m;
int ret = 987654321;

pair<int, int> k, h;

char matrix[MAX][MAX];
bool visited[MAX][MAX];

int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'K')
                k = {i, j};
            else if (matrix[i][j] == 'H')
                h = {i, j};
        }

    
    cout << ret << endl;
    return 0;
}