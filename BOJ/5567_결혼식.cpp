/**
 * 백준 5567번 - 결혼식
 * 
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 501;
int n, m;
vector<int> v[MAX];
bool visited[MAX];
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    queue<pair<int, int>> q;
    visited[1] = true;
    q.push({1, 0});

    int ret = 0;
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            
            if (visited[next]) continue;
            visited[next] = true;
            q.push({next, cnt + 1});
            if (cnt < 2)
                ret++;
        }
    }
    cout << ret << "\n";
    return 0;
}