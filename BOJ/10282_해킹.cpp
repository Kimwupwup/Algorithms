/**
 * 백준 10282번 - 해킹
 * 
 * TODO:
 * BFS, 다익스트라
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 10001;
const int INF = 987654321;

vector<pair<int, int>> graph[MAX];

vector<int> dijkstra(int start, int size) {
    vector<int> ret(size, INF);
    ret[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int next_cost = cost + graph[cur][i].second;
            
            if (ret[next] <= next_cost) 
                continue;
            
            ret[next] = next_cost;
            pq.push({next_cost, next});
        }
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n, m, start;
        cin >> n >> m >> start;

        for (int i = 1; i <= n; i++)
            graph[i].clear();

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[v].push_back({u, w});
        }

        vector<int> ret = dijkstra(start, n + 1);

        int cnt = 0, maxi = 0;
        for (int i = 1; i < ret.size(); i++) {
            if (ret[i] != INF)
                cnt++;
            if (maxi < ret[i] && ret[i] != INF)
                maxi = ret[i];
        }
        cout << cnt << " " << maxi << "\n";
    }

    return 0;
}