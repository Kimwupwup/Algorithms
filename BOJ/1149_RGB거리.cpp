/**
 * 백준 1149번 - RGB 거리 문제
 * 
 * TODO:
 * DP
 * 
 * 직선구조로 되어있기 때문에, dp[0][j]를 첫 집의 각색의 비용을 넣고 시작하면 된다.
 * dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + matrix[i][0];
 * (dp[i][0]는 0 색을 칠할 때 i 까지의 최소 비용이므로, 
 * i - 1 까지의 1, 2 색(이웃끼리 겹치면 안된다.)의 최솟값에 
 * i 집의 0 색의 비용을 더해주면 된다.)
 * 4. 이를 0, 1, 2 색을 실행한다.
 * 
 * 백준 17404번 - RGB 거리 2 유사문제
 * */
#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001][3];
int cost[1001][3];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }
    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << endl;
    return 0;
}