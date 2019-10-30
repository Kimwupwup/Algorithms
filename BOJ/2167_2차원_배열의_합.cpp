#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 301;
int n, m, k;
int matrix[MAX][MAX];
int cache[MAX][MAX];
int a, b, x, y;

void solution()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cache[i][j] = cache[i - 1][j] + cache[i][j - 1] + matrix[i][j] - cache[i - 1][j - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> matrix[i][j];
    solution();
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> b >> a >> y >> x;
        cout << cache[y][x] - cache[y][a - 1] - cache[b - 1][x] + cache[b - 1][a - 1] << endl;
    }
    return 0;
}