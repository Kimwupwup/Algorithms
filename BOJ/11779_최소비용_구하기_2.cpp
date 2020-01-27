    /**
     * 백준 11779번 - 최소비용 구하기 2
     * 
     * */
    #include <bits/stdc++.h>

    using namespace std;

    const int MAX = 1001;
    const int INF = 987654321;

    int n, m;
    int trace[MAX];
    vector<pair<int, int>> graph[MAX];

    vector<int> dijkstra(int start, int vertex) {
        vector<int> distance(vertex, INF);
        distance[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int cost = pq.top().first;
            int cur = pq.top().second;
            pq.pop();

            if (distance[cur] < cost)
                continue;
            
            for (int i = 0; i < graph[cur].size(); i++) {
                int next = graph[cur][i].first;
                int next_cost = graph[cur][i].second + cost;

                if (distance[next] > next_cost) {
                    distance[next] = next_cost;
                    trace[next] = cur;
                    pq.push({next_cost, next});
                }
            }
        }
        return distance;
    }

    int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);

        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
        }
        
        int start, finish;
        cin >> start >> finish;

        vector<int> ret = dijkstra(start, n + 1);
        cout << ret[finish] << "\n";

        vector<int> route;
        int node = finish;

        while (node) {
            route.push_back(node);
            node = trace[node];
        }
        cout << route.size() << "\n";
        for (int i = route.size() - 1; i >= 0; i--) {
            cout << route[i] << " ";
        }

        return 0;
    }