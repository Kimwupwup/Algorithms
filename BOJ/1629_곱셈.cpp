/**
 * 백준 1629번 - 곱셈
 * 
 * TODO:
 * 분할정복
 * */
#include <iostream>
using namespace std;

long long partition(int a, int b, int c) {
    if (b == 1) return a;
    long long tmp = partition(a, b / 2, c) % c;

    if (b % 2) return ((tmp * tmp) % c * a) % c;
    else return (tmp * tmp) % c;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    cout << partition(a % c, b, c) << "\n";
    return 0;
}