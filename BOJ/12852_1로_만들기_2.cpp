/**
 * 백준 12852번 - 1로 만들기 2
 * 
 * */
#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
const int MAX = 1e6 + 1;
int dp[MAX];
int answer[MAX];
int n;

int solve(int num) {
    if (num == 1)
        return 0;
    
    int &ret = dp[num];
    if (ret != -1) 
        return ret;
    
    ret = INF;
    int temp;
    int out;
    if (num % 3 == 0) {
        temp = solve(num / 3) + 1;
        if (temp < ret) {
            ret = temp;
            out = num / 3;
        }
    }
    if (num % 2 == 0) {
        temp = solve(num / 2) + 1;
        if (temp < ret) {
            ret = temp;
            out = num / 2;
        }    
    }
    if (num - 1 > 0) {
        temp = solve(num - 1) + 1;
        if (temp < ret) {
            ret = temp;
            out = num - 1;
        }    
    }
    answer[num] = out;
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i <= n; i++)
        dp[i] = -1;
    cout << solve(n) << "\n";

    int idx = n;
    while (idx) {
        cout << idx << " ";
        idx = answer[idx];
    }
    return 0;
}