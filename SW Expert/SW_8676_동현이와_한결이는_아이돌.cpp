/**
 * SW Expert 8676번 - 동현이와 한결이는 아이돌
 * 
 * */
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int dp[7];
const int MAX = 1000000007;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        string str;
        cin >> str;

        memset(dp, 0, sizeof(dp));

        for (int i = 0 ; i < str.size(); i++) {
            if (str[i] == 'S') {
                dp[0] = (dp[0] + 1) % MAX;
                dp[3] = (dp[3] + dp[2]) % MAX;
            } else if (str[i] == 'A') {
                dp[1] = (dp[0] + dp[1]) % MAX;
            } else if (str[i] == 'M') {
                dp[2] = (dp[1] + dp[2]) % MAX;
            } else if (str[i] == 'U') {
                dp[4] = (dp[3] + dp[4]) % MAX;
            } else if (str[i] == 'N') {
                dp[5] = (dp[4] + dp[5]) % MAX;
            } else if (str[i] == 'G') {
                dp[6] = (dp[5] + dp[6]) % MAX;
            }
        }
        cout << "#" << t << " " << dp[6] << "\n";
    }
    return 0;
}