/**
 * 백준 1865번 - 웜홀
 * 방향성 없음
 * 웜홀은 방향성이 있다.
 * 웜홀은 시간이 거꾸로 간다.(음수 간선 존재)
 * Bellman-ford
 * M, W 에 대해서 모두 실행하고
 * 마지막에 확인할 때, 변화가 있으면 음수 루프가 존재한다는 의미이다.
 **/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<pair<int, int>, int>> nodes;
int t;
int n, m, w;
int u, v, cost;
const int INF = 30000000;

bool bellman(int start)
{
    vector<int> ret(n + 1, INF);
    ret[start] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < nodes.size(); j++)
        {
            int u = nodes[j].first.first;
            int v = nodes[j].first.second;
            int cost = nodes[j].second;

            if (ret[u] != INF && ret[u] + cost < ret[v])
                ret[v] = ret[u] + cost;
        }
    }

    for (int i = 0; i < nodes.size(); i++)
    {
        int u = nodes[i].first.first;
        int v = nodes[i].first.second;
        int cost = nodes[i].second;

        if (ret[u] != INF && ret[u] + cost < ret[v])
            return true;
    }
    return false;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--)
    {
        nodes.clear();
        cin >> n >> m >> w;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> cost;
            nodes.push_back({{u, v}, cost});
            nodes.push_back({{v, u}, cost});
        }

        for (int i = 0; i < w; i++)
        {
            cin >> u >> v >> cost;
            nodes.push_back({{u, v}, cost * -1});
        }

        if (bellman(1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}