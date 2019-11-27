#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int N, y, x;
int dp[501][501];
vector<pair<int, int>> v;

int main()
{
    scanf("%d", &N);
    v.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d %d", &y, &x);
        v[i] = {y, x};
    }

    for (int i = 1; i < N; i++)
    {
        for (int start = 1; start + i <= N; start++)
        {
            int end = start + i;
            dp[start][end] = INT_MAX;

            for (int mid = start; mid < end; mid++)
            {
                dp[start][end] = min(dp[start][end], v[start].first * v[mid].second * v[end].second + dp[start][mid] + dp[mid + 1][end]);
            }
        }
    }
    printf("%d", dp[1][N]);
    return 0;
}