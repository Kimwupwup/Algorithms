/**
 * 백준 1939번 - 중량제한
 * 
 * TODO:
 * BFS, Binary search
 * Binary search로 값을 찾고, 그 값을 BFS로 목적지까지 갈 수 있는지 확인
 * */
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
int n, m;
int start, target;
int costMax = 0;
vector<vector<pair<int, int>>> v;
bool visited[10001];

bool BFS(int cost) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == target) {
            return true;
        }

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int next_cost = v[cur][i].second;
            if (!visited[next] && next_cost >= cost) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
        costMax = max(costMax, c);
    }
    cin >> start >> target;
    int left = 0;
    int right = costMax;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        memset(visited, false, sizeof(visited));
        if (BFS(mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << right << "\n";
    return 0;
}