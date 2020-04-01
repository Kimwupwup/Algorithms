/**
 * 백준 2455번 - 지능형 기차
 * 
 * */
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, sum = 0, ret = 0;
    for (int i = 0; i < 4; i++) {
        cin >> a >> b;
        sum += (b - a);
        ret = max(ret, sum);
    }
    cout << ret << "\n";
    return 0;
}