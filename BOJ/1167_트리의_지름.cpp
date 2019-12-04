/**
 * 백준 1167번 - 트리의 지름
 * 트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다.
 * 현재 정점, 연결된 정점1, 거리1, 연결된 정점n, 거리n, -1;
 * */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
vector<vector<pair<int, int>>> nodes;
vector<int> leaves;
bool visited[100001];
int futherest = 0;
long long ret = 0;
int n;

void BFS (int node) {
    queue<pair<int, int>> q;
    
    memset (visited, false, sizeof (visited));
    q.push ({node, 0});
    visited[node] = true;

    while (!q.empty ()) {
        int cur_node = q.front ().first;
        int cur_cost = q.front ().second;
        q.pop ();

        for (int i = 0; i < nodes[cur_node].size (); i++) {
            int next_node = nodes[cur_node][i].first;
            int next_cost = nodes[cur_node][i].second + cur_cost;

            if (!visited[next_node]) {
                if (ret < next_cost) {
                    ret = next_cost;
                    futherest = next_node;
                }
                    
                q.push ({next_node, next_cost});
                visited[next_node] = true;
            }
        }
    }
}

int main () {
    cin.tie (NULL);
    ios::sync_with_stdio (false);

    cin >> n;
    nodes.resize (n + 1);
    for (int i = 1; i <= n; i++) {
        int u, v, cost;
        cin >> u;
        while (true) {
            cin >> v;
            if (v == -1)
                break;
            cin >> cost;
            nodes[u].push_back ({v, cost});
        }
        if (nodes[u].size() == 1) {
            leaves.push_back (u);
        }
    }

    
    int node = leaves[0];
    BFS (node);
    BFS (futherest);

    cout << ret << "\n";
    return 0;
}