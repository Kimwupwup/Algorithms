/**
 * 백준 13023번 - ABCDE
 * 
 * TODO:
 * DFS
 * */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 2000;
vector<int> matrix[MAX];
bool visited[MAX];
int ret = 0;
int N, M;

void DFS(int idx, int cnt) {
    if (cnt == 4) {
        ret = 1;
        return;
    }

    for (int i = 0; i < matrix[idx].size(); i++) {
        int next = matrix[idx][i];

        if (visited[next] == true) continue;
        
        visited[next] = true;
        DFS(next, cnt + 1);
        visited[next] = false;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        matrix[u].push_back(v);
        matrix[v].push_back(u);
    }

    for (int i = 0; i < N; i++) {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        DFS(i, 0);
        if (ret == 1) 
            break;
    }
    cout << ret << "\n";

    return 0;
}