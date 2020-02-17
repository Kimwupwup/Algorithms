/**
 * 백준 1867번 - 돌멩이 제거
 * 
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 501;
int n, k;

vector<int> a_match, b_match;
vector<int> graph[MAX];
vector<int> visited;

bool DFS(int a) {
    if (visited[a] == 1)
        return false;
    
    visited[a] = 1;

    for (int i = 0; i < graph[a].size(); i++) {
        int b = graph[a][i];

        if (b_match[b] == -1 || DFS(b_match[b])) {
            b_match[b] = a;
            a_match[a] = b;

            return true;
        }
    }
    return false;
}

int bipartite_matching() {
    a_match = vector<int>(n + 1, -1);
    b_match = vector<int>(n + 1, -1);

    int ret = 0;
    for (int a = 1; a <= n; a++) {
        visited = vector<int>(n + 1, 0);
        ret += DFS(a);
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    cout << bipartite_matching() << "\n";
    return 0;
}