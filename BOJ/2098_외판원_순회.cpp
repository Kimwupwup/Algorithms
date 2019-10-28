#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

const int INF = 987654321;
const int MAX = 16;

int n;
int cache[MAX][1 << MAX];
int matrix[MAX][MAX];

int TSP(int current, int visited)
{
    if (visited == (1 << n) - 1)
    {
        if (matrix[current][0] != 0)
            return matrix[current][0];
        return INF;
    }
    int &result = cache[current][visited];
    if (result != -1)
        return result;

    result = INF;
    for (int next = 0; next < n; next++)
    {
        if (visited & (1 << next) || matrix[current][next] == 0)
            continue;
        int candidate = matrix[current][next] + TSP(next, visited + (1 << next));
        result = min(result, candidate);
    }
    return result;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    memset(cache, -1, sizeof(cache));
    cout << TSP(0, 1) << endl;
    return 0;
}