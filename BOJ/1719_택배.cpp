/**
 * 백준 1719번 - 택배
 * 
 * TODO:
 * 다익스트라
 * 모든 노드 다익스트라 실행
 * 기존의 다익스트라 알고리즘에 추가로 경로를 파악할 수 있어야 한다.
 * 
 * if (cur == start) ret[next] = next;
 * else ret[next] = ret[cur];
 * 
 * 처음 시작 노드라면, 다음 노드가 루트 노드가 된다.
 * 만약 그렇지 않다면, 다음 노드의 루트는 현 노드의 루트와 동일하다.
 * union find와 비슷한 형태(부모 찾기)
 * */
#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
const int MAX = 201;
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
            int next = graph[cur][i].first;
            int next_cost = cost + graph[cur][i].second;

            if (temp[next] <= next_cost) continue;
            if (cur == start)
                ret[next] = next;
            else 
                ret[next] = ret[cur];
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

    for (int i = 1; i <= n; i++) {
        vector<int> ret = dijkstra(i, n + 1);
        for (int j = 1; j <= n; j++) {
            if (ret[j] == 0)
                cout << "- ";
            else 
                cout << ret[j] << " ";
        }
        cout << "\n";
    }

    return 0;
}