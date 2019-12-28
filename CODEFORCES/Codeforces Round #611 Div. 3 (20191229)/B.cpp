/**
 * http://codeforces.com/contest/1283/problem/B
 * Codeforces Round #611 Div. 3 (20191229)
 * B. Candies Division
 * 
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;

        int div = n / k;
        int cnt = k / 2;

        int ret = div * k;
        ret += min(n - ret, cnt);
        cout << ret << "\n";
    }
    return 0;
}