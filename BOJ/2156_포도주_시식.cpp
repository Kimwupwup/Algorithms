#include <iostream>
#include <algorithm>
using namespace std;
int n;
int dp[10001];
int matrix[10001];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> matrix[i];

    for (int i = 1; i < 3 && i <= n; i++)
        if (i == 1)
            dp[i] = matrix[i];
        else
            dp[i] = matrix[i] + matrix[i - 1];
    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 3] + matrix[i - 1] + matrix[i], dp[i - 2] + matrix[i]);
        dp[i] = max(dp[i - 1], dp[i]);
    }
    cout << dp[n] << endl;
}