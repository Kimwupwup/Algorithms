/**
 * SW Expert 8659번 - GCD
 * 
 * */

#include <iostream>
#include <algorithm>

using namespace std;

int GCD(int a, int b) {
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        long long a = 2;
        long long b = 1;

        for (int i = 1; i < n; i++) {
            long long next_a = a + b;
            long long next_b = a;

            a = next_a;
            b = next_b;
        }

        cout << "#" << t << " " << a << " " << b << "\n";
    }
    return 0;
}