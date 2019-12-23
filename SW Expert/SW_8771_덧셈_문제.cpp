/**
 * SW Expert 8771번 - 덧셈 문제
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
        long long n, a, b;
        cin >> n >> a >> b;

        long long ret = (b - a) * (n - 2) + 1;

        if (a > b || (a != b && n == 1)) {
            ret = 0;
        }
        cout << "#" << t << " " << ret << "\n";
    }
    return 0;
}