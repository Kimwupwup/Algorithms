/**
 * 백준 2211번 - 네트워크 복구
 * 
 * TODO:
 * 크루스칼(틀림) - 1번에서 각 노드들로의 최단거리가 모든 간선의 최소비용고는 다르다.
 * 다익스트라 알고리즘으로 접근하는 것이 맞는 답안이다.
 * */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX = 1001;
vector<pair<int, int>> graph[MAX];
int n, m;

vector<int> dijkstra(int start, int size) {
    vector<int> temp(size, INF);
    vector<int> ret(size);
    temp[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next_cost = cost + graph[cur][i].second;
            int next = graph[cur][i].first;
            if (next_cost >= temp[next]) 
                continue;
            
            ret[next] = cur;
            temp[next] = next_cost;
            pq.push({next_cost, next});
        }
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<int> ret = dijkstra(1, n + 1);
    cout << n - 1 << "\n";
    for (int i = 1; i <= n; i++)
        if (ret[i] != 0)
            cout << i << " " << ret[i] << "\n";

    return 0;
}