/**
 * 백준 17471번 - 게리맨더링
 * 
 * TODO:
 * 완전 탐색, DFS, BFS
 * DFS 로 모든 조합을 구합니다. (2 개의 부분을 1, 0 으로 분리하여 표시)
 * BFS 를 두번 실행하여 2 개의 부분을 탐색합니다. (2 개의 부분이 존재)
 * 1 로 표시한 부분을 탐색하고, 그 후 0 으로 표시한 부분을 탐색합니다.
 * 
 * 주의) 자신의 부분에 해당하는 곳을 방문을 했었는지 확인해야 합니다.
 * 방문을 하지 않았다면, -1 을 반환하여 그 결과는 포함하지 않습니다.
 * */
#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
const int MAX = 11;
int matrix[MAX];
vector<int> graph[MAX];
vector<vector<int>> temp_set;
bool visited[MAX];
int n;

int BFS(vector<int> v, int type) {
    queue<int> q;
    int start = 0;
    int ret = 0;

    for (int i = 1; i <= n; i++) {
        if (v[i] == type) {
            start = i;
            break;
        }
    }

    if (start == 0) return -1;

    q.push(start);
    visited[start] = true;
    ret += matrix[start];

    while (!q.empty()) {
        int idx = q.front();
        q.pop();

        for (int i = 0; i < graph[idx].size(); i++) {
            int next = graph[idx][i];

            if (visited[next] || v[next] != type) continue;

            q.push(next);
            visited[next] = true;
            ret += matrix[next];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && v[i] == type) {
            return -1;
        }
    }
    return ret;
}

void DFS(int idx, vector<int> v) {
    for (int i = idx; i <= n; i++) {
        v[i] = 1;
        temp_set.push_back(v);
        DFS(i + 1, v);
        v[i] = 0;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> matrix[i];
    }

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int temp;
            cin >> temp;
            graph[i].push_back(temp);
        }
    }
    
    DFS(1, vector<int>(n + 1));

    int mini = INF;
    for (int i = 0; i < temp_set.size(); i++) {

        memset(visited, false, sizeof(visited));
        
        int a = BFS(temp_set[i], 1);
        int b = BFS(temp_set[i], 0);

        if (a == -1 || b == -1) continue;

        mini = min(mini, abs(a - b));
    }

    if (mini == INF)
        cout << -1 << "\n";
    else 
        cout << mini << "\n";
}