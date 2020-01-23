/**
 * http://codeforces.com/contest/1294/problem/F
 * Codeforces Round #615 Div.3 (20200122)
 * F. Three Paths on a Tree
 * */
#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 1;
int visited[MAX];
int ret_vertex[3];
int temp_vertex;
int main_cnt = 0, sub_cnt = 0;
vector<vector<int>> matrix;
int n;

void DFS(int cur, int cnt, int prev) {
    if (main_cnt <= cnt) {
        main_cnt = cnt;
        temp_vertex = cur;
    }

    for (int a : matrix[cur]) {
        if (a == prev) continue;
        DFS(a, cnt + 1, cur);
    }
}

void search(int cur, int cnt, int prev) {
    visited[cur] = cnt;
    for (int a : matrix[cur]) {
        if (a == prev) continue;
        search(a, cnt + 1, cur);
    }
}

void search2(int cur, int cnt, int prev) {
    if (sub_cnt < cnt) {
        sub_cnt = cnt;
        temp_vertex = cur;
    }

    for (int a : matrix[cur]) {
        if (a == prev) continue;
        if (visited[cur] > visited[a]) search2(a, 0, cur);
        else search2(a, cnt + 1, cur);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    matrix.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        matrix[u].push_back(v);
        matrix[v].push_back(u);
    }

    DFS(1, 0, -1);
    ret_vertex[0] = temp_vertex;

    DFS(temp_vertex, 0, -1);
    ret_vertex[1] = temp_vertex;

    search(ret_vertex[0], 0, -1);
    search2(ret_vertex[1], 0, -1);
    ret_vertex[2] = temp_vertex;
    
    cout << (main_cnt + sub_cnt) << "\n";
    if (temp_vertex == ret_vertex[0]) {
        for (int i = 1; i <= n; i++) {
            if (ret_vertex[0] != i && ret_vertex[1] != i) {
                ret_vertex[2] = i;
                break;
            }
        }
    }
    for (int a : ret_vertex) {
        cout << a << " ";
    }
    cout << "\n";
    return 0;
}