/**
 * 백준 1005번 - ACM Craft
 * 
 * TODO:
 * 위상 정렬
 * */
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1001;

struct cmp {
    bool operator() (pair<int, int> &a, pair<int, int> &b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> ret(N + 1, 0), time(N + 1, 0), degree(N + 1, 0);
        vector<int> matrix[N + 1];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        for (int i = 1; i <= N; i++)
            cin >> time[i];

        for (int i = 0; i < K; i++) {
            int u, v;
            cin >> u >> v;
            matrix[u].push_back(v);
            degree[v]++;
        }
        
        for (int i = 1; i <= N; i++) {
            if (degree[i] == 0) {
                q.push({i, time[i]});
                ret[i] = time[i];
            }
                
        }

        while (!q.empty()) {
            int cur = q.top().first;
            int cost = q.top().second;
            q.pop();

            for (int i = 0; i < matrix[cur].size(); i++) {
                int next = matrix[cur][i];
                int next_cost = time[next] + cost;
                degree[next]--;

                ret[next] = max(ret[next], next_cost);

                if (degree[next] == 0)
                    q.push({next, ret[next]});
            }
        }
        int W;
        cin >> W;
        cout << ret[W] << "\n";
    }

    return 0;
}