/**
 * 백준 11725번 - 트리의 부모 찾기
 * 트리 문제
 * */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int visited[100001];
int matrix[100001];
vector<vector<int>> v;

int main () {
    cin.tie (NULL);
    ios::sync_with_stdio (false);
    memset (visited, 0, sizeof(visited));

    int N;
    cin >> N;
    v.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back (b);
        v[b].push_back (a);
    }

    queue<int> q;
    q.push (1);
    visited[1] = 1;

    while (!q.empty ()) {
        int cur = q.front ();
        q.pop ();

        for (int i = 0; i < v[cur].size (); i++) {
            int next = v[cur][i];

            if (visited[next] == 0) {
                visited[next] = cur;
                q.push (next);
            }
        }
    }

    for (int i = 2; i <= N; i++)
        cout << visited[i] << "\n";
    return 0;
}