/**
 * 백준 11657번 - 타임머신
 * 방향 그래프
 * N 개 도시, M 개 버스 노선
 * 버스 노선 정보는 시작도시, 도착도시, 걸리는 시간으로 나타낼 수 있다.
 * C가 양수가 아닐 수 있다.(0, 음수 가능)
 * 1번에서 출발해서 나머지 도시로 최단 거리로 가는 것을 구하라.
 * 
 * TODO:
 * 무한히 되돌릴 수 있다면 첫줄에 -1을 출력하라.
 * 갈 수 있다면 가장 빠른 시간 순서대로 출력하고
 * 갈 수 없다면 -1을 출력하라.
 * 
 * FIXME:
 * 벨만포드 알고리즘
 * 간선 수 M 을 모든 노드에 대해서 실행시킨다. (O(N * M) 시간복잡도를 가진다.)
 * 모든 노드에 대해서 실행시키고 다시 간선 M개를 실행하였을 때, 변화(최단 거리 갱신)가 있으면
 * 무한 루프가 존재한다는 의미이다.
 * 0 과 음수를 고려해야 하므로 다익스트라 알고리즘으로 해결할 수 없다.
 * 그냥 다익스트라 알고리즘으로 할 경우, 무한 루프가 생긴다.(되돌아 가는 것이 최단 거리일 수 있으므로)
 * **/

#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

const int INF = 90000000;
vector<pair<pair<int, int>, int>> edges;
vector<int> ret;
int matrix[501][501];
int N, M;
int A, B, C;

bool bellman_ford(int start)
{
    ret[start] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int u = edges[j].first.first;
            int v = edges[j].first.second;
            int cost = edges[j].second;

            if (ret[u] != INF && ret[u] + cost < ret[v])
                ret[v] = ret[u] + cost;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int cost = edges[i].second;

        if (ret[u] != INF && ret[u] + cost < ret[v])
            return false;
    }
    return true;
}
int main()
{
    scanf("%d %d", &N, &M);
    edges.resize(M + 1);
    ret.resize(N + 1, INF);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &A, &B, &C);
        edges[i] = {{A, B}, C};
    }

    if (bellman_ford(1))
    {
        for (int i = 2; i <= N; i++)
            if (ret[i] < INF)
                printf("%d\n", ret[i]);
            else
                printf("-1\n");
    }
    else
        printf("-1\n");
    return 0;
}