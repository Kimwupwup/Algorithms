/**
 * SW Expert 8016번 - 홀수 피라미드
 * 
 * */

#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        n -= 1;
        long long ret = 1;
        long long current = 1 + (n - 1) * 2;
        long long sum = n * (1 + current);
        
        ret = 1 + 1 * sum;
        
        cout << "#" << t << " " << ret << " " << ret + (current + 1) * 2 << "\n";
    }
    return 0;
}