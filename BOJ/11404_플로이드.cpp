/**
 * 백준 11404번 - 플로이드
 * 
 * TODO:
 * 방향성 그래프
 * 도시 i 에서 도시 j 로 가는 최소 비용을 구하여야 하므로,
 * 플로이드 워셜 알고리즘을 사용해야 한다.
 * N*3
 * **/

#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int matrix[101][101];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            matrix[i][j] = INF;

    for (int i = 0; i < m; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        if (matrix[u][v] > cost)
            matrix[u][v] = cost;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i == j)
                    continue;
                else if (matrix[i][j] > matrix[i][k] + matrix[k][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (matrix[i][j] == INF)
                cout << 0 << " ";
            else
                cout << matrix[i][j] << " ";
        cout << "\n";
    }
}
