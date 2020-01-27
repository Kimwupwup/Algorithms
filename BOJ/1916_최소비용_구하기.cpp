/**
 * 백준 1916번 - 최소비용 구하기
 * 
 * TODO:
 * 다익스트라
 * */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 987654321;
const int MAX = 1001;
vector<pair<int, int>> graph[MAX];
int n, m;

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
            int next_cost = cost + graph[cur][i].second;

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

    return 0;
}