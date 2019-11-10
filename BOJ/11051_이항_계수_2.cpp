#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;
const int MAX = 1001;
int n, k;
int cache[MAX][MAX];

int solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (i == j || j == 0)
            {
                cache[i][j] = 1;
                continue;
            }
            cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j]) % 10007;
        }
    }
    return cache[n][k];
}

int main()
{
    cin >> n >> k;
    cout << solution() << endl;
    return 0;
}