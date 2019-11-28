/**
 * 백준 9370번 - 미확인 도착지
 * 방향성 없는 간선
 * 범인이 최단거리로 목적지로 갈 것이다.
 * 하나의 간선을 알려주고, 범인들은 그 간선을 무조건 지나간다.
 * 목적지의 후보에서 찾으면된다.
 * 
 * TODO:
 * 범인들이 주어진 간선을 지나고 최단 거리로 갈 수 있는 목적지를
 * 오름차순으로 출력한다.
 * 
 * FIXME:
 * 알고리즘 : 다익스트라(Dijkstra)
 * 
 * 1. 시작점에서 각 지점들에 대한 최단 거리를 계산한다.
 * 
 * 2. must_a, must_b를 잇는 간선을 지나는 조건으로
 * 최단 거리를 계산하고
 * 이 중 해당 하는 것을 선택한다.
 * 
 * 3. 이 간선을 지나지 않고 최단거리로 갈 수 있다면, 
 * 그 목적지는 제외한다.
 * **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 987654321;

vector<vector<pair<int, int>>> nodes;
int T;       // number of test cases.
int n, m, t; // each number of cross, road, targets.
int s, g, h; // start position, g and h are must path route.
int a, b, d; // u, v, cost.
int must_path_cost;
vector<int> targets;

vector<int> dijkstra(int start, int end)
{
    vector<int> ret(n + 1, INF);
    ret[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int current_cost = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        for (int i = 0; i < nodes[current_node].size(); i++)
        {
            int next_cost = nodes[current_node][i].first + current_cost;
            int next_node = nodes[current_node][i].second;

            if (next_cost < ret[next_node])
            {
                ret[next_node] = next_cost;
                pq.push({next_cost, next_node});
            }
        }
    }
    return ret;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        nodes.clear();
        targets.clear();
        scanf("%d %d %d", &n, &m, &t);
        scanf("%d %d %d", &s, &g, &h);

        nodes.resize(n + 1);
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &a, &b, &d);
            nodes[a].push_back({d, b});
            nodes[b].push_back({d, a});
        }

        for (int i = 0; i < t; i++)
        {
            int temp;
            scanf("%d", &temp);
            targets.push_back(temp);
        }

        vector<int> start_to_end = dijkstra(s, n);
        vector<int> g_to_end = dijkstra(g, n);
        vector<int> h_to_end = dijkstra(h, n);
        // s -> g -> h -> t
        // s -> h -> g -> t

        sort(targets.begin(), targets.end());
        for (int i = 0; i < t; i++)
        {
            int target = targets[i];
            int ret =
                min(start_to_end[g] + g_to_end[h] + h_to_end[target],
                    start_to_end[h] + h_to_end[g] + g_to_end[target]);
            if (ret < 0 || ret >= INF || ret > start_to_end[target])
                continue;
            printf("%d ", target);
        }
        printf("\n");
    }
    return 0;
}