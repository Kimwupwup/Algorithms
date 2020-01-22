/**
 * http://codeforces.com/contest/1294/problem/F
 * Codeforces Round #615 Div.3 (20200122)
 * F. Three Paths on a Tree
 * */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<pair<int, int>> ret_v; 
set<pair<int, int>> visited;
int further;
int ret = 0;

void BFS(int node) {
    visited.clear();
    queue<int> q;
    q.push(node);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        further = current;
        for (int i = 0; i < v[current].size(); i++) {
            int f = current;
            int s = v[current][i];
            if (f > s) {
                int temp = f;
                f = s;
                s = temp;
            }
            if (visited.find({f, s}) == visited.end()) {
                q.push(f == current ? s : f);
                visited.insert({f, s});
            }
        }
    }
}

void DFS(int node, int cnt) {
    if (ret < cnt) {
        ret = cnt;
        further = node;
        v.clear();
        
    }        
    
    for (int i = 0; i < v[node].size(); i++) {
        int f = node;
        int s = v[node][i];

        if (f > s) {
            int temp = f;
            f = s;
            s = temp;
        }
        if (visited.find({f, s}) == visited.end()) {
            visited.insert({f, s});
            DFS(v[node][i], cnt + 1);
            visited.erase({f, s});
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    v.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    BFS(2);
    cout << further << "\n";

    visited.clear();
    DFS(further, 0);
    cout << further << " : " << ret << "\n";

    return 0;
}