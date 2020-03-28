/**
 * 백준 1865번 - 웜홀
 * 
 * 
 **/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 987654321;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n, m, w;
        vector<pair<int, int>> adj[501];

        cin >> n >> m >> w;
        
        for (int i = 0; i < m; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }

        for (int i = 0; i < w; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            adj[u].push_back({v, -c});
        }

        vector<int> ret(n + 1, INF);
        bool good = false;
        ret[1] = 0;

        for (int i = 1; i <= n; i++) {
            good = false;
            for (int j = 1; j <= n; j++) {
                for (pair<int, int> p : adj[j]) {
                    int v = p.first;
                    int cost = p.second;

                    if (ret[v] > ret[j] + cost) {
                        ret[v] = ret[j] + cost;
                        good = true;
                    }
                }
            }
        }
        if (good) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}