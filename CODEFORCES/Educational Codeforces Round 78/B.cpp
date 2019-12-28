/**
 * Educational Codeforces Round 78
 * B. A and B
 * 
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;

int a, b;

bool solution(long long ret, int cal) {
    long long sum = ret  * (ret + 1) / 2;
    if (sum < cal) return false;
    return sum % 2 == cal % 2;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        
        cin >> a >> b;

        int cal = abs(a - b);
        if (cal == 0) {
            cout << 0 << "\n";
            continue;
        }

        long long ret = 1;
        while (!solution(ret, cal)) {
            ret++;
        }
        cout << ret << "\n";

    }
    return 0;
}