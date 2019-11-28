/*
 * 백준 1753 - 최단 경로
 * 알고리즘: BFS, heap
 * 시작 노드에서 각 노드와 최단 거리(최소 비용)을 찾는 문제
 * 단, 서로 다른 정점 사이에 여러 개의 간선이 존재할 수 있으므로,
 * 최대 힙을 통해 비용이 가장 적은 것부터 처리해야 시간 내에 문제를 풀 수 있다.
 * priority_queue에 pair<"누적 비용", "노드 번호">를 넣어 처리한다.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int V, E;
int start;
vector<vector<pair<int, int>>> nodes;
vector<int> ret;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int main()
{
    scanf("%d %d", &V, &E);
    scanf("%d", &start);

    nodes.resize(V + 1);
    ret.resize(V + 1, INT_MAX);

    for (int i = 0; i < E; i++)
    {
        int u;
        pair<int, int> p;
        scanf("%d %d %d", &u, &p.first, &p.second);
        nodes[u].push_back(p);
    }

    q.push({0, start});
    ret[start] = 0;

    while (!q.empty())
    {
        int current_cost = q.top().first;
        int current_node = q.top().second;
        q.pop();

        for (int i = 0; i < nodes[current_node].size(); i++)
        {
            int next = nodes[current_node][i].first;
            int cost = nodes[current_node][i].second;

            if (ret[next] > cost + current_cost) {
                q.push({cost + current_cost, next});
                ret[next] = cost + current_cost;
            }
        }
    }
    for (int i = 1; i <= V; i++)
        if (ret[i] == INT_MAX)
            printf("INF\n");
        else 
            printf("%d\n", ret[i]);

    return 0;
}