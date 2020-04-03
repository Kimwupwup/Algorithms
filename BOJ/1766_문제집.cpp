/**
 * 백준 1766번 - 문제집
 * 
 * TODO:
 * 위상 정렬
 * */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 32001;

int N, M;
vector<int> matrix[MAX];
int degree[MAX];
priority_queue<int, vector<int>, greater<int>> q;

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
        int cur = q.top();
        q.pop();

        cout << cur << " ";

        for (int i = 0; i < matrix[cur].size(); i++) {
            int next = matrix[cur][i];
            degree[next]--;
            
            if (degree[next] == 0)
                q.push(next);
        }
    }

    return 0;
}