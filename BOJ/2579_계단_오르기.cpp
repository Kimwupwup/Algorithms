#include <iostream>
#include <algorithm>
using namespace std;
int stair[301];
int dp[301];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> stair[i];

    for (int i = 1; i <= 3 && i <= n; i++)
        if (i != 3)
            dp[i] = dp[i - 1] + stair[i];
        else
            dp[i] = max(stair[i] + dp[i - 2], stair[i] + stair[i - 1]);

    for (int i = 4; i <= n; i++)
        dp[i] = max(stair[i] + dp[i - 2], stair[i] + stair[i - 1] + dp[i - 3]);

    cout << dp[n] << endl;
    return 0;
}