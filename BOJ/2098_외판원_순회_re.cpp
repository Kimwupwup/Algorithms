/**
 * 백준 2098번 - 외판원 순회
 * 문제 다시 풀어보기
 * 
 * TODO:
 * 마을을 방문했었는지 확인하여야 한다.
 * 최소 비용이여야 한다.
 * 
 * FIXME:
 * 마을을 방문했었는지 확인하기 위해서 비트마스트를 사용한다.
 * DP 알고리즘을 사용하며,
 * dp[i][j] : i는 현재 마을이며, j는 지금까지 방문했던 마을들이다.
 * dp[i][j]는 지금까지의 비용이다.
 * */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX = 16;

int n;
int matrix[MAX][MAX];
int dp[MAX][1 << MAX];

int TSP(int current, int visited) {
    
    // 다 방문했다는 소리.
    if (visited == (1 << n) - 1) {
        
        // 현재 마을에서 0번 마을로 돌아갈 수 있어야 한다.
        if (matrix[current][0] != 0) {
            return matrix[current][0];
        }
        return INF;
    }

    int &ret = dp[current][visited];
    if (ret != -1)
        return ret;
    
    ret = INF;

    for (int i = 0; i < n; i++) {

        // 다음 방문할 마을을 방문했거나, 갈 수 없는 상황이면 넘긴다.
        if (visited & (1 << i) || matrix[current][i] == 0) 
            continue;
        
        // 그 다음을 계속 진행한다.
        int next = matrix[current][i] + TSP(i, visited + (1 << i));

        // 진행 결과와 기존 값중 작은 값을 채택한다.
        ret = min(ret, next);
    }
    return ret;
}

int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    
    memset(dp, -1, sizeof(dp));
    cout << TSP(0, (1 << 0)) << endl;
    return 0;
}