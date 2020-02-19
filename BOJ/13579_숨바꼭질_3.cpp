/**
 * 백준 13549번 - 숨바꼭질 3
 * 
 * TODO:
 * DP, 다익스트라
 * 단순 BFS 는 해당하지 않는다.
 * BFS 는 모든 간선에 비용이 똑같을 때 해당하며, 간선에 0 을 포함하고 있으므로
 * 최소 시간을 측정하기 어렵다.
 * 따라서 다익스트라 알고리즘으로 접근해야 문제를 풀 수 있다.
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;
const int INF = 987654321;

int dp[MAX];
int n, m;

int solve() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dp[n] = 0;
    q.push({0, n});

    while (!q.empty()) {
        int cur = q.top().second;
        int cnt = q.top().first;
        q.pop();

        if (cur == m)
            return cnt;

        if (cur * 2 < MAX) {
            if (dp[cur * 2] > cnt) {
                q.push({cnt, cur * 2});
                dp[cur * 2] = cnt;
            }
        }
        if (cur + 1 < MAX) {
            if (dp[cur + 1] > cnt + 1) {
                q.push({cnt + 1, cur + 1});
                dp[cur + 1] = cnt + 1;
            }            
        }
        if (cur - 1 >= 0) {
            if (dp[cur - 1] > cnt + 1) {
                q.push({cnt + 1, cur - 1});
                dp[cur - 1] = cnt + 1;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < MAX; i++) {
        dp[i] = MAX;
    }
    
    cout << solve();

    return 0;
}