/**
 * 백준 1934번 - 최소공배수
 * 
 * */
#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b) {
    if (a % b == 0)
        return b;
    return GCD(b, a % b);
}

int LCM(int a, int b) {
    return (a * b) / GCD(a, b);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, t;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << LCM(a, b) << "\n";
    }
    
    return 0;
}