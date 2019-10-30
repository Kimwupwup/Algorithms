#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
const int MAX = 31;
int t, n, m;
int cache[MAX][MAX];

void solution()
{
    for (int i = 1; i <= 30; i++)
        cache[1][i] = i;
    for (int i = 2; i <= 30; i++)
        for (int j = i; j <= 30; j++)
            for (int k = j; k >= i; k--)
                cache[i][j] += cache[i - 1][k - 1];
}

int main()
{
    cin >> t;
    solution();
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        cout << cache[n][m] << endl;
    }

    return 0;
}