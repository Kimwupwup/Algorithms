/**
 * 백준 1956번 - 운동
 * 일방통행 방향 그래프
 * V 개 마을, E 개 도로
 * 운동을 한 후에 원점으로 다시 돌아와야 하므로 사이클이여야 한다.
 * 
 * TODO:
 * 최단 거리의 사이클을 찾아야 한다.
 * 두 마을을 왕복하는 것도 사이클에 포함된다.
 * 
 * FIXME:
 * 어딘가를 거쳐서 원래로 돌아오는 경우를 찾는다.
 * 플로이드 워셜 알고리즘
 * i == j 의 경우를 찾고 그 중에서 가장 작은 것을 고르면 될 것 같다.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int matrix[401][401];

int main () {
    cin.tie (NULL);
    ios::sync_with_stdio (false);
    int V, E;
    cin >> V >> E;

    // matrix 초기화
    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++)
            matrix[i][j] = INF;
    
    // matrix 에는 i 에서 j 로는 비용(cost)가 들어간다.
    for (int i = 0; i < E; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        matrix[u][v] = cost;
    }

    // 플로이드 워셜
    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                if (matrix[i][j] > matrix[i][k] + matrix[k][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
    
    // i 에서 i 로 가는 복귀하는 것 중에서 가장 작은 것을 고르고 출력한다.
    // 만약 INF 이면 존재 하지 않다는 것이다.
    int ret = INF;
    for (int i = 1; i <= V; i++)
        if (ret > matrix[i][i])
            ret = matrix[i][i];
    if (ret == INF)
        cout << -1 << "\n";
    else 
        cout << ret << "\n";
    return 0;
}