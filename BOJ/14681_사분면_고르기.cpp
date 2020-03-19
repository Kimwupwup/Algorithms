/**
 * 백준 14681번 - 사분면 고르기
 * 
 * */
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    if (a > 0 && b > 0) cout << 1 << "\n";
    else if (a > 0 && b < 0) cout << 4 << "\n";
    else if (a < 0 && b > 0) cout << 2 << "\n";
    else cout << 3 << "\n";

    return 0;
}