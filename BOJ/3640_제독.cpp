/**
 * 백준 3640번 - 제독
 * 
 * TODO:
 * 다익스트라, EOF, 방문, 엣지 확인
 * */
#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
const int MAX = 1001;
vector<pair<int, int>> graph[MAX];
int trace[MAX];
bool visited[MAX];
int n, m;

int dijkstra(int start, int size) {
    vector<int> temp(size, INF);
    temp[start] = 0;
    trace[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int next_cost = cost + graph[cur][i].second;

            if (next_cost >= temp[next] || visited[next])
                continue;
            temp[next] = next_cost;
            trace[next] = cur;
            pq.push({next_cost, next});
        }
    }
    int idx = n;
    while (trace[idx]) {
        if (idx == n) continue;
        visited[idx] = true;
        idx = trace[idx];
    }
    return temp[n];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while (!cin.eof()) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            graph[i].clear();
        
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
        }
        int a = dijkstra(1, n + 1);
        int b = dijkstra(1, n + 1);
        cout << a + b << "\n";
        memset(visited, false, sizeof(visited));
    }
    return 0;
}