/**
 * 백준 13913번 - 숨바꼭질 4
 * 
 * TODO:
 * DP
 * */
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 1e5 + 1;
const int INF = 987654321;

int dp[MAX];
int N, K;
int parent[MAX];
vector<int> ret;

int BFS() {
    queue<pair<int, int>> q;
    q.push({N, 0});
    dp[N] = 0;

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == K) {
            int idx = cur;
            while (idx != N) {
                ret.push_back(idx);
                idx = parent[idx];
            }
            ret.push_back(N);
            return cnt;
        }

        if (cur + 1 < MAX) {
            if (dp[cur + 1] > cnt + 1) {
                q.push({cur + 1, cnt + 1});
                dp[cur + 1] = cnt + 1;
                parent[cur + 1] = cur;
            }            
        }
        if (cur - 1 >= 0) {
            if (dp[cur - 1] > cnt + 1) {
                q.push({cur - 1, cnt + 1});
                dp[cur - 1] = cnt + 1;
                parent[cur - 1] = cur;
            }
        }
        if (cur * 2 < MAX) {
            if (dp[cur * 2] > cnt + 1) {
                q.push({cur * 2,  cnt + 1});
                dp[cur * 2] = cnt + 1;
                parent[cur * 2] = cur;
            }
        }
    }
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    fill_n(dp, MAX, INF);
    cout << BFS() << "\n";
    for (int i = ret.size() - 1; i >= 0; i--) {
        cout << ret[i] << " ";
    }
    return 0;
}