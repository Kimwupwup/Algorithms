#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int n, m, cnt = 0;
bool visited[101];
vector<vector<int>> matrix;
queue<int> q;

int main()
{
    memset(visited, false, sizeof(visited));
    scanf("%d", &n);
    scanf("%d", &m);
    matrix.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        matrix[u].push_back(v);
        matrix[v].push_back(u);
    }
    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int i = 0; i < matrix[current].size(); i++)
        {
            int next = matrix[current][i];
            if (visited[next])
                continue;

            q.push(next);
            visited[next] = true;
            cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}