/**
 * 백준 2252번 - 줄 세우기
 * 
 * TODO:
 * queue, 위상 정렬(topological sort)
 * 위상 정렬: 진입 차수를 사용하여 0 일 때만 처리한다.x
 * */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 32001;

int N, M;
int degree[MAX];
vector<int> matrix[MAX];
queue<int> q;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        matrix[u].push_back(v);
        degree[v]++;
    }

    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        cout << cur << " ";
        for (int i = 0 ; i < matrix[cur].size(); i++) {
            degree[matrix[cur][i]]--;
            if (degree[matrix[cur][i]] == 0)
                q.push(matrix[cur][i]);
        }
    }

    return 0;
}