#include <iostream>
#include <algorithm>
#include <memory.h>
#include <limits.h>

using namespace std;
int t, n;
int cache[501][501];
int sum[501];
int matrix[501];

int main()
{

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        memset(cache, 0, sizeof(cache));
        memset(sum, 0, sizeof(sum));

        scanf("%d", &n);
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &matrix[j]);
            sum[j] = sum[j - 1] + matrix[j];
        }

        for (int j = 1; j < n; j++)
        {
            for (int start = 1; start + j <= n; start++)
            {
                int end = start + j;
                cache[start][end] = INT_MAX;

                for (int mid = start; mid < end; mid++)
                {
                    cache[start][end] = min(cache[start][end], cache[start][mid] + cache[mid + 1][end] + sum[end] - sum[start - 1]);
                }
            }
        }
        printf("%d\n", cache[1][n]);
    }
    return 0;
}