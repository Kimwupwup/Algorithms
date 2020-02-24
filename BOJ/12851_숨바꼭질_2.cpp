/**
 * 백준 12851번 - 숨바꼭질 2
 * 
 * TODO:
 * BFS
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;
const int INF = 987654321;

int counter[MAX];
int matrix[MAX];
int n, m;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    for (int i = 0; i < MAX; i++) 
        matrix[i] = INF;
    
    cin >> n >> m;
    queue<pair<int, int>> q;
    q.push({0, n});
    matrix[n] = 0;

    int mini = INF;
    while (!q.empty()) {
        int cnt = q.front().first;
        int cur = q.front().second;
        q.pop();

        if (cur == m) {
            mini = min(mini, cnt);
            counter[mini]++;                
            continue;
        }

        if (cur * 2 < MAX && matrix[cur * 2] >= cnt + 1) {
            q.push({cnt + 1, cur * 2});
            matrix[cur * 2] = cnt + 1;
        }
        if (cur + 1 < MAX && matrix[cur + 1] >= cnt + 1) {
            q.push({cnt + 1, cur + 1});
            matrix[cur + 1] = cnt + 1;
        }
        if (cur - 1 >= 0 && matrix[cur - 1] >= cnt + 1) {
            q.push({cnt + 1, cur - 1});
            matrix[cur - 1] = cnt + 1;
        }
    }

    cout << mini << "\n" << counter[mini] << "\n";
    return 0;
}