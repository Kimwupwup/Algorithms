/**
 * 백준 2355번 - 시그마
 * 
 * */
#include <iostream>
#include <cmath>
using namespace std;

long long A, B;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> A >> B;

    long long cnt = (abs(B - A) + 1) / 2;
    long long mid = (abs(B - A) + 1) % 2 == 1 ? (B + A) / 2 : 0;
    long long ret = (A + B) * cnt + mid;
    cout << ret << "\n";
    return 0;
}