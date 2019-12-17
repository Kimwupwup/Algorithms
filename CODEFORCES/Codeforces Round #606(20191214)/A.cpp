/**
 * http://codeforces.com/contest/1277/problem/A
 * Codeforces Round #606(20191214)
 * A. Happy Birthday, Polycarp!
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
        int ret = 0;
        long long m;
        long long n;
        cin >> n;

        for (int i = 1; i < 10; i++) {
            m = 0;
            while (true) {
                m = m * 10 + i;
                if (m > n)
                    break;
                else
                    ret++;
            }
        }
        cout << ret << "\n";
    }
    return 0;
}