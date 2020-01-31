/**
 * 백준 10473번 - 인간 대포
 * 
 * TODO:
 * 다익스트라
 * 각 좌표와 속도를 알고 있으므로, 시간을 구할 수 있습니다.
 * 출발 지점, 도착 지점, 각 대포로 이동하는 시간들을 모두 구해 그래프를 형성하고
 * 다익스트라 알고리즘을 통해 답을 구할 수 있습니다.
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 102;
const double V = 5.0;
const double INF = 978654321.0;

vector<pair<int, double>> graph[MAX];
pair<double, double> pos[MAX];
pair<double, double> start, finish;

int n;

double distance(pair<double, double> a, pair<double, double> b) {
    return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}

double dijkstra(int start, int size) {
    vector<double> ret(size, INF);
    ret[start] = 0.0;

    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0.0, start});

    while (!pq.empty()) {
        double cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            double next_cost = cost + graph[cur][i].second;

            if (next_cost >= ret[next]) continue;

            ret[next] = next_cost;
            pq.push({next_cost, next});
        }
    }

    return ret[size - 1];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);   

    cin >> start.first >> start.second >> finish.first >> finish.second;
    cin >> n;

    for (int i = 1; i <= n; i++) 
        cin >> pos[i].first >> pos[i].second;
    
    // 시작 지점에서 각 대포로의 그래프 형성
    for (int i = 1; i <= n; i++) {
        graph[0].push_back({i, distance(start, pos[i]) / V});
    }

    // 시작 지점에서 도착 지점으로의 그래프 형성
    graph[0].push_back({n + 1, distance(start, finish) / V});

    // 각 대포에서 끝점으로의 그래프 형성
    for (int i = 1; i <= n; i++) {
        // 달려갔을 때
        graph[i].push_back({n + 1, distance(pos[i], finish) / V});
        // 대포를 사용했을 때
        graph[i].push_back({n + 1, 2.0 + abs(distance(pos[i], finish) - 50.0) / V});
    }

    // 각 대포끼리의 그래프 형성
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                graph[i].push_back({j, distance(pos[i], pos[j]) / V});
                graph[i].push_back({j, 2.0 + abs(distance(pos[i], pos[j]) - 50.0) / V});
            }
        }
    }
    cout << dijkstra(0, n + 2) << "\n";
    return 0;
}