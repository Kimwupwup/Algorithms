#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1001;

int matrix[MAX];
int dp[MAX];
int N;
int ret;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> matrix[i];

    for (int i = 0; i < N; i++) {
        dp[i] = matrix[i];

        for (int j = 0; j <= i; j++) {
            if (matrix[i] > matrix[j] && dp[i] < dp[j] + matrix[i]) {
                dp[i] = dp[j] + matrix[i];
            }
            ret = max(ret, dp[i]);
        }
    }
    cout << ret << "\n";
    return 0;
}