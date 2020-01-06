/**
 * 백준 1939번 - 중량제한
 * 
 * */
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
int n, m;
int start, target;
vector<vector<pair<int, int>>> v;
queue<pair<int, int>> q;
bool visited[10001];

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
    }
    cin >> start >> target;
    
    q.push(make_pair(start, 0));
    visited[start] = true;

    int ret = 0;
    while (!q.empty()) {
        int cur = q.front().first;
        int cost = q.front().second;
        q.pop();

        if (cur == target) {
            ret = max(ret, cur);
        }        
        
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int next_cost = v[cur][i].second;
            if (!visited[next] || (visited[next] && next_cost > cost)) {
                visited[next] = true;
                q.push(make_pair(next, next_cost));
            }
        }
    }
    
    cout << ret << "\n";

    return 0;
}