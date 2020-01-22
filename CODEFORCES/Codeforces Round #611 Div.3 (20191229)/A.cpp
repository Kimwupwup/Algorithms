/**
 * http://codeforces.com/contest/1283/problem/A
 * Codeforces Round #611 Div. 3 (20191229)
 * A. Minutes Before the New Year
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
        int h, m;
        cin >> h >> m;
        m = m + (h * 60);
        int time = 1440;

        int ret = time - m;
        cout << ret << "\n";
    }
    return 0;
}