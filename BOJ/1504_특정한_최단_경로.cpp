/**
 * 백준 1504번 - 특정한 최단 경로
 * 방향성 없는 그래프
 * 1 에서 N 번 정점까지의 최단 경로
 * 
 * TODO: 두가지 조건
 * 임의의 두 정점을 반드시 통과해야 한다는 것
 * 지났던 정점과 간선을 다시 이동할 수 있다.
 * 
 * 초기 생각 :
 * start -> must_a -> must_b -> end
 * start -> must_b -> must_a -> end
 * 다익스트라를 수행
 *  **/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321;

vector<vector<pair<int, int>>> nodes;
int N, E;
int u, v, cost;
int must_a, must_b;

vector<int> dijkstra(int start, int end)
{
    vector<int> ret(N + 1, INF);
    ret[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        for (int i = 0; i < nodes[current_node].size(); i++)
        {
            int next_cost = nodes[current_node][i].first + cost;
            int next = nodes[current_node][i].second;

            if (next_cost < ret[next])
            {
                ret[next] = next_cost;
                pq.push({next_cost, next});
            }
        }
    }
    return ret;
}

int main()
{
    scanf("%d %d", &N, &E);
    nodes.resize(N + 1);

    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &u, &v, &cost);
        nodes[u].push_back({cost, v});
        nodes[v].push_back({cost, u});
    }
    scanf("%d %d", &must_a, &must_b);

    vector<int> start_to_end = dijkstra(1, N);
    vector<int> must_a_to_end = dijkstra(must_a, N);
    vector<int> must_b_to_end = dijkstra(must_b, N);

    int ret =
        min(start_to_end[must_a] + must_a_to_end[must_b] + must_b_to_end[N],
            start_to_end[must_b] + must_b_to_end[must_a] + must_a_to_end[N]);
    if (ret < 0 || ret >= INF)
        printf("-1\n");
    else
        printf("%d\n", ret);
    return 0;
}