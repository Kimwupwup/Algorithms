/**
 * 백준 2749번 - 피보나치 수 3
 * 
 * TODO:
 * 피사보 주기
 * 피보나치 수열의 값들을 일정한 값의 나머지로 하였을 때, 주기를 가진다.
 * m1, m2 변수를 이용하여 flip을 계속 진행하면서, 다시 m1, m2가 1, 1을 가질 때를 찾는다.
 * m1 = 1, m2 = 1
 * if (뒤집지 않았을 때)
 * m1 = (m1 + m2) % mod
 * else
 * m2 = (m1 + m2) % mod
 * flip = !flip
 * 이를 진행하면 피보나치 수열을 만들면서 주기를 찾을 수 있다.
 * 주기를 찾은 후, 주기를 실행하면 n번째 피보나치 수를 알 수 있다.
 * */
#include <iostream>

using namespace std;

const int MOD = 1000000;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    long long n;
    cin >> n;

    if (n == 1 || n == 2) {
        cout << 1 << "\n";
        return 0;
    }

    int m1 = 1, m2 = 1;
    bool flip = true;
    int cnt = 3;    // index 0, 1, 2 카운트한 상태

    // 주기 찾기
    while (true) {
        if (flip)
            m1 = (m1 + m2) % MOD;
        else 
            m2 = (m1 + m2) % MOD;
        flip = !flip;

        if (m1 == 1 && m2 == 1)
            break;
        cnt++;
    }

    // cnt(주기)를 찾았으니, n의 나머지 만큼 돌리면 된다.
    // cnt는 1, 1을 한번 더 찾은 경우이므로, 2를 빼줘야 정확한 주기값이 된다. (0 ~ cnt - 3까지 이므로 cnt - 2주기)
    n %= (cnt - 2);
    m1 = 1;
    m2 = 1;
    flip = true;
    for (int i = 3; i <= n; i++) {
        if (flip)
            m1 = (m1 + m2) % MOD;
        else
            m2 = (m1 + m2) % MOD;
        flip = !flip;
    }
    flip = !flip;
    cout << (flip ? m1 : m2) << "\n";
    return 0;
}