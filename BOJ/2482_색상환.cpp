/**
 * 백준 2482번 - 색상환
 * 
 * */

#include <iostream>

using namespace std;

const int MAX = 1001;
const int MOD = 1000000003;

int n, m;
int dp[MAX][MAX];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    cin >> m;

    for (int i = 1; i <= 3; i++)
        dp[i][1] = i;
    
    for (int i = 4; i <= n; i++) {
        int max_cho = i / 2;

        for (int cho = 1; cho <= max_cho; cho++) {
            if (cho == 1)
                dp[i][cho] = i;
            else {
                dp[i][cho] = (dp[i - 2][cho - 1] + dp[i - 1][cho]) % MOD;
            }
        }
    }
    
    cout << dp[n][m] << endl;
    return 0;
}