/**
 * 백준 2475번 - 검증수
 * 
 * */
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int arr[5], ret = 0;
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
        ret += (arr[i] * arr[i]) % 10;
    }

    cout << ret % 10 << "\n";

    return 0;
}