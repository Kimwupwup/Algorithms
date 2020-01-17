/**
 * 백준 10872번 - 팩토리얼
 * 
 * */
#include <iostream>
using namespace std;

const int MAX = 13;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    long long ret = 1;
    for (int i = 1; i <= n; i++) {
        ret *= i;
    }
    cout << ret << "\n";
    return 0;
}