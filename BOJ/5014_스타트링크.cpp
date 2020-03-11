/**
 * 백준 5014번 - 스타트링크
 * 
 * TODO:
 * 완전탐색, BFS, 다익스트라
 * */
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1000001;
const int INF = 987654321;

int matrix[MAX];
int f, s, g, u, d;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> f >> s >> g >> u >> d;
    for (int i = 1; i <= f; i++)
        matrix[i] = INF;
    
    matrix[s] = 0;
    queue<pair<int, int>> q;
    q.push({s, 0});

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur + u <= f && matrix[cur + u] > cnt + 1) {
            matrix[cur + u] = cnt + 1;
            q.push({cur + u, cnt + 1});
        }
        if (cur - d >= 1 && matrix[cur - d] > cnt + 1) {
            matrix[cur - d] = cnt + 1;
            q.push({cur - d, cnt + 1});
        }        
    }
    if (matrix[g] == INF)
        cout << "use the stairs\n";
    else 
        cout << matrix[g] << "\n";
    return 0;
}