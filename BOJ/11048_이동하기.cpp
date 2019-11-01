#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1001;

int n, m;
int matrix[MAX][MAX];
int cache[MAX][MAX];

int solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cache[i][j] = max({cache[i - 1][j], cache[i][j - 1], cache[i - 1][j - 1]}) + matrix[i][j];
        }
    }
    return cache[n][m];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> matrix[i][j];

    cout << solution() << endl;
    return 0;
}