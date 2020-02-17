/**
 * 백준 11438번 - LCA 2
 * 
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;
const int MAX_LEVEL = (int)floor(log2(MAX));
int n, m;
vector<int> matrix[MAX];
vector<int> depth;
vector<vector<int>> parent;
vector<int> ret;

int LCA(int a, int b) {
    if (depth[a] < depth[b])
        swap(a, b);
    
    if (depth[a] != depth[b]) {
        for (int i = MAX_LEVEL; i >= 0; i--) {
            if (depth[parent[a][i]] >= depth[b]) {
                a = parent[a][i];
            }
        }
    }

    if (a != b) {
        for (int i = MAX_LEVEL; i >= 0; i--) {
            if (parent[a][i] != parent[b][i] && parent[a][i] != 0) {
                a = parent[a][i];
                b = parent[b][i];
            }
        }
        return parent[a][0];
    }
    else {
        return a;
    }
}

void make_tree() {
    queue<int> q;
    depth[1] = 1;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < matrix[cur].size(); i++) {
            int next = matrix[cur][i];

            if (depth[next] != 0) continue;

            depth[next] = depth[cur] + 1;
            parent[next][0] = cur;
            q.push(next);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        matrix[u].push_back(v);
        matrix[v].push_back(u);
    }

    depth.resize(n + 1, 0);
    parent.resize(n + 1, vector<int>(MAX_LEVEL + 1, 0));

    make_tree();

    for (int i = 1; i <= MAX_LEVEL; i++) {
        for (int j = 1; j <= n; j++) {
            if (parent[j][i - 1] != 0)
                parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << "\n";
    }
    return 0;
}