/**
 * 백준 1238번 - 파티
 * 
 * TODO:
 * 다익스트라
 * */
#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
const int MAX = 1001;

int n, m, x;
vector<pair<int, int>> graph[MAX];

vector<int> dijkstra(int start, int size) {
    vector<int> ret(size, INF);
    ret[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int next_cost = graph[cur][i].second + cost;

            if (ret[next] > next_cost) {
                ret[next] = next_cost;
                pq.push({next_cost, next});
            }
        }
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<int> go_home = dijkstra(x, n + 1);

    int ret = 0;
    for(int i = 1; i <= n; i++) {
        if (i == x) continue;
        vector<int> go_party = dijkstra(i, n + 1);
        ret = max(ret, go_party[x] + go_home[i]);
    }
    cout << ret << "\n";
    return 0;
}