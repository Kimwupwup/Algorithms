/**
 * 백준 1016번 - 제곱 ㄴㄴ 수
 * 
 * TODO:
 * 에라토스테네스의 체
 * */
#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 1000000 + 1;
long long n, m;
long long matrix[MAX];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (long long i = 2; i * i <= m; i++) {
        long long sq = i * i;

        long long cnt = n / sq;

        if (n % sq != 0) {
            cnt++;
        }

        while (cnt * sq <= m) {
            matrix[cnt * sq - n]++;
            cnt++;
        }
    }

    long long ret = 0;
    for (int i = 0; i < m - n + 1; i++) {
        if (!matrix[i])
            ret++;
    }
    cout << ret << "\n";
    return 0;
}