/**
 * 백준 6118번 - 숨바꼭질
 * 
 * TODO:
 * 다익스트라
 * 1:N의 결과를 찾아야 하기때문.
 * */
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX = 20001;
vector<int> graph[MAX];

vector<pair<int, int>> djkstra(int start, int size) {
    vector<pair<int, int>> temp(size, {INF, 0});
    temp[1] = {0, 1};

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next_cost = cost + 1;
            int next = graph[cur][i];

            if (temp[next].first <= next_cost) continue;

            temp[next].first = next_cost;
            temp[next].second = next;
            pq.push({next_cost, next});
        }
    }
    sort(temp.begin(), temp.end(), greater<pair<int, int>>());
    vector<pair<int, int>> ret;
    for (pair<int, int> p : temp) {
        if (p.first == temp[1].first)
            ret.push_back(p);
    }

    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<pair<int, int>> ret = djkstra(1, n + 1);
    cout << ret[ret.size() - 1].second << " " << ret[ret.size() - 1].first << " " << ret.size() << "\n";
    return 0;
}