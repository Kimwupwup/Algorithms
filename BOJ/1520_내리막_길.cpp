/**
 * 백준 1520번 - 내리막 길
 * 세로 M, 가로 N 의 배열 에 높이 최대 10000이하의 자연수
 * 
 * TODO:
 * 0, 0 부터 시작하여 M - 1, N - 1 까지 내리막을 가야 한다.
 * 
 * FIXME:
 * BFS 알고리즘을 통해 해결할 수 있을 것 같다. (시간 초과)
 * DP 와 DFS 를 통해 해결하는 문제이다.
 * dp[i][j] 에는 i, j 에서 M, N 까지 갈 수 있는 경로의 갯수를 저장한다.
 * dp[i][j] 가 이미 간적이 있던 경로라면 바로 dp[i][j] 를 반환한다.
 * 도착하면 1 을 반환한다.
 * 이가 거꾸로 반환되면서 0, 0 에 도착할 수 있는 경로의 갯수가 누적된다.
 * */
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int matrix[501][501];
int dp[501][501];
int dir_y[4] = {0, 0, 1, -1};
int dir_x[4] = {1, -1, 0, 0};

bool in_range (int y, int x, int M, int N) {
    return y >= 0 && y < M && x >= 0 && x < N;
}

bool down_hill (int y, int x, int next_y, int next_x) {
    return matrix[y][x] > matrix[next_y][next_x];
}

int DFS (int y, int x, int M, int N) {
    if (y == M - 1 && x == N - 1)
        return 1;

    int &ret = dp[y][x];

    if (ret != -1)
        return ret;
    
    ret = 0;

    for (int i = 0; i < 4; i++) {
        int next_y = y + dir_y[i];
        int next_x = x + dir_x[i];

        if (in_range (next_y, next_x, M, N) && down_hill (y, x, next_y, next_x)) {
            ret += DFS(next_y, next_x, M, N);
        }
    }
    return ret;
}

int main () {
    cin.tie (NULL);
    ios::sync_with_stdio (false);

    int M, N;
    cin >> M >> N;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> matrix[i][j];
    memset (dp, -1, sizeof(dp));
    cout << DFS(0, 0, M, N) << "\n";
    return 0;
}