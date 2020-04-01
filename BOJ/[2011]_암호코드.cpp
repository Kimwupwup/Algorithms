/**
 * 백준 2011번 - 암호코드
 * 
 * TODO:
 * DP
 * 
 * dp[i] 는 i 번 째 자리까지 고려했을 때, 나오는 경우의 수
 * 만약 25114 가 있다면, 
 * dp[1] = 1 : {2}
 * dp[2] = dp[1] + dp[0] = 2 : {2, 5}, {25}
 * dp[3] = dp[2] = 2 : {2, 5, 1}, {25, 1}
 * dp[4] = dp[3] + dp[2] = 4 
 *  : 이전 경우의 수에 한 자리 추가한 경우 {2, 5, 1, 1}, {25, 1, 1}
 *    이전전 경우의 수에 한 자리 추가한 경우 {2, 5, 11}, {25, 11}
 * ...
 * */
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int MAX = 5001;
const int MOD = 1000000;

int dp[MAX];

int ctoi(char c) {
    return c - '0';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string str;

    cin >> str;
    if (ctoi(str[0]) == 0) {
        cout << 0 << "\n";
        return 0;
    }
    dp[0] = dp[1] = 1;

    // 실제 string 의 위치는 한칸 앞
    for (int i = 2; i <= str.size(); i++) {
        int current = i - 1;
        int a = ctoi(str[current]);
        int b = ctoi(str[current - 1]);
        int num = b * 10 + a;

        // 현재 자리가 0이 아니면, 바로 전 경우의 수와 똑같다.
        if (a > 0) dp[i] = dp[i - 1] % MOD;

        // 현재 숫자가 두 자리 수 라면, 현재의 경우의 수 + 2칸 전의 경우의 수
        if (10 <= num && num <= 26) dp[i] = (dp[i] + dp[i - 2]) % MOD;
    }
    cout << dp[str.size()] << "\n";
    return 0;
}