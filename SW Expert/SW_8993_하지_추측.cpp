/**
 * SW Expert 8993번 - 하지 추측
 * 
 * 짝수면 2로 나누고
 * 홀수면 3을 곱하고 3을 더한다.
 * 홀수 * 홀수 = 홀수
 * 홀수 + 3 = 짝수
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
        long long n;
        cin >> n;

        while (n % 2 == 0) {
            n /= 2;
        }
        if (n == 1)
            cout << "#" << t << " " << "YES" << "\n";
        else 
            cout << "#" << t << " " << "NO" << "\n";
    }
    return 0;
}