/**
 * 백준 10217번 - KCM travel
 * 방향성 그래프
 * 비용을 넘지않게 목적지에 도달하여야 한다.
 * 음수는 없다.
 * 
 * 비용을 넘지 않으면서 시간도 가장 짧아야 한다.
 * 단순 다익스트라 알고리즘으로 접근하면 메모리 초과가 일어난다. 혹은 시간초과
 * DP를 통해 시간을 저장하고
 * 비용을 통한 최단 시간을 활용하는 것이 문제의 중요 포인트이다.
 * **/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
    int v;
    int cost;
    int time;

    bool operator< (const node &p) const {
        if (this->time == p.time)
            return this->cost > p.cost;
        return this->time > p.time;
    }
};
const int INF = 987654321;

int dp[101][10001];
vector<node> nodes[101];
priority_queue<node> q;


int dijkstra(int n, int money) {
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= money; j++)
            dp[i][j] = INF;
    
    while (!q.empty())
        q.pop();
    q.push({1, 0, 0});
    dp[1][0] = 0;

    while (!q.empty()) {
        node current = q.top();
        q.pop();

        int v = current.v;
        int cost = current.cost;
        int time = current.time;
        if (v == n) break;

        if (dp[v][cost] < time) continue;
        dp[v][cost] = time;

        for (int i = 0; i < nodes[v].size(); i++) {
            node& next = nodes[v][i];

            if (cost + next.cost > money) continue;
            if (dp[next.v][cost + next.cost] <= time + next.time) continue;

            q.push({next.v, cost + next.cost, time + next.time});
            dp[next.v][cost + next.cost] = time + next.time;
        }
    }
    int ret = INF;
    for (int i = 0; i <= money; i++)
        ret = min(ret, dp[n][i]);
    return ret;
}

int main () {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i <= n; i++) nodes[i].clear();

        while (k--) {
            int u, v, cost, time;
            cin >> u >> v >> cost >> time;
            nodes[u].push_back({v, cost, time});
        }

        int ret = dijkstra(n, m);
        if (ret < INF) cout << ret << "\n";
        else cout << "Poor KCM\n";
    }
    
    return 0;
}